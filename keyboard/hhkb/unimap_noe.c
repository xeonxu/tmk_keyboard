/*
Copyright 2016 Jun Wako <wakojun@gmail.com>

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
#include "unimap_trans.h"


/* id for user defined functions */
enum function_id {
    LSHIFT_LPAREN,
};

enum macro_id {
    HELLO,
    VOLUP,
    ALT_TAB,
    CMD_TAB,
};

enum keymap_layout {
    BASE = 0,
    DVORAK,
    TENKEY,
    MOUSE,
    HHKB,
    HHKB_EXT,
};

#define AC_L0         ACTION_LAYER_MOMENTARY(BASE)
#define AC_L1         ACTION_LAYER_MOMENTARY(HHKB)
#define AC_MENU2      ACTION_LAYER_TAP_KEY(HHKB_EXT, KC_MENU)
/* #define AC_SLS3       ACTION_LAYER_TAP_KEY(3, KC_SLSH) */
#define AC_SPC4       ACTION_LAYER_TAP_KEY(MOUSE, KC_SPC)

#define AC_BASE0 ACTION_DEFAULT_LAYER_SET(BASE)
#define AC_HHKB1 ACTION_DEFAULT_LAYER_SET(HHKB)
/* #define AC_DFLTL2 ACTION_DEFAULT_LAYER_SET(HHKB_EXT) */
#define AC_TEN3 ACTION_DEFAULT_LAYER_SET(TENKEY)
#define AC_MSE4 ACTION_DEFAULT_LAYER_SET(MOUSE)
#define AC_DVRK5 ACTION_DEFAULT_LAYER_SET(DVORAK)

#define AC_APSW   ACTION_MODS_KEY(MOD_LGUI, KC_TAB)
/* #define AC_LALT_RO   ACTION_MODS_TAP_KEY(MOD_LALT, KC_RO) */
/* #define AC_RGUI_HENK   ACTION_MODS_TAP_KEY(MOD_RGUI, KC_HENK) */
/* #define AC_RALT_MHEN   ACTION_MODS_TAP_KEY(MOD_RALT, KC_MHEN) */

#define AC_BACK    ACTION_MODS_KEY(MOD_LALT, KC_LEFT)
#define AC_FRWD    ACTION_MODS_KEY(MOD_LALT, KC_RIGHT)
#define AC_RCTL_ENT    ACTION_MODS_TAP_KEY(MOD_RCTL, KC_ENT)

#define AC_LSFTONE  ACTION_MODS_ONESHOT(MOD_LSFT)
#define AC_RSFTONE  ACTION_MODS_ONESHOT(MOD_RSFT)

// Function: LShift with tap '('
#define AC_LPRN     ACTION_FUNCTION_TAP(LSHIFT_LPAREN)
// Macro: say hello
#define AC_HELO     ACTION_MACRO(HELLO)

#ifdef KEYMAP_SECTION_ENABLE
const action_t actionmaps[][UNIMAP_ROWS][UNIMAP_COLS] __attribute__ ((section (".keymap.keymaps"))) = {
#else
const action_t actionmaps[][UNIMAP_ROWS][UNIMAP_COLS] PROGMEM = {
#endif
    [BASE] = UNIMAP_HHKB(
    ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSLS,GRV,
    TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,     BSPC,
    LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     RCTL_ENT,
    LSFT,     Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,     RSFT,MENU2,
         LALT,L1,               SPC4,                    RGUI,RALT),

    [HHKB] = UNIMAP_HHKB(
    PWR, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, INS, DEL,
    APSW,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PSCR,SLCK,PAUS,UP,  TRNS,     TRNS,
    TRNS,VOLD,VOLU,MUTE,F20,TRNS,PAST,PSLS,HOME,PGUP,LEFT,RGHT,          PENT,
    TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,PPLS,PMNS,END, PGDN,DOWN,     TRNS, TRNS,
         TRNS,TRNS,               TRNS,                    TRNS,TRNS),

    [HHKB_EXT] = UNIMAP_HHKB(
    PWR, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, INS, DEL,
    CAPS,BASE0,HHKB1,TEN3,MSE4,DVRK5,TRNS,TRNS,PSCR,SLCK,PAUS,UP,  TRNS,     TRNS,
    TRNS,VOLD,VOLU,MUTE,F20,TRNS,PAST,PSLS,HOME,PGUP,LEFT,RGHT,          PENT,
    TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,PPLS,PMNS,END, PGDN,DOWN,     TRNS, TRNS,
         TRNS,TRNS,               TRNS,                    TRNS,TRNS),

    /* Layer 3: Tenkey layer
     * ,-----------------------------------------------------------------------------------------.
     * | Esc |     |     |     |     |     |     |     |     |     |  /  |  *  |  -  |     | BSp |
     * |-----------------------------------------------------------------------------------------|
     * |        |     |     |     |     |     |     |     |     |  7  |  8  |  9  |  +  |        |
     * |-----------------------------------------------------------------------------------------|
     * |          |     |     |     |     |     |     |     |     |  4  |  5  |  6  |   Enter    |
     * |-----------------------------------------------------------------------------------------|
     * |             |     |     |     |     |     |     |     |  1  |  2  |  3  |    +    | Fn0 |
     * `-----------------------------------------------------------------------------------------'
     *           |     |        |              SpaceFN              |   0    |  .  |
     *           `-----------------------------------------------------------------'
     */
    [TENKEY] = UNIMAP_HHKB(
    ESC, NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  PSLS,PAST,PMNS,NO,  BSPC, \
    TRNS,NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  KP_7,KP_8,KP_9,PPLS,NO, \
    TRNS,NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  KP_4,KP_5,KP_6,PENT, \
    TRNS,NO,  NO,  NO,  NO,  NO,  NO,  NO,  KP_1,KP_2,KP_3,PPLS,MENU2, \
          TRNS,L1,                TRNS,                 KP_0,PDOT),

    [MOUSE] = UNIMAP_HHKB(
    ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, INS, DEL,
    TAB, NO,  NO,  NO,  NO,  NO,  NO,BTN1,BTN2,BTN3,BTN4,BACK,FRWD,     TRNS,
    LCTL,NO,  ACL0,ACL1,ACL2, NO, MS_L,MS_D,MS_U,MS_R,TRNS,NO,            ENT,
    LSFT,     NO,  NO,  NO,  NO,  NO,WH_L,WH_D,WH_U,WH_R,NO,       RSFT,MENU2,
         TRNS,L1,               TRNS,                    TRNS,TRNS),
    /* Layer 5: Dvorak Layer
     * ,-----------------------------------------------------------------------------------------.
     * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  [  |  ]  |  `  | BSp |
     * |-----------------------------------------------------------------------------------------|
     * |  Tab   |  '  |  ,  |  .  |  P  |  Y  |  F  |  G  |  C  |  R  |  L  |  /  |  =  |   \    |
     * |-----------------------------------------------------------------------------------------|
     * | Control  |  A  |  O  |  E  |  U  |  I  |  D  |  H  |  T  |  N  |  S  |  -  |   Enter    |
     * |-----------------------------------------------------------------------------------------|
     * |    Shift    |  ;  |  Q  |  J  |  K  |  X  |  B  |  M  |  W  |  V  |  Z  |  Shift  | Fn0 |
     * `-----------------------------------------------------------------------------------------'
     *           |LAlt |  LGui  |              SpaceFN              |  RGui  |RAlt |
     *           `-----------------------------------------------------------------'
     */
    [DVORAK] = UNIMAP_HHKB(
    ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   LBRC,RBRC,BSLS, GRV, \
    TAB, QUOT,COMM,DOT, P,   Y,   F,   G,   C,   R,   L,   SLSH,EQL, BSPC, \
    TRNS,A,   O,   E,   U,   I,   D,   H,   T,   N,   S,   MINS,ENT, \
    TRNS,SCLN,Q,   J,   K,   X,   B,   M,   W,   V,   Z,   TRNS,MENU2, \
       TRNS,L1,                SPC4,                 TRNS,TRNS),
};


/*
 * Macro definition
 */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case HELLO:
            return (record->event.pressed ?
                    MACRO( I(0), T(H), T(E), T(L), T(L), W(255), T(O), END ) :
                    MACRO_NONE );
        case VOLUP:
            return (record->event.pressed ?
                    MACRO( D(VOLU), U(VOLU), END ) :
                    MACRO_NONE );
        case ALT_TAB:
            return (record->event.pressed ?
                    MACRO( D(LALT), D(TAB), END ) :
                    MACRO( U(TAB), END ));
        case CMD_TAB:
            return (record->event.pressed ?
                    MACRO( D(LGUI), D(TAB), END ) :
                    MACRO( U(TAB), END ));
    }
    return MACRO_NONE;
}



/*
 * user defined action function
 */
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    if (record->event.pressed) dprint("P"); else dprint("R");
    dprintf("%d", record->tap.count);
    if (record->tap.interrupted) dprint("i");
    dprint("\n");

    switch (id) {
        case LSHIFT_LPAREN:
            // Shift parentheses example: LShft + tap '('
            // http://stevelosh.com/blog/2012/10/a-modern-space-cadet/#shift-parentheses
            // http://geekhack.org/index.php?topic=41989.msg1304899#msg1304899
            if (record->event.pressed) {
                if (record->tap.count > 0 && !record->tap.interrupted) {
                    if (record->tap.interrupted) {
                        dprint("tap interrupted\n");
                        register_mods(MOD_BIT(KC_LSHIFT));
                    }
                } else {
                    register_mods(MOD_BIT(KC_LSHIFT));
                }
            } else {
                if (record->tap.count > 0 && !(record->tap.interrupted)) {
                    add_weak_mods(MOD_BIT(KC_LSHIFT));
                    send_keyboard_report();
                    register_code(KC_9);
                    unregister_code(KC_9);
                    del_weak_mods(MOD_BIT(KC_LSHIFT));
                    send_keyboard_report();
                    record->tap.count = 0;  // ad hoc: cancel tap
                } else {
                    unregister_mods(MOD_BIT(KC_LSHIFT));
                }
            }
            break;
    }
}
