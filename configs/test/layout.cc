// layout_helper.h defines the helper macros as well as short alias to each
// keycode. Please include it at the top of the layout.cc file.
#include "layout_helper.h"

// Alias for the key matrix GPIO pins. This is for better readability and is
// optional.

#define C0 18
#define C1 24 // boşta
#define C2 20
#define C3 26
#define C4 0
#define C5 16
#define C6 27 
#define C7 15
#define C8 1
#define C9 13
#define C10 10
#define C11 2
#define C12 9
#define C13 3
#define C14 11
#define C15 6
#define C16 7
#define C17 5
#define C18 4

#define R0 22
#define R1 19
#define R2 17
#define R3 14
#define R4 28
#define R5 21
#define R6 8
#define R7 12


// These two are also optional

#define CONFIG_NUM_PHY_ROWS 9
#define CONFIG_NUM_PHY_COLS 19

// This is a special layer that rotary encoder might have different behaviors.
// Also optional.

//#define ALT_LY 4

// For a layout.cc file, the followings are required: kGPIOMatrix, and
// kKeyCodes. They need to have exactly the same shape and type. They also need
// to be constexpr. For array types you don't need to specify the size for all
// the dimenions as long as compiler is happy. See docs/layout_cc.md for an
// example key matrix setup.

// clang-format off

// Keyboard switch physical GPIO connection setup. This is a map from the
// physical layout of the keys to their switch matrix. The reason for having 
// this mapping is that often times the physical layout of the switches does not
// match up with their wiring matrix. For each switch, it specifies the 
// direction of scanning.
static constexpr GPIO kGPIOMatrix[CONFIG_NUM_PHY_ROWS][CONFIG_NUM_PHY_COLS] = {
  {G(C0, R0),  G(C2, R0),  G(C4, R0),  G(C7, R0),  G(C8, R0),  G(C10, R0), G(C12, R0), G(C13, R0), G(C14, R0),  G(C15, R0), G(C17, R0), G(C18, R0)},
  {G(C0, R1),  G(C4, R1),  G(C7, R1),  G(C13, R1), G(C17, R1)},
  {G(C4, R2),  G(C5, R2),  G(C9, R2),  G(C15, R2), G(C16, R2), G(C17, R2)},
  {G(C2, R3),  G(C3, R3),  G(C5, R3),  G(C7, R3),  G(C9, R3),  G(C10, R3), G(C11, R3),  G(C14, R3),  G(C16, R3)},
  {G(C0, R4),  G(C4, R4),  G(C6, R4),  G(C11, R4), G(C13, R4), G(C15, R4), G(C17, R4), G(C18, R4)},
  {G(C0, R5),  G(C2, R5),  G(C4, R5),  G(C5, R5),  G(C15, R5), G(C17, R5),  G(C18, R5)},
  {G(R6, C7),  G(C2, R6),  G(C3, R6),  G(C4, R6),  G(C6, R6),    G(C7, R6),  G(C10, R6), G(C11, R6),  G(C12, R6),  G(C13, R6),  G(C14, R6),  G(C15, R6),  G(C16, R6),  G(C17, R6)},
  {G(C0, R7),  G(C3, R7),  G(C4, R7),  G(C7, R7),  G(C13, R7), G(C17, R7)},
  {G(R3,C6),}
  // {G(C0, R0),  G(C1, R0),  G(C2, R0),  G(C3, R0),  G(C4, R0),  G(C5, R0),  G(C6, R0),  G(C7, R0),  G(C8, R0),  G(C9, R0),  G(C10, R0),  G(C11, R0),  G(C12, R0),  G(C13, R0),  G(C14, R0),  G(C15, R0),  G(C16, R0),  G(C17, R0)},
  //  {G(C0, R1),  G(C1, R1),  G(C2, R1),  G(C3, R1),  G(C4, R1),  G(C5, R1),  G(C6, R1),  G(C7, R1),  G(C8, R1),  G(C9, R1),  G(C10, R1),  G(C11, R1),  G(C12, R1),  G(C13, R1),  G(C14, R1),  G(C15, R1),  G(C16, R1),  G(C17, R1)},
  // {G(C0, R2),  G(C1, R2),  G(C2, R2),  G(C3, R2),  G(C4, R2),  G(C5, R2),  G(C6, R2),  G(C7, R2),  G(C8, R2),  G(C9, R2),  G(C10, R2),  G(C11, R2),  G(C12, R2),  G(C13, R2),  G(C14, R2),  G(C15, R2),  G(C16, R2),  G(C17, R2), },
  // {G(C0, R3),  G(C1, R3),  G(C2, R3),  G(C3, R3),  G(C4, R3),  G(C5, R3),  G(C6, R3),  G(C7, R3),  G(C8, R3),  G(C9, R3),  G(C10, R3),  G(C11, R3),  G(C12, R3),  G(C13, R3),  G(C14, R3),  G(C15, R3),  G(C16, R3),  G(C17, R3), },
  // {G(C0, R4),  G(C1, R4),  G(C2, R4),  G(C3, R4),  G(C4, R4),  G(C5, R4),  G(C6, R4),  G(C7, R4),  G(C8, R4),  G(C9, R4),  G(C10, R4),  G(C11, R4),  G(C12, R4),  G(C13, R4),  G(C14, R4),  G(C15, R4),  G(C16, R4),  G(C17, R4), G(C18, R4)},
  // {G(C0, R5),  G(C1, R5),  G(C2, R5),  G(C3, R5),  G(C4, R5),  G(C5, R5),  G(C6, R5),  G(C7, R5),  G(C8, R5),  G(C9, R5),  G(C10, R5),  G(C11, R5),  G(C12, R5),  G(C13, R5),  G(C14, R5),  G(C15, R5),  G(C16, R5),  G(C17, R5), },
  // {G(C0, R6),  G(C1, R6),  G(C2, R6),  G(C3, R6),  G(C4, R6),  G(C5, R6),  G(C6, R6),  G(C7, R6),  G(C8, R6),  G(C9, R6),  G(C10, R6),  G(C11, R6),  G(C12, R6),  G(C13, R6),  G(C14, R6),  G(C15, R6),  G(C16, R6),  G(C17, R6),  },
  // {G(C0, R7),  G(C1, R7),  G(C2, R7),  G(C3, R7),  G(C4, R7),  G(C5, R7),  G(C6, R7),  G(C7, R7),  G(C8, R7),  G(C9, R7),  G(C10, R7),  G(C11, R7),  G(C12, R7),  G(C13, R7),  G(C14, R7),  G(C15, R7),  G(C16, R7),  G(C17, R7), },
};

static constexpr Keycode kKeyCodes[][CONFIG_NUM_PHY_ROWS][CONFIG_NUM_PHY_COLS] = {
  [0]={

    {K(K_Q), K(K_ARR_R), K(K_TAB), K(K_SPACE), K(K_A), K(K_ARR_L), K(K_ARR_U), K(K_S), K(K_ARR_D), K(K_E), K(K_D), K(K_W)},
    // {K(K_1), K(K_2), K(K_3), K(K_4), K(K_5), K(K_6), K(K_7), K(K_8), K(K_9), K(K_0), K(K_F1), K(K_F2), K(K_F3), K(K_F4), K(K_F5), K(K_F6), K(K_F7), K(K_F8)},
    {K(K_O), K(K_U), K(K_GUI_L), K(K_Y), K(K_I)},
    {K(K_H), K(K_B), K(K_CTR_L), K(K_PAGED), K(K_CTR_R),K(HID_KEY_APOSTROPHE)},
    {K(K_T), K(K_Z), K(K_G), K(K_V), K(K_F), K(K_ESC), K(K_X), K(K_R), K(K_C)},
    {K(K_0), K(K_8), K(HID_KEY_SHIFT_LEFT), K(HID_KEY_SHIFT_RIGHT), K(K_7), K(K_PAGEU), K(K_9), K(K_DEL)},
    {K(K_COMMA), K(K_CAPS), K(K_N), K(K_M), K(K_SLASH), K(K_APP), K(K_PERID)},
    {K(K_5), K(K_BACKS), K(K_1), K(K_MINUS),  K(K_6),  K(K_4), K(K_K), K(K_2), K(K_SEMIC), K(K_HOME), K(K_J), K(K_L), K(K_3), K(K_EQUAL)},
    {K(HID_KEY_BACKSLASH), K(K_ALT_R), K(HID_KEY_BRACKET_LEFT), K(K_ALT_L), K(K_P), K(HID_KEY_BRACKET_RIGHT)},
    {K(K_ENTER),}
    // {K(K_Q), K(K_SPACE), K(K_ARR_R), K(K_NONE), K(K_TAB), K(K_NONE), K(K_NONE), K(K_NONE), K(K_A), K(K_NONE), K(K_ARR_L), K(K_NONE), K(K_ARR_U), K(K_S), K(K_ARR_D), K(K_E), K(K_NONE), K(K_D), K(K_W)},
    // {K(K_O), K(K_GUI_L), K(K_NONE), K(K_NONE), K(K_U), K(K_NONE), K(K_NONE), K(K_NONE), K(K_NONE), K(K_NONE), K(K_NONE), K(K_NONE), K(K_NONE), K(K_Y), K(K_NONE), K(K_NONE), K(K_NONE), K(K_I)},
    // {K(K_NONE), K(K_NONE), K(K_NONE), K(K_NONE), K(K_H), K(K_B), K(K_NONE), K(K_NONE), K(K_NONE), K(K_CTR_L), Kx(K_NONE), K(K_NONE), K(K_NONE), K(K_NONE), K(K_NONE), K(K_PAGED), K(K_CTR_R),K(HID_KEY_APOSTROPHE)},
    // {K(K_NONE), K(K_NONE), K(K_T), K(K_Z), K(K_NONE), K(K_G), K(K_ENTER), K(K_V), K(K_NONE), K(K_F), K(K_ESC), K(K_X), K(K_NONE), K(K_NONE), K(K_R), K(K_NONE), K(K_C), K(K_NONE)},
    // {K(K_0), K(K_NONE), K(K_NONE), K(K_NONE), K(K_8), K(K_NONE), K(HID_KEY_SHIFT_LEFT), K(K_NONE), K(K_NONE), K(K_NONE), K(K_NONE), K(HID_KEY_SHIFT_RIGHT), K(K_NONE), K(K_7), K(K_NONE), K(K_PAGEU), K(K_NONE), K(K_9), K(K_DEL)},
    // {K(K_COMMA), K(K_NONE), K(K_CAPS), K(K_NONE), K(K_N), K(K_M), K(K_NONE), K(K_NONE), K(K_NONE), K(K_NONE), K(K_NONE), K(K_NONE), K(K_NONE), K(K_NONE), K(K_NONE), K(K_SLASH), K(K_NONE), K(K_APP)},
    // {K(K_NONE), K(K_4), K(K_BACKS), K(K_1), K(K_MINUS), K(K_NONE), K(K_6), K(K_5), K(K_NONE), K(K_NONE), K(K_K), K(K_2), K(K_SEMIC), K(K_HOME), K(K_J), K(K_L), K(K_3), K(K_EQUAL)},
    // {K(HID_KEY_BACKSLASH), K(K_NONE), K(K_NONE), K(K_ALT_R), K(HID_KEY_BRACKET_LEFT), K(K_NONE), K(K_NONE), K(K_ALT_L), K(K_NONE), K(K_NONE), K(K_NONE), K(K_NONE), K(K_NONE), K(K_P), K(K_NONE), K(K_NONE), K(K_NONE), K(HID_KEY_BRACKET_RIGHT)},
  }
};



// Compile time validation and conversion for the key matrix. Must include this.
#include "layout_internal.inc"

// Only register the key scanner to save binary size

static Status register1 = RegisterKeyscan(/*tag=*/0);
static Status register2 = RegisterUSBKeyboardOutput(/*tag=*/1);
