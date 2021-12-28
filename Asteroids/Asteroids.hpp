#ifndef ASTEROIDS_HPP
#define ASTEROIDS_HPP

#include <stdint.h>
#include <avr/pgmspace.h>
#include <EEPROM.h>
#include "Laser.h"

#include "button_controller.h"
#include "title_bitmap.h"
#include "hackvision_logo_bitmap.h"
#include "asteroid_bitmaps.h"
#include "asteroid_vertices.h"
#include "fire_vertices.h"
#include "ship_vertices.h"
#include "saucer_vertices.h"
#include "explosion_bitmaps.h"
#include "ship_explosion_objects.h"
#include "explosion_frequencies.h"
#include "asteroids_font.h"

#define MAX_ASTEROIDS 16
#define MAX_EXPLOSIONS 3
#define MAX_SHOTS 5
#define SHOT_TTL 16
#define SHOT_SPEED 2
#define SIZEOF_ASTEROID_BITMAP_RECORD 34
#define SIZEOF_ASTEROID_VERTICES_RECORD 25
#define SIZEOF_ASTEROID_OBJECT_RECORD 14
#define SIZEOF_SHIP_VERTICES_RECORD 6
#define SIZEOF_SHIP_OBJECT_RECORD 5
#define SIZEOF_FIRE_OBJECT_RECORD 3
#define SIZEOF_SAUCER_VERTICES_RECORD 12
#define SIZEOF_SAUCER_OBJECT_RECORD 10
#define SIZEOF_EXPLOSION_OBJECT_RECORD 9
#define W 128
#define H 96
#define FOOTER_Y 86
#define THRUST 0.15
#define DRAG 0.02;
// trigonometric values for computing thrust at different angles
#define SIN67_5  0.9239 // cos(22.5) and sin(67.5)
#define SIN45 0.7071  // sin(45) and cos(45)
#define SIN22_5  0.3827 // sin(22.5) and cos(67.5)
#define F1 100
#define F2 970
#define FIRE 1
#define EXPLOSION 2

typedef struct Asteroid {
  uint8_t x;
  uint8_t y;
  uint8_t info;  // high 4 bits are type, low 4 bits are heading
} Asteroid;

typedef struct Shot {
  uint8_t x;
  uint8_t y;
  uint8_t ttl;
  uint8_t heading;
} Shot;

typedef struct Explosion {
  uint8_t x;
  uint8_t y;
  uint8_t index; // index into the explosion bitmaps
} Explosion;

class Asteroids {

  public:

    Asteroids(Laser * laser);

    // Initialize a new game
    void initGame(bool start);

    // Called each tick of the game - from the arduino loop method
    void tick();

  private:

    // Display a debug integer
    void debug(int m);

    // Display a debug screen
    void debug(char *ss);

    // Detect all on screen collisions
    boolean detectCollisions();

    // Blow up the ship
    void die();

    // Display the stored high scores
    boolean displayHighScores(uint8_t file);

    // Add the score to the drawing list
    void displayScore();

    // Add an asteroid to the drawing list
    void drawAsteroid(Asteroid a);

    // Draw all explosions on screen
    void drawExplosions();

    // Draw the alien saucer on screen
    void drawSaucer();

    // Draw the player's ship
    void drawShip();

    // Store a high scroee
    void enterHighScore(uint8_t file);

    // Let the user enter their initials for high score
    void enterInitials();

    // Remove an asteroid from the drawing list
    void eraseAsteroid(Asteroid a);

    // Game is over
    void gameOver();

    // Read the controller input and act on it
    boolean getInput();

    // Allocate a buffer and return it
    int getMemory();

    // TBD - Sound related
    void heartbeat();

    // Increment the player score by n
    void incrementScore(int n);

      // Reset the game vars for a new level
    void initVars();

    // This is the point-in-polygon algorithm adapted from
    // http://www.ecse.rpi.edu/Homepages/wrf/Research/Short_Notes/pnpoly.html
    boolean inPolygon(uint8_t nvert, const uint8_t *xvert, const uint8_t *yvert, int x, int y);

    // Reposition all the asteroids on screen
    void moveAsteroids();

    // Move the players ship - this accounts for deceleration/drag
    void moveShip();

    // Update the position of a single shot
    void moveShot(Shot *s);

    // Reposition all the shots on screen
    void moveShots();

    // Start a new level
    void newLevel();

    // Play a tone of the given frequency and duration
    void playTone(unsigned int frequency, unsigned long duration_ms);

    // Play a tone of the given frequency, duration, and prioriy
    void playTone(unsigned int frequency, unsigned long duration_ms, uint8_t priority);

    // Return whether the fire button is being held down
    boolean pollFireButton(int n);

    // Set the sound pwm frequency
    void setPWMFreq(unsigned int f);

    // Sound interrupt handler
    void soundISR();

    // Draw the main title screen. Wait for player input to start the game
    boolean titleScreen();

    // Deprecated
    void erasebitmap(uint8_t x, uint8_t y, const unsigned char * bmp, uint16_t i, uint8_t width, uint8_t lines);
    void overlaybitmap(uint8_t x, uint8_t y, const unsigned char * bmp, uint16_t i, uint8_t width, uint8_t lines);

    // char s[16]; // general string buffer
    uint8_t x, y;
    float shipX, shipY;
    float shipDX, shipDY;
    uint8_t shipHeading;
    uint8_t oldShipHeading;
    uint8_t oldShipX, oldShipY;
    uint8_t thrustX, thrustY;
    unsigned long clock;
    unsigned long nextHeartbeat;
    char hyperspaceCount;
    uint8_t level = 1;
    uint8_t nAsteroids;
    volatile unsigned int freq;
    volatile uint8_t sound;
    uint8_t explosionFreqIndex;
    uint8_t heartbeatFreq;
    uint32_t LOW_FREQ_OCR;

    Asteroid asteroids[MAX_ASTEROIDS];
    Shot shots[MAX_SHOTS];
    Shot saucerShot;
    Explosion explosions[MAX_EXPLOSIONS];
    Explosion shipExplosion;
    uint8_t saucerX, saucerY, endSaucerX;
    uint8_t saucerHeading;
    uint8_t saucerType;
    unsigned int score;
    char remainingShips;
    char initials[3];
    boolean fired;
    boolean scored;
    uint8_t currentTonePriority;
    uint8_t explosionIndex;

    unsigned long debugTime;

    // Allow the overall speed of the game to be adjusted.
    // Higher number (like 1.5) slow the game down.  Lower numbers (like 0.6) speed it up.
    float speedAdjust;

    // const char s0[] PROGMEM = "ASTEROIDS";
    // const char s1[] PROGMEM = "HIGH SCORES";
    // const char s2[] PROGMEM = "GAME";
    // const char s3[] PROGMEM = "OVER";

    // const char* const strings[] PROGMEM = {s0, s1, s2, s3};

    Laser * laser;
};

#endif
