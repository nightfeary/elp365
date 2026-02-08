#include "app.h"
#include "app_config.h"

// Include other modules
#include "../signal/signal_gen.h"
#include "../input/input.h"
#include "../display/display.h"

// --------------------
// Internal State
// --------------------

static AppState app_state;

// --------------------
// Initialization
// --------------------

void app_init(void)
{
    //TODO
}

// --------------------
// Main Application Loop
// --------------------

void app_run(void)
{
    //TODO
}

// --------------------
// State Access
// --------------------

const AppState* app_get_state(void)
{
    return &app_state;
}
