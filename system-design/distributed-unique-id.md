# Distributed Unique ID Generation

## requirements
- globally unique
- roughly sorted by time
    - in distributed settings, cannot guarantee stricly sorted, but roughly
- as short as possible

## methodology
### twitter snowflake
- 1 bit: reserved
- 41 bits: timestamp
- 10 bits: machine number
- 12 bits: sequence number

### multiple sql server
- round robin load balancer before `n` servers
- each server is responsible for `[1, ..., n] * k` ids
    - server 1: 1, n+1, 2n+1, ...
    - server 2: 2, n+2, 2n+2, ...
