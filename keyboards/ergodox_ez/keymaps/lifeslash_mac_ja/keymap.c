/* v1.1.0.4 Mac Ja */

#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

bool is_hanzen = false;

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  VRSN = EZ_SAFE_RANGE
#else
  VRSN = SAFE_RANGE,
#endif
  RGB_SLD,
  HANZEN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Grv    |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  | Power  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    | Q/L1 |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  | P/L1 |   -    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |CAPSctrl|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|   "'   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LSht(  |Z/Cmd |X/ALT |   C  |   V  |   B  |      |           |      |   N  |   M  |  ,<  |.>/ALT|//Cmd | RShift)|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |  英数  |      |
 *                                 | Space|Backsp|------|       |------|  かな  |Enter |
 *                                 |      |ace   |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox(
  // left hand
  KC_GRV,       KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_NO,
  KC_TAB,       LT(SYMB,KC_Q),KC_W,KC_E,   KC_R,    KC_T,    KC_NO,
  CTL_T(KC_CAPS),KC_A,   KC_S,    KC_D,    KC_F,    KC_G,
  SC_LSPO,      GUI_T(KC_Z),LALT_T(KC_X),KC_C,KC_V, KC_B,    KC_NO,
  KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                                    KC_NO,   KC_NO,
                                                             KC_NO,
                                           KC_SPC,  KC_BSPC, KC_NO,
  // right hand
  KC_NO,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_KB_POWER,
  KC_NO,        KC_Y,    KC_U,    KC_I,    KC_O,    LT(SYMB,KC_P),KC_MINUS,
  KC_H,         KC_J,    KC_K,    KC_L,    LT(MDIA, KC_SCLN),KC_QUOT,
  KC_NO,        KC_N,    KC_M,    KC_COMM, LALT_T(KC_DOT),GUI_T(KC_SLSH),SC_RSPC,
  KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,        KC_NO,
  KC_NO,
  KC_NO,        HANZEN,  KC_ENT // KC_LNG1 <-> KC_LNG2 for MAC
),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |RESET    |      |  @   |  $   |  ^   |   +  |      |           |      |  \   |  |   |      |      |      |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |CAPS     |  !   |  #   |  %   |  &   |   =  |------|           |------|  -   |      |      |      |      |   INS  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |EPRM     |      |  {   |  }   |  <-  |  ↓  |      |           |      |  ↑  |  ->  |  [   |  ]   |  _   |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |MACRO |MACRO |      |       |      |MACRO |      |
 *                                 | REC1 | STOP |------|       |------|PLAY1 |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox(
  // left hand
  VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_NO,
  QK_BOOT, KC_NO,   KC_AT,   KC_DLR,  KC_CIRC, KC_PLUS, KC_NO,
  KC_CAPS, KC_EXLM, KC_HASH, KC_PERC, KC_AMPR, KC_EQL,
  EE_CLR,  KC_NO,   KC_LCBR, KC_RCBR, KC_LEFT, KC_DOWN, KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                               KC_NO,   KC_NO,
                                                        KC_NO,
                                      DM_REC1, DM_RSTP, KC_NO,
  // right hand
  KC_NO,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_NO,   KC_NUBS, KC_PIPE, KC_NO,   KC_NO,   KC_NO,   KC_F12,
  KC_MINS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_INS,
  KC_NO,   KC_UP,   KC_RGHT, KC_LBRC, KC_RBRC, KC_BSLS, KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,   KC_NO,
  KC_NO,
  KC_NO,   DM_PLY1, KC_NO
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | MsUp |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |MsLeft|MsDown|MsRght|      |      |------|           |------|MsLeft|MsDown| MsUp |MsRght|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |VolDn |                                       |VolUp |      | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 | Wheel| Wheel|      |       |      |      |      |
 *                                 | Down | Up   |------|       |------| Lclk | Rclk |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MDIA] = LAYOUT_ergodox(
  // left hand
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  
  KC_NO,   KC_NO,   KC_MS_U, KC_NO,   KC_NO,   KC_NO,   KC_NO,  
  KC_NO,   KC_MS_L, KC_MS_D, KC_MS_R, KC_NO,   KC_NO,  
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_VOLD,
                                               KC_NO,   KC_NO,  
                                                        KC_NO,  
                                      KC_WH_D, KC_WH_U, KC_NO,  
  // right hand
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  
           KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO,   KC_NO,  
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  
                    KC_VOLU, KC_NO,   KC_MUTE, KC_NO,   KC_NO,  
  KC_NO,   KC_NO,  
  KC_NO,  
  KC_NO,   KC_BTN1, KC_BTN2
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case VRSN:
        // SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        SEND_STRING ("ergodox_ez/lifeslash_mac_JA @ v1.1.0.3");
        return false;
      case HANZEN:
        if (is_hanzen) {
          is_hanzen = false;
          register_code(KC_LNG1);
        } else {
          is_hanzen = true;
          register_code(KC_LNG2);
        }
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      /*case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;//*/
      default:
        break;
    }

  return state;
};
