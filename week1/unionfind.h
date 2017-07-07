#ifndef __UNIONFIND_H_INCLUDED__
#define __UNIONFIND_H_INCLUDED__


class UF
{

  int *N;
  int size;
  #ifdef quickunionheight
  int *height;
  #endif
  #ifdef quickunionimproved
  int *sz;
  #endif

  int root (int idx) {
    while(idx != this->N[idx]) {
      #ifdef quickunionimproved
      this->N[idx] = this->N[this->N[idx]];
      #endif
      idx = this->N[idx];
    }
    return idx;
  }

public:

  UF(int);

  void print() {
    int i = 0;
    while(i < this->size) std::cout<<*(this->N + i++)<<std::endl;
  }

  void union_UF(int, int);

  bool connected(int , int);

  #ifdef CATCH_CONFIG_MAIN
  friend class test_cases_helpers;
  #endif
};


#endif
