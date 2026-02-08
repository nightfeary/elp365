#ifndef APP_H
#define APP_H

// --------------------
// Includes
// --------------------
// Arduino core (for types like bool, millis(), etc.)
#include <Arduino.h>

// --------------------
// Public Types
// --------------------

// Waveform types supported by the function generator
typedef enum {
    WAVE_SINE = 0,
    WAVE_SQUARE,
    WAVE_TRIANGLE
    // Add more later (SAW, NOISE, etc.)
} WaveformType;

// Application state structure
typedef struct {
    float frequency;        // Output frequency in Hz
    float amplitude;        // Output amplitude (normalized or volts)
    float dc_offset;        // DC offset
    WaveformType waveform;  // Current waveform
    bool output_enabled;    // Output ON/OFF
} AppState;

// --------------------
// Public API
// --------------------

// Initialize the application
// Called once from setup()
void app_init(void);

// Main application loop
// Called repeatedly from loop()
void app_run(void);

// (Optional but useful) Get current state for display module
const AppState* app_get_state(void);

#endif // APP_H
