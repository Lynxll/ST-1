// Copyright 2025 UNN-CS
#include <cstdint>
#include <gtest/gtest.h>

#include "alg.h"

TEST(st1_checkPrime, HandlesSmallNumbers) {
  EXPECT_FALSE(checkPrime(0));
  EXPECT_FALSE(checkPrime(1));
  EXPECT_TRUE(checkPrime(2));
  EXPECT_TRUE(checkPrime(3));
}

TEST(st1_checkPrime, HandlesEvenAndComposite) {
  EXPECT_FALSE(checkPrime(4));
  EXPECT_FALSE(checkPrime(9));
  EXPECT_FALSE(checkPrime(21));
}

TEST(st1_checkPrime, HandlesLargePrimeAndComposite) {
  EXPECT_TRUE(checkPrime(97));
  EXPECT_FALSE(checkPrime(121)); 
}

TEST(st1_nPrime, FirstPrimeIs2) {
  EXPECT_EQ(2u, nPrime(1));
}

TEST(st1_nPrime, SeveralFirstPrimes) {
  EXPECT_EQ(3u, nPrime(2));
  EXPECT_EQ(5u, nPrime(3));
  EXPECT_EQ(7u, nPrime(4));
}

TEST(st1_nPrime, TenthPrimeIs29) {
  EXPECT_EQ(29u, nPrime(10));
}

TEST(st1_nextPrime, NextAfterSmallNumbers) {
  EXPECT_EQ(2u, nextPrime(0));
  EXPECT_EQ(2u, nextPrime(1));
  EXPECT_EQ(3u, nextPrime(2));
}

TEST(st1_nextPrime, NextAfterPrimeSkipsItself) {
  EXPECT_EQ(5u, nextPrime(3)); 
  EXPECT_EQ(13u, nextPrime(11));
}

TEST(st1_nextPrime, NextAfterComposite) {
  EXPECT_EQ(5u, nextPrime(4));
  EXPECT_EQ(19u, nextPrime(18));
}

TEST(st1_sumPrime, HandlesBoundsCorrectly) {
  EXPECT_EQ(0u, sumPrime(0));
  EXPECT_EQ(0u, sumPrime(2)); 
  EXPECT_EQ(2u, sumPrime(3));  
}

TEST(st1_sumPrime, SmallExamples) {
  EXPECT_EQ(17u, sumPrime(10));
  EXPECT_EQ(77u, sumPrime(20));
}

TEST(st1_sumPrime, TwoMillion) {
  uint64_t res = sumPrime(2000000);
  uint64_t expected = 142913828922ULL;
  EXPECT_EQ(expected, res);
}