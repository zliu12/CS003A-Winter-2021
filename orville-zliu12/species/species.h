/**
 * Species Classes
 *
 * Copyright (c) [2021], Zhao Liu
 */

#include <iostream>
#include <string>
#ifndef SPECIES_H_
#define SPECIES_H_

// Base class
class Humanoid {
 public:
  double weight();
  double height();
  double speciesWeight;
  double speciesHeight;
};

// Class Eevak 
class Eevak {
 public:
  bool isRunning() const;
  bool run();
  bool stop();

 private:
  bool _isRunning = false;
};

// Class Gelatin
class Gelatin {
 public:
  friend bool operator!=(const Gelatin &gelNew, const Gelatin &gelOriginal);
  Gelatin(double gelWeight);
  double weight();
  const char *shape();
  void morph(const char *gelMorph);
  void morph();
  Gelatin split();

private:
  double _gelWeight;
  const char *_gelShape;
};

// Class human, a derived class from class Humanoid
class Human : public Humanoid {
 public:
  Human(bool male, double humanHeight, double humanWeight);
  bool isMale();

 private:
  bool _isMale;
};

// Class Kaylon, a derived class from class Humanoid
class Kaylon : public Humanoid {
 public:
  Kaylon(double kaylonHeight, double kaylonWeight);
  bool isFiring() const;
  bool startFiring();
  bool stopFiring();

 private:
  bool _isFiring = false;
};

// Class Moclan, a drived class from class Humanoid
class Moclan : public Humanoid {
 public:
  Moclan(double mocHeight, double mocWeight);
  bool isEgg();
  Moclan layEgg();
  void hatch();

 private:
  bool _isEgg;
};


#endif // SPECIES_H_