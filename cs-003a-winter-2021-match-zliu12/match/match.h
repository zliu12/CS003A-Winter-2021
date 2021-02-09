/**
 * Match declarations.
 *
 * Copyright (c) 2019, Sekhar Ravinutala.
 */

#ifndef MATCH_MATCH_H_
#define MATCH_MATCH_H_

#include <cstdint>
#include <map>
#include <vector>
#include "data/data.h"

class Match {
 public:
  static std::map<uint32_t, uint32_t> pairs(std::vector<Profile> &);
};

#endif  // MATCH_MATCH_H_
