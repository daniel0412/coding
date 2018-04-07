# Rate Limiter
Given `maxRate`, return if access permit can be obtained. [Ref](http://systemdesigns.blogspot.com/2015/12/rate-limiter.html)
## Solutions
### fixed queue
```cpp
// vector size is rate per second
vector <int> ts(maxRate, 0); // curcularly used
int nextId = 0;
bool acquire() {
    int currentTs;
    if(currentTs - ts[nextId] > 1) {
        ts[nextId] = currentTs;
        nextId = (nextId+1) % maxRate;
        return true;
    }
    return false;
}
```
### token bucket
    - idea: when trying to acquire, distribute max permits, and then allocate it
```cpp
int preTs = 0;
bool acquire() {
    int currentTs;
    int numPermits = min(maxRate, numPermits + (currentTs - preTs)*maxRate);
    preTs = currentTs;
    if(numPermits < 1) return false;
    --numPermits;
    return true;
}
```

- [google guava implementation](https://github.com/google/guava/blob/master/guava/src/com/google/common/util/concurrent/RateLimiter.java)

## Follow-ups
- How to save space with `10^9` query per hour?      Batch queries
- How to support multiple threads?      Lock
- How to support limiter on users/ips?
    - for each identity, maintain a queue `<uid/ips, requestList>`
- How to support query with different quotas?      Acquire ( quota )
