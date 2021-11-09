// ControllerKit.h : Include file for standard system include files,
// or project specific include files.

#ifndef _CK_
#define _CK_

#include "Types.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
	void CK_Init(void);
	void CK_Deinit(void);
	void CK_Refresh(void);
	CK_Bool CK_PollEvent(CK_Event* event);
#ifdef __cplusplus
}
#endif // __cplusplus
#endif // _CK_


// TODO: Reference additional headers your program requires here.
