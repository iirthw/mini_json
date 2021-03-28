#include "gtest/gtest.h"

#include "json.h"

/*
Example Json schema:
{
  "type": "object",
  "properties": {
    "first_name": { "type": "string" },
    "last_name": { "type": "string" },
    "birthday": { "type": "string", "format": "date" },
    "address": {
      "type": "object",
      "properties": {
        "street_address": { "type": "string" },
        "city": { "type": "string" },
        "state": { "type": "string" },
        "country": { "type" : "string" }
      }
    }
  }
}
*/

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