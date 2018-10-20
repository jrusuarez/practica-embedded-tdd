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

TEST(ExampleTestGroup, XorCase1) {
  CHECK_FALSE(xorOp(false, false));
}

TEST(ExampleTestGroup, XorCase2) {
  CHECK_TRUE(xorOp(true, false));
}

TEST(ExampleTestGroup, XorCase3) {
  CHECK_TRUE(xorOp(false, true));
}

TEST(ExampleTestGroup, XorCase4) {
  CHECK_FALSE(xorOp(true, true));
}
