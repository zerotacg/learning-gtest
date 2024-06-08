#include <gtest/gtest.h>

#include <learning-gtest/hello/hello.hpp>
#include <learning-gtest/world/world.hpp>

TEST(HelloWorldTest, BasicAssertions) {
    Hello hello;
    World world;
    EXPECT_EQ(hello.getEverything(), world.getEverything());
}
