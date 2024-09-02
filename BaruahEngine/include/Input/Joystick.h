#pragma once

namespace Baruah
{
	/*! @} */

	/*! @defgroup joysticks Joysticks
	 *  @brief Joystick IDs.
	 *
	 *  See [joystick input](@ref joystick) for how these are used.
	 *
	 *  @ingroup input
	 *  @{ */
	#define BE_JOYSTICK_1             0
	#define BE_JOYSTICK_2             1
	#define BE_JOYSTICK_3             2
	#define BE_JOYSTICK_4             3
	#define BE_JOYSTICK_5             4
	#define BE_JOYSTICK_6             5
	#define BE_JOYSTICK_7             6
	#define BE_JOYSTICK_8             7
	#define BE_JOYSTICK_9             8
	#define BE_JOYSTICK_10            9
	#define BE_JOYSTICK_11            10
	#define BE_JOYSTICK_12            11
	#define BE_JOYSTICK_13            12
	#define BE_JOYSTICK_14            13
	#define BE_JOYSTICK_15            14
	#define BE_JOYSTICK_16            15
	#define BE_JOYSTICK_LAST          BE_JOYSTICK_16
	 /*! @} */

	 /*! @defgroup gamepad_buttons Gamepad buttons
	  *  @brief Gamepad buttons.
	  *
	  *  See @ref gamepad for how these are used.
	  *
	  *  @ingroup input
	  *  @{ */
	#define BE_GAMEPAD_BUTTON_A               0
	#define BE_GAMEPAD_BUTTON_B               1
	#define BE_GAMEPAD_BUTTON_X               2
	#define BE_GAMEPAD_BUTTON_Y               3
	#define BE_GAMEPAD_BUTTON_LEFT_BUMPER     4
	#define BE_GAMEPAD_BUTTON_RIGHT_BUMPER    5
	#define BE_GAMEPAD_BUTTON_BACK            6
	#define BE_GAMEPAD_BUTTON_START           7
	#define BE_GAMEPAD_BUTTON_GUIDE           8
	#define BE_GAMEPAD_BUTTON_LEFT_THUMB      9
	#define BE_GAMEPAD_BUTTON_RIGHT_THUMB     10
	#define BE_GAMEPAD_BUTTON_DPAD_UP         11
	#define BE_GAMEPAD_BUTTON_DPAD_RIGHT      12
	#define BE_GAMEPAD_BUTTON_DPAD_DOWN       13
	#define BE_GAMEPAD_BUTTON_DPAD_LEFT       14
	#define BE_GAMEPAD_BUTTON_LAST            BE_GAMEPAD_BUTTON_DPAD_LEFT

	#define BE_GAMEPAD_BUTTON_CROSS       BE_GAMEPAD_BUTTON_A
	#define BE_GAMEPAD_BUTTON_CIRCLE      BE_GAMEPAD_BUTTON_B
	#define BE_GAMEPAD_BUTTON_SQUARE      BE_GAMEPAD_BUTTON_X
	#define BE_GAMEPAD_BUTTON_TRIANGLE    BE_GAMEPAD_BUTTON_Y
	  /*! @} */

	  /*! @defgroup gamepad_axes Gamepad axes
	   *  @brief Gamepad axes.
	   *
	   *  See @ref gamepad for how these are used.
	   *
	   *  @ingroup input
	   *  @{ */
	#define BE_GAMEPAD_AXIS_LEFT_X        0
	#define BE_GAMEPAD_AXIS_LEFT_Y        1
	#define BE_GAMEPAD_AXIS_RIGHT_X       2
	#define BE_GAMEPAD_AXIS_RIGHT_Y       3
	#define BE_GAMEPAD_AXIS_LEFT_TRIGGER  4
	#define BE_GAMEPAD_AXIS_RIGHT_TRIGGER 5
	#define BE_GAMEPAD_AXIS_LAST          BE_GAMEPAD_AXIS_RIGHT_TRIGGER
};

