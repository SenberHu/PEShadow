
// PEShadow.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CPEShadowApp:
// �йش����ʵ�֣������ PEShadow.cpp
//

class CPEShadowApp : public CWinApp
{
public:
	CPEShadowApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CPEShadowApp theApp;