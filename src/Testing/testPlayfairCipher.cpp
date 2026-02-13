//! Unit Tests for MPAGSCipher CaesarCipher Class
#include "gtest/gtest.h"

#include "PlayfairCipher.hpp"

TEST(PlayfairCipher, Encrypt)
{
    PlayfairCipher cc{"hello"};
    EXPECT_EQ(cc.applyCipher("HELLOWORLD", CipherMode::Encrypt), "RIJVSUYVJN");
}

TEST(PlayfairCipher, Decrypt)
{
    PlayfairCipher cc{"hello"};
    EXPECT_EQ(cc.applyCipher("RIJVSUYVJN", CipherMode::Decrypt), "HELLOWORLD");
}
