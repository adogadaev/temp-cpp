#include <gtest/gtest.h>

struct OthelloTests : public testing::Test {
    virtual void SetUp() override {

    }

    virtual void TearDown() override {

    }
};

TEST_F(OthelloTests, Demo) {
    ASSERT_TRUE(true);
}