#pragma once
#include "CObject.h"

class CUpgrade: public CObject
{
public:
	CUpgrade() {}
	CUpgrade(HINSTANCE hInstance, string plane, int x, int y, char style);
	char getStyle() const;
private:
	char m_style;
};