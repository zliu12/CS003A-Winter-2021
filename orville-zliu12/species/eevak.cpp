/**
 * Eevak Implementation
 *
 * Copyright (c) [2021], Zhao Liu
 */

#include "species.h"

// Member function isRunning(), return the true or false
bool Eevak::isRunning() const {
  return _isRunning;
}

// Memember function run(), set the _isRunning value of the object to true
bool Eevak::run() {
  return _isRunning = true;
}

// Memember function stop(), set the _isRunning value of the object back to 
// false
bool Eevak::stop() {
  return _isRunning = false;
}
