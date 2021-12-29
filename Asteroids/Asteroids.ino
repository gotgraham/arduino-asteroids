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

#include <stdlib.h>

#include "DrawingBuffer.hpp"
#include "Laser.h"

Laser laser(5);
DrawingBuffer drawing_buffer(&laser, &Serial);
Asteroids game(&drawing_buffer);

unsigned long lastMillis = 0;

// Interrupt is called once a millisecond,
SIGNAL(TIMER0_COMPA_vect)
{
  unsigned long currentMillis = millis();

  if (currentMillis - lastMillis > 16) {
    drawing_buffer.drawObjects();
    lastMillis = currentMillis;
  }
}

void setup()  {
  Serial.begin(9600);
  // Timer0 is already used for millis() - we'll just interrupt somewhere
  // in the middle and call the "Compare A" function below
  OCR0A = 0xAF;
  TIMSK0 |= _BV(OCIE0A);

  randomSeed(analogRead(0));

  Serial.begin(9600);

  laser.init();

  // tv.set_vbi_hook(&soundISR);
  game.initGame(false);
}

void loop() {
  game.tick();
 // drawing_buffer.drawObjects();
}
