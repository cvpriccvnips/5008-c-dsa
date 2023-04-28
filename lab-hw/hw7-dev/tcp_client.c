
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// 定义服务器端口
#define SERVER_PORT 5432
// 定义最大消息长度
#define MAX_LINE 256

int
main(int argc, char * argv[])
{
  // 定义文件指针
  FILE *fp;
  // 定义hostent结构体指针
  struct hostent *hp;
  struct sockaddr_in sin;
  // 定义服务器主机名
  char *host;
  // 定义消息缓冲区
  char buf[MAX_LINE];
  // define sockets
  int s;
  // define message length
  int len;

  // 检查命令行参数是否正确
  if (argc==2) {
    // 获取主机名
    host = argv[1];
  }
  else {
    // 输出使用方法
    fprintf(stderr, "usage: simplex-talk host\n");
    // exit program
    exit(1);
  }

  /*
  gethostbyname() 函数用于通过主机名获取主机的网络地址信息。该函数的参数是一个指向主机名的字符串指针，函数返回一个指向 hostent 结构体的指针，该结构体包含了主机的各种网络地址信息。
  hp = gethostbyname(host) 表示将 gethostbyname() 函数的返回值赋值给 hp 变量，即将指向 hostent 结构体的指针赋值给 hp 变量。host 是一个字符串指针，用于指定要查询的主机名。
  hostent 结构体包含了主机的各种网络地址信息，包括主机名、别名、地址类型和地址等。该结构体的定义如下：

  plaintext
  Copy code
  struct hostent {
    char    *h_name;            // official name of host 
    char    **h_aliases;        // alias list 
    int     h_addrtype;         // host address type 
    int     h_length;           // length of address 
    char    **h_addr_list;      // list of addresses 
  };

  其中，h_name 表示主机的正式名称，h_aliases 表示主机的别名列表，h_addrtype 表示主机地址类型，h_length 表示主机地址的长度，h_addr_list 表示主机的地址列表。
  */
  hp = gethostbyname(host);
  // 检查主机是否存在
  if (!hp) {
    /*
    fprintf is a function that prints a formatted message to a file stream.
    stderr is a file stream that represents the standard error output, usually displayed on the terminal/console.
    "simplex-talk: unknown host: %s\n" is a formatted string that specifies the message to be printed. %s is a placeholder for the string that will be provided as an argument.
    host is a variable of type char* that contains the name of the unknown host that caused the error. It is used to fill in the %s placeholder in the formatted string.
    */
    fprintf(stderr, "simplex-talk: unknown host: %s\n", host);
    exit(1);
  }
  // 初始化sin结构体
  bzero((char *)&sin, sizeof(sin));
  // 设置地址族为IPv4
  sin.sin_family = AF_INET;
  // 将主机地址拷贝到sockaddr_in结构体中
  bcopy(hp->h_addr, (char *)&sin.sin_addr, hp->h_length);
  // 设置端口号
  sin.sin_port = htons(SERVER_PORT);

  // 创建socket
  if ((s = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
    // 输出错误信息
    perror("simplex-talk: socket");
    exit(1);
  }
  // 连接服务器
  if (connect(s, (struct sockaddr *)&sin, sizeof(sin)) < 0)
  {
    // 输出错误信息
    perror("simplex-talk: connect");
     // close socket
    close(s);
    exit(1);
  }

  // 从标准输入读取消息并发送
  while (fgets(buf, sizeof(buf), stdin)) {
    // 将消息缓冲区的末尾设为'\0'
    buf[MAX_LINE-1] = '\0';
    // 计算消息长度
    len = strlen(buf) + 1;
    // 发送消息
    send(s, buf, len, 0);
  }
} 
