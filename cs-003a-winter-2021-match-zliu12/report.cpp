/**
 * Generate report for an integration test.
 *
 * Copyright (c) 2019, Sekhar Ravinutala.
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#include "data/data.h"
#include "match/match.h"

#define GENDER(g) (g ? "Male" : "Female")

int main() {
  std::vector<Profile> up = profiles(100);

  // Sample print for illustration, replace with your code
  // for (auto p : up) {
  //   printf("%-8d %s\n", p.id, GENDER(p.gender));
  // }

  std::map<uint32_t, uint32_t> report = Match::pairs(up);
  std::map<uint32_t, uint32_t>::iterator itr;
  for (itr = report.begin(); itr != report.end(); ++itr) {
    std::cout << itr->first << " " << itr->second << "\n";
  }
}
