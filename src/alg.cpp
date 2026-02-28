// Copyright 2025 UNN-CS

#include "alg.h"

#include <cstdint>
#include <vector>

bool checkPrime(uint64_t value) {
  if (value < 2) {
    return false;
  }

  if (value == 2) {
    return true;
  }

  if (value % 2 == 0) {
    return false;
  }

  for (uint64_t i = 3; i * i <= value; i += 2) {
    if (value % i == 0) {
      return false;
    }
  }

  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 0) {
    return 0;
  }

  uint64_t count = 0;
  uint64_t candidate = 1;

  while (count < n) {
    ++candidate;
    if (checkPrime(candidate)) {
      ++count;
    }
  }

  return candidate;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t candidate = value + 1;

  while (!checkPrime(candidate)) {
    ++candidate;
  }

  return candidate;
}

uint64_t sumPrime(uint64_t hbound) {
  if (hbound <= 2) {
    return 0;
  }

  std::vector<bool> sieve(static_cast<size_t>(hbound), true);
  sieve[0] = false;
  sieve[1] = false;

  for (uint64_t i = 2; i * i < hbound; ++i) {
    if (sieve[static_cast<size_t>(i)]) {
      for (uint64_t j = i * i; j < hbound; j += i) {
        sieve[static_cast<size_t>(j)] = false;
      }
    }
  }

  uint64_t sum = 0;
  for (uint64_t i = 2; i < hbound; ++i) {
    if (sieve[static_cast<size_t>(i)]) {
      sum += i;
    }
  }

  return sum;
}
