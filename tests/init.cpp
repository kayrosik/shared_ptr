#include "shared_ptr.hpp"
#include <catch.hpp>
#include <iostream>
using namespace std;
 
SCENARIO("count", "[count]"){
  stack<int> s;
  s.push(1);
  REQUIRE(s.count()==1);
}

