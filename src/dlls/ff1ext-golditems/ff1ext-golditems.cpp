// ff1ext-golditems.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "ff1ext-golditems.h"
#include "CustomModule.h"
#include <FFBaseApp.h>
#include "ff1ext-golditems-resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CCustomModule theApp; // The one and only application object


extern "C"
{

	FF1GOLDITEMS_API char* Invoke(const EditorInterop * ei)
	{
		CString response = theApp.Invoke(ei);
		if (response.IsEmpty())
			return nullptr;
		return Editors2::AllocReturnValue(ei->allocator, response);
	}

}