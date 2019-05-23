#ifndef CR_H
#define CR_H

#include <chrono>

#define WORDS_LEN 200

// todo: struct 字节对齐未考虑
typedef int ID;
typedef std::chrono::time_point<std::chrono::system_clock> Time;
typedef unsigned int token_t;

// 包头
typedef struct header {
  int ver;
  int kind;
  int p_len;
}Header;

// 消息包 - 0
typedef struct msgpack {
  ID from;
  ID to;
  char words[WORDS_LEN];
  Time stamptime;
  token_t tk;
}MsgPack;

// 心跳包 - 1
typedef struct heartpack {
  ID id;
  Time stamptime;
  token_t tk;
}HeartPack;

// 注册包 - 2
typedef struct registerpack {
  ID id;
  char pwd[12];
  User user;
}RegisterPack;

// 登入包 - 3
typedef struct loginpack {
  ID id;
  char pwd[12];
}LoginPack;

// 确认包 - 9
typedef struct ackpack {
  short status;
  token_t tk;
}AckPack;

// 用户
typedef struct user {
  ID id;
  char name[32];
  char pwd[12];
  short status;
  unsigned int sockfd;
  Time last;
  int count;
  unsigned int friends[120];
}User;

// socket缓存区
typedef struct buffer_ {
  unsigned int len;
  char buffers[sizeof(Header) + sizeof(MsgPack)];
}Buffer;


