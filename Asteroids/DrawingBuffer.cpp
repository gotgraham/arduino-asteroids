#ifndef DRAWINGBUFFER_HPP
#include "DrawingBuffer.hpp"
#endif

#include "Drawing.h"

 DrawingBuffer::DrawingBuffer(Laser * laser, HardwareSerial * serial) : laser(laser), serial(serial) {
   memset(&object_list[0], sizeof(Object) * OBJECT_COUNT, 0);
 }

// Purpose: Add a new object to our list
void DrawingBuffer::addObject(uint8_t id, long x, long y, const uint16_t* data, uint16_t size, float scale) {
  // Find the first open slot and assign the object data to it
  for (int i = 0; i < OBJECT_COUNT; ++i) {
    Object & object = object_list[i];
    if (!object.visible) {
      object.id = id;
      object.x = x;
      object.y = y;
      object.data = data;
      object.size = size;
      object.scale = scale;
      object.visible = true;
      break; // We're done
    }
  }
}

// Purpose: Remove an existing object from our list
void DrawingBuffer::removeObject(uint8_t id) {
 //removeAll();
  bool found = false;
  for (int i = 0; i < OBJECT_COUNT && !found; ++i) {
    Object & object = object_list[i];

    if (object.id == id) {
      object.visible = false;
    }
  }
  if (!found) {
    serial->println("Not found!");
    serial->println(id);
  }
}

// Purpose: Hide all objects in the list
void DrawingBuffer::removeAll() {
  for (int i = 0; i < OBJECT_COUNT; ++i) {
    object_list[i].visible = false;
  }
}

// Purpose: Draw all objects in the list
int DrawingBuffer::drawObjects() {
  int count = 0;
  for (int i = 0; i < OBJECT_COUNT; ++i) {
    Object & object = object_list[i];

    if (object.visible) {
      count++;
      laser->setScale(object.scale);
      Drawing::drawObject(object.data, object.size, object.x, object.y);
    }
  }
  return count;
}