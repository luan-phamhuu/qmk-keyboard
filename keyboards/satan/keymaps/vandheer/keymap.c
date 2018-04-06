#include "satan.h"

// Used for SHIFT_ESC
#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0 // Base Layer
#define _NA 1 // Navigation Layer
#define _FL 2 // Function Layer
#define _MA 3 // Macro layer

//Tap Dance Declarations
enum {
  TD_SPC_ENT = 0
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,-----------------------------------------------------------.
   * |Esc~| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |
   * |-----------------------------------------------------------|
   * |Nav~Esc|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |
   * |-----------------------------------------------------------|
   * |Ctrl|Alt |Gui |      Space            |Gui |Alt |FN  |Macro|
   * `-----------------------------------------------------------'
   */
[_BL] = KEYMAP_ANSI(
  F(0),    KC_1,    KC_2,    KC_3,   KC_4,    KC_5,    KC_6,    KC_7,     KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,     KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, \
  LT(_NA, KC_ESC), KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_H,    KC_J,     KC_K,    KC_L,   KC_SCLN, KC_QUOT,          KC_ENT,  \
  KC_LSPO, KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,    KC_N,    KC_M,     KC_COMM, KC_DOT, KC_SLSH,                   KC_RSPC, \
  KC_LCTL, KC_LALT, KC_LGUI,                           KC_SPC,                             KC_RGUI, KC_RALT, MO(_FL), MO(_MA)),

/* Keymap _NA: Navigation Layer
   * ,-----------------------------------------------------------.
   * |   |   |   |   |   |   |   |   |   |   |   |   |   |       |
   * |-----------------------------------------------------------|
   * |     |   |   |   |   |   |   |Hom|Up |End|   |   |   |     |
   * |-----------------------------------------------------------|
   * |Nav~Esc|   |   |   |   |   |PUp|Lef|Dow|Rig|   |   |       |
   * |-----------------------------------------------------------|
   * |Shift   |   |   |   |   |   |PDo|   |   |   |   |          |
   * |-----------------------------------------------------------|
   * |Ctrl|Alt |Gui |                        |Gui |Alt |Fn |Macro|
   * `-----------------------------------------------------------'
   */
[_NA] = KEYMAP_ANSI(
  KC_GRV,   KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_NO,  KC_NO, \
  KC_NO,    KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_HOME,  KC_UP,    KC_END,   KC_NO,    KC_NO,  KC_NO,  KC_NO,  \
  KC_TRNS,  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_PGUP,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_NO,    KC_NO,          KC_TRNS,\
  KC_TRNS,  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_PGDN,  KC_NO,    KC_NO,    KC_NO,    KC_NO,                    KC_TRNS,\
  KC_TRNS,  KC_TRNS,  KC_TRNS,                     KC_TRNS,                         KC_TRNS,  KC_TRNS,KC_TRNS,          KC_TRNS),

/* Keymap _FL: Function Layer
   * ,-----------------------------------------------------------.
   * |   | F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|  DEL  |
   * |-----------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |
   * |-----------------------------------------------------------|
   * |Nav~Esc|   |   |   |   |   |   |   |   |   |Vol-|Vol+|     |
   * |-----------------------------------------------------------|
   * |Shift   |   |   |   |   |   |   |   |   |   |   |          |
   * |-----------------------------------------------------------|
   * |Ctrl|Alt |Gui |                        |Gui |Alt |Fn |Macro|
   * `-----------------------------------------------------------'
   */
[_FL] = KEYMAP_ANSI(
  LALT(LGUI(KC_ESC)),   KC_F1,    KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12, KC_DEL, \
  KC_NO,    KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,    KC_NO,    KC_NO,  KC_NO,  \
  KC_TRNS,  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_VOLD,  KC_VOLU,          KC_TRNS,\
  KC_TRNS,  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,                      KC_TRNS,\
  KC_TRNS,  KC_TRNS,  KC_TRNS,                     KC_TRNS,                         KC_TRNS,  KC_TRNS,KC_TRNS,            KC_TRNS),

  /* Keymap _BL: (Base Layer) Default Layer
   * ,-----------------------------------------------------------.
   * |Esc~| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
   * |-----------------------------------------------------------|
   * |     |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |
   * |-----------------------------------------------------------|
   * |Nav~Esc|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |
   * |-----------------------------------------------------------|
   * |Ctrl|Alt |Gui |      Space            |Gui |Alt |FN  |Ctrl |
   * `-----------------------------------------------------------'
   */
[_MA] = KEYMAP_ANSI(
  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, \
  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, \
  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,          KC_NO,  \
  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                  KC_NO, \
  KC_NO,  KC_NO,  KC_NO,                           KC_NO,                         KC_NO,  KC_NO,  KC_NO,  KC_TRNS),
};

enum function_id {
    SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(SHIFT_ESC)
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
    case SHIFT_ESC:
      shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
      if (record->event.pressed) {
        if (shift_esc_shift_mask) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (shift_esc_shift_mask) {
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
  }
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_SPC_ENT]  = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_ENT)
};
