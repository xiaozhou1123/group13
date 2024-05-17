
// MFCApplication1Dlg.h: 头文件
//

#pragma once


// CMFCApplication1Dlg 对话框
class CMFCApplication1Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
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
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit2();
	// 输入的度数
	double degree;
	// sin输出值
	// sin输出值
	double sin;
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnBnClickedButton1();
	double cos;
	CString tan_t;
	double arcsin_t;
	double arccos_t;
	double arctan_t;
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnEnChangeEdit8();
	double tan_v;
	afx_msg void OnEnChangeEdit5();
};
