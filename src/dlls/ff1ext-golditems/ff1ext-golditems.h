#ifndef FF1_GOLDITEMS_
#define FF1_GOLDITEMS_

#ifdef FF1GOLDITEMS_EXPORTS
#define FF1GOLDITEMS_API __declspec(dllexport)
#else
#define FF1GOLDITEMS_API __declspec(dllimport)
#endif

#include "EditorInterop.h"

extern "C"
{
	FF1GOLDITEMS_API char* Invoke(const EditorInterop * ei);
}

#endif //FF1_GOLDITEMS_
