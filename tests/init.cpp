#include "shared_ptr.hpp"
#include <catch.hpp>
#include <iostream>

 
SCENARIO("count", "[count]"){
 shared_ptr<size_t> s;
  REQUIRE(s.count()==1);
 REQUIRE(s.get()==nullptr);
}

