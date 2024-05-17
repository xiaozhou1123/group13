
// MFCApplication1Dlg.cpp: 实现文件
//
#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include <iostream>
#include "Python.h"
#include <windows.h> // For SetDllDirectory
#include <string> // 包含std::to_string所需的头文件
#include <cmath>  // 包含std::isnan所需的头文件

void callPythonFunction(double angle_degrees) {

}
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
public:
	afx_msg void OnBnClickedButton_dd();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);


}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CAboutDlg::OnBnClickedButton_dd)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 对话框



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
	, degree(0)
	, sin(0)
	, cos(0)
	, tan_t(_T("      第16组基于第13组的Python程序开发的MFC上位机(C++)，其中python代码规定反三角函数输入值为计算得到的三角函数值，因此得到输入值。"))
	, arcsin_t(0)
	, arccos_t(0)
	, arctan_t(0)
	, tan_v(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT2, degree);
	DDX_Text(pDX, IDC_EDIT3, sin);
	DDV_MinMaxDouble(pDX, sin, -1, 1);
	DDX_Text(pDX, IDC_EDIT1, cos);
	DDV_MinMaxDouble(pDX, cos, -1, 1);
	DDX_Text(pDX, IDC_EDIT4, tan_t); 
	DDX_Text(pDX, IDC_EDIT5, arcsin_t);
	DDX_Text(pDX, IDC_EDIT6, arccos_t);
	DDX_Text(pDX, IDC_EDIT7, arctan_t);
	DDX_Text(pDX, IDC_EDIT8, tan_v);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCApplication1Dlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT2, &CMFCApplication1Dlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &CMFCApplication1Dlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT4, &CMFCApplication1Dlg::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT8, &CMFCApplication1Dlg::OnEnChangeEdit8)
	ON_EN_CHANGE(IDC_EDIT5, &CMFCApplication1Dlg::OnEnChangeEdit5)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 消息处理程序

BOOL CMFCApplication1Dlg::OnInitDialog()
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

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCApplication1Dlg::OnPaint()
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
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CMFCApplication1Dlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CAboutDlg::OnBnClickedButton_dd()
{
	// TODO: 在此添加控件通知处理程序代码
	


}


void CMFCApplication1Dlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMFCApplication1Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);


	SetDllDirectory(L"D:\Software\PYTHON\PYTHONN\Python\DLLs"); // 确保路径正确
	SetDllDirectory(L"D:\Software\PYTHON\PYTHONN\Python"); // 确保路径正确
	// Initialize the Python interpreter
	Py_Initialize();

	try {
		// Load the Python script
		FILE* file;
		errno_t err = fopen_s(&file, "C:\\Users\\12039\\Desktop\\ruanjain\\MMFFCC\\MFCApplication1\\trig_calculator_python_angle_degrees.py", "r");
		//errno_t err = fopen_s(&file, "\\MMFFCC\\MFCApplication1\\trig_calculator_python_angle_degrees.py", "r");
		if (err == 0 && file != nullptr) {
			PyRun_SimpleFile(file, "trig_calculator_python_angle_degrees.py");
			fclose(file);
		}
		else {
			std::cerr << "Could not open trig_calculator.py" << std::endl;
			return;
		}

		// Get a reference to the main module
		PyObject* main_module = PyImport_AddModule("__main__");
		if (!main_module) {
			PyErr_Print();
			return;
		}

		// Get a reference to the dictionary of the main module
		PyObject* main_dict = PyModule_GetDict(main_module);

		// Get a reference to the trig_calculator function
		PyObject* trig_calculator_func = PyDict_GetItemString(main_dict, "trig_calculator");

		if (PyCallable_Check(trig_calculator_func)) {
			// Call the trig_calculator function
			PyObject* args = PyTuple_Pack(1, PyFloat_FromDouble(degree));
			PyObject* result = PyObject_CallObject(trig_calculator_func, args);
			if (result) {
				sin = PyFloat_AsDouble(PyTuple_GetItem(result, 0));
				cos = PyFloat_AsDouble(PyTuple_GetItem(result, 1));
				tan_v = PyFloat_AsDouble(PyTuple_GetItem(result, 2));
				PyObject* arcsin_value_obj = PyTuple_GetItem(result, 3);
				PyObject* arccos_value_obj = PyTuple_GetItem(result, 4);
				PyObject* arctan_value_obj = PyTuple_GetItem(result, 5);
				//arcsin_t = PyFloat_Check(arcsin_value_obj) ? PyFloat_AsDouble(arcsin_value_obj) : NAN;
				//arccos_t = PyFloat_AsDouble(PyTuple_GetItem(result, 4));
				//arctan_t = PyFloat_AsDouble(PyTuple_GetItem(result, 5));
				
				 arcsin_t = PyFloat_Check(arcsin_value_obj) ? PyFloat_AsDouble(arcsin_value_obj) : NAN;
				 arccos_t = PyFloat_Check(arccos_value_obj) ? PyFloat_AsDouble(arccos_value_obj) : NAN;
				 arctan_t = PyFloat_Check(arctan_value_obj) ? PyFloat_AsDouble(arctan_value_obj) : NAN;
				 

				//std::cout << "Arcsine: " << (std::isnan(arcsin_value) ? "Undefined" : std::to_string(arcsin_value)) << std::endl;
				//std::cout << "Arccosine: " << (std::isnan(arccos_value) ? "Undefined" : std::to_string(arccos_value)) << std::endl;
				//std::cout << "Arctangent: " << (std::isnan(arctan_value) ? "Undefined" : std::to_string(arctan_value)) << std::endl;

				Py_DECREF(result);
			}
			else {
				PyErr_Print();
			}
			Py_DECREF(args);
		}
		else {
			std::cerr << "trig_calculator function not callable" << std::endl;
			PyErr_Print();
		}
	}
	catch (...) {
		PyErr_Print();
	}

	// Finalize the Python interpreter
	Py_Finalize();




	UpdateData(FALSE);
}


void CMFCApplication1Dlg::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMFCApplication1Dlg::OnEnChangeEdit8()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMFCApplication1Dlg::OnEnChangeEdit5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
