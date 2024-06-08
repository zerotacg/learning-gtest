#include <gtest/gtest.h>

#include <learning-gtest/world/world.hpp>

TEST(WorldTest, BasicAssertions) {
    EXPECT_STRNE("hello", "world");
    EXPECT_EQ(7 * 6, 42);

    World instance;
    EXPECT_EQ(instance.getEverything(), 42);
}
