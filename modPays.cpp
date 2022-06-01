// modPays.cpp : implementation file
//

#include "stdafx.h"
#include "ClubApp.h"
#include "modPays.h"
#include "afxdialogex.h"
#include "afxdao.h"


// modPays dialog

IMPLEMENT_DYNAMIC(modPays, CDialogEx)

modPays::modPays(CWnd* pParent /*=NULL*/)
	: CDialogEx(modPays::IDD, pParent)
	, mod_pays(_T(""))
	, mod_continent(_T(""))
{
	I_icon = AfxGetApp()->LoadIcon(IDI_ICON13);
	app = AfxGetApp()->LoadIcon(IDI_ICON14);
}

modPays::~modPays()
{
}

void modPays::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_p, mod_pays);
	DDX_Text(pDX, IDC_c, mod_continent);
	DDX_Control(pDX, IDC_BUTTON1, icon_app);
}


BEGIN_MESSAGE_MAP(modPays, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &modPays::OnClickedAppliquer)
END_MESSAGE_MAP()


// modPays message handlers
BOOL modPays::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetIcon(I_icon, TRUE);			// Set big icon
	SetIcon(I_icon, FALSE);// Set small icon
	icon_app.SetIcon(app);
	return TRUE;
}



void modPays::OnClickedAppliquer()
{
	// TODO: Add your control notification handler code here

	
	CDaoDatabase db;
	CDaoRecordset rc(&db);
	db.Open(L"GestionClubs.mdb");
	CString code_p;
	for(int i=0;i<3;i++)
	{
		code_p+=v1[i];
	}
	rc.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT VILLAGES.NO_PAYS FROM VILLAGES,PROPOSER WHERE PROPOSER.NO_VILLAGE=VILLAGES.NO_VILLAGE",NULL);
	if(!rc.Find(AFX_DAO_FIRST,_T("VILLAGES.NO_PAYS='"+code_p+"'"))){

		CString pay,con;
		GetDlgItemText(IDC_p, pay);
		GetDlgItemText(IDC_c, con);

		g.OnsMod(v1);
		g.Onamod(pay,con);
	
		t=true;

		OnOK();
	}
	else{
		AfxMessageBox(L"modification impossible,Pays est déjà associé à un village ayant une ou plusieurs activitées/langues",MB_ICONINFORMATION|MB_OK);
		OnOK();
	
	}
}
