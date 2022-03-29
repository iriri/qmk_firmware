/* Copyright 2022 iriri
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
    L_T_MD = SAFE_RANGE, // LED toggle mode
    L_PTN,               // LED pattern select next
    L_BRI,               // LED brightness increase
    L_T_PTD,             // LED toggle scrolling pattern direction and effect
    L_PSI,               // LED pattern speed increase
    L_RATI,              // LED keys/edge ratio increase
} carina_keycodes;

typedef enum {
    IRI_LFN = L_RATI + 1,
    IRI_RFN,

    IRI_SGR = UC(0x25A0),
    IRI_S1  = UC(0x2020),
    IRI_S2  = UC(0x2021),
    IRI_S3  = UC(0x2248),
    IRI_S4  = UC(0x00A7),
    IRI_S5  = UC(0x2286),
    IRI_S6  = UC(0x2287),
    IRI_S7  = UC(0x00B6),
    IRI_S8  = UC(0x00D7),
    IRI_S9  = UC(0x2211),
    IRI_S0  = UC(0x220F),
    IRI_SMN = UC(0x2014),
    IRI_SEQ = UC(0x00AC),

    IRI_SQ  = UC(0x2227),
    IRI_SW  = UC(0x2228),
    IRI_SE  = UC(0x22C2),
    IRI_SR  = UC(0x22C3),
    IRI_ST  = UC(0x2282),
    IRI_SY  = UC(0x2283),
    IRI_SU  = UC(0x2200),
    IRI_SI  = UC(0x221E),
    IRI_SO  = UC(0x2203),
    IRI_SP  = UC(0x2202),
    IRI_SLB = UC(0x2329),
    IRI_SRB = UC(0x232A),
    IRI_SBS = UC(0x2219),

    IRI_SA  = UC(0x22A5),
    IRI_SS  = UC(0x22A4),
    IRI_SD  = UC(0x22A2),
    IRI_SF  = UC(0x22A3),
    IRI_SG  = UC(0x2191),
    IRI_SH  = UC(0x2193),
    IRI_SJ  = UC(0x2190),
    IRI_SK  = UC(0x2192),
    IRI_SL  = UC(0x2194),
    IRI_SSC = UC(0x2234),
    IRI_SQT = UC(0x2032),

    IRI_SZ  = UC(0x230A),
    IRI_SX  = UC(0x2308),
    IRI_SC  = UC(0x2260),
    IRI_SV  = UC(0x2243),
    IRI_SB  = UC(0x2261),
    IRI_SN  = UC(0x2264),
    IRI_SM  = UC(0x2265),
    IRI_SCM = UC(0x00AB),
    IRI_SPR = UC(0x00BB),
    IRI_SSL = UC(0x00F7),

    IRI_FQ = UC(0x00B9),
    IRI_FW = UC(0x00B2),
    IRI_FE = UC(0x00B3),
    IRI_FR = UC(0x2074),
    IRI_FT = UC(0x2075),
    IRI_FY = UC(0x2076),
    IRI_FU = UC(0x2077),
    IRI_FI = UC(0x2078),
    IRI_FO = UC(0x2079),
    IRI_FP = UC(0x2070),

    IRI_FZ  = UC(0x2081),
    IRI_FX  = UC(0x2082),
    IRI_FC  = UC(0x2083),
    IRI_FV  = UC(0x2084),
    IRI_FB  = UC(0x2085),
    IRI_FN  = UC(0x2086),
    IRI_FM  = UC(0x2087),
    IRI_FCM = UC(0x2088),
    IRI_FPR = UC(0x2089),
    IRI_FSL = UC(0x2080),
} iri_keycodes;

#define IRI_LAYER_BASE 0
#define IRI_LAYER_FN   1
#define IRI_LAYER_XSFT 2
#define IRI_LAYER_XFN  3

keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [IRI_LAYER_BASE] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL, IRI_LFN, KC_LALT,                            KC_SPC,                             KC_RGUI, IRI_RFN, KC_DOWN, KC_UP),

    [IRI_LAYER_FN] = LAYOUT(
        KC_LSFT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F13,
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS, KC_F14,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
        KC_BSPC, KC_DEL,  KC_INS,  KC_TRNS, KC_TRNS, KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS,  KC_DEL,  KC_BSPC,
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [IRI_LAYER_XSFT] = LAYOUT(
        IRI_SGR, IRI_S1,  IRI_S2,  IRI_S3,  IRI_S4,  IRI_S5,  IRI_S6,  IRI_S7,  IRI_S8,  IRI_S9,  IRI_S0,  IRI_SMN, IRI_SEQ, KC_TRNS,
        KC_TRNS, IRI_SQ,  IRI_SW,  IRI_SE,  IRI_SR,  IRI_ST,  IRI_SY,  IRI_SU,  IRI_SI,  IRI_SO,  IRI_SP,  IRI_SLB, IRI_SRB, IRI_SBS,
        KC_TRNS, IRI_SA,  IRI_SS,  IRI_SD,  IRI_SF,  IRI_SG,  IRI_SH,  IRI_SJ,  IRI_SK,  IRI_SL,  IRI_SSC, IRI_SQT, KC_TRNS,
        KC_TRNS, IRI_SZ,  IRI_SX,  IRI_SC,  IRI_SV,  IRI_SB,  IRI_SN,  IRI_SM,  IRI_SCM, IRI_SPR, IRI_SSL, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [IRI_LAYER_XFN] = LAYOUT(
        KC_TRNS, L_T_MD,  L_PTN,   L_BRI,   L_T_PTD, L_PSI,   L_RATI,  KC_TRNS, KC_TRNS, UC_M_LN, UC_M_WI, UC_M_OS, RESET,   KC_TRNS,
        KC_TRNS, IRI_FQ,  IRI_FW,  IRI_FE,  IRI_FR,  IRI_FT,  IRI_FY,  IRI_FU,  IRI_FI,  IRI_FO,  IRI_FP,  KC_PSCR, KC_SLCK, KC_PAUS,
        KC_TRNS, KC_TRNS, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, IRI_FZ,  IRI_FX,  IRI_FC,  IRI_FV,  IRI_FB,  IRI_FN,  IRI_FM,  IRI_FCM, IRI_FPR, IRI_FSL, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS, KC_PGDN, KC_PGUP),
};

led_instruction_t led_instructions[] = {
    {.flags = LED_FLAG_USE_ROTATE_PATTERN},
    {.end = 1},
};

static const uint16_t IRI_PERIOD_TAP        = 200;
static const uint16_t IRI_PERIOD_DOUBLE_TAP = 300;

#define IRI_IDX_KC_LSFT 0
#define IRI_IDX_KC_RSFT 1
#define IRI_IDX_IRI_LFN 2
#define IRI_IDX_IRI_RFN 3
#define IRI_N_TAP_MODS  4

#define IRI_TAPPED      0x8000u
#define IRI_TAP_TS_MASK 0x7fffu

static uint16_t iri_last_ts[IRI_N_TAP_MODS]     = {0, 0, 0, 0};
static uint16_t iri_last_tap_ts[IRI_N_TAP_MODS] = {0, 0, 0, 0};

#define IRI_BIT_KC_LSFT 0x1
#define IRI_BIT_KC_RSFT 0x2
#define IRI_BIT_IRI_LFN 0x1
#define IRI_BIT_IRI_RFN 0x2

static uint8_t iri_state_sft = 0x0, iri_state_fn = 0x0;
static uint8_t iri_locked_sft = 0x0, iri_locked_fn = 0x0;

void
rgb_matrix_init_user(void) {
    led_lighting_mode = LED_MODE_INDICATORS_ONLY;
}

_Static_assert(((LED_MODE_MAX_INDEX + 1) & LED_MODE_MAX_INDEX) == 0);

static void
iri_led_cycle_mode(keyrecord_t *record) {
    if (!record->event.pressed) {
        return;
    }
    led_lighting_mode += iri_state_sft == 0x0 ? 1 : -1;
    led_lighting_mode %= LED_MODE_MAX_INDEX + 1;
}

// _Static_assert((led_setups_count & (led_setups_count - 1)) == 0);

static void
iri_led_cycle_pattern(keyrecord_t *record) {
    if (!record->event.pressed) {
        return;
    }
    led_animation_id += iri_state_sft == 0x0 ? 1 : -1;
    led_animation_id %= led_setups_count;
}

static void
iri_led_mod_brightness(keyrecord_t *record) {
    if (!record->event.pressed) {
        return;
    }
    if (iri_state_sft == 0x0) {
        if (LED_GCR_STEP > LED_GCR_MAX - gcr_desired) {
            gcr_desired = LED_GCR_MAX;
        } else {
            gcr_desired += LED_GCR_STEP;
        }
    } else {
        if (LED_GCR_STEP > gcr_desired) {
            gcr_desired = 0;
        } else {
            gcr_desired -= LED_GCR_STEP;
        }
    }
}

static void
iri_led_cycle_direction(keyrecord_t *record) {
    static int8_t scroll_effect = 0;
    if (!record->event.pressed) {
        return;
    }
    switch (scroll_effect += iri_state_sft == 0x0 ? 1 : -1) {
    break;case 1: // Patterns with scroll move horizontal (Right to left)
        led_animation_direction = 1;
        led_animation_orientation = 0;
        led_animation_circular = 0;
    break;case 2: // Patterns with scroll move vertical (Top to bottom)
        led_animation_direction = 1;
        led_animation_orientation = 1;
        led_animation_circular = 0;
    break;case 3: // Patterns with scroll move vertical (Bottom to top)
        led_animation_direction = 0;
        led_animation_orientation = 1;
        led_animation_circular = 0;
    break;case 4: // Patterns with scroll explode from center
        led_animation_direction = 0;
        led_animation_orientation = 0;
        led_animation_circular = 1;
    break;case -1:
        scroll_effect = 5;
    /*fallthrough*/case 5: // Patterns with scroll implode on center
        led_animation_direction = 1;
        led_animation_orientation = 0;
        led_animation_circular = 1;
    break;default: //Patterns with scroll move horizontal (Left to right)
        scroll_effect = 0;
        led_animation_direction = 0;
        led_animation_orientation = 0;
        led_animation_circular = 0;
    }
}

static void
iri_led_mod_speed(keyrecord_t *record) {
    if (!record->event.pressed) {
        return;
    }
    if (iri_state_sft == 0x0) {
        led_animation_speed += 0.25;
    } else {
        led_animation_speed -= 0.25;
        if (led_animation_speed < 0) {
            led_animation_speed = 0;
        }
    }
}

static void
iri_led_mod_ratio(keyrecord_t *record) {
    if (!record->event.pressed) {
        return;
    }
    if (iri_state_sft == 0x0) {
        led_ratio_brightness += 0.1;
        if (led_ratio_brightness > 2.0) {
            led_ratio_brightness = 2.0;
        }
    } else {
        led_ratio_brightness -= 0.1;
        if (led_ratio_brightness < 0.0) {
            led_ratio_brightness = 0.0;
        }
    }
}

static bool
iri_was_double_tapped(uint16_t keycode, keyrecord_t *record, size_t idx) {
    // assert(!record->event.pressed);
    if ((uint16_t)(record->event.time - iri_last_ts[idx]) > IRI_PERIOD_TAP) {
        iri_last_tap_ts[idx] = 0;
        return false;
    }
    uint16_t lt = iri_last_tap_ts[idx];
    iri_last_tap_ts[idx] = record->event.time | IRI_TAPPED;
    if ((lt & IRI_TAPPED) == 0) {
        return false;
    }
    uint16_t d = (record->event.time - lt) & IRI_TAP_TS_MASK;
    if (d > IRI_PERIOD_DOUBLE_TAP) {
        return false;
    }
    return true;
}

static void __attribute__((always_inline))
iri_process_kc_lsft(keyrecord_t *record) {
    if (record->event.pressed) {
        iri_state_sft |= IRI_BIT_KC_LSFT;
    } else if (iri_was_double_tapped(KC_LSFT, record, IRI_IDX_KC_LSFT)) {
        iri_locked_sft |= IRI_BIT_KC_LSFT;
    } else if (iri_locked_sft == 0x3) {
        iri_state_sft = iri_locked_sft = 0x0;
    } else {
        iri_state_sft  &= ~IRI_BIT_KC_LSFT;
        iri_locked_sft &= ~IRI_BIT_KC_LSFT;
    }
    iri_last_ts[IRI_IDX_KC_LSFT] = record->event.time;
}

static void __attribute__((always_inline))
iri_process_kc_rsft(keyrecord_t *record) {
    if (record->event.pressed) {
        iri_state_sft |= IRI_BIT_KC_RSFT;
    } else if (iri_was_double_tapped(KC_RSFT, record, IRI_IDX_KC_RSFT)) {
        iri_locked_sft |= IRI_BIT_KC_RSFT;
    } else if (iri_locked_sft == 0x3) {
        iri_state_sft = iri_locked_sft = 0x0;
    } else {
        iri_state_sft  &= ~IRI_BIT_KC_RSFT;
        iri_locked_sft &= ~IRI_BIT_KC_RSFT;
    }
    iri_last_ts[IRI_IDX_KC_RSFT] = record->event.time;
}

static void __attribute__((always_inline))
iri_process_iri_lfn(keyrecord_t *record) {
    if (record->event.pressed) {
        iri_state_fn |= IRI_BIT_IRI_LFN;
    } else if (iri_was_double_tapped(IRI_LFN, record, IRI_IDX_IRI_LFN)) {
        iri_locked_fn |= IRI_BIT_IRI_LFN;
    } else if (iri_locked_fn == 0x3) {
        iri_state_fn = iri_locked_fn = 0x0;
    } else {
        iri_state_fn  &= ~IRI_BIT_IRI_LFN;
        iri_locked_fn &= ~IRI_BIT_IRI_LFN;
    }
    iri_last_ts[IRI_IDX_IRI_LFN] = record->event.time;
}

static void __attribute__((always_inline))
iri_process_iri_rfn(keyrecord_t *record) {
    if (record->event.pressed) {
        iri_state_fn |= IRI_BIT_IRI_RFN;
    } else if (iri_was_double_tapped(IRI_LFN, record, IRI_IDX_IRI_RFN)) {
        iri_locked_fn |= IRI_BIT_IRI_RFN;
    } else if (iri_locked_fn == 0x3) {
        iri_state_fn = iri_locked_fn = 0x0;
    } else {
        iri_state_fn  &= ~IRI_BIT_IRI_RFN;
        iri_locked_fn &= ~IRI_BIT_IRI_RFN;
    }
    iri_last_ts[IRI_IDX_IRI_RFN] = record->event.time;
}

static void __attribute__((always_inline))
iri_set_layers(void) {
    switch (iri_state_sft) {
    break;case 0x3:
        register_code(KC_LSFT);
        layer_on(IRI_LAYER_XSFT);
    break;case 0x0:
        layer_off(IRI_LAYER_XSFT);
        unregister_code(KC_LSFT);
    break;default:
        layer_off(IRI_LAYER_XSFT);
        register_code(KC_LSFT);
    }
    switch (iri_state_fn) {
    break;case 0x3:
        layer_on(IRI_LAYER_FN);
        layer_on(IRI_LAYER_XFN);
    break;case 0x0:
        layer_off(IRI_LAYER_XFN);
        layer_off(IRI_LAYER_FN);
    break;default :
        layer_off(IRI_LAYER_XFN);
        layer_on(IRI_LAYER_FN);
    }
}

bool
process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    break;case L_T_MD:
        iri_led_cycle_mode(record);
        return false;
    break;case L_PTN:
        iri_led_cycle_pattern(record);
        return false;
    break;case L_BRI:
        iri_led_mod_brightness(record);
        return false;
    break;case L_T_PTD:
        iri_led_cycle_direction(record);
        return false;
    break;case L_PSI:
        iri_led_mod_speed(record);
        return false;
    break;case L_RATI:
        iri_led_mod_ratio(record);
        return false;
    break;case KC_LSFT: iri_process_kc_lsft(record);
    break;case KC_RSFT: iri_process_kc_rsft(record);
    break;case IRI_LFN: iri_process_iri_lfn(record);
    break;case IRI_RFN: iri_process_iri_rfn(record);
    break;default     : return true;
    }
    iri_set_layers();
    return false;
}

void
housekeeping_task_user(void) {
    uint16_t ts = timer_read() | 1;
    for (size_t i = 0; i < IRI_N_TAP_MODS; ++i) {
        if ((iri_last_tap_ts[i] & IRI_TAPPED) == 0) {
            continue;
        }
        uint16_t d = (ts - iri_last_tap_ts[i]) & IRI_TAP_TS_MASK;
        if (d > IRI_PERIOD_DOUBLE_TAP) {
            iri_last_tap_ts[i] = 0;
        }
    }
}

void
suspend_power_down_user(void) {
    for (size_t i = 0; i < IRI_N_TAP_MODS; ++i) {
        iri_last_tap_ts[i] = 0;
    }
}
