#pragma once
#include "Pays.h"
#include "afxwin.h"

// modPays dialog

class modPays : public CDialogEx
{
	DECLARE_DYNAMIC(modPays)

public:
	modPays(CWnd* pParent = NULL);   // standard constructor
	virtual ~modPays();

// Dialog Data
	enum { IDD = IDD_MOD_PAYS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	HICON app,I_icon;
	virtual BOOL OnInitDialog();
	CString v1,v2;
	Pays g;
	bool t;
	CString mod_pays;
	CString mod_continent;
	afx_msg void OnClickedAppliquer();
	CButton icon_app;
};
