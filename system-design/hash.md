## Consistent Hashing
### Regular Hashing
#### Why
- to break the `RAM` limitation of single server, need to distribute traffic to multiple servers
- for certain traffic, which server should it go to
```cpp
serverId = hash(key) % n
```

#### Disadvantages
- severe rehashing issues, when adding/removing servers, `n` is increased/decreased
- most of the data will need to be moved to other servers

### Consistent Hasing
Consistent hashing ideas
- `key` space forms a virtual hash value cycle, each server gets mapped to a node in the cycle
- after `hash(key)`, each key is processed/stored by the server next to it in clockwise direction
- to suit different servers with different capability in terms of RAM/CPU and etc, we can assign weights to each server, i.e., put multiple logical
servers on the ring for the same physical server
- if one server goes down, only data on this server is affected, and rehashing only applies to this physical node
- if more physical servers are added, `[r1, r2)` are split into `[r1, r3)` and `[r3, r2)`, and only data from `[r1, r3)` needs to be rehashed to the new
server

#### Use Cases
- Memcached
- Load balancing

