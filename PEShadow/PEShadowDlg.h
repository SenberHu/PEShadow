
// PEShadowDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "PeCheckFunc.h"
#include "PEHeaderDlg.h"
#include "PETableDlg.h"


// CPEShadowDlg �Ի���
class CPEShadowDlg : public CDialogEx
{
// ����
public:
	CPEShadowDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_PESHADOW_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl    m_TabMain;
	CString     m_EditFilePath;
	CString     m_EditFileType;
	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg void OnTcnSelchangeTabMain(NMHDR *pNMHDR, LRESULT *pResult);
public:
	TCHAR		     m_FilePath[1024];
	CHAR*	         m_szFileData;
	ULONG		     m_ulLow;
	PETYPE		     PeType;
	CRect            m_TabRect;
	CPEHeaderDlg     m_PeHeaderDlg;
	CPETableDlg      m_PeTableDlg;
	VOID             OnInitTabConctrl();
		
	
};
