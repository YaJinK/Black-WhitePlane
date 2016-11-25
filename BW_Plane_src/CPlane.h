#pragma once
#include "CObject.h"

class CPlane: public CObject
{
public:
	CPlane() {}
	CPlane(HINSTANCE hInstance, string plane, int x, int y, int life, int power = 1);
	int getLife() const;
	void setLife(int l);
	int getPower() const;
	void setPower(int l);
private:
	int m_life;
	int m_power;
};