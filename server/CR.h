#ifndef CR_H
#define CR_H

#include <chrono>
// todo: struct 字节对齐未考虑
typedef int ID;
typedef std::chrono::time_point<std::chrono::system_clock> Time;

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
}MsgPack;

// 心跳包 - 1
typedef struct heartpack {
  ID id;
  Time stamptime;
}HeartPack;

// 注册包 - 2
typedef struct registerpack {
  ID id;
  User user;
}RegisterPack;

// 用户
typedef struct user {
  ID id;
  char name[32];
  short status;
  int sockfd;
  Time last;
  int count;
  int friends[120];
}User;

// socket缓存区
typedef struct buffer_ {
  int len;
  char buffers[sizeof(Pack)];
}Buffer;


