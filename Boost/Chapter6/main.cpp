// #define BOOST_DISABLE_ASSERTS

#define _MINIMAL_TEST_
//#undef _MINIMAL_TEST_
#include <boost/assert.hpp>
#include <boost/static_assert.hpp>
#ifndef _MINIMAL_TEST_
#include <boost/core/lightweight_test.hpp>
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#else
#include <boost/test/minimal.hpp>
#endif
#include <iostream>
#include <memory>
#include <exception>

/*
BOOST_AUTO_TEST_SUITE(my)

BOOST_AUTO_TEST_CASE(mm)
{

}

BOOST_AUTO_TEST_SUITE_END()
*/

double func(int x)
{
  BOOST_ASSERT_MSG(x != 0, "Divide bu Zero!");
  return 1.0/ static_cast<double>(x);
}

#ifdef _MINIMAL_TEST_
int test_main(int argc, char* argv[]) {
#else
int main(int argc, char* argv[]) {
#endif
#if 0
  if (argc < 2)
    return 0; 
  /*
  BOOST_ASSERT
  */
  BOOST_ASSERT(atoi(argv[1]) == atoi(argv[2]));
#endif

  /*
  BOOST_STATIC_ASSERT
  */
#if 0
  if (argc <= 1) return 0;
  BOOST_STATIC_ASSERT(4 == sizeof(int));
  std::cout << sizeof(atoi(argv[0])) << '\n';
  std::cout << func(atoi(argv[1]));
#endif
  
  /*
  BOOST_TEST()
  BOOST_TEST_NOT()
  BOOST_ERROR()
  BOOST_TEST_EQ()
  BOOST_TEST_NE()
  BOOST_TEST_CSTR_EQ()
  BOOST_TEST_CSTR_NQ()
  BOOST_TEST_THROWS()
  */
#if 0
  if (argc <= 1) return 0;
  std::shared_ptr<int> share_point_int = std::make_shared<int>(atoi(argv[1]));
  BOOST_TEST(10 == *share_point_int);
  BOOST_TEST_NOT(!share_point_int);
  BOOST_TEST_EQ(share_point_int.use_count(), 1);
  BOOST_TEST_NE(*share_point_int, 11);
  share_point_int.reset();
  BOOST_TEST_THROWS(*share_point_int, std::runtime_error);
  BOOST_ERROR("error accured!");
  boost::report_errors();
#endif

#ifdef _MINIMAL_TEST_
  if (argc <= 3) return 0;
  BOOST_CHECK( 1 < atoi(argv[1]));
  BOOST_REQUIRE(1 < atoi(argv[2]));
  if(1 < atoi(argv[3])) BOOST_FAIL("true");
  BOOST_ERROR("this is a error");
#endif

  return 0;
}