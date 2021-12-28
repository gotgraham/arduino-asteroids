# Arduino Laser Asteroids

The asteroids game has been re-written - converting it from a raster based implementation to vector based in order to be compatible with
the laser galvo projector.

Based on three projects:

- Arduino Laser Projector
  https://github.com/DeltaFlo/LaserProjector

- Asteroids for Hackvision, the tiny, hackable, Arduino-based video game system.
  https://github.com/nootropicdesign/arduino-asteroids

- Controllers Library from Hackvision
  https://github.com/nootropicdesign/hackvision-controllers

Projector setup / hardware / pinouts is described here:
https://www.instructables.com/Arduino-Laser-Show-With-Real-Galvos/

Uses a Sega Genesis controller for input:

Controller Pin -> Arduino Input

LEFT     3  ->     D3
RIGHT    4  ->     D2
UP       1  ->     D4
DOWN     2  ->     D8
C (fire) 6  ->     D9
+5       5
GND      7

Licensed under LGPL v2.1 as Asteroids for Hackvision carries that license.
