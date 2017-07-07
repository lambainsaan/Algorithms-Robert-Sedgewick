#include <iostream>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"


#include "unionfind.h"

#ifdef quickfind
#include "quickfind.cpp"
#endif

#ifdef quickunion
#include "quickunion.cpp"
#endif

#ifdef quickunionimproved
#include "quickunionimproved.cpp"

#endif

#ifdef quickunionheight
#include "quickunionheight.cpp"
#endif

class test_cases_helpers
{ /*
   * This is a helper class which is a friend of UF class,
   * this class is only for testing purposes.
   * And the member functions of this class access the private members of UF class.
   *
   */

  public:

  void set_N(UF *obj, int *a) {
    /*
     * This member function that alters the contents of original array N,
     *
     * PARAMS
     * obj - The object whose array has to be changed,
     * a - the new address where the array should point
     *
     */

    obj->N = a;
  }

  int test_root(UF *obj, int idx){
    /*
     * This member function returns the value returned by the private member function root(int)
     * this is mereley another layer to interact with the private member function.
     *
     * PARAMS
     * obj - The object whose array we have to scan
     * idx - The index of the element in the array whose root we have to find out
     *
     */

    return obj->root(idx);
  }

  int* get_N(UF *obj){
    /**
     * This method returns the
     **/
    return obj->N;
  }
};




TEST_CASE( "give proper result when we do union" ) {
  /*
   * This is the test suite to test the functionality of union method in class UF,
   * for this to work connected and union_UF should work fine.
   *
   */


  UF test_union(10);
  test_union.union_UF(5,6);
  test_union.union_UF(3,4);
  test_union.union_UF(3,2);
  test_union.union_UF(5,2);
  test_union.union_UF(4,8);

  REQUIRE( test_union.connected(4,8) == true);
  REQUIRE( test_union.connected(1,3) == false);
  REQUIRE( test_union.connected(3,8) == true);
  REQUIRE( test_union.connected(5,6) == true);
  REQUIRE( test_union.connected(5,2) == true);
  REQUIRE( test_union.connected(6,4) == true);
}

#ifndef quickfind

TEST_CASE("test functionality of root method") {
  /*
   *
   * This is the test suite to test the functionality of root method in class UF,
   * while developing code for it I came across a problem of testing private methods in the class,
   * I did not know much about how to get around it without making the member function and data members public,
   * which is the worst way possible to get around the thing.
   *
   * So I used the information on http://stackoverflow.com/questions/14186245/unit-testing-c-how-to-test-private-members
   * and made a helper class to get around it
   *
   */

  UF test_root(10);
  int N []= {3, 2, 4, 4, 4, 6, 8, 9, 0, 9};
  test_cases_helpers test_root_helper;
  test_root_helper.set_N(&test_root, N);
  REQUIRE( test_root_helper.test_root(&test_root, 4) == 4);
  REQUIRE( test_root_helper.test_root(&test_root, 5) == 4);
  REQUIRE( test_root_helper.test_root(&test_root, 1) == 4);
  REQUIRE( test_root_helper.test_root(&test_root, 0) == 4);
  REQUIRE( test_root_helper.test_root(&test_root, 7) == 9);
  REQUIRE( test_root_helper.test_root(&test_root, 9) == 9);
}





TEST_CASE("test functionality of connected method") {
  UF test_connected(10);
  int N []= {3, 2, 4, 4, 4, 6, 8, 9, 0, 9};
  test_cases_helpers dummy;
  dummy.set_N(&test_connected, N);
  REQUIRE(test_connected.connected(5, 3) == true);
  REQUIRE(test_connected.connected(1, 2) == true);
  REQUIRE(test_connected.connected(4, 5) == true);
  REQUIRE(test_connected.connected(7, 4) == false);
  REQUIRE(test_connected.connected(9, 0) == false);
  REQUIRE(test_connected.connected(9, 7) == true);

}

#endif

#ifdef quickunionimproved

TEST_CASE("Test functionality of path compression, in root method."){
  UF test_pathcompression(11);
  test_cases_helpers dummy;
  int N [] = {0, 0, 0, 1, 1, 2, 4, 4, 6, 6, 6};
  dummy.set_N(&test_pathcompression, N);
  dummy.test_root(&test_pathcompression, 9);
  int *array = dummy.get_N(&test_pathcompression);
  int test_agianst [] =  {0, 0, 0, 1, 0, 2, 4, 4, 6, 4, 6};
  for (int idx = 0; idx < 11; idx++){
    REQUIRE(*(array + idx) == test_agianst[idx]);
  }
}

#endif
