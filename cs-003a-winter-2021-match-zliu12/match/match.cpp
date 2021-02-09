/**
 * Match Implementation.
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#include <map>
#include <set>
#include <tuple>
#include <cstdint>
#include <cassert>
#include <algorithm>
#include "match/match.h"
#include "data/data.h"

typedef std::tuple<uint32_t, uint32_t, double> score_t;

#define S(x) (std::get<0>(m.x) == std::get<0>(f.x) ? \
  std::get<1>(m.x) + std::get<1>(f.x) : 0)

double score(Profile m, Profile f) {
  return S(country) + S(diet) + S(drinking) + S(language) + S(religion) +
         S(smoking);
}

std::map<uint32_t, uint32_t> Match::pairs(std::vector<Profile> &profiles) {
  std::vector<uint32_t> males, females; 
  std::vector<score_t> scores;
  std::set<uint32_t> picked;
  std::map<uint32_t, uint32_t> pairs;

  // Split candidates into two vectors based on the gender
  for (int i = 0; i < profiles.size(); i++) {
    (profiles[i].gender == MALE ? males : females).push_back(i);
  }
  assert(males.size() == females.size());

  // Pair each male with female candidate and calculate the pair score
  for (uint32_t m : males) {
    for (uint32_t f : females) {
      scores.push_back(score_t(m, f, score(profiles[m], profiles[f])));
    }
  }

  // Sort score in descending order
  std::sort(scores.begin(), scores.end(), [](score_t a, score_t b) {
    return std::get<2>(a) > std::get<2>(b);
  });

  // Pick pairs from scores, starting at the top and avoiding duplicates
  for (score_t s : scores) {
    uint32_t m = std::get<0>(s);
    uint32_t f = std::get<1>(s);
    if (picked.count(m) == 0 && picked.count(f) == 0) {
      pairs[m] = f;
      picked.insert(m);
      picked.insert(f);
    }
    if(picked.size() == profiles.size()) {
      break;
    }
  }

  return pairs;
}
