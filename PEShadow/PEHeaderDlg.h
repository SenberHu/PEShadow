#pragma once


// CPEHeaderDlg �Ի���

class CPEHeaderDlg : public CDialog
{
	DECLARE_DYNAMIC(CPEHeaderDlg)

public:
	CPEHeaderDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPEHeaderDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_PEHEADER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_EditNumberofSec;
	CString m_EditOpEntry;
	CString m_EditSizeOfOption;
	CString m_EditOpImageBase;
	CString m_EditOpBaseOfData;
	CString m_EditOpBaseOfCode;
	CString m_EditSectionAligment;
	CString m_EditFileAligment;
	CString m_EditOpNumOfDir;
	CString m_EditOptionMagic;
	CString m_EditFileSign;

	CHAR*	m_FileData;

	VOID    CheckPEHeader();
	virtual BOOL OnInitDialog();
	CString m_EditFileCharac;
};
