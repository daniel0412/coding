# Database Overview
- [basic concepts](#basic-concepts)

## Basic Concepts
- [sharding](#sharding)
- [normalization](#normalization)
### Sharding
Database `sharding` is to split data across different serves to improve scalability. [REF](http://www.25hoursaday.com/weblog/2009/01/16/BuildingScalableDatabasesProsAndConsOfVariousDatabaseShardingSchemes.aspx)
#### Why Sharding
- dataset too large
    - too much data, cannot store on same machien disk
    - too much data, cannot fit into memory for caching
- too many writes
    - IO system (can be improved by `RAID 10` controller w/ battery backed write cache)
    - slave delay (hard to address)
#### Sharding Schemes
- vertical parititioning
    - denomalize to split by col features, but needs future partitioning if users grows too much
- range based partitioning
    - for db with single feature, can partition the feature by range, e.g., parititon by year/date, but can lead to unbalanced db for not knowing the data distribution
- key/hasing based partitioning
    - hash the id, take the modulo, to get right server, but to add/remove server, db needs to be offline
- directory/lookup based partitioning
    - have a lookup svc to check where is the data, no db down time, update this lookup after coping data to new machines
    - too complicated to implement and maintain
#### Pros
- high availability: one server down does not affect data on other servers
- fast query: each server stores less data, also can cache all data per server
- more write bandwidth: each server handles writes for its key ranges
#### Cons
- data rebalancing
    - when original sharding cannot handle data growth, need to reshard and rebalance data
    - extremely difficult without downtime, can use above directory based method, but too complex
- join data from multiple shards
    - join from different tables in same server is easy, but not for multiple shards due to performance constraints
    - denormalization to the rescue, by storing same data to different machines
    - but introduce data inconsistency issue by denormalziation
- referential integrity
    - does not support referential constraint, like foreign key, across different servers
- how to partition: hard to pick one-fit-all partition scheme
- sharding not supported by SQL, implementation can be difficult


### Normalization

## SQL Database

## NoSQL Database
NoSQL is short for `not only SQL`, is designed to handle problems with relational database, e.g., horizontal scaling, frequent write

### CAP Theorem
NOT possible to build an implementation of read-write storage in an asynchronous network that satisfies all of the following three properties:
- Availability - will a request made to the data store always eventually complete?
- Consistency - will all executions of reads and writes seen by all nodes be atomic or linearizably consistent?
- Partition tolerance - the network is allowed to drop any messages.

### key-value store
### wide column store
### document store
### graph database

## SQL vs NoSQL
 | Aspect      | SQL                                                                       | NoSQL                                                                       |
 | :-----      | :---                                                                      | :----                                                                       |
 | Storage     | stored in a relational model, with rows and cols                          | different storage model, check different types                              |
 | Schema      | fixed schema with fixed cols, can append new cols, but with db offline    | dynamic schema, can add cols on the fly, each row no needs to have all cols |
 | Scalability | easy vertical scaling, horizontal scaling is difficult and time consuming | support easy horizontal scaling                                             |
 | ACID        | compliant                                                                 | sacrifice ACID for performance and scalability                              |
 | Operations  | support `join` and `secondary indexing`                                   | no support for `join` and `secondary indexing`                              |
 | Performance | cannot handle too much write                                              | can handle more write per second                                            |


