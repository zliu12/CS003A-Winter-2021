/**
 * Generate test data.
 *
 * Copyright (c) 2019, Sekhar Ravinutala.
 */

#ifndef DATA_DATA_H_
#define DATA_DATA_H_

#include <cstdint>
#include <vector>
#include <tuple>

enum Country {
  CANADA, MEXICO, USA
};

enum Diet {
  NONVEGETARIAN, EGGETARIAN, VEGAN, VEGETARIAN
};

enum Gender {
  FEMALE, MALE
};

enum Language {
  ENGLISH, FRENCH, SPANISH
};

enum Religion {
  BUDDHIST, CHRISTIAN, JEWISH
};

struct Profile {
  uint32_t id;
  Gender gender;
  std::tuple<Country, double> country;
  std::tuple<Diet, double> diet;
  std::tuple<bool, double> drinking;
  std::tuple<Language, double> language;
  std::tuple<Religion, double> religion;
  std::tuple<bool, double> smoking;
};

// struct type vector, vector size is equal to count,
// each element contains 8 feedbacks of a candidate
std::vector<Profile> profiles(uint16_t count);

#endif  // DATA_DATA_H_
