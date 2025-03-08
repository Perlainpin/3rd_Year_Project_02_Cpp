#pragma once
#define NOMINMAX
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <wingdi.h>

#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>

#include "resource.h"

#ifdef _DEBUG
#include <crtdbg.h>
#define DEBUG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DEBUG_NEW
#endif
