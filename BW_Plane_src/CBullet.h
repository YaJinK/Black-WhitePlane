#pragma once
#include "CObject.h"

class CBullet: public CObject
{
public:
	CBullet() {}
	CBullet(HINSTANCE hInstance, string plane, int x, int y, int style);
	int getStyle() const;
	void setStyle(int style);
private:
	int m_style;
};