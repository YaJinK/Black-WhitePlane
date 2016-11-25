#pragma once
#include "CObject.h"

class CBack : public CObject
{
public:
	CBack(HINSTANCE hInstance, string bitmap, string b, string w, string caption, int x, int y, int begin);
	int getBegin() const;
	HBITMAP getBBit() const;
	HBITMAP getWBit() const;
	HBITMAP getCaptionBit() const;
	void setBegin(int begin);
private:
	int m_begin;
	HBITMAP m_b;
	HBITMAP m_w;
	HBITMAP m_caption;
};