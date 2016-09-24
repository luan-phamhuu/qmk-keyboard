const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BLANK
   * ,-----------------------------------------------------------.
   * |    |   |   |   |   |   |   |   |   |   |   |   |   |      |
   * |-----------------------------------------------------------|
   * |Tab  |   |   |   |   |   |   |   |   |   |   |   |   |     |
   * |-----------------------------------------------------------|
   * |CAPS   |   |   |   |   |   |   |   |   |   |   |   |       |
   * |-----------------------------------------------------------|
   * |Shift   |   |   |   |   |   |   |   |   |   |   |          |
   * |-----------------------------------------------------------|
   * |Ctrl|Alt |Gui |      Space            |Gui |Alt |FN  |Ctrl |
   * `-----------------------------------------------------------'
   */
[_BLANK] = KEYMAP_ANSI(
  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, \
  KC_TAB, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, \
  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,          KC_NO,  \
  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                  KC_NO, \
  KC_NO,  KC_NO,  KC_NO,                           KC_NO,                         KC_NO,  KC_NO,  KC_NO,  KC_NO),
};
