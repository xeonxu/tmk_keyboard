/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "keymap_common.h"
#include "macro_str.h"


/* ,---.   ,---------------. ,---------------. ,---------------. ,-----------.
 * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau|
 * `---'   `---------------' `---------------' `---------------' `-----------'
 * ,-----------------------------------------------------------. ,-----------. ,---------------.
 * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|    Bsp| |Ins|Hom|PgU| |NmL|  /|  *|  -|
 * |-----------------------------------------------------------| |-----------| |---------------|
 * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | |Del|End|PgD| |  7|  8|  9|  +|
 * |-----------------------------------------------------------| `-----------' |-----------|   |
 * |CapsL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  Return|               |  4|  5|  6|  +|
 * |-----------------------------------------------------------|     ,---.     |---------------|
 * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /|Shift     |     |Up |     |  1|  2|  3|   |
 * |-----------------------------------------------------------| ,-----------. |-----------|   |
 * |Ctl|Gui|Alt|           Space               |Alt|App  |Ctl  | |Lef|Dow|Rig| |      0|  .|Ent|
 * `-----------------------------------------------------------' `-----------' `---------------'
 */
#define KEYMAP_NOE( \
    K29,K3A,K3B,K3C,K3D,K3E,K3F,K40,K41,K42,K43,K44,K45,      K46,K47,K48,                   \
    K35,K1E,K1F,K20,K21,K22,K23,K24,K25,K26,K27,K2D,K2E,K2A,  K49,K4A,K4B,  K53,K54,K55,K56, \
    K2B,K14,K1A,K08,K15,K17,K1C,K18,K0C,K12,K13,K2F,K30,K31,  K4C,K4D,K4E,  K5F,K60,K61,     \
    K39,K04,K16,K07,K09,K0A,K0B,K0D,K0E,K0F,K33,K34,    K28,                K5C,K5D,K5E,K57, \
    KE1,K1D,K1B,K06,K19,K05,K11,K10,K36,K37,K38,        KE5,      K52,      K59,K5A,K5B,     \
    KE0,KE3,KE2,        K2C,                KE6,K65,    KE4,  K50,K51,K4F,  K62,    K63,K58  \
) KEYMAP_ALL( \
            NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO,                                               \
    K29,    K3A,K3B,K3C,K3D,K3E,K3F,K40,K41,K42,K43,K44,K45,      K46,K47,K48,  NO, NO, NO, NO,  NO,      \
    K35,K1E,K1F,K20,K21,K22,K23,K24,K25,K26,K27,K2D,K2E,NO, K2A,  K49,K4A,K4B,  K53,K54,K55,K56, NO, NO,  \
    K2B,K14,K1A,K08,K15,K17,K1C,K18,K0C,K12,K13,K2F,K30,    K31,  K4C,K4D,K4E,  K5F,K60,K61,K57, NO, NO,  \
    K39,K04,K16,K07,K09,K0A,K0B,K0D,K0E,K0F,K33,K34,    NO, K28,                K5C,K5D,K5E,NO,  NO, NO,  \
    KE1,NO, K1D,K1B,K06,K19,K05,K11,K10,K36,K37,K38,    NO, KE5,      K52,      K59,K5A,K5B,NO,  NO, NO,  \
    KE0,KE3,KE2,NO, NO,     K2C,    NO, NO, NO, KE6, NO,K65,KE4,  K50,K51,K4F,  K62,    K63,K58, NO, NO   \
)


#define KEYMAP_HHKB( \
    K29,K1E,K1F,K20,K21,K22,K23,K24,K25,K26,K27,K2D,K2E,K2A,\
    K2B,K14,K1A,K08,K15,K17,K1C,K18,K0C,K12,K13,K2F,K30,K31,\
    K39,K04,K16,K07,K09,K0A,K0B,K0D,K0E,K0F,K33,K34,    K28,\
    KE1,K1D,K1B,K06,K19,K05,K11,K10,K36,K37,K38,        KE5,\
    KE0,KE3,KE2,        K2C,                KE6,K65,    KE4 \
) KEYMAP_ALL( \
            NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO,                                               \
    K29,    NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO,       NO, NO, NO,   NO, NO, NO, NO, NO,      \
    NO, K1E,K1F,K20,K21,K22,K23,K24,K25,K26,K27,K2D,K2E,NO, K2A,  NO, NO, NO,   NO, NO, NO, NO, NO, NO,  \
    K2B,K14,K1A,K08,K15,K17,K1C,K18,K0C,K12,K13,K2F,K30,    K31,  NO, NO, NO,   NO, NO, NO, NO, NO, NO,  \
    K39,K04,K16,K07,K09,K0A,K0B,K0D,K0E,K0F,K33,K34,    NO, K28,                NO, NO, NO, NO, NO, NO,  \
    KE1,NO, K1D,K1B,K06,K19,K05,K11,K10,K36,K37,K38,    NO, KE5,       NO,      NO, NO, NO, NO, NO, NO,  \
    KE0,KE3,KE2,NO, NO,     K2C,    NO, NO, NO, KE6, NO,K65,KE4,  NO, NO, NO,   NO,     NO, NO, NO, NO   \
)

enum keymap_layout {
    SAFE = 0,
    BASE,
    PSEUDO_US,
    IOS,
    DVORAK,
    TENKEY,
    MOUSE,
    HHKB,
    HHKB_EXT,
    HHKB_IOS,
    LAYER,
};

const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
/* 0: plain Qwerty without layer switching
 * ,---.   ,---------------. ,---------------. ,---------------. ,-----------.
 * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau|
 * `---'   `---------------' `---------------' `---------------' `-----------'
 * ,-----------------------------------------------------------. ,-----------. ,---------------.
 * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|    Bsp| |Ins|Hom|PgU| |NmL|  /|  *|  -|
 * |-----------------------------------------------------------| |-----------| |---------------|
 * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | |Del|End|PgD| |  7|  8|  9|  +|
 * |-----------------------------------------------------------| `-----------' |-----------|   |
 * |CapsL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  Return|               |  4|  5|  6|  +|
 * |-----------------------------------------------------------|     ,---.     |---------------|
 * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |     |Up |     |  1|  2|  3|   |
 * |-----------------------------------------------------------| ,-----------. |-----------|   |
 * |Ctl|Gui|Alt|           Space               |Alt|App  |Ctl  | |Lef|Dow|Rig| |      0|  .|Ent|
 * `-----------------------------------------------------------' `-----------' `---------------'
 */
  [SAFE]=KEYMAP(
		ESC,      F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,      PSCR,SLCK,BRK,
		GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,     INS, HOME,PGUP,    NLCK,PSLS,PAST,PMNS,
		TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,     DEL, END, PGDN,    P7,  P8,  P9,
		CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,                         P4,  P5,  P6,  PPLS,
		LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,          RSFT,          UP,           P1,  P2,  P3,
		FN4, LGUI,LALT,          SPC,                     RALT,RGUI,APP, RCTL,     LEFT,DOWN,RGHT,    P0,       PDOT,PENT
		),

  [BASE]=KEYMAP_HHKB(
		     ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, FN2, \
		     TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,    FN5,RBRC,BSPC, \
		     LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L, FN7,    FN6,     FN12, \
		     LSFT,Z,   X,   C,   V,   B,   N,   M,COMM, DOT,SLSH,             RSFT, \
		     FN4, FN8,FN0,                FN3,                 RGUI,FN10, FN1
		     ),


  [HHKB]=KEYMAP_HHKB(
		     PWR, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, INS,  \
		     CAPS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PSCR,SLCK,PAUS, UP, TRNS, DEL, \
		     TRNS,VOLD,VOLU,MUTE,TRNS,TRNS,PAST,PSLS,HOME,PGUP,LEFT,RGHT,FN12, \
		     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PPLS,PMNS,END, PGDN,DOWN,     TRNS, \
		     FN4, TRNS,TRNS,                FN3,               TRNS,TRNS,TRNS
		     ),
  [MOUSE]=KEYMAP_HHKB(
		     ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, INS,
		     TAB, NO,  NO,  NO,  NO,  NO,  NO,BTN1,BTN3,BTN2,NO,BTN4,BTN5,    TRNS,
		     LCTL,NO,  ACL0,ACL1,ACL2, NO, MS_L,MS_D,MS_U,MS_R,TRNS,NO,       FN12,
		     LSFT,     NO,  NO,  NO,  NO,  NO,WH_L,WH_D,WH_U,WH_R,NO,         TRNS,
		     CAPS, FN4,FN1,                FN3,                 RGUI,FN5, CAPS
		     ),

  [LAYER]=KEYMAP_HHKB(
		     PWR, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, INS,  \
		     CAPS,FN11,FN12,FN13,TRNS,TRNS,TRNS,FN14,PSCR,SLCK,PAUS, UP, TRNS, DEL, \
		     TRNS,VOLD,VOLU,MUTE,TRNS,TRNS,PAST,PSLS,HOME,PGUP,LEFT,RGHT,FN12, \
		     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PPLS,PMNS,END, PGDN,DOWN,     TRNS, \
		     FN4, TRNS,TRNS,                FN3,               TRNS,TRNS,TRNS
		      ),

};


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch (id) {
    case 0:
      return (record->event.pressed ?
        S_SYSPWD :
        MACRO_NONE );
  }
  return MACRO_NONE;
}

const action_t fn_actions[] PROGMEM = {
  [0]   = ACTION_LAYER_TAP_KEY(HHKB, KC_MHEN),
  [1]   = ACTION_LAYER_TAP_KEY(HHKB, KC_KANA),
  [2]   = ACTION_LAYER_TAP_KEY(LAYER, KC_BSLS),
  [3]   = ACTION_LAYER_TAP_KEY(MOUSE, KC_SPACE),
  [4]   = ACTION_LAYER_TAP_KEY(LAYER, KC_LCTL),
  [5]   = ACTION_MODS_TAP_KEY(MOD_LSFT | MOD_LCTL | MOD_LALT | MOD_LGUI, KC_LBRC),
  [6]   = ACTION_MODS_TAP_KEY(MOD_LCTL | MOD_LALT | MOD_LGUI, KC_QUOT),
  [7]   = ACTION_MODS_TAP_KEY(MOD_LCTL | MOD_LALT | MOD_LSFT, KC_SCLN),
  [8]   = ACTION_MODS_TAP_KEY(MOD_LALT, KC_ZKHK),
  [10]  = ACTION_MODS_TAP_KEY(MOD_RALT, KC_HENK),
  [11]  = ACTION_DEFAULT_LAYER_SET(BASE),
  [12]  = ACTION_DEFAULT_LAYER_SET(HHKB),
  [13]  = ACTION_DEFAULT_LAYER_SET(MOUSE),
  [14]  = ACTION_DEFAULT_LAYER_SET(SAFE),
  /* [11] = ACTION_DEFAULT_LAYER_SET(TENKEY), */
  /* [12] = ACTION_DEFAULT_LAYER_SET(DVORAK), */
  [20] = ACTION_MODS_TAP_KEY(MOD_RCTL, KC_ENT),
  [21] = ACTION_MACRO(0),
};

