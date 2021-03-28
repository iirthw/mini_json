#include "gtest/gtest.h"

#include "json.h"

class JsonTest : public ::testing::Test {
protected:
    void SetUp() override {
        
    }

    // void TearDown() override {}
};

TEST(JsonTest, TestConstruction)
{
    mjson::Json json("{ number: 1 }");

    ASSERT_TRUE(true);
}