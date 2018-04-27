## Load Balancing
- servers that distribute traffic across multiple servers
### benefits
- prevent overloading servers
- prevent requests routed to unhealthy servers
- eliminate single point of failure
- SSL early termination, such that servers do not need to process request decryption
- session persistence, to route certain requets to the same server

### availability
- good to have multiple load balancers for availability reason
- two possible availability modes: 
    - active - active: master-master
    - active - pasive: master-slave
### general schemes
- random
- least loaded
- session persistent
- round robin or weighted round robin (according to qps different servers can handle)
- functionality based
- consisten hasing based
- Layer 4 load balancer
    - depends on `transportation layer` information, e.g., source/destination ip address and port
- layer 7 load balancer
    - depends on `application layer` information, i.e., the contents of the requests

## Reverse Proxy
- a web server that centralizes internal services and provides unified interfaces to the public
- requests from clients are forwarded to a server that can fulfill it before the reverse proxy returns the server's response to the client.
- even works for just one single server

### benefits:
- Increased security: hide information about backend servers, blacklist IPs, limit number of connections per client
- Increased scalability and flexibility: lients only see the reverse proxy's IP, allowing you to scale servers or change their configuration
- SSL termination: decrypt incoming requests and encrypt server responses so backend servers do not have to perform these potentially expensive operations
    - Removes the need to install X.509 certificates on each server
- Compression: compress server responses
- Caching: return the response for cached requests
- Static content: serve static content directly, e.g., HTML/CSS/JS, Photos, Videos

