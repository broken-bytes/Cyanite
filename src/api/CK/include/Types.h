#ifndef _CK_TYPES_
#define _CK_TYPES_
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


	typedef uint8_t byte_t;
	typedef uint8_t* byte_p;
#define CK_Bool bool

	enum {
		ControllerConnectedEvent,
		ControllerDisconnectedEvent,
		ControllerDataEvent
	} typedef CK_EventType;

	enum {
		DPadNone,
		DPadLeft = 1,
		DPadUp = 2,
		DPadLeftUp = 3,
		DPadRight = 4,
		DPadRightUp = 6,
		DPadDown = 8,
		DPadLeftDown = 9,
		DPadRightDown = 12
	} typedef CK_DPadDirection;

	enum {
		TriggerLeft,
		TriggerRight
	} typedef CK_Trigger;

	enum {
		RumbleLeft,
		RumbleRight,
		RumbleTriggerLeft,
		RumbleTriggerRight
	}typedef CK_Rumble;

	enum {
		LeftX,
		LeftY,
		RightX,
		RightY,
		LeftTrigger,
		RightTrigger
	} typedef CK_Axis;

	enum {
		Button0, Cross = 0, A = 0,
		Button1, Square = 1, X = 1,
		Button2, Circle = 2, B = 2,
		Button3, Triangle = 3, Y = 3,
		Button4, L1 = 4, LB = 4,
		Button5, R1 = 5, RB = 5,
		Button6, L2 = 6, LT = 6,
		Button7, R2 = 7, RT = 7,
		Button8, Share = 8, Create = 8, View = 8,
		Button9, Options = 9, Menu = 9,
		Button10, L3 = 10,
		Button11, R3 = 11,
		Button12, PS_Home = 12, XBox_Home = 12,
		Button13, TouchPad = 13, XBox_Share = 13,
		Button14, PS_MUTE = 14,
		Button15 = 15,
		Button16 = 16
	} typedef CK_Button;

	struct {
		uint8_t X;
		uint8_t Y;
	} typedef CK_Stick;

	struct CK_DPad {
		CK_Bool Left;
		CK_Bool Up;
		CK_Bool Right;
		CK_Bool Down;
	} typedef CK_DPad;

	struct {
		CK_Bool Button0;
		CK_Bool Button1;
		CK_Bool Button2;
		CK_Bool Button3;
		CK_Bool Button4;
		CK_Bool Button5;
		CK_Bool Button6;
		CK_Bool Button7;
		CK_Bool Button8;
		CK_Bool Button9;
		CK_Bool Button10;
		CK_Bool Button11;
		CK_Bool Button12;
		CK_Bool Button13;
		CK_Bool Button14;
		CK_Bool Button15;
		CK_Stick LeftStick;
		CK_Stick RightStick;
		uint8_t LeftTrigger;
		uint8_t RightTrigger;
		CK_DPad DPad;
	} typedef CK_InputReport;

	struct {
		CK_InputReport Report;
	} typedef CK_EventData;

	struct {
		uint8_t ControllerNumber;
		CK_EventType Type;
		CK_EventData Data;
	} typedef CK_Event;

	struct {
		uint8_t R;
		uint8_t G;
		uint8_t B;
	} typedef CK_Color;

	enum {
		DualShockType,
		DualSenseType,
		XBoxOneType,
		XBoxSeriesType
	} typedef CK_ControllerType;

	struct {
		uint8_t Number;
		CK_ControllerType Type;
	} typedef CK_Controller;

#ifdef __cplusplus
}
#endif // __cplusplus


#endif
