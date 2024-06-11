#include <gtest/gtest.h>

#include <liblearning-gtest/hello/hello.hpp>
#include <liblearning-gtest/world/world.hpp>

TEST(HelloWorldTest, BasicAssertions) {
    Hello hello;
    World world;
    EXPECT_EQ(hello.getEverything(), world.getEverything());
}

TEST(HelloWorldTest, SecondTestCase) {
    EXPECT_STRNE("hello", "world");
}
