#include "CUpgrade.h"

CUpgrade::CUpgrade(HINSTANCE hInstance, string plane, int x, int y, char style): CObject(hInstance, plane, x, y), m_style(style) {}

char CUpgrade::getStyle() const
{
	return m_style;
}