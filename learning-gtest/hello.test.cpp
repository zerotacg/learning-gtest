#include <gtest/gtest.h>

#include <learning-gtest/hello.hpp>

TEST(HelloTest, BasicAssertions) {
    EXPECT_STRNE("hello", "world");
    EXPECT_EQ(7 * 6, 42);

    Hello instance;
    EXPECT_EQ(instance.getEverything(), 42);
}
