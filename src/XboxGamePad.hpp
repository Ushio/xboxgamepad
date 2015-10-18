#pragma once

#include <Windows.h>
#include <Xinput.h>

/*
#define XINPUT_GAMEPAD_DPAD_UP          0x0001
#define XINPUT_GAMEPAD_DPAD_DOWN        0x0002
#define XINPUT_GAMEPAD_DPAD_LEFT        0x0004
#define XINPUT_GAMEPAD_DPAD_RIGHT       0x0008
#define XINPUT_GAMEPAD_START            0x0010
#define XINPUT_GAMEPAD_BACK             0x0020
#define XINPUT_GAMEPAD_LEFT_THUMB       0x0040
#define XINPUT_GAMEPAD_RIGHT_THUMB      0x0080
#define XINPUT_GAMEPAD_LEFT_SHOULDER    0x0100
#define XINPUT_GAMEPAD_RIGHT_SHOULDER   0x0200
#define XINPUT_GAMEPAD_A                0x1000
#define XINPUT_GAMEPAD_B                0x2000
#define XINPUT_GAMEPAD_X                0x4000
#define XINPUT_GAMEPAD_Y                0x8000
*/

namespace xbox {
	static const int kMaxControllers = 4;
	bool isConnected(int index);
	void update();
	bool isOn(int index, int button);
	bool isTrigger(int index, int button);
	
	float stick_L_x(int index);
	float stick_L_y(int index);
	float stick_R_x(int index);
	float stick_R_y(int index);

	float stick_L_x_prev(int index);
	float stick_L_y_prev(int index);
	float stick_R_x_prev(int index);
	float stick_R_y_prev(int index);

	float trigger_L(int index);
	float trigger_R(int index);
}
