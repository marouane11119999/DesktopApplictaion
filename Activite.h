#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include<vector>

// Activite dialog

class Activite : public CDialogEx
{
	DECLARE_DYNAMIC(Activite)

public:
	Activite(CWnd* pParent = NULL);   // standard constructor
	virtual ~Activite();

// Dialog Data
	enum { IDD = IDD_ACTIVITE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	HICON add,update,delet,deletall;
	virtual BOOL OnInitDialog();
	std::vector<CString> vect;
	bool non_trouv;
	bool supp;
	void OnsMod(CString str1,CString str2);
	void Onamod(CString st1,CString st2,CString st3);
	bool checkAjout();
	bool checksupression();
	bool checkfind();
	void RefreshList();
	CString nom_activite;
	CString nom_village;
	CListCtrl liste_activite;
	CComboBox gratuit;
	afx_msg void OnAjouter();
	CString m_delete;
	afx_msg void OnClickedDelete();
	CString m_delete1;
	afx_msg void OnClickedDeleteAll();
	afx_msg void OnChangeEdit3();
	afx_msg void OnChangeEdit4();
	CString m_find;
	afx_msg void OnClickedFind();
	CString m_find1;
	afx_msg void OnClickedUpdate();
	afx_msg void OnChangeEdit6();
	CButton icon_add;
	CButton icon_deletall;
	CButton icon_delet;
	CButton icon_upadate;
	CEdit c_activite;
	CEdit c_village;
	CEdit s_activite;
	CEdit s_village;
	CEdit m_village;
	CEdit m_activite;
};
