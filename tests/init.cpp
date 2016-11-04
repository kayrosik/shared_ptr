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
SCENARIO("SP: get", "[get]") {
	size_t * ptr = new size_t[10];
	shared_ptr<size_t> sp(ptr);

	REQUIRE(ptr == sp.get());
}
SCENARIO("SP: use_count", "[use_count]") {
	size_t * ptr = new size_t[10];
	shared_ptr<size_t> f_sp(ptr);

	REQUIRE(f_sp.count() == 1);

	shared_ptr<size_t> s_sp(f_sp);

	REQUIRE(f_sp.count() == 2);
	REQUIRE(s_sp.count() == 2);

	shared_ptr<size_t> t_sp(s_sp);

	REQUIRE(f_sp.count() == 3);
	REQUIRE(s_sp.count() == 3);
	REQUIRE(t_sp.count() == 3);
}
