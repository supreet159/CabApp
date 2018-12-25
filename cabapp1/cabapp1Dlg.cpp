
// cabapp1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "cabapp1.h"
#include "cabapp1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

const TCHAR CABARCEXE[] =_T("cabarc.exe");
const TCHAR TEMPPATH[] = _T("D:\\cabtemp");
const TCHAR STARTDOTSTAR[] = _T("\\*.*");

// CAboutDlg dialog used for App About

void RecursiveDelete1(CString szPath123)
{
	CFileFind ff;
	CString path = szPath123;
	if(path.Right(1) != "\\")
		path += "\\";
	path += "*.*";

	BOOL res = ff.FindFile(path);

	while(res)
	{
		res = ff.FindNextFileW();
		if(!ff.IsDots() && !ff.IsDirectory())
			DeleteFile(ff.GetFilePath());
				
		else if (ff.IsDirectory() && !ff.IsDots())
		{
			path = ff.GetFilePath();

			RecursiveDelete1(path);

			RemoveDirectory(path);
		}
		/*else DeleteFile(ff.GetFilePath());*/
	}
}

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Ccabapp1Dlg dialog




Ccabapp1Dlg::Ccabapp1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ccabapp1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ccabapp1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	/*DDX_Control(pDX, IDC_EDIT1, m_edit1);*/
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
	DDX_Control(pDX, IDC_LIST3, m_listtext1);
	DDX_Control(pDX, IDC_PROGRESS1, m_Progress);
	DDX_Control(pDX, IDC_CHECK1, m_CheckBox1);
}

BEGIN_MESSAGE_MAP(Ccabapp1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Ccabapp1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &Ccabapp1Dlg::OnBnClickedButton3)
	ON_LBN_SELCHANGE(IDC_LIST3, &Ccabapp1Dlg::OnLbnSelchangeList3)
	ON_BN_CLICKED(IDC_CHECK1, &Ccabapp1Dlg::OnBnClickedCheck1)
	ON_STN_CLICKED(IDB_BITMAP2, &Ccabapp1Dlg::OnStnClickedBitmap2)
END_MESSAGE_MAP()


// Ccabapp1Dlg message handlers

BOOL Ccabapp1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	m_Progress.SetRange(0,100);


	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Ccabapp1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Ccabapp1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Ccabapp1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ccabapp1Dlg::OnBnClickedButton1()
{
	CString strSup1;
	CString TempFolder;
	CreateDirectory(TEMPPATH, NULL);
	TCHAR newpath[MAX_PATH]={0};
	TCHAR newpath1[MAX_PATH]={0};
	_tcscpy( newpath, TEMPPATH);
	_tcscat(newpath, _T("\\"));
	_tcscpy(newpath1,newpath);
	CFileDialog FileDialogue(TRUE ,_T("*.*"), NULL,OFN_READONLY | OFN_ALLOWMULTISELECT, _T("all files: (*.*)|*.*||"));
	TCHAR strFiles[MAX_PATH] = {0};
	CString str;
	FileDialogue.GetOFN().lpstrFile = str.GetBuffer(MAX_PATH);

	if(FileDialogue.DoModal() == IDOK)
	{

		POSITION pos = FileDialogue.GetStartPosition();

		if(pos != NULL)
		{
			CString Pathname;
			/*CString strTemp2;*/
			TCHAR filenamebuff[_MAX_FNAME]={0};
			TCHAR filextbuff[_MAX_EXT]={0};
		
			do
			{
				Pathname = FileDialogue.GetNextPathName(pos);
				SourcePath = Pathname;
				_tsplitpath_s(Pathname,NULL,0,NULL,0,filenamebuff,_MAX_FNAME,filextbuff,_MAX_EXT);
				_tcscat(filenamebuff,filextbuff);
				_tcscat(newpath,filenamebuff);
				m_listtext1.AddString(Pathname);
				memset(filenamebuff,0,_MAX_FNAME);
				memset(filextbuff,0,_MAX_FNAME);
				CopyFile(Pathname,newpath,1);
				memset(newpath,0,_MAX_FNAME);
			    _tcscpy(newpath,newpath1);
			} while(pos);
		}
		
	}
	strSup1 = FileDialogue.GetPathName();
	SourcePath = strSup1;
}


void Ccabapp1Dlg::OnBnClickedButton3()
{
	m_Progress.SetPos(33);
	TCHAR lpExepath[MAX_PATH]={0};
	TCHAR lpExename[MAX_PATH]={0};
	DWORD err = 0;
	const TCHAR lpConstant[]=_T(" -m LZX:21 N ");
	const TCHAR m_gettext3[]=_T("D:\\cabtemp\\*.*");
	TCHAR lpTemp[MAX_PATH]={0};
	CString strSup2;
	m_edit2.GetWindowTextW(strSup2);
	m_gettext2 = strSup2;
	_tcscpy(lpTemp,CABARCEXE);
	_tcscat(lpTemp,lpConstant);
	_tcscat(lpTemp,m_gettext2);
	_tcscat(lpTemp,_T(" "));
	_tcscat(lpTemp,m_gettext3);
	_tcscpy(lpExepath,lpTemp);
		m_Progress.SetStep(66);
	STARTUPINFOW siStartUpInfo;
	PROCESS_INFORMATION piProcessInfo;
	memset(&siStartUpInfo,0,sizeof(siStartUpInfo));
	memset(&piProcessInfo,0,sizeof(piProcessInfo));
	siStartUpInfo.cb = sizeof(siStartUpInfo);
	siStartUpInfo.dwFlags |= STARTF_USESHOWWINDOW;
    siStartUpInfo.wShowWindow = SW_HIDE;

	
	if(CreateProcessW(0,lpExepath,0,0,false,CREATE_DEFAULT_ERROR_MODE,0,0,&siStartUpInfo,&piProcessInfo)!= false)
	{
		WaitForSingleObject(piProcessInfo.hProcess, INFINITE );
	}
	else
	{
		//handle
	}
	err = GetLastError();
	if(piProcessInfo.hProcess != NULL)
	CloseHandle(piProcessInfo.hProcess);
	if(piProcessInfo.hThread != NULL)
	CloseHandle(piProcessInfo.hThread);
	RecursiveDelete1(TEMPPATH);
	m_Progress.SetPos(100);
	/*Sleep(100);*/
	AfxMessageBox(_T("Created Successfully"));
	m_listtext1.ResetContent();
	m_edit2.SetWindowTextW(_T(""));
	m_Progress.SetPos(0);
}


void Ccabapp1Dlg::OnLbnSelchangeList3()
{
	// TODO: Add your control notification handler code here
}

void Ccabapp1Dlg::OnBnClickedCheck1()
{
	if (m_CheckBox1.GetCheck() == BST_UNCHECKED)
	{
		m_edit2.SetWindowTextW(_T(""));
	}
	else 
	{
	SourcePath1 = SourcePath + _T("\\newcab.cab");
	m_edit2.SetWindowTextW(SourcePath1);
    }
}


void Ccabapp1Dlg::OnStnClickedBitmap2()
{
	// TODO: Add your control notification handler code here
}
