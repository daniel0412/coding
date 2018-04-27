# Content Delivery Network (CDN)

## what and why
- globally distributed network of proxy servers
- mostly used to provide static content data, e.g., html/css/js, photos, videos
- reduce latency by using data closer to the client geographically
- reduce server traffic by routing to CDN servers

## types
### Push CDN
- push content data to cdn whenever this is any change to the data
- only need to push once if data not change that often, thus reduce traffic

### Pull CDN
- pull it when first requested for the content, thus slower than cached already
- TTL is set to determin how long the content can be stored
- minimize cdn storage by not pulling content never requested
- increase traffic by multiple pull, even for contents never changed
- content might be stale if it is changed before TTL is reached
