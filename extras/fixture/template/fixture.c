
#include "unity_fixture.h"

TEST_GROUP(group);

TEST_SETUP(group)
{
}

TEST_TEAR_DOWN(group)
{
}

TEST(group, test)
{
  /* do assertions here */
}

TEST_GROUP_RUNNER(group)
{
  RUN_TEST_CASE(group, test);
}
