# Typeahead System
## Scenarios
- Google typeahead suggestions
    - prefix-> top `k` hot keywords
    - DAU: 500m
    - Searches: 6 * 6 * 500m ~ 18b (6 words and 6 chars per word)
    - QPS: 18b / 24 / 3600 = 18b / 86400 ~ 200k
    - Peak QPS: 2 * QPS ~ 400k
- Twitter typeahead
    - suggestion + user + hashtag

## Services
- Query ervice
    - each time user types a char, the entire prefix is sent to the query service
- Data collection service

## Storege
### Query service db
#### word count table schema
| keyword | hits |
| :---    | :--- |
| amazon  | 20b  |
| adidas  | 10b  |
| airbnb  | 7b   |
- should be case-insensitive
- SQL query: `SELECT * from hit_stats where keyword LIKE ${key}% ORDER BY hits DESC LIMIT 10`
    - `LIKE` operation is expensive
    - `LIKE abc%` equals to `keyword >= "abc" and keyword <"abd"`

#### prefix table schema
convert keyword table to prefix table

| prefix | top k words                 |
| :----  | :----                       |
| a      | "amazon", "adidas", "apple" |
| am     | "amazon", "amc"             |
| ad     | "adidas", "adobe"           |
| don    | "don't havs", "donald"      |

#### trie
- trie in memory + serialized trie (how?) on disk
    - faster than db: all in memory vs db miss
- store word count at ending node, but it is too slow
    - top K will be exponential to traversal all nodes
- store top k hot words at each node with the current prefix, O(n)

| prefix | top k words                 |
| :----  | :----                       |
| a      | "amazon", "adidas", "apple" |
| am     | "amazon", "amc"             |
| ad     | "adidas", "adobe"           |
| don    | "don't havs", "donald"      |

- how to add new record `{"abc": 3b}`
    - add it to all nodes along the trie path
    - if exceeds `k`, should compare with all records on that node, and replace the less frequent word with new rec

### Data collection service db
- where to store the data
    - big table (user, keyword, timestamp) how to store?
- how often do you aggregate the data to update the tire?
    - realtime impractical: read/write qps ~ 200k, will slow down query
    - once per week: every week, fetch all the log file and aggregate
- how to update the trie? offline upate and works online
    - donot update in memory trie, update the serialized trie, next time when loading, gets the upload

## Scale
### How to reduce latency
- caceh results
    - front-end browser cache
- pre-fetch
    - fetch the latest results

### what if trie size too large to be stored in one machine
- use consistent hashing to distribute the prefix strings
    - "a", "am", "ad" should be stored on different machiens
    - should not shard by character, since not all query string are evenly distributed according to characters

### How to reduce size of log files, too much queries
- probablistic logging
    - too much log, and too slow to aggregate
    - log with 1/10,000 probability
- hyperloglog (????)
