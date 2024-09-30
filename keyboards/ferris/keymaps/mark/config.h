/*
Copyright 2020 Pierre Chevalier <pierrechevalier83@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published bynnnn
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// The time in milliseconds of when a tap becomes a hold
#undef TAPPING_TERM
#define TAPPING_TERM 250


// The time in milliseconds for a double tap and hold to output string of letters
// is you wanted to type llllllllllll, but had LSFT_T(KC_L), you need to tap L twice
// But the second time needs to occur in this window - I want to disable this option
#define QUICK_TAP_TERM 0 // make a very small number

// When holding and releasing a dual-function key will result in nothing being triggered.
#define RETRO_TAPPING
#define RETRO_TAPPING_PER_KEY

// Define a keycode which cancels a modifier - like GUI or ALT
#define DUMMY_MOD_NEUTRALIZER_KEYCODE KC_RIGHT_CTRL

// Neutralize left alt, left GUI, right GUI
#define MODS_TO_NEUTRALIZE { MOD_BIT(KC_LEFT_ALT), MOD_BIT(KC_LEFT_GUI), MOD_BIT(KC_RIGHT_GUI) }

#define EE_HANDS

// #define ONESHOT_TAP_TOGGLE 2
// #define ONESHOT_TIMEOUT 5000
