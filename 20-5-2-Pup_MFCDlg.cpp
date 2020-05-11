
// 20-5-2-Pup_MFCDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "20-5-2-Pup_MFC.h"
#include "20-5-2-Pup_MFCDlg.h"
#include "afxdialogex.h"

#include "SQL_Query.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


#define HEADER_NUMBER 0   // 列数
#define COLUMN_NUMBER 4   // 求的列数 我这到 4列

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


// CMy2052PupMFCDlg 对话框



CMy2052PupMFCDlg::CMy2052PupMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY2052PUP_MFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy2052PupMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}

BEGIN_MESSAGE_MAP(CMy2052PupMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CMy2052PupMFCDlg::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDC_BUTTON_LOAD, &CMy2052PupMFCDlg::OnBnClickedButtonLoad)
	ON_BN_CLICKED(IDC_BUTTON_CALC, &CMy2052PupMFCDlg::OnBnClickedButtonCalc)
END_MESSAGE_MAP()


// CMy2052PupMFCDlg 消息处理程序

BOOL CMy2052PupMFCDlg::OnInitDialog()
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
	// 1.  加表头
	// 1.1 设置表格的样式
	m_list.SetExtendedStyle(
		m_list.GetExtendedStyle() |
		LVS_EX_GRIDLINES | // 表格网格线
		LVS_EX_FULLROWSELECT);      // 点击某一个单元格，整行都会高亮选中

	//1.2 设置表格的表头
	m_list.InsertColumn(HEADER_NUMBER,"系数a", LVCFMT_LEFT, 100);

	/*int j = 1;
	for (int i = 0; i < 5; i++)
	{
		m_list.InsertColumn(j, "Y%d", LVCFMT_LEFT, 100);   //这个  i  该如何显示出来呢？
		j++;
	}*/
	m_list.InsertColumn(HEADER_NUMBER + 1, "Y0", LVCFMT_LEFT, 100);
	m_list.InsertColumn(HEADER_NUMBER + 2, "Y1", LVCFMT_LEFT, 100);
	m_list.InsertColumn(HEADER_NUMBER + 3, "Y2", LVCFMT_LEFT, 100);
	m_list.InsertColumn(HEADER_NUMBER + 4, "Y3", LVCFMT_LEFT, 100);
	m_list.InsertColumn(HEADER_NUMBER + 5, "Y4", LVCFMT_LEFT, 100);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMy2052PupMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy2052PupMFCDlg::OnPaint()
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
HCURSOR CMy2052PupMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMy2052PupMFCDlg::OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}

// 加载数据
void CMy2052PupMFCDlg::OnBnClickedButtonLoad()
{
	SQL_Query sql_query;    // 数据库管理层对象
	sql_query.init();       // 数据库管理层初始化
	// 1.使用数据库管理层的接口，来获取数据
	m_SQL_data = sql_query.getData();
	// 2.获取到的数据，填充到用户界面
	for (int i = 0; i < m_SQL_data.size(); i++)
	{
		CString str_SQL_data;
		// 第0列 a的数据
		str_SQL_data.Format("%d", m_SQL_data[i].a); // 把 int 转换为 string
		m_list.InsertItem(i, str_SQL_data);

		// 第一列 y0 的数据
		str_SQL_data.Format("%d", m_SQL_data[i].y0);
		m_list.SetItemText(i, 1, str_SQL_data);
	}
}

//差分计算
void CMy2052PupMFCDlg::OnBnClickedButtonCalc()
{
	CString str_SQL_Diff_data;
	for (int i = 0; i < m_SQL_data.size(); i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			int diff_Value = m_SQL_data[i].data_Calculation(j); 
			str_SQL_Diff_data.Format("%d", diff_Value);

			m_list.SetItemText(i, j + 1, str_SQL_Diff_data);
		}

	}
}
