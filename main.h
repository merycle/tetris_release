#pragma once
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#ifdef _DEBUG
#define MYDEBUG new(_NORMAL_BLOCK,__FILE__,__LINE__)
#define new MYDEBUG
#endif
