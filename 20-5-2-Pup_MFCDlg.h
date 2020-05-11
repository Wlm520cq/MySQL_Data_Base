
// 20-5-2-Pup_MFCDlg.h: 头文件
//

#pragma once
#include "SQL_Query.h"

// CMy2052PupMFCDlg 对话框
class CMy2052PupMFCDlg : public CDialogEx
{
// 构造
public:
	CMy2052PupMFCDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY2052PUP_MFC_DIALOG };
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
private:
	// 存放差分计算的数据的变量
	CListCtrl m_list;
	//调取数据库的数据的变量
	vector<DifferEqu_Data> m_SQL_data;
public:
	afx_msg void OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedButtonLoad();
	afx_msg void OnBnClickedButtonCalc();
};
