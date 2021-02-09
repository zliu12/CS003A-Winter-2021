/**
 * Generate test data.
 *
 * Copyright (c) 2019, Sekhar Ravinutala.
 */

#include <cstdint>
#include <cstdlib>
#include "data/data.h"

#define WEIGHT (static_cast<double>(std::rand()) / RAND_MAX)

std::vector<Profile> profiles(uint16_t count) {
  std::vector<Profile> profiles;

  Gender gender = FEMALE;
  for (uint16_t i = 0; i < count; ++i) {
    profiles.push_back({
      std::rand() % 900000U + 100000,
      gender = gender == MALE ? FEMALE : MALE,
      {static_cast<Country>(std::rand() % 3), WEIGHT},
      {static_cast<Diet>(std::rand() % 4), WEIGHT},
      {std::rand() % 2 > 0, WEIGHT},
      {static_cast<Language>(std::rand() % 3), WEIGHT},
      {static_cast<Religion>(std::rand() % 3), WEIGHT},
      {std::rand() % 2 > 0, WEIGHT}
    });
  }

  return profiles;
}
