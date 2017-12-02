### Consistent Hashing
#### Problem With Hashing
To break the `RAM` limitation of single server caching system, we need to vertically scale the caching system with multiple servers.
One problem to address is to decide which server should the current `key` go to. Suppoe we have `N` servers, a simple solution is use the following 
to calculate the `serverId` to get/set the `(key, value)` pair:
```cpp
serverId = hash(key) % N
```
This leads to severe rehashing issues, when adding/removing servers, `N` is increased/decreased. Thus, most of the data will need to be moved to other servers,
which is a huge amount of work.

#### Consistent Hasing
Consistent hashing ideas
- virtual `hash ring`, representing hashed value within range `[0, MAX]`
- `N` physical servers are put on the ring, and each stores a subset of the hashed value `[r1, r2]`
- to suit different servers with different capability in terms of RAM/CPU and etc, we can assign weights to each server, i.e., put multiple logical 
servers on the ring for the same physical server
- if one server goes down, only data on this server is affected, and rehashing only applies to this physical node
- if more physical servers are added, `[r1, r2)` are split into `[r1, r3)` and `[r3, r2)`, and only data from `[r1, r3)` needs to be rehashed to the new
server

#### Use Cases
- Memcached

