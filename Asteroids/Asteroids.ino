/*
  Asteroids
  Copyright (C) 2011 nootropic design, LLC
  All ights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.
*/
#ifndef ASTEROIDS_HPP
#include "Asteroids.hpp"
#endif

#include "Laser.h"

Laser laser(5);
Asteroids game(&laser);

void setup()  {
  randomSeed(analogRead(0));

  laser.init();
  laser.setScale(32);

  // tv.set_vbi_hook(&soundISR);
  game.initGame(false);
}

void loop() {
  game.tick();
}
