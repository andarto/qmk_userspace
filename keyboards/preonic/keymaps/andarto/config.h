#pragma once

#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

#undef UNICODE_SELECTED_MODES
#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX, UNICODE_MODE_WINCOMPOSE

#undef UNICODE_CYCLE_PERSIST
#define UNICODE_CYCLE_PERSIST false

#undef UNICODE_TYPE_DELAY // default 10
#define UNICODE_TYPE_DELAY 20

#undef TAPPING_TERM // also used as timeout value for other timers
#define TAPPING_TERM 175

// disable alternate repeat key as we have currently have to space to put
// it on a base layer
#define NO_ALT_REPEAT_KEY
