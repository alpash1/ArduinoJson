// Copyright Benoit Blanchon 2014-2016
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson
// If you like this project, please add a star!

#include <ArduinoJson.h>
#include <gtest/gtest.h>

TEST(Issue278, Test) {
  char json[] =
      "[\"E0\",\"E1\",\"E2\",\"E3\","
      "[\"E3.0\",\"E3.1\","
      "[\"E3.1.0\",\"E3.1.1\"]]]";
  DynamicJsonBuffer jsonBuffer;
  JsonArray& root = jsonBuffer.parseArray(json);
  ASSERT_STREQ("E0", root[0]);
  ASSERT_STREQ("E1", root[1]);
  ASSERT_STREQ("E2", root[2]);
  ASSERT_STREQ("E3", root[3]);
  ASSERT_STREQ("E3.0", root[4][0]);
  ASSERT_STREQ("E3.1", root[4][1]);
  ASSERT_STREQ("E3.1.0", root[4][2][0]);
  ASSERT_STREQ("E3.1.1", root[4][2][1]);
}
