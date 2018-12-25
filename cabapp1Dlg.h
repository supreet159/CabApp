
// cabapp1Dlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// Ccabapp1Dlg dialog
class Ccabapp1Dlg : public CDialogEx
{
// Construction
public:
	Ccabapp1Dlg(CWnd* pParent = NULL);	// standard constructor
	CString m_gettext2;
	CString SourcePath;
	CString SourcePath1;
// Dialog Data
	enum { IDD = IDD_CABAPP1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit1;
	afx_msg void OnBnClickedButton1();
	CEdit m_edit2;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	CListBox m_listtext1;
	CProgressCtrl m_Progress;
	afx_msg void OnLbnSelchangeList3();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnStnClickedBitmap2();
	CButton m_CheckBox1;
};
