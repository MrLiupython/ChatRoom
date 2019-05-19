#ifndef BUFFMAP_H
#define BUFFMAP_H
#include <map>

template<typename T>
class Buffermap {
  map<int, T*> buffers;
 public:
  Buffermap(): size(0){}
  Buffermap(const Buffermap&)=delete;
  Buffermap& operator=(const Buffermap&)=delete;
  
  ~Buffermap() {
    map<int, T*>::iterator iter;
    for (iter=buffers.begin();iter!=buffers.end();) {
      delete *(iter->second);
      buffers.erase(iter++);
    }
  }
  
  T* insert(int sock) {
    T buffer = new T;
    buffers.insert({{sock, &buffer}});
    return &buffer;
  }
  
  int erase(int sock) {
    map<int, T*>::iterator iter;
    if ((iter=buffers.find(sock)) == buffers.end() ) {
      return 0;
    }
    else {
      delete *(iter->second);
      buffers.erase(iter);
      return 1;
    }
  }
}
