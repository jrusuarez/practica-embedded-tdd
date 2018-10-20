#include "CppUTest/TestHarness.h"
#include "Example/Example.h"

TEST_GROUP(ExampleTestGroup)
{
};

TEST(ExampleTestGroup, SumTwoNumbers)
{
    CHECK_EQUAL(2, sum(1, 1));
}

TEST(ExampleTestGroup, ConcatenateTwoStrings) {
  char s1[100] = "Hello ";
  char s2[] = "World";

  STRCMP_EQUAL("Hello World", concat(s1, s2));
}

TEST(ExampleTestGroup, BooleanNotOperator) {
  bool a = true;

  CHECK_TRUE(a);
  CHECK_FALSE(notOp(a));
}
