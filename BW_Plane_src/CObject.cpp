#include "CObject.h"

CObject::CObject(HINSTANCE hInstance, string bitmap, int x, int y)
{
	m_bitmap = (HBITMAP)LoadImage(NULL, bitmap.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	m_point.x = x;
	m_point.y = y;
	BITMAP temp;
	GetObject(m_bitmap, sizeof(temp), &temp);
	m_height = temp.bmHeight;
	m_width = temp.bmWidth;
	m_speed = 2;
	DeleteObject(&temp);
}

HBITMAP CObject::getHbitmap() const 
{
	return m_bitmap;
}

POINT CObject::getLocation() const
{
	return m_point;
}

long CObject::getHeight() const
{
	return m_height;
}

long CObject::getWidth() const
{
	return m_width;
}

void CObject::move(long x, long y)
{
	m_point.x = x;
	m_point.y = y;
}

int CObject::getSpeed() const
{
	return m_speed;
}

void CObject::setSpeed(int speed)
{
	m_speed = speed;
}

