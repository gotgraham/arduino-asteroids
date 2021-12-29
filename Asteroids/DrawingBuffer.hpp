#ifndef DRAWINGBUFFER_HPP
#define DRAWINGBUFFER_HPP

#include <stdint.h>

#include "Laser.h"
#include <HardwareSerial.h>


typedef struct Object {
  uint8_t id;
  long x;
  long y;
  const uint16_t* data;
  uint16_t size;
  float scale;
  bool visible;
} Object;

#define OBJECT_COUNT 25

class DrawingBuffer {

  public:
    DrawingBuffer(Laser * laser, HardwareSerial * serial);

    // Add a new object to our list
    void addObject(uint8_t id, long x, long y, const uint16_t* data, uint16_t size, float scale);
    // Hide all objects in the list
    void removeAll();
    // Remove an existing object from our list
    void removeObject(uint8_t id);
    // Draw all objects in the list
    int drawObjects();

  private:

    Object object_list[OBJECT_COUNT];
    Laser * laser;
    HardwareSerial * serial;
};

#endif