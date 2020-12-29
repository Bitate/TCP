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
* [RFC 793](https://tools.ietf.org/html/rfc793)
* [RFC 6528](https://tools.ietf.org/html/rfc6528)
* [Using Linux Raw Sockets](https://squidarth.com/networking/systems/rc/2018/05/28/using-raw-sockets.html)
* [A Guide to Using Raw Sockets](https://www.opensourceforu.com/2015/03/a-guide-to-using-raw-sockets/)
* [TCP Initial Sequence Numbers in Linux](https://chris-wood.github.io/2016/09/30/TCP-ISN-MD5.html)
* [Write a Network Device Driver](https://tldp.org/LDP/LG/issue93/bhaskaran.html)
* [What's the difference between a TCP segment and a TCP packet?](https://superuser.com/questions/298087/whats-the-difference-between-a-tcp-segment-and-a-tcp-packet)
* [Linux网络协议栈【驱动和网卡怎样交互？】](https://zhuanlan.zhihu.com/p/73576057)
* [网卡适配器收发数据帧流程](https://www.cnblogs.com/jmilkfan-fanguiju/p/12789806.html)
* [Low level networking in assembler (x86 compatible)](https://stackoverflow.com/questions/3621932/low-level-networking-in-assembler-x86-compatible)