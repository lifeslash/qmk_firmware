/* v1.1.0.4 Win */

#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  VRSN = EZ_SAFE_RANGE
#else
  VRSN = SAFE_RANGE,
#endif
  RGB_SLD,
  ALT_TAB
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |CtlWin<-|   1  |   2  |   3  |   4  |   5  |   6  |           |   7  |   8  |   9  |   0  |AltTab|CtWinD|CtlWin->|
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    | Q/L1 |   W  |   E  |   R  |   T  |  '   |           |   \  |   Y  |   U  |   I  |   O  | P/L1 |  DEL   |
 * |--------+------+------+------+------+------|  Cmd |           |  Cmd |------+------+------+------+------+--------|
 * |WordCAPS|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|APP/Alt |
 * |--------+------+------+------+------+------|   =  |           |   -  |------+------+------+------+------+--------|
 * | LShift(|Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift)|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  Grv |  '"  | Esc  | Left | Down |                                       |  Up  | Right|   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |DM_RC1|       |DM_RC2|        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |DM_STP|       |DM_STP|        |      |
 *                                 | Space|Backsp|------|       |------|  Han   |Enter |
 *                                 |      |ace   |DM_PL1|       |DM_PL2|        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox(
  // left hand
  LCTL(LGUI(KC_LEFT)),KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
  KC_TAB,          LT(SYMB,KC_Q),KC_W,   KC_E,    KC_R,    KC_T,    GUI_T(KC_QUOT),
  CW_TOGG,         KC_A,        KC_S,    KC_D,    KC_F,    KC_G,
  SC_LSPO,         CTL_T(KC_Z), KC_X,    KC_C,    KC_V,    KC_B,    KC_EQL,
  KC_GRV,          KC_QUOT,     KC_ESC,  KC_LEFT, KC_DOWN,
                                                                 KC_NO,   DM_REC1,
                                                                          DM_RSTP,
                                                         KC_SPC, KC_BSPC, DM_PLY1,
  // right hand
  KC_7,         KC_8,    KC_9,    KC_0,    ALT_TAB,           LCTL(LGUI(KC_D)),   LCTL(LGUI(KC_RIGHT)),
  GUI_T(KC_BSLS),KC_Y,   KC_U,    KC_I,    KC_O,              LT(SYMB,KC_P),      KC_DEL,
  KC_H,         KC_J,    KC_K,    KC_L,    LT(MDIA, KC_SCLN), LALT_T(KC_APP),
  KC_MINS,      KC_N,    KC_M,    KC_COMM, KC_DOT,            CTL_T(KC_SLSH),     SC_RSPC,
  KC_UP,        KC_RGHT, KC_LBRC, KC_RBRC, TT(SYMB),
  DM_REC2, KC_NO,
  DM_RSTP,
  DM_PLY2, LCTL(KC_SPC), KC_ENT
),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |  PRTSC |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |RESET    |      |   @  |  $   |  ^   |  *   |   [  |           |  ]   |   7  |   8  |   9  |   *  |   /  |   INS  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |CAPS     |   !  |   #  |  %   |  &   |  Esc |------|           |------|   4  |   5  |   6  |   +  |   -  |        |
 * |---------+------+------+------+------+------|   <  |           |  >   |------+------+------+------+------+--------|
 * |         |      |      |      | jis\ | jis_ |      |           |      |   1  |   2  |   3  |   0  |   =  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      | Home | PgDn |                                       | PgUp | End  |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox(
  // left hand
  VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
  QK_BOOT, KC_NO,   KC_AT,   KC_DLR,  KC_CIRC, KC_ASTR, KC_LBRC,
  KC_CAPS, KC_EXLM, KC_HASH, KC_PERC, KC_AMPR, KC_ESC,
  KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_INT3, KC_INT1, LSFT(KC_COMM),
  EE_CLR,  KC_NO,   KC_NO,   KC_HOME, KC_PGDN,
                                               RGB_MOD, KC_NO,
                                                        KC_NO,
                                      RGB_VAD, RGB_VAI, KC_NO,
  // right hand
  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,
  KC_RBRC,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_SLSH, KC_INS,
  KC_4,    KC_5,    KC_6,    KC_PLUS, KC_MINS, KC_NO,
  LSFT(KC_DOT),KC_1,KC_2,    KC_3,    KC_0,    KC_EQL,  KC_TRNS,
  KC_PGUP, KC_END,  KC_NO,   KC_NO,   KC_TRNS,
  RGB_TOG, RGB_SLD,
  KC_NO,
  KC_NO,   RGB_HUD, RGB_HUI
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
        SEND_STRING ("ergodox_ez/lifeslash_win @ v1.1.0.5");
        return false;
      case ALT_TAB:
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  } else {
    switch (keycode) {
      case ALT_TAB:
        unregister_code(KC_TAB);
        return false;
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

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}

/*void suspend_power_down_kb(void)
{
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_kb(void)
{
    rgb_matrix_set_suspend_state(false);
}//*/
