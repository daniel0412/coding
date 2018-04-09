# News Feeds

## Scenario
### features
- user registration/login
- user profile display/edit
- friendship follow/unfollow
- tweet posting text/image/video
- news feeds
- timeline
- topic search

### analysis
- avg query:  150m (DAU) * 60 (daily avg request) / 86400 (secs/day) ~ 100k
- peak QPS: 100k * 3 ~ 300k
- estimated growth: 300k * 2 ~ 600k (can mention this)
- read qps ~ 300k
- write qps ~ 5k

## Services
- user service
- firendship service
- tweet service
- media service

### pull vs push
#### pull
steps:
- first get all my N following ids (1 DB read)
- for each of N follows, get all recent tweets (N DB reads)
- k-way merge all the tweets (negligible, since all in memory)

good/bad
- post tweet 1 DB write, but N DB reads

when to use?
- enough resources ( can add cache to reduce N DB read latency)
- time sensitive ( since push fanout can takes hours)
- frequent posts

#### Push:
steps:
- every user maintain a `news feed list`
- FANOUT: when followed user post a tweet,  add this tweet info into all the followers `feed list`
- when retrieve news feed, just get most recent from this list

good/bad
- fanout can be asynchronized, but need N DB writes, and N can be huge (celebrity)

when to use?
- less resources of memory, push just store into disk
- time not sensitive
- less frequent posts

#### pull + push

## Storage
- sql
    - user info
    - friendship info
- nosql
    - tweets
    - media data meta info (e.g., file path, number of likes, comments)
- file system
    - image/video

## Scale
- optimize: pull/push, normalization/de-normalization/corner cases/more features
- add a feature to store number of likes of a tweet (de-nomalize it into a separate table from tweet table)
- robustness
- scalability

