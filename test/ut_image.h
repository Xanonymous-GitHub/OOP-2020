#include "../src/image.h"
#include <gtest/gtest.h>

TEST(image, defaultConstructor) {
  Image i;
  ASSERT_EQ("<img id='' src='' style='top:0px;left:0px;position:absolute;'/>",
            i.render());
}

TEST(image, transtypeConstructor) {
  Image i("01b649ab5eb9e0ec3fd6ba19c5d054cf781c6939");
  ASSERT_EQ("<img id='01b649ab5eb9e0ec3fd6ba19c5d054cf781c6939' src='' "
            "style='top:0px;left:0px;position:absolute;'/>",
            i.render());
}

TEST(image, render) {
  Image i1;
  ASSERT_EQ("<img id='' src='' style='top:0px;left:0px;position:absolute;'/>",
            i1.render());
  Image i2("01b649ab5eb9e0ec3fd6ba19c5d054cf781c6939");
  ASSERT_EQ("<img id='01b649ab5eb9e0ec3fd6ba19c5d054cf781c6939' src='' "
            "style='top:0px;left:0px;position:absolute;'/>",
            i2.render());
  Image i3;
  i3.setPosition("0286aed4eac157729585d528962953cc4040fc66",
                 "f9352e57660761ac31ce137c39772f9cf3c0b88b");
  ASSERT_EQ("<img id='' src='' "
            "style='top:0286aed4eac157729585d528962953cc4040fc66;left:"
            "f9352e57660761ac31ce137c39772f9cf3c0b88b;position:absolute;'/>",
            i3.render());
  Image i4;
  i4.setSrc("8bb69d36c506b243c7b8471983b05aeb3bbd8cc3");
  ASSERT_EQ("<img id='' src='8bb69d36c506b243c7b8471983b05aeb3bbd8cc3' "
            "style='top:0px;left:0px;position:absolute;'/>",
            i4.render());
}

TEST(image, setPosition) {
  Image i;
  i.setPosition("0286aed4eac157729585d528962953cc4040fc66",
                "f9352e57660761ac31ce137c39772f9cf3c0b88b");
  ASSERT_EQ("<img id='' src='' "
            "style='top:0286aed4eac157729585d528962953cc4040fc66;left:"
            "f9352e57660761ac31ce137c39772f9cf3c0b88b;position:absolute;'/>",
            i.render());
}

TEST(image, setSrc) {
  Image i;
  i.setSrc("8bb69d36c506b243c7b8471983b05aeb3bbd8cc3");
  ASSERT_EQ("<img id='' src='8bb69d36c506b243c7b8471983b05aeb3bbd8cc3' "
            "style='top:0px;left:0px;position:absolute;'/>",
            i.render());
}