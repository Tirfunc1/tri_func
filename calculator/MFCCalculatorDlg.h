
// MFCCalculatorDlg.h: 头文件
//

#pragma once

//运算符
enum Calculator_Flag {
	flag_Sum,
	flag_Sub,
	flag_Mult,
	flag_Divi,
	flag_Cos,
	flag_Sin,
	flag_Arcsin,
	flag_Arctan,
	flag_Null
};

// CMFCCalculatorDlg 对话框
class CMFCCalculatorDlg : public CDialogEx
{
// 构造
public:
	CMFCCalculatorDlg(CWnd* pParent = nullptr);	// 标准构造函数
	void SaveFirstValue();		//保存第一个输入值
	void Calculator();			//计算
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCCALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private :
	CString mStrInput;			//编辑框1内的字符串
	CString mStr1;				//编辑框2内的字符串
	CString mStr2;	
	CString mStr3;
	CString mStr4;
	CString mStr5;
	CString mStr6;
	CString mTempStr;
	double mNum1;				//输入的2个值
	double mNum2;
	Calculator_Flag mFlag;		//运算符号
	int mMode;					//1对应角度，0对应弧度
	int mSign;					//正负号标志
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnEnChangeEditInput();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEditinput();
	afx_msg void OnBnClickedButtonMult1();
	afx_msg void OnEnChangeDeitInput();
	afx_msg void OnBnClickedButtonEqu();
	afx_msg void OnBnClickedButtonDot();
	afx_msg void OnBnClickedButtonDivi();
	afx_msg void OnBnClickedButtonBack();
	afx_msg void OnBnClickedButtonClearAll();
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButtonSub();
	afx_msg void OnBnClickedButtonSum();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnBnClickedButtonCos();
	afx_msg void OnBnClickedButtonSin();
	afx_msg void OnBnClickedButtonArcsin();
	afx_msg void OnBnClickedButtonArctan();
	afx_msg void OnBnClickedButtonRad();
	afx_msg void OnBnClickedButtonDeg();
};
