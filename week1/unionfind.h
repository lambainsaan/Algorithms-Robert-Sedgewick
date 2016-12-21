#ifndef __UNIONFIND_H_INCLUDED__
#define __UNIONFIND_H_INCLUDED__


class UF
{

  int *N;
  int size;
#ifdef QUICKUNIONIMP
  int *sz;
#endif

  int root (int idx) {
    while(idx != this->N[idx]) {
      #ifdef QUICKUNIONIMP
      this->N[idx] = this->N[this->N[idx]];
      #endif
      idx = this->N[idx];
    }
    return idx;
  }

public:


  UF(int size){
    int i = 0;
    this->N = new int[size];
    #ifdef QUICKUNIONIMP
    this->sz = new int[size];
    #endif
    this->size = size;
    while(i < size && (this->sz[i] = 1)) this->N[i] = i++;
  };

  void print() {
    int i = 0;
    while(i < this->size) std::cout<<*(this->N + i++)<<std::endl;
  }

  void union_UF(int, int);

  bool connected(int p, int q){
    return this->root(p) == this->root(q);
  }

  #ifdef CATCH_CONFIG_MAIN
  friend class test_cases_helpers;
  #endif
};


#endif
