#include "CBullet.h"

CBullet::CBullet(HINSTANCE hInstance, string plane, int x, int y,int style): CObject(hInstance, plane, x, y), m_style(style) {}

int CBullet::getStyle() const
{
	return m_style;
}
void CBullet::setStyle(int s)
{
	m_style = s;
}