# TCP Implementation
Get my hands dirty on the TCP (Transmission Control Protocol).

## Prerequisites
* Linux Operating System
* [GoogleTest](https://github.com/google/googletest)
* [Cmake](https://cmake.org)

## How to build?
1. `git clone https://github.com/Bitate/TCP`
2. `mkdir build && cd build`
3. `cmake ..`

## Difficulties
* Why the generation of ISN is critical(Initial Sequence Number)?
An inappropriate generation will make TCP suffer ISN gussing attacks. 

    * What is the mechanism of the attack? 


* How to select an appropriate ISN?

    * Linux's approach:

    * Window's approach: 

    * My approach: 

## References
* [RFC 675](https://tools.ietf.org/html/rfc675)
* [RFC 6528](https://tools.ietf.org/html/rfc6528)
* [Using Linux Raw Sockets](https://squidarth.com/networking/systems/rc/2018/05/28/using-raw-sockets.html)
* [A Guide to Using Raw Sockets](https://www.opensourceforu.com/2015/03/a-guide-to-using-raw-sockets/)
* [TCP Initial Sequence Numbers in Linux](https://chris-wood.github.io/2016/09/30/TCP-ISN-MD5.html)