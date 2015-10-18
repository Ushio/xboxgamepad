#include "XboxGamePad.hpp"
#include <algorithm>
namespace xbox {
	static const float kStickMax = 32767.0f;
	static const float kInputDead = kStickMax * 0.24f;

	struct ControllerState {
		ControllerState(){
			memset(&state, 0, sizeof(state));
			isConnected = false;
		}
		XINPUT_STATE state;
		bool isConnected;
	};

	static ControllerState g_controllers[kMaxControllers];
	static ControllerState g_controllers_previous[kMaxControllers];

	static inline bool isInvalidIndex(int index) {
		return index < 0 || kMaxControllers <= index;
	}
	bool isConnected(int index) {
		if(isInvalidIndex(index)) { 
			return false; 
		}
		return g_controllers[index].isConnected;
	}
	void update() {
		std::copy(g_controllers, g_controllers + kMaxControllers, g_controllers_previous);

		for(int i = 0; i < kMaxControllers; i++ )
		{
			ControllerState state;
			if(XInputGetState( i, &state.state ) == ERROR_SUCCESS) {
				state.isConnected = true;

				if( ( state.state.Gamepad.sThumbLX < kInputDead &&
                      state.state.Gamepad.sThumbLX > -kInputDead ) &&
                    ( state.state.Gamepad.sThumbLY < kInputDead &&
                      state.state.Gamepad.sThumbLY > -kInputDead ) )
                {
                    state.state.Gamepad.sThumbLX = 0;
                    state.state.Gamepad.sThumbLY = 0;
                }

                if( ( state.state.Gamepad.sThumbRX < kInputDead &&
                      state.state.Gamepad.sThumbRX > -kInputDead ) &&
                    ( state.state.Gamepad.sThumbRY < kInputDead &&
                      state.state.Gamepad.sThumbRY > -kInputDead ) )
                {
                    state.state.Gamepad.sThumbRX = 0;
                    state.state.Gamepad.sThumbRY = 0;
                }
			} else {
				state.isConnected = false;
			}
			g_controllers[i] = state;
		}
	}
	bool isOn(int index, int button) {
		if(isInvalidIndex(index)) { 
			return false; 
		}
		return (g_controllers[index].state.Gamepad.wButtons & button) != 0;
	}
	bool isTrigger(int index, int button) {
		if(isInvalidIndex(index)) { 
			return false; 
		}
		if(g_controllers_previous[index].isConnected == false) {
			return false;
		}
		bool previousIsOn = (g_controllers_previous[index].state.Gamepad.wButtons & button) != 0;
		return isOn(index, button) && previousIsOn == false;
	}
	float stick_L_x(int index) {
		if(isInvalidIndex(index)) { 
			return false; 
		}
		return g_controllers[index].state.Gamepad.sThumbLX / kStickMax;
	}
	float stick_L_y(int index) {
		if(isInvalidIndex(index)) { 
			return false; 
		}
		return g_controllers[index].state.Gamepad.sThumbLY / kStickMax;
	}
	float stick_R_x(int index) {
		if(isInvalidIndex(index)) { 
			return false; 
		}
		return g_controllers[index].state.Gamepad.sThumbRX / kStickMax;
	}
	float stick_R_y(int index) {
		if(isInvalidIndex(index)) { 
			return false; 
		}
		return g_controllers[index].state.Gamepad.sThumbRY / kStickMax;
	}

	float stick_L_x_prev(int index) {
		if(isInvalidIndex(index)) { 
			return 0.0f; 
		}
		if(g_controllers_previous[index].isConnected == false) {
			return 0.0f;
		}
		return g_controllers_previous[index].state.Gamepad.sThumbLX / kStickMax;
	}
	float stick_L_y_prev(int index) {
		if(isInvalidIndex(index)) { 
			return 0.0f; 
		}
		if(g_controllers_previous[index].isConnected == false) {
			return 0.0f;
		}
		return g_controllers_previous[index].state.Gamepad.sThumbLY / kStickMax;
	}
	float stick_R_x_prev(int index) {
		if(isInvalidIndex(index)) { 
			return 0.0f; 
		}
		if(g_controllers_previous[index].isConnected == false) {
			return 0.0f;
		}
		return g_controllers_previous[index].state.Gamepad.sThumbRX / kStickMax;
	}
	float stick_R_y_prev(int index) {
		if(isInvalidIndex(index)) { 
			return 0.0f; 
		}
		if(g_controllers_previous[index].isConnected == false) {
			return 0.0f;
		}
		return g_controllers_previous[index].state.Gamepad.sThumbRY / kStickMax;
	}
	float trigger_L(int index) {
		if(isInvalidIndex(index)) { 
			return 0.0f; 
		}
		return g_controllers[index].state.Gamepad.bLeftTrigger / 255.0f;
	}
	float trigger_R(int index) {
		if(isInvalidIndex(index)) { 
			return 0.0f; 
		}
		return g_controllers[index].state.Gamepad.bRightTrigger / 255.0f;
	}
}