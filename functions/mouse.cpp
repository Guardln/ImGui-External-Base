#include "../Header Files/globals.hh"
#include <Windows.h>


void mouse::Move(int x, int y, int s)
{
	mouse_event(0x0001, x, y, 0, 0);
	Sleep(s);
}

void mouse::click(int holdTime)
{
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	Sleep(holdTime);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}