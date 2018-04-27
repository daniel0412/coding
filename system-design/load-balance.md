# Load Balancing
- good to have multiple load balancers for availability reason
- two possible availability modes: 
    - active - active: master-master
    - active - pasive: master-slave
## General Schemes
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
