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

using namespace minijson;

class JsonTest : public ::testing::Test {
protected:
    void SetUp() override {
        
    }

    // void TearDown() override {}
};

TEST(JsonTest, TestConstruction)
{
    Json json("{ number: 1 }");
    auto jsonObject = json.rootElement();
    ASSERT_TRUE(jsonObject != nullptr);
}

TEST(JsonTest, TestGetInt)
{
    Json json("{ number: 2 }");
    auto jsonObject = json.rootElement();
    ASSERT_EQ(2, jsonObject->getInt("number"));
}

TEST(JsonTest, TestGetInt1)
{
    Json json("{ number1: 1, number2: 2 }");
    auto jsonObject = json.rootElement();
    ASSERT_EQ(2, jsonObject->getInt("number2"));
}

TEST(JsonTest, TestGetFloat)
{
    Json json("{ floatNumber : 1.0f }");
    auto jsonObject = json.rootElement();
    ASSERT_EQ(1.0f, jsonObject->getFloat("floatNumber"));
}

TEST(JsonTest, TestGetFloat2)
{
    Json json("{ number: 1, floatNumber : 1.0f }");
    auto jsonObject = json.rootElement();
    ASSERT_EQ(1.0f, jsonObject->getFloat("floatNumber"));
}

TEST(JsonTest, TestString)
{
    Json json("{ number: 1, floatNumber: 2.0f, foo: \"bar\" }");
    auto jsonObject = json.rootElement();
    ASSERT_TRUE(jsonObject->getString("foo") == "bar");
}

TEST(JsonTest, TestObject)
{
    Json json("{ number: 1, person: { firstName: \"John\", lastName: \"Appleseed\" } }");
    auto jsonObject = json.rootElement();
    ASSERT_TRUE(jsonObject->getObject("person") != nullptr);
}

TEST(JsonTest, TestObject2)
{
    Json json("{ number: 1, person: { firstName: \"John\", lastName: \"Appleseed\" } }");
    auto jsonObject = json.rootElement();
    auto personObject = jsonObject->getObject("person");

    ASSERT_TRUE(personObject->getString("firstName") == "John");
    ASSERT_TRUE(personObject->getString("lastName") == "Appleseed");
}