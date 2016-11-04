#include "shared_ptr.hpp"
#include <catch.hpp>
#include <iostream>

 
SCENARIO("count", "[count]"){
 shared_ptr<size_t> s;
  REQUIRE(s.count()==0);
 REQUIRE(s.get()==nullptr);
}

SCENARIO("count1", "[count1]"){
 shared_ptr<size_t> s(new size_t[10]);
 REQUIRE(s.get()!=nullptr);
}

