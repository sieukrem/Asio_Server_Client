#include "../Server/include/jsonparser.h"

#include <gtest/gtest.h>

TEST(JsonParser, TranslateToJson) {
//  std::string key = "hello";
//  auto attributeKey = AttributeKeys(key);
//  ASSERT_EQ(attributeKey.GetKeyAsString(), key); // NOLINT
    Serf::jsonparser testee;

    auto jsonAsText = testee.TranslateTextJson("a", "b");

    EXPECT_EQ("ab",jsonAsText);
}

