#include "CPlane.h"

CPlane::CPlane(HINSTANCE hInstance, string plane, int x, int y, int life, int power): CObject(hInstance, plane, x, y), m_life(life), m_power(power) {}

int CPlane::getLife() const
{
	return m_life;
}

void CPlane::setLife(int l)
{
	m_life = l;
}

int CPlane::getPower() const
{
	return m_power;
}

void CPlane::setPower(int p)
{
	m_power = p;
}