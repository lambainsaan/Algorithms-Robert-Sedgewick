#include <iostream>

#include "unionfind.h"
#include "union-find-quick-find.cpp"


int main()
{
  UF a(10);
  a.union_UF(5,6);
  a.union_UF(3,4);
  a.union_UF(3,2);
  a.union_UF(4,8);
  a.print();
  std::cout << a.connected(1, 2) << std::endl;
  std::cout << a.connected(9, 1) << std::endl;
  std::cout << a.connected(8, 4) << std::endl;

  return 0;
}
