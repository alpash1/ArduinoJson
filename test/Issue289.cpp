// Copyright Benoit Blanchon 2014-2016
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson
// If you like this project, please add a star!

#include <ArduinoJson.h>
#include <gtest/gtest.h>

TEST(Issue289, AddObjectToExistingArray) {
  // clang-format off
  char input[] = "{\"nodeCount\":1,\"nodeArray\":[{\"nodeAddress\":1,\"nodeType\":\"DHT\",\"txInterval\":5}]}";
  const char* expected = "{\"nodeCount\":2,\"nodeArray\":[{\"nodeAddress\":1,\"nodeType\":\"DHT\",\"txInterval\":5},{\"nodeAddress\":2,\"nodeType\":\"DHT\",\"txInterval\":5}]}";
  // clang-format on
  DynamicJsonBuffer jsonBuffer;

  JsonObject& root = jsonBuffer.parseObject(input);
  JsonObject& node = root["nodeArray"].asArray().createNestedObject();
  node["nodeAddress"] = 2;
  node["nodeType"] = "DHT";
  node["txInterval"] = 5;
  root["nodeCount"] = 2;

  char output[256];
  root.printTo(output, sizeof(output));

  ASSERT_STREQ(expected, output);
}
