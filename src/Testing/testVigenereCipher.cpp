//! Unit Tests for MPAGSCipher VigenereCipher Class
#include "gtest/gtest.h"

#include "VigenereCipher.hpp"

TEST(VigenereCipher, Encrypt)
{
    VigenereCipher cc{"hello"};
    EXPECT_EQ(
        cc.applyCipher("ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ",
                       CipherMode::Encrypt),
        "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ");
}

TEST(VigenereCipher, Decrypt)
{
    VigenereCipher cc{"hello"};
    EXPECT_EQ(
        cc.applyCipher("ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ",
                       CipherMode::Decrypt),
        "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ");
}
