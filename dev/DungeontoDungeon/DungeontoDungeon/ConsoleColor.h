#pragma once
#include <iostream>
#include <string>

#ifdef _WIN32
#define NOMINMAX
#include <Windows.h>
#endif


namespace ConsoleColor
{
//	enum class Ink
//	{
//		Purple, Cyan, Grean, Yellow, Red, White
//	};
//
//	inline void Print(const std::string& message, Ink ink)
//	{
//#ifdef _WIN32
//		HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
//		CONSOLE_SCREEN_BUFFER_INFO oringal{}; 
//
//		if (output != INVALID_HANDLE_VALUE && GetConsoleScreenBufferInfo output, &oringal)
//		{
//			WORD color = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY; //purple
//		}
//
//	}
};

