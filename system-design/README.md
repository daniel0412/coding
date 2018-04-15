# System Design Interview

## Basic Knowledge
- [multi-threading](multithreading.md)
- [database](database.md)
- [hashing](hash.md)
- [load-balancing](load-balance.md)

## General Principals
### Steps to Analyze (4S)
- Scenarios: what features/query per second (QPS)/ daily active users (DAU)/ interfaces
    - ~ 100, single laptop
    - ~ 1k, webserver
    - ~ 1k, sql db
    - ~ 10k, no sql db
    - ~ 1m, no sql cache
- Services: split into different services
- Storage: how to store? schema/sql/nosql/filesytem
- Scale: how to scale? sharding/optimization corner cases

## Classical Design Questions
- [News Feeds](newsfeeds.md)
- [Web Crawler](crawler.md)
- [Typeahead System](typeahead.md)
- [Key Value Store](key-value-store.md)
- [Point of Interest](poi.md)
- [Rate Limiter](ratelimiter.md)
- [Distributed Unique ID](distributed-unique-id.md)
