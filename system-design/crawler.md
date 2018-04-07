# Crawler

## Scenario
Given seeds, crawl the web
- How many web pages?
    - trillion web pages
- How long?
    - Crawl all of them every week
- How large?
    - Average size of a web page: 10k
    - 10p web page storage

## Service
* Crawler service
* Task service
* Storage service

## Scale
### Shard task table
* Horizontal sharding



Below is a evolving list of crawler system in terms of complexity and scalability
### Simplistic news crawler
Given the URL of news list page
- Send an HTTP request and grab the content of the news list page
- Extract all the news titles from the news list page with `regex`
```python
import urllib2
url = 'http://tech.163.com/it'
# get html
request = urllib2.Request(url)
response = urllib2.urlopen(request)
page = response.read()

# extract info using regular expressions
```

### Single threaded web crawler
- given some selected url seeds, generate list of more urls
#### simple bfs solution
```python
// breath first search, single-threaded crawler
def run():
    while(len(url_queue) > 0):
	url = url_queue.dequeue()
	html = web_page_loader.load( url ) // consume
	url_list = url_extractor.extract( html ) // produce
	url_queue.enqueue_all( url_list )
```

#### producer consumer impementation
```python
import time
import random
from threading import Thread, Lock

# maintain a globle queue
queue = []
lock = Lock()

# Producer keeps on adding to the queue
class ProducerThread(Thread):
    def run(self):
	nums = range(5) # model the produced urls
	global queue
	while True:
	    # model more urls are scraped
	    num = random.choice(nums)
	    lock.acquire()
	    queue.append(num)
	    lock.release()
	    time.sleep(random.random())

# Consumer keeps on removing from the queue
class ConsumerThread(Thread):
    def run(self):
	global queue
	while True:
	    # queue is kept inside lock to avoid race condition
	    lock.acquire()
	    num = queue.pop(0)
	    lock.release()
	    time.sleep(random.random())

# start one producer thread and one consumer thread
ProducerThread().start()
ConsumerThread().start()
```

#### Improve with Condition
* Condition object allows one or more threads to wait until notified by another thread. 
And this is exactly what we want. We want consumer to wait when the queue is empty and resume only when it gets notified by the producer. 
Producer should notify only after it adds something to the queue. 
So after notification from producer, we can be sure that queue is not empty and hence no error can crop if consumer consumes.
- Condition is always associated with a lock
- A condition has acquire() and release() methods that call the corresponding methods of the associated lock. 
Condition provides acquire() and release() which calls lock's acquire() and release() internally, 
and so we can replace lock instances with condition instances and our lock behaviour will keep working properly.
- Consumer needs to wait using a condition instance and producer needs to notify the consumer using the condition instance too. 
So, they must use the same condition instance for the wait and notify functionality to work properly.

```python
from threading import Condition

condition = Condition()
class ConsumerThread(Thread):
    def run(self):
	global queue
	while True:
	    condition.acquire()
	    if not queue:
		condition.wait()
	    num = queue.pop(0)
	    condition.release()
	    time.sleep(random.random())

class ProducerThread(Thread):
    def run(self):
	nums = range(5)
	global queue
	while True:
	    condition.acquire()
	    num = random.choice(nums)
	    queue.append(num)
	    condition.notify()
	    condition.release()
	    time.sleep(random.random())
```

#### Add a max size on the queue

```python
import time
import random
from threading import Thread, Condition

queue = []
MAX_NUM = 10
condition = Condition()

class ProducerThread(Thread):
    def run(self):
	nums = range(5)
	global queue
	while True:
	    condition.acquire()
	    if len(queue) == MAX_NUM:
		condition.wait()
	num = random.choice(nums)
	queue.append(num)
	condition.notify()
	condition.release()
	time.sleep(random.random())

class ConsumerThread(Thread):
    def run(self):
	global queue
	while True:
	    condition.acquire()
	   if not queue:
	    condition.wait()
	num = queue.pop(0)
	condition.notify()
	condition.release()
	time.sleep(random.random())

ProducerThread().start()
ConsumerThread().start()
```

#### Use a queue instead
- `Queue` encapsulates the behaviour of Condition, wait(), notify(), acquire() etc.

```python
import time
import random
from Queue import Queue
from threading import Thread

queue = Queue(10)

class ProducerThread(Thread):
    def run(self):
	nums = range(5)
	global queue
	while True:
	    num = random.choice(nums)
	    queue.put(num)
	    time.sleep(random.random())

class ConsumerThread(Thread):
    def run(self):
	global queue
	while True:
	    num = queue.get()
	    queue.task_done()
	    time.sleep(random.random())

ProducerThread().start()
ConsumerThread().start()
```

### Multi-threaded web crawler
#### How different threads work together?
- sleep: Stop a random interval and come back to see whether the resource is available to use.
- condition variable: As soon as the resource is released by other threads, you could get it immediately.
- semaphore: Allowing multiple number of threads to occupy a resource simultaneously. Number of semaphore set to 1.

#### More threads `!=` better performance. Number of threads on a single machine is limited because:
- Context switch cost ( CPU number limitation )
- Thread number limitation (16 bits = 65536)
- Network bottleneck for single machine (10Gbps)

### A distributed web crawler
- URL queue is inside memory. Queue is too big to completely fit into memory. Use a MySQL DB task table
    - state (working/idle): Whether it is being crawling.
	- priority (1/0):
	    - available time: frequency. When to fetch the next time.

	    | id | url                     | state     | priority | available_time        |
	    |----|-------------------------|-----------|----------|-----------------------|
	    | 1  | “http://www.sina.com/”  | “idle”    | 1        | “2016-03-04 11:00 am” |
	    | 2  | “http://www.sina1.com/” | “working” | 1        | “2016-03-04 12:00 am” |
	    | 3  | “http://www.sina2.com/” | “idle”    | 0        | “2016-03-14 02:00 pm” |
	    | 4  | “http://www.sina3.com/” | “idle”    | 2        | “2016-03-12 04:25 am” |


### How to handle update for failure
- Exponential back-off
    - Success: crawl after 1 week
    - no.1 failure: crawl after 2 weeks
    - no.2 failure: crawl after 4 weeks
    - no.3 failure: crawl after 8 weeks

### How to handle dead cycle
- Too many web pages in sina.com, the crawler keeps crawling sina.com and don't crawl other websites
- Use quota (10%)

### Multi-region
- When Google's webpage crawls China's webpages, it will be really really slow. Deploy crawler servers in multiple regions.
