#pragma once
#include <Windows.h>
#include <string>
using std::string;

class CObject
{
public:
	CObject() {}
	CObject(HINSTANCE hInstance, string bitmap, int x, int y);
	HBITMAP getHbitmap() const;
	POINT getLocation() const;
	long getHeight() const;
	long getWidth() const;
	int getSpeed() const;
	void setSpeed(int speed);
	void move(long x, long y);
private:
	HBITMAP m_bitmap;
	POINT m_point;
	long m_height;
	long m_width;
	int m_speed;
};