#pragma once
#include "quantum.h"

#if defined(UNICODEMAP_ENABLE)
#include "unicode/unicode.h"
#endif

// clang format off
#define FOREACH_UNICODE(M) \
    M(EAC, 0x00E9)    /* é */ \
    M(IRONY, 0x2E2E)  /* ⸮ */ \
    M(CHECK, 0x2713)  /* ✓ */ \
    M(CROSS, 0x2717)  /* ✗ */ \
    M(BULL, 0x2022)   /* • */ \
    M(TBULL, 0x2023)  /* ‣ */ \
    M(HBULL, 0x2043)  /* ⁃ */ \
    M(OPDOT, 0x2219)  /* ∙ */ \
    M(VSPC, 0x2423)  /* ␣ */ \
    M(EMDSH, 0x2014)  /* — */ \
    M(ARRLF, 0x2190)  /* ← */ \
    M(ARRUP, 0x2191)  /* ↑ */ \
    M(ARRRT, 0x2192)  /* → */ \
    M(ARRDN, 0x2193)  /* ↓ */ \
    M(NEQ, 0x2260)    /* ≠ */
// clang format on

#define UCM_NAME(name, code)    U_ ## name,                 // U_NEQ,
#define UCM_ENTRY(name, code)   [U_ ## name] = code,        // [U_NEQ] = 0x2260,
#define UCM_KEYCODE(name, code) N_ ## name = UM(U_ ## name), // N_NEQ = UM(U_NEQ)

#if defined(UNICODEMAP_ENABLE)
enum unicode_names {
    FOREACH_UNICODE(UCM_NAME)
};

extern const uint32_t PROGMEM unicode_map[];

enum unicode_keycodes {
    FOREACH_UNICODE(UCM_KEYCODE)
};

#define N_YESNO  UP(U_CHECK, U_CROSS)
#define N_UNIDOT UP(U_BULL,  U_OPDOT)

#endif
