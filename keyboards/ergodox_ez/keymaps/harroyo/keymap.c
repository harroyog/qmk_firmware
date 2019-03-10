#include QMK_KEYBOARD_H
#include "debug.h"
#include "version.h"
#include "action_layer.h"
#include "config.h"

#define _____ KC_TRANSPARENT



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_ergodox(
    
    KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_MPLY,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_MPRV,
    KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MNXT,
    KC_LCTL, KC_LGUI, KC_LALT, KC_LEFT, KC_RGHT,
     KC_HOME, KC_END,
     KC_ESC,
     KC_SPC, KC_BSPC, MO(1),
     
    KC_MUTE, KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQL,
    KC_COPY, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
    KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
    KC_PSTE, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
    KC_UP, KC_DOWN, KC_RALT, MO(1), KC_RCTL,
     KC_PGUP, KC_PGDN,
     KC_INS,
     KC_DEL, MO(1), KC_ENT),

	[1] = LAYOUT_ergodox(
    KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,
    KC_TAB, KC_NO, KC_NO, KC_NO, KC_LPRN, KC_RPRN, KC_NO,
    KC_CAPS, KC_NO, KC_NO, KC_NO, KC_LCBR, KC_RCBR,
    KC_LSFT, KC_NO, KC_NO, KC_NO, KC_LBRC, KC_RBRC, KC_NO,
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC,
     KC_NO, KC_NO, 
     KC_NO,
     KC_SPC, KC_NO, KC_TRNS,
     
    KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR,
    KC_NO, KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PPLS, KC_BSLS,
    KC_PAST, KC_P4, KC_P5, KC_P6, KC_PCMM, KC_ENT,
    KC_PEQL, KC_PMNS, KC_P1, KC_P2, KC_P3, KC_PEQL, KC_RSFT,
    KC_P0, KC_P0, KC_PDOT, KC_TRNS, KC_RCTL,
     MAGIC_UNNO_GUI, MAGIC_NO_GUI,
     KC_NO,
     KC_NO, KC_TRNS, KC_ENT)
};

void matrix_init_user(void) {
#ifdef RGBLIGHT_ENABLE
  rgblight_init();
  rgblight_enable();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
#endif
};

void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
        break;
      case 1:
        ergodox_right_led_1_on();
        break;
      default:
        break;
    }
  return state;
};
