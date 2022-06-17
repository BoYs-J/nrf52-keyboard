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
#define AC_FN1    ACTION_LAYER_TAP(1, KC_SPC)
#define AC_FN2    ACTION_LAYER_TAP(2, KC_DEL)

/* 
 * @brief 按键映射
 * 下面的按键映射与按键布局的第一组实际布局对应
 */
const action_t actionmaps[][MATRIX_ROWS][MATRIX_COLS] = { 
	[0] = ACTIONMAP_ROT(
        TAB, Q, W, E, R, T, Y, U, I, O, P, BSPC,
        CAPS, A, S, D, F, G, H, J, K, L, ENT,
        LSFT, Z, X, C, V, B, N, M, COMM, DOT, RSFT,
        LCTL, LGUI, LALT, FN1, SPC,FN2, RALT, RCTL,
		VOLU, VOLD,  ESC),
		
	[1] = ACTIONMAP(
        ESC, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, BSPC,
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS),

	[2] = ACTIONMAP(
        F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, MUTE, VOLD, VOLU, TRNS, TRNS,
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS),
};

#define NO NO_LED

led_config_t g_led_config = {
    {
        // Key Matrix to LED Index
        {  0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,   NO },
        { 22,21,20,19,18,17,16,15,14,13,12,   NO },
        { 23,24,25,26,27,28,29,30,31,32,33,   NO },
        { 41,40,39,38,NO,37,NO,36,35,34,11,   0  },
    },
    { // LED Index to Physical Position
        { 12, 5 },{ 33, 5 },{ 54, 5 },{ 75, 5 },{ 96, 5 },{ 117, 5 },{ 138, 5 },{ 159, 5 },{ 180, 5 },{ 201, 5 },{ 222, 5 },{ 243, 5 },
        { 235, 26 },{ 206, 26 },{ 185, 26 },{ 164, 26 },{ 143, 26 },{ 122, 26 },{ 101, 26 },{ 80, 26 },{ 59, 26 },{ 38, 26 },{ 15, 26 },   
		{ 20, 47 }, { 49, 47 },{ 70, 47 },{ 91, 47 },{ 112, 47 },{ 133, 47 },{ 154, 47 }, { 175, 47 },{ 196, 47 },{ 217, 47 },{ 240, 47 }, 
        { 240, 68 },{ 217, 68 },{ 197, 68 },{ 151, 68 },{ 98, 68 },{ 61, 68 },{ 38, 68 },{ 15, 68 }, 
	 },
    { // LED Index to Flag
        255, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
		4  , 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
		4  , 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
		4  , 4, 4, 4, 4, 4, 4, 4 }
};
