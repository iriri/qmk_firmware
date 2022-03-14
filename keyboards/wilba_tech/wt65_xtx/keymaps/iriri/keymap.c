/* Copyright 2020 Jason Williams (Wilba)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

typedef enum {
    IRI_LFN = SAFE_RANGE,
    IRI_RFN,

    IRI_S1Q = UC(0x2227),
    IRI_S1W = UC(0x2228),
    IRI_S1E = UC(0x22C2),
    IRI_S1R = UC(0x22C3),
    IRI_S1T = UC(0x2282),
    IRI_S1Y = UC(0x2283),
    IRI_S1U = UC(0x2200),
    IRI_S1I = UC(0x221E),
    IRI_S1O = UC(0x2203),
    IRI_S1P = UC(0x2202),

    IRI_S1A = UC(0x22A5),
    IRI_S1S = UC(0x22A4),
    IRI_S1D = UC(0x22A2),
    IRI_S1F = UC(0x22A3),
    IRI_S1G = UC(0x2191),
    IRI_S1H = UC(0x2193),
    IRI_S1J = UC(0x2190),
    IRI_S1K = UC(0x2192),
    IRI_S1L = UC(0x2194),

    IRI_S1Z = UC(0x230A),
    IRI_S1X = UC(0x2308),
    IRI_S1C = UC(0x2260),
    IRI_S1V = UC(0x2243),
    IRI_S1B = UC(0x2261),
    IRI_S1N = UC(0x2264),
    IRI_S1M = UC(0x2265),
} iri_keycodes;

#define IRI_LAYER_BASE 0
#define IRI_LAYER_FN   1
#define IRI_LAYER_XSFT 2
#define IRI_LAYER_XFN  3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [IRI_LAYER_BASE] = LAYOUT_all(
        KC_F13,  KC_F18,     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC, KC_INS,
        KC_F14,  TO(3),      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_DEL,
        KC_F15,  TO(2),      KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                    KC_PGUP,
        KC_F16,  TO(1),      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                   KC_UP,   KC_PGDN,
        KC_F17,  TO(0),      KC_LCTL, IRI_LFN, KC_LALT,                            KC_SPC,                             KC_RGUI, IRI_RFN,          KC_LEFT, KC_DOWN, KC_RGHT),

    [IRI_LAYER_FN] = LAYOUT_all(
        KC_F19,  KC_TRNS,    KC_LSFT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F13,  KC_F13,  KC_F15,
        KC_F20,  KC_TRNS,    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS, KC_F14,           KC_F16,
        KC_F21,  KC_TRNS,    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,                    KC_F17,
        KC_F22,  KC_TRNS,    KC_BSPC, KC_DEL,  KC_INS,  KC_TRNS, KC_TRNS, KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS,  KC_DEL,  KC_BSPC,                   KC_TRNS, KC_F18,
        KC_F23,  KC_TRNS,    KC_TRNS, IRI_LFN, KC_TRNS,                            KC_TRNS,                            KC_TRNS, IRI_RFN,          KC_TRNS, KC_TRNS, KC_TRNS),

    [IRI_LAYER_XSFT] = LAYOUT_all(
        KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,    KC_TRNS, IRI_S1Q, IRI_S1W, IRI_S1E, IRI_S1R, IRI_S1T, IRI_S1Y, IRI_S1U, IRI_S1I, IRI_S1O, IRI_S1P, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
        KC_TRNS, KC_TRNS,    KC_TRNS, IRI_S1A, IRI_S1S, IRI_S1D, IRI_S1F, IRI_S1G, IRI_S1H, IRI_S1J, IRI_S1K, IRI_S1L, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,
        KC_TRNS, KC_TRNS,    KC_TRNS, IRI_S1Z, IRI_S1X, IRI_S1C, IRI_S1V, IRI_S1B, IRI_S1N, IRI_S1M, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS),

    [IRI_LAYER_XFN] = LAYOUT_all(
        KC_TRNS, KC_TRNS,    KC_TRNS, TO(0),   TO(1),   TO(2),   TO(3),   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS,          KC_TRNS,
        KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,
        KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, UC_M_LN, UC_M_WI, UC_M_MA, RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_PGUP, KC_TRNS,
        KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS,          KC_HOME, KC_PGDN, KC_END),
};

static const uint16_t IRI_TAPPING_PERIOD = 200;

#define IRI_STATE_NORMAL 0
#define IRI_STATE_LSFT   1
#define IRI_STATE_LSFTL  2
#define IRI_STATE_RSFT   3
#define IRI_STATE_RSFTL  4
#define IRI_STATE_XSFT   5
#define IRI_STATE_XSFTL  6
#define IRI_STATE_LFN    7
#define IRI_STATE_LFNL   8
#define IRI_STATE_RFN    9
#define IRI_STATE_RFNL   10
#define IRI_STATE_XFN    11
#define IRI_STATE_XFNL   12

static const size_t IRI_IDX_KC_LSFT = 0;
static const size_t IRI_IDX_KC_RSFT = 1;
static const size_t IRI_IDX_IRI_LFN = 2;
static const size_t IRI_IDX_IRI_RFN = 3;

// Threads? Never heard of them.
static uint8_t  iri_state       = IRI_STATE_NORMAL;
static bool     iri_down[]      = {false, false, false, false};
static uint16_t iri_last_kc     = 0;
static uint16_t iri_last_ts     = 0;
static uint16_t iri_last_tap_kc = 0;
static uint16_t iri_last_tap_ts = 0;

static bool
iri_was_double_tapped(uint16_t keycode, keyrecord_t* record) {
    // assert(!record->event.pressed);
    if (keycode != iri_last_kc) {
        goto reset_last_tap_kc;
    }
    if (record->event.time - iri_last_ts < IRI_TAPPING_PERIOD) {
        if (keycode == iri_last_tap_kc &&
            record->event.time - iri_last_tap_ts < IRI_TAPPING_PERIOD * 2)
        {
            return true;
        }
        iri_last_tap_kc = keycode;
        iri_last_tap_ts = record->event.time;
        return false;
    }
reset_last_tap_kc:
    iri_last_tap_kc = 0;
    return false;
}

static void
iri_process_kc_lsft(keyrecord_t *record) {
    switch (iri_state) {
    break;case IRI_STATE_NORMAL:
        // assert(record->event.pressed);
        register_code(KC_LSFT);
        iri_state = IRI_STATE_LSFT;
        goto skip_reset_last_tap;
    break;case IRI_STATE_LSFT:
        // assert(!record->event.pressed);
        if (iri_was_double_tapped(KC_LSFT, record)) {
            iri_state = IRI_STATE_LSFTL;
        } else {
            unregister_code(KC_LSFT);
            iri_state = IRI_STATE_NORMAL;
        }
        goto skip_reset_last_tap;
    break;case IRI_STATE_LSFTL:
        // assert(record->event.pressed);
        iri_state = IRI_STATE_LSFT;
    break;case IRI_STATE_RSFT:
        // assert(record->event.pressed);
        layer_on(IRI_LAYER_XSFT);
        iri_state = IRI_STATE_XSFT;
    break;case IRI_STATE_RSFTL:
        // assert(record->event.pressed);
        layer_on(IRI_LAYER_XSFT);
        iri_state = IRI_STATE_XSFTL;
    break;case IRI_STATE_XSFT:
        // assert(!record->event.pressed);
        layer_off(IRI_LAYER_XSFT);
        iri_state = IRI_STATE_RSFT;
    break;case IRI_STATE_XSFTL:
        if (record->event.pressed) {
            layer_off(IRI_LAYER_XSFT);
            iri_state = IRI_STATE_LSFT;
        }
    break;default:
        if (!iri_down[IRI_IDX_KC_RSFT]) {
            if (record->event.pressed) {
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_LSFT);
            }
        }
    }
    iri_last_tap_kc = 0;
skip_reset_last_tap:
    iri_down[IRI_IDX_KC_LSFT] = record->event.pressed;
}

static void
iri_process_kc_rsft(keyrecord_t *record) {
    switch (iri_state) {
    break;case IRI_STATE_NORMAL:
        // assert(record->event.pressed);
        register_code(KC_LSFT);
        iri_state = IRI_STATE_RSFT;
        goto skip_reset_last_tap;
    break;case IRI_STATE_LSFT:
        // assert(record->event.pressed);
        layer_on(IRI_LAYER_XSFT);
        iri_state = IRI_STATE_XSFT;
    break;case IRI_STATE_LSFTL:
        // assert(record->event.pressed);
        layer_on(IRI_LAYER_XSFT);
        iri_state = IRI_STATE_XSFTL;
    break;case IRI_STATE_RSFT:
        // assert(!record->event.pressed);
        if (iri_was_double_tapped(KC_RSFT, record)) {
            iri_state = IRI_STATE_RSFTL;
        } else {
            unregister_code(KC_LSFT);
            iri_state = IRI_STATE_NORMAL;
        }
        goto skip_reset_last_tap;
    break;case IRI_STATE_RSFTL:
        // assert(record->event.pressed);
        iri_state = IRI_STATE_RSFT;
    break;case IRI_STATE_XSFT:
        // assert(!record->event.pressed);
        layer_off(IRI_LAYER_XSFT);
        iri_state = IRI_STATE_LSFT;
    break;case IRI_STATE_XSFTL:
        if (record->event.pressed) {
            layer_off(IRI_LAYER_XSFT);
            iri_state = IRI_STATE_RSFT;
        }
    break;default:
        if (!iri_down[IRI_IDX_KC_LSFT]) {
            if (record->event.pressed) {
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_LSFT);
            }
        }
    }
    iri_last_tap_kc = 0;
skip_reset_last_tap:
    iri_down[IRI_IDX_KC_RSFT] = record->event.pressed;
}

static void
iri_process_iri_lfn(keyrecord_t *record) {
    switch (iri_state) {
    break;case IRI_STATE_NORMAL:
        // assert(record->event.pressed);
        layer_on(IRI_LAYER_FN);
        iri_state = IRI_STATE_LFN;
        goto skip_reset_last_tap;
    break;case IRI_STATE_LFN:
        // assert(!record->event.pressed);
        if (iri_was_double_tapped(IRI_LFN, record)) {
            iri_state = IRI_STATE_LFNL;
        } else {
            layer_off(IRI_LAYER_FN);
            iri_state = IRI_STATE_NORMAL;
        }
        goto skip_reset_last_tap;
    break;case IRI_STATE_LFNL:
        // assertA(record->event.pressed);
        iri_state = IRI_STATE_LFN;
    break;case IRI_STATE_RFN:
        // assert(record->event.pressed);
        layer_on(IRI_LAYER_XFN);
        iri_state = IRI_STATE_XFN;
    break;case IRI_STATE_RFNL:
        // assert(record->event.pressed);
        layer_on(IRI_LAYER_XFN);
        iri_state = IRI_STATE_XFNL;
    break;case IRI_STATE_XFN:
        // assert(!record->event.pressed);
        layer_off(IRI_LAYER_XFN);
        iri_state = IRI_STATE_RFN;
    break;case IRI_STATE_XFNL:
        if (record->event.pressed) {
            layer_off(IRI_LAYER_XFN);
            layer_off(IRI_LAYER_FN);
            iri_state = IRI_STATE_NORMAL;
        }
    break;default:
        if (!iri_down[IRI_IDX_IRI_RFN]) {
            if (record->event.pressed) {
                layer_on(IRI_LAYER_FN);
            } else {
                layer_off(IRI_LAYER_FN);
            }
        }
    }
    iri_last_tap_kc = 0;
skip_reset_last_tap:
    iri_down[IRI_IDX_IRI_LFN] = record->event.pressed;
}

static void
iri_process_iri_rfn(keyrecord_t *record) {
    switch (iri_state) {
    break;case IRI_STATE_NORMAL:
        // assert(record->event.pressed);
        layer_on(IRI_LAYER_FN);
        iri_state = IRI_STATE_RFN;
        goto skip_reset_last_tap;
    break;case IRI_STATE_LFN:
        // assert(record->event.pressed);
        layer_on(IRI_LAYER_XFN);
        iri_state = IRI_STATE_XFN;
    break;case IRI_STATE_LFNL:
        // assert(record->event.pressed);
        layer_on(IRI_LAYER_XFN);
        iri_state = IRI_STATE_XFNL;
    break;case IRI_STATE_RFN:
        // assert(!record->event.pressed);
        if (iri_was_double_tapped(IRI_RFN, record)) {
            iri_state = IRI_STATE_RFNL;
        } else {
            layer_off(IRI_LAYER_FN);
            iri_state = IRI_STATE_NORMAL;
        }
        goto skip_reset_last_tap;
    break;case IRI_STATE_RFNL:
        // assert(record->event.pressed);
        iri_state = IRI_STATE_RFN;
    break;case IRI_STATE_XFN:
        // assert(!record->event.pressed);
        layer_off(IRI_LAYER_XFN);
        iri_state = IRI_STATE_LFN;
    break;case IRI_STATE_XFNL:
        if (record->event.pressed) {
            layer_off(IRI_LAYER_XFN);
            layer_off(IRI_LAYER_FN);
            iri_state = IRI_STATE_NORMAL;
        }
    break;default:
        if (!iri_down[IRI_IDX_IRI_LFN]) {
            if (record->event.pressed) {
                layer_on(IRI_LAYER_FN);
            } else {
                layer_off(IRI_LAYER_FN);
            }
        }
    }
    iri_last_tap_kc = 0;
skip_reset_last_tap:
    iri_down[IRI_IDX_IRI_RFN] = record->event.pressed;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    break;case KC_LSFT: iri_process_kc_lsft(record);
    break;case KC_RSFT: iri_process_kc_rsft(record);
    break;case IRI_LFN: iri_process_iri_lfn(record);
    break;case IRI_RFN: iri_process_iri_rfn(record);
    break;default     :
        iri_last_kc = iri_last_tap_kc = 0;
        return true;
    }
    iri_last_kc = keycode;
    iri_last_ts = record->event.time;
    return false;
}
