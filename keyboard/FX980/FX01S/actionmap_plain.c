/*
 Copyright (C) 2021,2022 Geno <geno@live.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "actionmap.h"
#include "action_code.h"
#include "actionmap_common.h"
#include "keyboard_fn.h"
#include "rgb_matrix.h"
#include "rgb_matrix_types.h"
#include "user_fn.h"

/* 
 * 定义需使用的FN按键
 */
#define AC_FN0 ACTION_LAYER_TOGGLE(1)
#define AC_FN1 ACTION_LAYER_TOGGLE(1)

#define AC_FN2 ACTION_LAYER_TAP(2, KC_MENU)
#define AC_FN3 ACTION_LAYER_TAP(2, KC_MENU)

/* 
 * @brief 按键映射
 * 下面的按键映射与按键布局的第一组实际布局对应
 */
const action_t actionmaps[][MATRIX_ROWS][MATRIX_COLS] = { 
	[0] = ACTIONMAP_ROT(
        ESC, F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, HOME, END, FN0, 
	GRV, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, MINS, EQL, BSPC, INS, NLCK, PSLS, PAST, PMNS, 
	TAB, Q, W, E, R, T, Y, U, I, O, P, LBRC, RBRC, BSLS, DEL, P7, P8, P9, PPLS, 
	CAPS, A, S, D, F, G, H, J, K, L, SCLN, QUOT, ENT, P4, P5, P6,  
	LSFT, Z, X, C, V, B, N, M, COMM, DOT, SLSH, RSFT, UP, P1, P2, P3, PENT, 
	LCTL, LGUI, LALT, SPC, RALT, RGUI, FN2, RCTL, LEFT, DOWN, RGHT, P0, PDOT, VOLD, VOLU),

	[1] = ACTIONMAP_ROT(
        ESC, F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, HOME, END, FN1, 
	GRV, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, MINS, EQL, BSPC, INS, NLCK, PSLS, PAST, PMNS, 
	TAB, Q, W, E, R, T, Y, U, I, O, P, LBRC, RBRC, BSLS, DEL, P7, P8, P9, PPLS, 
	CAPS, A, S, D, F, G, H, J, K, L, SCLN, QUOT, ENT, P4, P5, P6,  
	LSFT, Z, X, C, V, B, N, M, COMM, DOT, SLSH, RSFT, UP, P1, P2, P3, PENT, 
	LCTL, LGUI, LALT, SPC, RALT, RGUI, FN3, RCTL, LEFT, DOWN, RGHT, P0, PDOT, BRTD, BRTI),

	[2] = ACTIONMAP(
        ESC, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, 
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, 
        TRNS, BTN1, MS_U, BTN2, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, 
        TRNS, MS_L, MS_D, MS_R, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, 
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, WH_U, TRNS, TRNS, TRNS, TRNS,  
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, WH_L, WH_D, WH_R, TRNS, TRNS),

	[3] = ACTIONMAP(
        ESC, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, 
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, 
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, 
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, 
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, 
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS),
};

#define NO NO_LED

led_config_t g_led_config = {
    {
        // Key Matrix to LED Index
        { 0, 	1,	2,	3,	4,	5,	6,	7,	8,	9, NO_LED },
        { 17,	18,	19,	20,	21,	22,	23,	24,	25,	26, NO_LED },
        { 36,	37,	38,	39,	40,	41,	42,	43,	44,	45, NO_LED },
        { 54,	55,	56,	57,	58,	59,	60,	61,	62,	63, NO_LED },
        { 71,	72,	73,	74,	75,	76,	77,	78,	79,	80, NO_LED },
        { 88,	89,	90,	92,	94,	95,	96,	97,	98,	99, NO_LED },
        { 10,	11,	12,	13,	14,	NO_LED,	33,	34,	35,	70, NO_LED },
        { 27,	28,	29,	30,	31,	32,	51,	52,	53,	69, NO_LED },
        { 46,	47,	48,	49,	50,	67,	68,	85,	86,	87, NO_LED },
        { 64,	65,	81,	82,	66,	83,	84,	100,	101,	102, NO_LED },
    },
    { // LED Index to Physical Position
         { 0, 0 }, { 23, 0 }, { 35, 0 }, { 46, 0 }, { 58, 0 }, { 75, 0 }, { 86, 0 }, { 98, 0 }, { 109, 0 }, { 127, 0 }, { 138, 0 }, { 150, 0 }, { 161, 0 }, { 175, 0 }, { 190, 0 }, { 201, 0 }, { 213, 0 }, 
         { 0, 14 }, { 12, 14 }, { 23, 14 }, { 35, 14 }, { 46, 14 }, { 58, 14 }, { 69, 14 }, { 81, 14 }, { 92, 14 }, { 104, 14 }, { 115, 14 }, { 127, 14 }, { 138, 14 }, { 155, 14 }, { 175, 14 }, { 190, 14 }, { 201, 14 }, { 213, 14 }, { 224, 14 }, 
         { 3, 25 }, { 17, 25 }, { 29, 25 }, { 40, 25 }, { 52, 25 }, { 63, 25 }, { 75, 25 }, { 86, 25 }, { 98, 25 }, { 109, 25 }, { 121, 25 }, { 132, 25 }, { 144, 25 }, { 158, 25 }, { 175, 25 }, { 190, 25 }, { 201, 25 }, { 213, 25 }, 
         { 4, 36 }, { 20, 36 }, { 32, 36 }, { 43, 36 }, { 55, 36 }, { 66, 36 }, { 78, 36 }, { 89, 36 }, { 101, 36 }, { 112, 36 }, { 124, 36 }, { 135, 36 }, { 154, 36 }, { 190, 36 }, { 201, 36 }, { 213, 36 }, { 224, 31 }, 
         { 7, 47 }, { 26, 47 }, { 37, 47 }, { 49, 47 }, { 60, 47 }, { 72, 47 }, { 83, 47 }, { 95, 47 }, { 106, 47 }, { 118, 47 }, { 129, 47 }, { 151, 47 }, { 175, 47 }, { 190, 47 }, { 201, 47 }, { 213, 47 }, { 224, 53 }, 
         { 1, 58 }, { 16, 58 }, { 30, 58 }, { 52, 58 }, { 73, 58 }, { 94, 58 }, { 115, 58 }, { 127, 58 }, { 138, 58 }, { 150, 58 }, { 164, 58 }, { 175, 58 }, { 187, 58 }, { 201, 58 }, { 213, 58 }, 
         
         { 6, 31 }, { 6, 42 }, { 6, 53 }, { 30, 53 }, { 53, 53 }, { 77, 53 }, { 100, 53 }, { 124, 53 }, { 147, 53 }, { 171, 53 }, { 195, 53 }, { 218, 53 }, { 218, 42 }, 
         { 6, 19 }, { 6, 7 }, { 30, 7 }, { 53, 7 }, { 77, 7 }, { 100, 7 }, { 124, 7 }, { 147, 7 }, { 171, 7 }, { 195, 7 }, { 218, 7 }, { 218, 19 }, { 218, 31 }, 

    },
    { // LED Index to Flag
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 

	4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
	4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 

 },
};
