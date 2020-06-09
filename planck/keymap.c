/**
 * Hi! This is the configuration for my Planck keyboard.
 *
 * The thoughts behind this layout mainly come from my Ergodox layout.
 * https://github.com/Olical/ergodox/blob/master/layout.png
 *
 * This file is a _heavily_ modified version of the default Planck layout file.
 *
 * There are 47 keys per layer.
 *
 * Here's the keys I need assigned, grouped by layer.
 *
 * == Default ==
 * A-Z (26)
 * (
 * {
 * [
 * Space
 * Shift
 * Escape
 * Alt
 * Control
 * GUI (super)
 * Tab
 * Comma
 * Period
 * Semi-colon
 * Backspace
 * Forward slash
 * Quote
 * Hash
 * Enter
 * Equals
 * Raise
 * Lower
 *
 * == Lower ==
 * 0-9 (10)
 * Directions (4)
 * Delete
 * Minus
 * Backslash
 * Backtick
 * )
 * }
 * ]
 *
 * == Raise ==
 * F1-F12 (12)
 * Page up
 * Page down
 * Home
 * End
 * Vol+
 * Vol-
 * Mute
 * Play
 *
 * == Adjust ==
 * Cycle LEDs
 * Default adjust keys
 */

#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _DEFAULT,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  DEFAULT = SAFE_RANGE,
  LOWER,
  RAISE,
  BACKLIT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Default
 * ,-----------------------------------------------------------------------------------.
 * |   [  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   =  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   (  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   {  |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |   #  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | Tab  | Lower|    Space    | Raise| Bksp | Esc  | Shift| Enter|
 * `-----------------------------------------------------------------------------------'
 */
[_DEFAULT] = {
  {KC_LBRC, KC_Q,    KC_W,    KC_E,   KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_EQL},
  {KC_LPRN, KC_A,    KC_S,    KC_D,   KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LCBR, KC_Z,    KC_X,    KC_C,   KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_NUHS},
  {KC_LCTL, KC_LGUI, KC_LALT, KC_TAB, LOWER, KC_SPC, KC_SPC, RAISE, KC_BSPC, KC_ESC,  KC_LSFT, KC_ENT}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ]  |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   )  |      |      |      |      |      | Left | Down | Up   | Right|      |  `   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   }  |      |      |      |      |      |      |      |      |      |  \   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Del  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_RBRC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_MINUS},
  {KC_RPRN, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, KC_GRV},
  {KC_RCBR, _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_NUBS, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,  _______,  _______, _______}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | Home | PgDn | PgUp | End  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | Play | Vol- | Vol+ | Mute |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12},
  {_______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______},
  {_______, _______, _______, _______, _______, _______, KC_MPLY, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | LEDs | Reset|      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {BACKLIT, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, _______},
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, _______,  _______, _______, _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______}
}


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        PORTE &= ~(1<<6);
      } else {
        unregister_code(KC_RSFT);
        PORTE |= (1<<6);
      }
      return false;
      break;
  }
  return true;
}
