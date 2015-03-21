Introduction to SSAPI

# Overview #

C sockets are a very simple and well established API. The SSAPI (Simple Sockets API) establishes that same lightweight, abstract, and easy to use API and wraps it up into a few simple polymorphic classes.


# Details #

SSAPI constists of these classes:
  * **Socket** - the _base_ class
  * **Address** - an abstract class for wrapping host resolving
  * **Inet** - parent class to all _Internet_ type sockets
  * **Unix** - parent class to all _Unix_ style sockets
  * **FileSocket** - _Unix_ _file_ socket type
  * **SocketPair** - class for creating _socket_ _pair_ type sockets
  * **UdpSocket** - class for _UDP_ socket type
  * **TcpSocket** - class for _TCP_ socket type

#  **Text in**bold**or _italic_
#** Headings, paragraphs, and lists
#  