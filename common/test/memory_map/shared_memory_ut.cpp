#include <gtest/gtest.h>

class SharedMemoryTest : public ::testing::Test
{
  protected:
    void SetUp() override
    {
    }

    void TearDown() override
    {
    }
};

TEST_F(SharedMemoryTest, ExampleTest)
{
    ASSERT_TRUE(true);
}