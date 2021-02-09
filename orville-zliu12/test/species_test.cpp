/**
 * Unit tests for Species.
 *
 * Copyright (c) 2019, Sekhar Ravinutala.
 */

#include <gtest/gtest.h>
#include <type_traits>
#include "species/species.h"

TEST(species, eevak) {
  // Default.
  Eevak eevak;
  EXPECT_FALSE(eevak.isRunning());

  // Must not be humaoid.
  EXPECT_FALSE((std::is_base_of<Humanoid, Eevak>::value));

  // Check running.
  eevak.run();
  EXPECT_TRUE(eevak.isRunning());

  // Stop.
  eevak.stop();
  EXPECT_FALSE(eevak.isRunning());
}

TEST(species, gelatin) {
  // A 540 lb Gelatin
  Gelatin gelatin(540);
  EXPECT_EQ(gelatin.weight(), 540);
  EXPECT_STREQ(gelatin.shape(), "sphere");

  // Must not be humaoid
  EXPECT_FALSE((std::is_base_of<Humanoid, Gelatin>::value));

  // Morph to "flat" shape
  gelatin.morph("flat");
  EXPECT_STREQ(gelatin.shape(), "flat");

  // Go back to default
  gelatin.morph();
  EXPECT_STREQ(gelatin.shape(), "sphere");

  // Ignore all other morph attempts
  gelatin.morph("crazy");
  EXPECT_STREQ(gelatin.shape(), "sphere");

  // Split into two
  Gelatin newGelatin = gelatin.split();
  EXPECT_NE(newGelatin, gelatin);
  EXPECT_EQ(gelatin.weight(), 270);
  EXPECT_EQ(newGelatin.weight(), 270);
  EXPECT_STREQ(newGelatin.shape(), gelatin.shape());
}

TEST(species, human) {
  // Female, 5.9 feet tall, 180 lb
  Human human(false, 5.9, 180);
  EXPECT_FALSE(human.isMale());
  EXPECT_EQ(human.height(), 5.9);
  EXPECT_EQ(human.weight(), 180);

  // Must be humaoid
  EXPECT_TRUE((std::is_base_of<Humanoid, Human>::value));
}

TEST(species, kaylon) {
  // 5.4 feet tall, 130 lb
  Kaylon kaylon(5.4, 130);
  EXPECT_EQ(kaylon.height(), 5.4);
  EXPECT_EQ(kaylon.weight(), 130);
  EXPECT_FALSE(kaylon.isFiring());

  // Must be humaoid
  EXPECT_TRUE((std::is_base_of<Humanoid, Kaylon>::value));

  // Check firing
  kaylon.startFiring();
  EXPECT_TRUE(kaylon.isFiring());
  kaylon.stopFiring();
  EXPECT_FALSE(kaylon.isFiring());
}

TEST(species, moclan) {
  // 6.9 feet tall, 320 lb
  Moclan moclan(6.9, 320);
  EXPECT_EQ(moclan.height(), 6.9);
  EXPECT_EQ(moclan.weight(), 320);
  EXPECT_FALSE(moclan.isEgg());

  // Must be humaoid
  EXPECT_TRUE((std::is_base_of<Humanoid, Moclan>::value));

  // Lay egg
  Moclan moclanEgg = moclan.layEgg();
  EXPECT_FALSE(moclan.isEgg());
  EXPECT_TRUE(moclanEgg.isEgg());

  // Hatch
  moclanEgg.hatch();
  EXPECT_FALSE(moclanEgg.isEgg());
}
