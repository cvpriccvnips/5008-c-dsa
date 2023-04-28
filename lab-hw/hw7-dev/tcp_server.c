#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// 定义服务器的端口号
#define SERVER_PORT  5432
// 最大的挂起连接数
#define MAX_PENDING  5
// 最大的缓冲区大小
#define MAX_LINE     256

int
main()
{
  // 用于表示socket地址结构体
  struct sockaddr_in sin;
  // 缓冲区，用于存储发送和接收的数据
  char buf[MAX_LINE];
  int buf_len, addr_len;
  // s表示socket文件描述符，new_s表示接收到的socket文件描述符
  int s, new_s;

  // 初始化socket地址结构体
  bzero((char *)&sin, sizeof(sin));
  // 设置地址族为IPv4
  sin.sin_family = AF_INET;
  // 设置IP地址
  sin.sin_addr.s_addr = INADDR_ANY;
  // 设置端口号
  sin.sin_port = htons(SERVER_PORT);

  // socket() 函数用于创建一个新的套接字，并返回该套接字的文件描述符。该函数的参数包括套接字的地址族、套接字的类型和协议，其中 PF_INET 表示 IPv4 地址族，SOCK_STREAM 表示面向连接的流式套接字，0 表示使用默认的协议。 (s = socket(PF_INET, SOCK_STREAM, 0)) 表示将 socket() 函数的返回值赋值给 s 变量，并判断 s 是否小于 0。如果 socket() 函数调用失败，s 的值会小于 0，此时会执行 if 语句块中的代码。
  if ((s = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
    perror("simplex-talk: socket");
    exit(1);
  }

  // 绑定socket到指定的地址和端口号
  // (struct sockaddr *)&sin 表示将 sin 结构体强制转换为 sockaddr 类型的指针。这是因为 bind() 函数需要传入一个指向 sockaddr 结构体的指针作为第二个参数。
  // &sin 表示取 sin 结构体的地址，即获取指向 sin 结构体的指针。
  // sizeof(sin) 表示获取 sin 结构体的大小，单位是字节。
  // < 0 表示比较结果小于 0。如果 bind() 函数的返回值小于 0，则表示绑定失败。
  if ((bind(s, (struct sockaddr *)&sin, sizeof(sin))) < 0) {
    perror("simplex-talk: bind");
    exit(1);
  }
  // 监听socket，等待连接请求
  listen(s, MAX_PENDING);

  while(1) {
    /* 
    accept() 函数用于接受客户端的连接请求，并返回一个新的套接字文件描述符，该文件描述符用于与客户端进行通信。accept() 函数的参数包括服务器的套接字文件描述符、指向 sockaddr 结构体的指针以及用于存储客户端地址的变量的指针。
    (new_s = accept(s, (struct sockaddr *)&sin, &addr_len)) 表示将 accept() 函数的返回值赋值给 new_s 变量，并判断 new_s 是否小于 0。如果 accept() 函数调用失败，new_s 的值会小于 0，此时会执行 if 语句块中的代码。
    (struct sockaddr *)&sin 表示将 sin 结构体强制转换为 sockaddr 类型的指针。这是因为 accept() 函数需要传入一个指向 sockaddr 结构体的指针作为第二个参数。
    &addr_len 表示获取 addr_len 变量的地址，即返回一个指向 addr_len 变量的指针。addr_len 变量用于存储客户端地址结构体的大小。

    在使用套接字进行网络通信时，需要使用套接字文件描述符来标识和操作套接字。套接字文件描述符是一个整数，用于唯一标识一个套接字。可以使用该文件描述符进行数据的发送和接收，以及其他操作。
    在服务器端，当有多个客户端连接时，需要为每个客户端创建一个新的套接字文件描述符，用于与客户端进行通信。这是因为，每个客户端连接都是独立的会话，需要使用不同的套接字文件描述符来处理。
    因此，当服务器端使用 accept() 函数接受客户端连接请求时，会返回一个新的套接字文件描述符，用于与客户端进行通信。该新的套接字文件描述符是服务器端为该客户端创建的，用于处理该客户端连接的套接字。
    */
    if ((new_s = accept(s, (struct sockaddr *)&sin, &addr_len)) < 0) {
      perror("simplex-talk: accept");
      exit(1);
    }
    // 循环接收数据，直到接收到的数据长度为0
    /*
    recv() 函数用于从套接字接收数据，并将接收到的数据存储到指定的缓冲区中。recv() 函数的参数包括套接字文件描述符、指向缓冲区的指针、缓冲区的大小以及其他参数。
    while (buf_len = recv(new_s, buf, sizeof(buf), 0)) 表示使用 recv() 函数从 new_s 套接字接收数据，并将接收到的数据存储到 buf 缓冲区中，同时判断 buf_len 是否大于 0。如果 recv() 函数接收到数据，则 buf_len 的值为接收到的数据的字节数；如果 recv() 函数未接收到数据，则 buf_len 的值为 0。当 buf_len 的值为 0 时，表示客户端已经关闭了连接，此时会退出 while 循环。
    buf 是一个字符数组，用于存储接收到的数据。sizeof(buf) 表示获取 buf 数组的大小，单位是字节。这里使用 sizeof(buf) 是为了确保 recv() 函数不会将超过 buf 数组大小的数据存储到 buf 中，从而避免缓冲区溢出的问题。
    new_s 是一个套接字文件描述符，用于标识与客户端进行通信的套接字。
    */
    while (buf_len = recv(new_s, buf, sizeof(buf), 0)) 
      // 将接收到的数据输出到标准输出
      fputs(buf, stdout);
    // 关闭接收到的socket文件描述符
    close(new_s);
  }
}

/*
socket(): 创建一个socket，返回socket的文件描述符。
bind(): 将socket与指定的IP地址和端口号绑定在一起，使得客户端可以通过指定的IP地址和端口号来访问服务器。
listen(): 将socket设置为监听状态，使得服务器可以接收客户端的连接请求。
accept(): 接收客户端的连接请求，并创建一个新的socket文件描述符用于与客户端通信。
recv(): 接收从客户端发送的数据，并将其存储在缓冲区中。
close(): 关闭socket连接。
*/
