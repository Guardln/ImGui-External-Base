#pragma once
#include <unordered_map>
#include <thread>
#include <Windows.h>


class c_globals {
public:
	bool active = true;

	int page = 0;
	int subPage = 0;
};

class color_settings
{
public:
	float all[4] = { 0.20f, 0.20f, 0.20f, 255 };
};

inline c_globals globals;
inline color_settings color;

namespace mouse
{
	void Move(int x,int y, int s);
	void click(int holdTime);
}

namespace keyboard
{
	void pressKey(int key, int holdTime);
}

namespace thread // used for running features you add
{
	
}

