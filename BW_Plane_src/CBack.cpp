#include "CBack.h"

CBack::CBack(HINSTANCE hInstance, string bitmap, string b, string w, string caption, int x, int y, int begin) : CObject(hInstance, bitmap, x, y), m_begin(begin)
{
	m_b = (HBITMAP)LoadImage(NULL,b.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	m_w = (HBITMAP)LoadImage(NULL, w.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	m_caption = (HBITMAP)LoadImage(NULL, caption.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

int CBack::getBegin() const
{
	return m_begin;
}

HBITMAP CBack::getBBit() const
{
	return m_b;
}

HBITMAP CBack::getWBit() const
{
	return m_w;
}

void CBack::setBegin(int begin)
{
	m_begin = begin;
}

HBITMAP CBack::getCaptionBit() const
{
	return m_caption;
}



