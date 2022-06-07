# TCP Interface
## Server/Client Chat App 

### Build:
```
cmake -Bbuild && cd build && make
```

### Usage: 
```
[ ./tcp Usage ]
./tcp [ Required: -s | -c ] [Optional: -i <ip-address>, -p <port>]>
-s | Run server
-c | Run client
-i | Set ip address, if not set default 127.0.0.1 is used
-p | Set port, if not set default 8080 is used
```
