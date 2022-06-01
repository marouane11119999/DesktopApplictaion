#pragma once
#include "afxcmn.h"
#include<vector>
#include "afxwin.h"

// Pays dialog

class Pays : public CDialogEx
{
	DECLARE_DYNAMIC(Pays)

public:
	Pays(CWnd* pParent = NULL);   // standard constructor
	virtual ~Pays();

// Dialog Data
	enum { IDD = IDD_PAYS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public :
	HICON add,update,delet,deletall;
	virtual BOOL OnInitDialog();
	std::vector<CString> v;
	bool non_trouv;
	void OnsMod(CString st1);
	void Onamod(CString st1,CString st2);
	CString nom_pays;
	CString nom_continent;
	CListCtrl liste_pays;
	void RefreshList();
	bool checkAjout();
	bool checksupression();
	bool checkfind();
	afx_msg void OnClickedAjout();
	afx_msg void OnClickedDelete();
	afx_msg void OnClickedDeleteall();
	CString v_delete;
	afx_msg void OnChangeEdit2();
	afx_msg void OnChangeEdit3();
	afx_msg void OnClickedFind();
	CString v_find;
	afx_msg void OnClickedUpdate();
	afx_msg void OnChangeEdit4();
	CButton icon_add;
	CButton icon_delet;
	CButton icon_deletall;
	CButton icon_update;
	CEdit C_nompays;
	CEdit C_continent;
	CEdit m_pays;
	CEdit s_pays;
};
