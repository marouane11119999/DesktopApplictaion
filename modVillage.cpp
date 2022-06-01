// modVillage.cpp : implementation file
//

#include "stdafx.h"
#include "ClubApp.h"
#include "modVillage.h"
#include "afxdialogex.h"
#include "afxdao.h"
#include "Village.h"


// modVillage dialog

IMPLEMENT_DYNAMIC(modVillage, CDialogEx)

modVillage::modVillage(CWnd* pParent /*=NULL*/)
	: CDialogEx(modVillage::IDD, pParent)
	, mod_village(_T(""))
	, mod_pays(_T(""))
	, mod_continent(_T(""))
{
	I_icon = AfxGetApp()->LoadIcon(IDI_ICON13);
	app = AfxGetApp()->LoadIcon(IDI_ICON14);
}

modVillage::~modVillage()
{
}

void modVillage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_v, mod_village);
	DDX_Text(pDX, IDC_p, mod_pays);
	DDX_Text(pDX, IDC_c, mod_continent);
	DDX_Control(pDX, IDC_BUTTON1, icon_app);
}


BEGIN_MESSAGE_MAP(modVillage, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &modVillage::OnClickedAppliquer)
//	ON_EN_CHANGE(IDC_v, &modVillage::OnChangeV)
END_MESSAGE_MAP()


// modVillage message handlers
BOOL modVillage::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetIcon(I_icon, TRUE);			// Set big icon
	SetIcon(I_icon, FALSE);// Set small icon
	icon_app.SetIcon(app);
	return TRUE;
}

void modVillage::OnClickedAppliquer()
{
	// TODO: Add your control notification handler code here
	CDaoDatabase db;
	CDaoRecordset rc(&db);
	db.Open(L"GestionClubs.mdb");
	rc.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT NO_VILLAGE from  PROPOSER",NULL);
	CString code_v;
	for(int i=0;i<3;i++){
		code_v+=v1[i];
	
	}
	
	if(!rc.Find(AFX_DAO_FIRST,_T("NO_VILLAGE ='"+code_v+"'"))){

	CString vil,pay,con;
	GetDlgItemText(IDC_v,vil);
	GetDlgItemText(IDC_p, pay);
	GetDlgItemText(IDC_c, con);
	g.Onamod(vil,pay,con);
	if(g.supp == false)
	     g.OnsMod(v1);
	
	
	t=true;

	OnOK();
	}
	else{
		AfxMessageBox(L"modification impossible,village associé à une ou plusieurs activitées/langues",MB_ICONINFORMATION|MB_OK);
		OnOK();	
	
	}
	rc.Close();
	db.Close();
	
}


