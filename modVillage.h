#pragma once
#include "Village.h"
#include "afxwin.h"

// modVillage dialog

class modVillage : public CDialogEx
{
	DECLARE_DYNAMIC(modVillage)

public:
	modVillage(CWnd* pParent = NULL);   // standard constructor
	virtual ~modVillage();

// Dialog Data
	enum { IDD = IDD_MOD_VILLAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	HICON app,I_icon;
	virtual BOOL OnInitDialog();
	bool t;
	CString v1,v2,v3;
	Village g;
	CString mod_village;
	CString mod_pays;
	CString mod_continent;
	afx_msg void OnClickedAppliquer();
//	afx_msg void OnChangeV();
	CButton icon_app;
};
