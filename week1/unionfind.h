#ifndef __UNIONFIND_H_INCLUDED__
#define __UNIONFIND_H_INCLUDED__


class UF
{
  int *N;
  int size;
public:

  UF(int size){
    int i = 0;
    this->N = new int[size];
    this->size = size;
    while(i < size ) *(this->N + i) = i++;
  };

  void print() {
    int i = 0;
    while(i < this->size) std::cout<<*(this->N + i++)<<std::endl;
  }

  void union_UF(int, int);
  bool connected(int, int);
};

#endif
