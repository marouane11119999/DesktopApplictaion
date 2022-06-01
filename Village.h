#pragma once
#include "afxcmn.h"
#include<vector>
#include "afxwin.h"


// Village dialog

class Village : public CDialogEx
{
	DECLARE_DYNAMIC(Village)

public:
	Village(CWnd* pParent = NULL);   // standard constructor
	virtual ~Village();

// Dialog Data
	enum { IDD = IDD_VILLAGES };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	HICON add,update,delet,deletall;
	std::vector<CString> v;
	CString s;
	bool non_trouv;
	bool supp;
	void OnsMod(CString st1);
	void Onamod(CString st1,CString st2,CString st3);
	bool checkAjout();
	bool checksupression();
	bool checkfind();
	void RefreshList();
	virtual BOOL OnInitDialog();
	CString nom_village;
	CString nom_pays;
	CListCtrl liste_village;
	afx_msg void On_ajouter();
	afx_msg void Onmodifier();
	CString nom_continent;
	afx_msg void Onsupprimer();
	afx_msg void Onsupprimertout();
	CString v_supression;
	CString v_find;
	afx_msg void OnClickedFind();
	afx_msg void OnChangeEdit1();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnChangeEdit4();
	afx_msg void OnChangeFind();
	CButton ico_add;
	CButton icon_delet;
	CButton icon_add;
	CButton icon_deletall;
	CEdit c_nomvillage;
	CEdit c_nompays;
	CEdit c_continent;
	CEdit s_village;
	CEdit m_village;
};
