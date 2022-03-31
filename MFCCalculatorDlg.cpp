
// MFCCalculatorDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCCalculator.h"
#include "MFCCalculatorDlg.h"
#include "afxdialogex.h"

#include "fnArctan.h"
#include "fnArcsin.h"
#include "fnCos.h"
#include "fnSin.h"



#define pi 3.1415926535898
#define std_angle (pi/180)//标准角

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCCalculatorDlg 对话框



CMFCCalculatorDlg::CMFCCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCCALCULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_DEIT_Input, mStrInput);
	DDX_Text(pDX, IDC_EDIT2, mStr1);
	DDX_Text(pDX, IDC_EDIT3, mStr2);
	DDX_Text(pDX, IDC_EDIT4, mStr3);
	DDX_Text(pDX, IDC_EDIT5, mStr4);
	DDX_Text(pDX, IDC_EDIT6, mStr5);
}


BEGIN_MESSAGE_MAP(CMFCCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//ON_BN_CLICKED(IDC_BUTTON1, &CMFCCalculatorDlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT2, &CMFCCalculatorDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_DEIT_Input, &CMFCCalculatorDlg::OnEnChangeDeitInput)
	ON_BN_CLICKED(IDC_BUTTON_SUB, &CMFCCalculatorDlg::OnBnClickedButtonSub)
	ON_BN_CLICKED(IDC_BUTTON_SUM, &CMFCCalculatorDlg::OnBnClickedButtonSum)
	ON_BN_CLICKED(IDC_BUTTON_DIVI, &CMFCCalculatorDlg::OnBnClickedButtonDivi)
	ON_BN_CLICKED(IDC_BUTTON_MULT1, &CMFCCalculatorDlg::OnBnClickedButtonMult1)
	ON_BN_CLICKED(IDC_BUTTON_EQU, &CMFCCalculatorDlg::OnBnClickedButtonEqu)
	ON_BN_CLICKED(IDC_BUTTON_Back, &CMFCCalculatorDlg::OnBnClickedButtonBack)
	ON_BN_CLICKED(IDC_BUTTON_Clear_All, &CMFCCalculatorDlg::OnBnClickedButtonClearAll)
	ON_BN_CLICKED(IDC_BUTTON_Clear, &CMFCCalculatorDlg::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCCalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCCalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCCalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCCalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCCalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCCalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCCalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCCalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCCalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON0, &CMFCCalculatorDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_DOT, &CMFCCalculatorDlg::OnBnClickedButtonDot)
	
	ON_EN_CHANGE(IDC_EDIT4, &CMFCCalculatorDlg::OnEnChangeEdit4)
	ON_BN_CLICKED(IDC_BUTTON_arctanx, &CMFCCalculatorDlg::OnBnClickedButtonarctanx)
	
	ON_BN_CLICKED(IDC_BUTTON_arcsinx, &CMFCCalculatorDlg::OnBnClickedButtonarcsinx)
	ON_BN_CLICKED(IDC_BUTTON_cosx, &CMFCCalculatorDlg::OnBnClickedButtoncosx)
	ON_BN_CLICKED(IDC_BUTTON_sinx1, &CMFCCalculatorDlg::OnBnClickedButtonsinx1)
END_MESSAGE_MAP()


// CMFCCalculatorDlg 消息处理程序

BOOL CMFCCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCCalculatorDlg::SaveFirstValue()
{
	UpdateData(TRUE);
	mNum1 = _wtof(mStrInput);
	mTempStr = mStrInput;
	mStrInput = L"";
	UpdateData(FALSE);
}

void CMFCCalculatorDlg::Calculator()
{
	UpdateData(TRUE);
	mNum2 = _wtof(mStrInput);
	double result = 0.0f;
	switch (mFlag)
	{
	case flag_Sum:						//加  
		result = mNum1 + mNum2;
		mTempStr = mTempStr + _T("+") + mStrInput + _T("=");
		break;
	case flag_Sub:						//减 
		result = mNum1 - mNum2;
		mTempStr = mTempStr + _T("-") + mStrInput + _T("=");
		break;
	case flag_Mult:					    //乘  
		result = mNum1 * mNum2;
		mTempStr = mTempStr + _T("x") + mStrInput + _T("=");
		break;
	case flag_Divi:						//除  
		if (mNum2 == 0.0f)
			{
				result = mNum1;
				mTempStr = _T("---除数不能为0！！！---");
			}
			else
			{
				result = mNum1 / mNum2;
				mTempStr = mTempStr + _T("/") + mStrInput + _T("=");
			}
		break;
	
	default:
		break;
	}
	//如果浮点数是个整数,就显示为整数
	if (result - int(result) <= 1e-5)
	{
		mStrInput.Format(L"%d", (int)result);
	}
	else
	{
		mStrInput.Format(L"%f", result);
	}
	mTempStr += mStrInput;
	mStr6 = mStr5;
	mStr5 = mStr4;
	mStr4 = mStr3;
	mStr3 = mStr2;
	mStr2 = mStr1;
	mStr1 = mTempStr;
	UpdateData(FALSE);

	mNum1 = result;
	mNum2 = 0.0f;

}


void CMFCCalculatorDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}





void CMFCCalculatorDlg::OnEnChangeEditInput()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMFCCalculatorDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMFCCalculatorDlg::OnEnChangeEditinput()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}



void CMFCCalculatorDlg::OnEnChangeDeitInput()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMFCCalculatorDlg::OnBnClickedButtonEqu()
{
	// TODO: 在此添加控件通知处理程序代码
	Calculator();
}





void CMFCCalculatorDlg::OnBnClickedButtonBack()
{
	// TODO: 在此添加控件通知处理程序代码
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (!mStrInput.IsEmpty()) {
		mStrInput = mStrInput.Left(mStrInput.GetLength() - 1);
	}
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButtonClearAll()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	mStrInput = L"";
	mStr1 = L"";
	mStr2 = L"";
	mStr3 = L"";
	mStr4 = L"";
	mStr5 = L"";
	mStr6 = L"";
	mNum1 = 0.0f;
	mNum2 = 0.0f;
	mFlag = flag_Sum;
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButtonClear()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	mStrInput = L"";
	mNum1 = 0.0f;
	mNum2 = 0.0f;
	mFlag = flag_Sum;
	UpdateData(FALSE);
}
void CMFCCalculatorDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	mStrInput += L"1";
	UpdateData(FALSE);
}

void CMFCCalculatorDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	mStrInput += L"2";
	UpdateData(FALSE);
}
void CMFCCalculatorDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	mStrInput += L"3";
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	mStrInput += L"4";
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	mStrInput += L"5";
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	mStrInput += L"6";
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	mStrInput += L"7";
	UpdateData(FALSE);
}



void CMFCCalculatorDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	mStrInput += L"8";
	UpdateData(FALSE);
}



void CMFCCalculatorDlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	mStrInput += L"9";
	UpdateData(FALSE);

}


void CMFCCalculatorDlg::OnBnClickedButton0()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	mStrInput += L"0";
	UpdateData(FALSE);
}



void CMFCCalculatorDlg::OnBnClickedButtonDot()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	//如果没有小数点，则加上一个小数点，如果已有小数点就忽略此次的小数点，保证最多只有1个  
	if (-1 == mStrInput.Find(L'.'))
	{
		mStrInput += L".";
	}
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButtonDivi()
{
	// TODO: 在此添加控件通知处理程序代码
	SaveFirstValue();
	mFlag = flag_Divi;
}



void CMFCCalculatorDlg::OnBnClickedButtonMult1()
{
	// TODO: 在此添加控件通知处理程序代码
	SaveFirstValue();
	mFlag = flag_Mult;
}


void CMFCCalculatorDlg::OnBnClickedButtonSub()
{
	// TODO: 在此添加控件通知处理程序代码
	SaveFirstValue();
	mFlag = flag_Sub;
}


void CMFCCalculatorDlg::OnBnClickedButtonSum()
{
	// TODO: 在此添加控件通知处理程序代码
	SaveFirstValue();
	mFlag = flag_Sum;
}


void CMFCCalculatorDlg::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}






void CMFCCalculatorDlg::OnBnClickedButtonarctanx()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	mTempStr = _T("arctan(") + mStrInput + _T(")=");
	mNum1 = _wtof(mStrInput);

	double f = fnArctan(mNum1)/ std_angle;// * std_angle
	if (f - int(f) <= 1e-5) {
		mStrInput.Format(L"%d", (int)f); 
	}
	else {
		mStrInput.Format(L"%f", f);
	}
	
	mTempStr += mStrInput + _T("°");
	mStr6 = mStr5;
	mStr5 = mStr4;
	mStr4 = mStr3;
	mStr3 = mStr2;
	mStr2 = mStr1;
	mStr1 = mTempStr;
	UpdateData(FALSE);

	mNum1 = f;
	mNum2 = 0.0f;
	mFlag = flag_Arctanx;
}




void CMFCCalculatorDlg::OnBnClickedButtonarcsinx()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	mTempStr = _T("arcsin(") + mStrInput + _T(")=");
	mNum1 = _wtof(mStrInput);

	double f = Arcsin(mNum1)/ std_angle;// * std_angle
	if (f - int(f) <= 1e-5) {
		mStrInput.Format(L"%d", (int)f);
	}
	else {
		mStrInput.Format(L"%f", f);
	}

	mTempStr += mStrInput + _T("°");
	mStr6 = mStr5;
	mStr5 = mStr4;
	mStr4 = mStr3;
	mStr3 = mStr2;
	mStr2 = mStr1;
	mStr1 = mTempStr;
	UpdateData(FALSE);

	mNum1 = f;
	mNum2 = 0.0f;
	mFlag = flag_Arcsinx;

}


void CMFCCalculatorDlg::OnBnClickedButtonRad()
{
	// TODO: 在此添加控件通知处理程序代码
	SaveFirstValue();
	mAngleMode = flag_RadMode;
}

void CMFCCalculatorDlg::OnBnClickedButtoncosx()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	mTempStr = _T("cos(") + mStrInput + _T(")=");
	mNum1 = _wtof(mStrInput);


	double f = fnCos(mAngleMode, mNum1);/// std_angle;// * std_angle
	if (f - int(f) <= 1e-5) {
		mStrInput.Format(L"%d", (int)f);
	}
	else {
		mStrInput.Format(L"%f", f);
	}

	mTempStr += mStrInput;
	mStr6 = mStr5;
	mStr5 = mStr4;
	mStr4 = mStr3;
	mStr3 = mStr2;
	mStr2 = mStr1;
	mStr1 = mTempStr;
	UpdateData(FALSE);

	mNum1 = f;
	mNum2 = 0.0f;
	mFlag = flag_Cosx;
	mAngleMode = flag_AngleMode;
}


void CMFCCalculatorDlg::OnBnClickedButtonsinx1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	mTempStr = _T("sin(") + mStrInput + _T(")=");
	mNum1 = _wtof(mStrInput);

	double f = fnCos(mAngleMode, mNum1);/// std_angle;// * std_angle
	if (f - int(f) <= 1e-5) {
		mStrInput.Format(L"%d", (int)f);
	}
	else {
		mStrInput.Format(L"%f", f);
	}

	mTempStr += mStrInput ;
	mStr6 = mStr5;
	mStr5 = mStr4;
	mStr4 = mStr3;
	mStr3 = mStr2;
	mStr2 = mStr1;
	mStr1 = mTempStr;
	UpdateData(FALSE);

	mNum1 = f;
	mNum2 = 0.0f;
	mFlag = flag_Sinx;
	mAngleMode = flag_AngleMode;
}
