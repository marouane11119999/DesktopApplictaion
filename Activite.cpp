// Activite.cpp : implementation file
//

#include "stdafx.h"
#include "ClubApp.h"
#include "Activite.h"
#include "afxdialogex.h"
#include "afxdao.h"
#include"stdlib.h"
#include <comdef.h>
#include "modActivite.h"


// Activite dialog

IMPLEMENT_DYNAMIC(Activite, CDialogEx)

Activite::Activite(CWnd* pParent /*=NULL*/)
	: CDialogEx(Activite::IDD, pParent)
	, nom_activite(_T(""))
	, nom_village(_T(""))
	, m_delete(_T(""))
	, m_delete1(_T(""))
	, m_find(_T(""))
	, m_find1(_T(""))
{
    add = AfxGetApp()->LoadIcon(IDI_ICON10);
	update  = AfxGetApp()->LoadIcon(IDI_ICON13);
	delet = AfxGetApp()->LoadIcon(IDI_ICON12);
	deletall =AfxGetApp()->LoadIcon(IDI_ICON11);
	Create(IDD_ACTIVITE,pParent);
}

Activite::~Activite()
{
}

void Activite::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, nom_activite);
	DDX_Text(pDX, IDC_EDIT3, nom_village);
	DDX_Control(pDX, IDC_LIST1, liste_activite);
	DDX_Control(pDX, IDC_COMBO2, gratuit);
	DDX_Text(pDX, IDC_EDIT2, m_delete);
	DDX_Text(pDX, IDC_EDIT4, m_delete1);
	DDX_Text(pDX, IDC_EDIT5, m_find);
	DDX_Text(pDX, IDC_EDIT6, m_find1);
	DDX_Control(pDX, IDC_BUTTON1, icon_add);
	DDX_Control(pDX, IDC_BUTTON4, icon_deletall);
	DDX_Control(pDX, IDC_BUTTON3, icon_delet);
	DDX_Control(pDX, IDC_BUTTON2, icon_upadate);
	DDX_Control(pDX, IDC_EDIT1, c_activite);
	DDX_Control(pDX, IDC_EDIT3, c_village);
	DDX_Control(pDX, IDC_EDIT2, s_activite);
	DDX_Control(pDX, IDC_EDIT4, s_village);
	DDX_Control(pDX, IDC_EDIT5, m_village);
	DDX_Control(pDX, IDC_EDIT6, m_activite);
}


BEGIN_MESSAGE_MAP(Activite, CDialogEx)
	//ON_CBN_SELCHANGE(IDC_COMBO1, &Activite::OnSelchangeCombo1)
//	ON_EN_CHANGE(IDC_EDIT1, &Activite::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &Activite::OnAjouter)
	ON_BN_CLICKED(IDC_BUTTON3, &Activite::OnClickedDelete)
	ON_BN_CLICKED(IDC_BUTTON4, &Activite::OnClickedDeleteAll)
	ON_EN_CHANGE(IDC_EDIT3, &Activite::OnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &Activite::OnChangeEdit4)
	//ON_BN_CLICKED(IDC_BUTTON5, &Activite::OnClickedFind)
	ON_BN_CLICKED(IDC_BUTTON2, &Activite::OnClickedUpdate)
	ON_EN_CHANGE(IDC_EDIT6, &Activite::OnChangeEdit6)
END_MESSAGE_MAP()

BOOL Activite::OnInitDialog(){

CDialogEx::OnInitDialog();
c_village.SetCueBanner(L"Village");
c_activite.SetCueBanner(L"Activité du Village");
s_village.SetCueBanner(L"Village");
s_activite.SetCueBanner(L"Activité ");
m_village.SetCueBanner(L"Village");
m_activite.SetCueBanner(L"Activité ");
gratuit.SetCueBanner(L"Gratuite");
        liste_activite.InsertColumn(0,L"Village",LVCFMT_CENTER,130,-1); 	
	    liste_activite.InsertColumn(1,L"Activité",LVCFMT_CENTER,130,-1); 
	    liste_activite.InsertColumn(2,L"Activité gratuite",LVCFMT_CENTER,120,-1); 
	    ListView_SetExtendedListViewStyle(liste_activite,LVS_EX_GRIDLINES); 
	    liste_activite.DeleteAllItems(); 
	    liste_activite.SetBkColor(RGB(255,255,255));// pour colorer la list
		icon_add.SetIcon(add);
	    icon_upadate.SetIcon(update);
	    icon_delet.SetIcon(delet);
	    icon_deletall.SetIcon(deletall);
		this->SetBackgroundColor(RGB(152,152,152));

		GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
		RefreshList();

return TRUE;



}
void Activite::RefreshList()
{	
	CDaoDatabase db;  //déclaration de variable base de donnée  db
	CDaoRecordset recset(&db); //déclaration de variable recset d'enregistrement 

	COleVariant var;//start Variables
	var.ChangeType(VT_BSTR,NULL);
      CString nv,na,g;//end variables
   
   liste_activite.DeleteAllItems();//clear list
   db.Open(L"GestionClubs.mdb");  
   recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT  VILLAGES.NOM,ACTIVITES.DESIGNATION,PROPOSER.GRATUITE FROM ACTIVITES,PROPOSER,VILLAGES WHERE ACTIVITES.NO_ACTIVITE = PROPOSER.NO_ACTIVITE AND VILLAGES.NO_VILLAGE=PROPOSER.NO_VILLAGE",NULL);
  
	   while(!recset.IsEOF())//do until eof
	   {int i=0;
		   
		   recset.GetFieldValue(0, var);
			nv.Format(L"%s",(LPCWSTR)var.pbstrVal);

			liste_activite.InsertItem(i,nv,0);

			recset.GetFieldValue(1,var);
			na.Format(L"%s",(LPCWSTR)var.pbstrVal);
			liste_activite.SetItemText(i,1,na);

			recset.GetFieldValue(2,var);
			g.Format(L"%s",(LPCWSTR)var.pbstrVal);
			liste_activite.SetItemText(i,2,g);
			
			i=i++;
			recset.MoveNext();   }
   
}
// Activite message handlers


void Activite::OnAjouter()
{
	// TODO: Add your control notification handler code here
	CDaoDatabase db3;
    CDaoRecordset recset1(&db3);
    CString V_vil,V_act,V_g;

    
    GetDlgItemText(IDC_EDIT1,V_act);
	GetDlgItemText(IDC_EDIT3, V_vil);
	GetDlgItemText(IDC_COMBO2, V_g);
	
		CString lpszFile=L"GestionClubs.mdb";
		//CString SqlCms3 = L"SELECT Nom from  VILLAGES where Nom='"+V_village+"'";
	
		db3.Open(lpszFile);

		CString code_v=L"";
		for(int i=0;i<3;i++){
			code_v+=V_vil[i];
		}
		
		recset1.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT NO_VILLAGE FROM VILLAGES",NULL);
		
		if(!recset1.Find(AFX_DAO_FIRST,_T("NO_VILLAGE ='"+code_v.MakeUpper()+"'"))){//check village if existent
			AfxMessageBox(L"village n'existe pas,veuillez l'ajouter",MB_ICONINFORMATION|MB_OK);

		}
		else{
			CDaoRecordset recset2(&db3);
			recset2.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT ACTIVITES.DESIGNATION FROM PROPOSER INNER JOIN ACTIVITES ON PROPOSER.NO_ACTIVITE = ACTIVITES.NO_ACTIVITE WHERE PROPOSER.NO_VILLAGE='"+code_v.MakeUpper()+"'",NULL);
			if(recset2.Find(AFX_DAO_FIRST,_T("ACTIVITES.DESIGNATION='"+V_act+"'"))){
				AfxMessageBox(L"cette activité est déjà associé à ce village",MB_ICONINFORMATION|MB_OK);
				recset2.Close();
			
			}
			else{
					
				  CDaoRecordset recset3(&db3);
				  COleVariant var;//start Variables
				  var.ChangeType(VT_BSTR,NULL);
				  recset3.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT NO_ACTIVITE,DESIGNATION FROM ACTIVITES WHERE DESIGNATION='"+V_act+"'",NULL);
				  if(recset3.Find(AFX_DAO_FIRST,_T("designation='"+V_act+"'"))){
						recset3.GetFieldValue(0, var);
						CString x;
						x.Format(L"%d",(LPCWSTR)var.pbstrVal);
						CString cmd=L"INSERT INTO PROPOSER VALUES('"+code_v.MakeUpper()+"','"+x+"','"+V_g+"')";
						db3.Execute(cmd);
						AfxMessageBox(L"Ajout éfféctué",MB_ICONINFORMATION|MB_OK);
						RefreshList();
						
				  
				  }else{
				  
					CString cmd1=L"INSERT INTO ACTIVITES(DESIGNATION) VALUES('"+V_act+"')";
					db3.Execute(cmd1);
					OnAjouter();
				  }
				
				recset2.Close();
			}
			
			
		}

    db3.Close();
    recset1.Close();

    //GetDlgItem(IDC_NUM)->SetWindowText(L"");
    GetDlgItem(IDC_EDIT1)->SetWindowText(L"");
    GetDlgItem(IDC_EDIT3)->SetWindowText(L"");
	GetDlgItem(IDC_COMBO2)->SetWindowText(L"");
   
    RefreshList();	
}


void Activite::OnClickedDelete()
{
	// TODO: Add your control notification handler code here
	CDaoDatabase db;
	CDaoRecordset recset(&db);
	CString lpszFile=L"GestionClubs.mdb";
	db.Open(lpszFile);
	CString V_village,V_activite;
	GetDlgItemText(IDC_EDIT4, V_village);

	CString code_v=L"";
	for(int i=0;i<3;i++){
		code_v+=V_village[i];
	}
	GetDlgItemText(IDC_EDIT2, V_activite);
	CDaoRecordset recset2(&db);
	recset2.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT NO_ACTIVITE ,DESIGNATION FROM ACTIVITES ",NULL);
	if(recset2.Find(AFX_DAO_FIRST,_T("DESIGNATION='"+V_activite+"'")))
	{
			COleVariant var;//start Variables
			var.ChangeType(VT_INT,NULL);
			recset2.GetFieldValue(L"NO_ACTIVITE", var);
			CString no_act;
			no_act.Format(L"%d",(LPCWSTR)var.pbstrVal);
			recset2.Close();

			CDaoRecordset recset9(&db);
			recset9.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT NO_ACTIVITE,NO_VILLAGE FROM PROPOSER WHERE NO_VILLAGE='"+code_v.MakeUpper()+"' AND NO_ACTIVITE="+no_act,NULL);

			if(recset9.Find(AFX_DAO_FIRST,_T("NO_VILLAGE='"+code_v.MakeUpper()+"'"))){


	        CString sql=(L"DELETE FROM PROPOSER WHERE NO_VILLAGE='"+code_v.MakeUpper()+"' AND NO_ACTIVITE="+no_act);

		     const int result = AfxMessageBox(L" Vous êtes sûr ?!!",  MB_YESNO);
		    	switch (result)
			      {
			        case IDYES:
				        db.Execute(sql);
						AfxMessageBox(L"Suppression éfféctuée",MB_ICONINFORMATION|MB_OK);
				        break;
			        case IDNO:
						break;
			       }	
			}else{
				AfxMessageBox(L"Introuvable",MB_ICONINFORMATION|MB_OK);
			}
	 }
	 else{
		 AfxMessageBox(L"Introuvable",MB_ICONINFORMATION|MB_OK);
	   }
				  db.Close();
				recset.Close();
				RefreshList();
				GetDlgItem(IDC_EDIT2)->SetWindowText(L"");
				GetDlgItem(IDC_EDIT4)->SetWindowText(L"");
}


void Activite::OnClickedDeleteAll()
{
	// TODO: Add your control notification handler code here
	CDaoDatabase db;
	CDaoRecordset recset(&db);
	CString lpszFile=L"GestionClubs.mdb";
	db.Open(lpszFile);
	CString sql=L"DELETE FROM PROPOSER";
	const int result = AfxMessageBox(L" Vous êtes sûr ?!!",  MB_YESNO);
	switch (result)
	{
	case IDYES:
		 
			 db.Execute(sql);
		   
				break;
	 case IDNO:
				break;
	}
		recset.Close();
		db.Close();
		RefreshList();
}
bool Activite::checkAjout(){
	CString var1,var2,var3;
    GetDlgItemText(IDC_EDIT1,var1);
    GetDlgItemText(IDC_EDIT3,var2);
	GetDlgItemText(IDC_COMBO2,var3);

    int nTokenPos = 0;
    CString strToken = var2.Tokenize(_T("+"), nTokenPos);

    if(var1 == "" ||strToken == "")
        return false;
    else if(var1 != "" && strToken != "")
        return true;
    return true;
}


void Activite::OnChangeEdit3()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	if(checkAjout()) //&& GetDlgItem(IDC_BUTTON2)==NULL)
		GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	else
		GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
}

bool Activite::checksupression(){
	CString var1,var2;
    GetDlgItemText(IDC_EDIT2,var1);
	GetDlgItemText(IDC_EDIT4,var2);

    int nTokenPos = 0;
    CString strToken = var2.Tokenize(_T("+"), nTokenPos);
    if(var1=="" || strToken == "")
        return false;
    else if( var2 !="" && strToken != "")
        return true;

    return true;
}

void Activite::OnChangeEdit4()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	// TODO:  Add your control notification handler code here
	if(checksupression())
		GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
	else
		GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
}


void Activite::OnClickedFind()
{
	// TODO: Add your control notification handler code here
	CDaoDatabase db3;
	CDaoRecordset recset3(&db3);
	CDaoRecordset recset4(&db3);
	CDaoRecordset recset5(&db3);
	CString V_vil , V_act , V_g ;
	
    CString lpszFile=L"GestionClubs.mdb";
    db3.Open(lpszFile);
    GetDlgItemText(IDC_EDIT5,V_vil);
	GetDlgItemText(IDC_EDIT6,V_act);
	COleVariant var;
	var.ChangeType(VT_BSTR,NULL);
	
	non_trouv=false;
	recset3.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT NOM FROM VILLAGES ",NULL);
	recset4.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT NO_ACTIVITE , DESIGNATION  FROM ACTIVITES",NULL);
	//recset5.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT GRATUITE FROM PROPOSER WHERE NO_VILLAGE='"++"' AND NO_ACTIVITE",NULL);

	if(recset3.Find(AFX_DAO_FIRST,_T("NOM='"+V_vil+"'")) && recset4.Find(AFX_DAO_FIRST,_T("DESIGNATION='"+V_act+"'")))
	{   
		CString V_ville,V_g;
		recset3.GetFieldValue(L"NOM",var);
		V_ville=(LPCWSTR)var.pbstrVal;
		CString code_v=L"";
		for(int i=0;i<3;i++){
			code_v+=V_vil[i];
		}
		CString V_activite;
		recset4.GetFieldValue(L"DESIGNATION",var);
		V_activite=(LPCWSTR)var.pbstrVal;

		recset4.GetFieldValue(L"NO_ACTIVITE", var);
		CString x;
		x.Format(L"%d",(LPCWSTR)var.pbstrVal);
		recset5.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT NO_ACTIVITE,NO_VILLAGE, GRATUITE  FROM PROPOSER WHERE NO_VILLAGE='"+code_v.MakeUpper()+"' AND NO_ACTIVITE="+x,NULL);
			if(recset5.Find(AFX_DAO_FIRST,_T("NO_VILLAGE='"+code_v.MakeUpper()+"'")) && recset5.Find(AFX_DAO_FIRST,_T("NO_ACTIVITE="+x)))
			{
				
								recset5.GetFieldValue(L"GRATUITE",var);
								V_g=(LPCWSTR)var.pbstrVal;
				
			
						UpdateData(false);		 
						vect.push_back(V_ville);
						vect.push_back(V_activite);
						vect.push_back(V_g);
			}
			else{
				non_trouv=true;
				AfxMessageBox(L"village n'est pas associé à cette activité",MB_ICONINFORMATION|MB_OK);
			}
		
	}
	else{
		non_trouv=true;
		AfxMessageBox(L"village ou activité n'existe pas",MB_ICONINFORMATION|MB_OK);
	}
	recset4.Close();
    recset3.Close(); 
    db3.Close();
}


void Activite::OnClickedUpdate()
{
	// TODO: Add your control notification handler code here
	OnClickedFind();
	if(non_trouv==false){
		modActivite md;
		md.v1=vect[0];
		md.v2=vect[1];
		md.v3 = vect[2];
		md.mod_village = vect[0];
	    md.mod_activite = vect[1];
		md.mod_gratuite= vect[2];
		md.DoModal();
		if(md.t==true)
			RefreshList();
	
	}
	GetDlgItem(IDC_EDIT5)->SetWindowText(L"");
	GetDlgItem(IDC_EDIT6)->SetWindowText(L"");
	GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
	vect.clear();
}

void Activite::OnsMod(CString str1,CString str2)
{
	// TODO: Add your control notification handler code here
	CDaoDatabase db;
	CDaoRecordset recset(&db);
	CString lpszFile=L"GestionClubs.mdb";
	db.Open(lpszFile);


	CString code_v=L"";
	for(int i=0;i<3;i++){
		code_v+=str1[i];
	}

	CDaoRecordset recset2(&db);
	recset2.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT NO_ACTIVITE ,DESIGNATION FROM ACTIVITES ",NULL);
	if(recset2.Find(AFX_DAO_FIRST,_T("DESIGNATION='"+str2+"'")))
	{
			COleVariant var;//start Variables
			var.ChangeType(VT_INT,NULL);
			recset2.GetFieldValue(L"NO_ACTIVITE", var);
			CString no_act;
			no_act.Format(L"%d",(LPCWSTR)var.pbstrVal);
			recset2.Close();
	        CString sql=(L"DELETE FROM PROPOSER WHERE NO_VILLAGE='"+code_v.MakeUpper()+"' AND NO_ACTIVITE="+no_act);
		    db.Execute(sql);
	 }
	 else{
		 AfxMessageBox(L"Introuvable",MB_ICONINFORMATION|MB_OK);
	   }
				  db.Close();
				recset.Close();
}

void Activite::Onamod(CString st1,CString st2,CString st3)
{
	// TODO: Add your control notification handler code here
	CDaoDatabase db3;
    CDaoRecordset recset1(&db3);
	
		CString lpszFile=L"GestionClubs.mdb";
		//CString SqlCms3 = L"SELECT Nom from  VILLAGES where Nom='"+V_village+"'";
	    supp=true;
		db3.Open(lpszFile);

		CString code_v=L"";
		for(int i=0;i<3;i++){
			code_v+=st1[i];
		}
		
		recset1.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT NO_VILLAGE FROM VILLAGES",NULL);
		
		if(!recset1.Find(AFX_DAO_FIRST,_T("NO_VILLAGE ='"+code_v.MakeUpper()+"'"))){//check village if existent
			AfxMessageBox(L"village n'existe pas,veuillez l'ajouter",MB_ICONINFORMATION|MB_OK);

		}
		else{
			CDaoRecordset recset2(&db3);
			recset2.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT ACTIVITES.DESIGNATION FROM PROPOSER INNER JOIN ACTIVITES ON PROPOSER.NO_ACTIVITE = ACTIVITES.NO_ACTIVITE WHERE PROPOSER.NO_VILLAGE='"+code_v.MakeUpper()+"'",NULL);
			if(recset2.Find(AFX_DAO_FIRST,_T("ACTIVITES.DESIGNATION='"+st2+"'"))){
				AfxMessageBox(L"cette activité est déjà associé à ce village",MB_ICONINFORMATION|MB_OK);
				recset2.Close();
			
			}
			else{
				   supp=false;
				  CDaoRecordset recset3(&db3);
				  COleVariant var;//start Variables
				  var.ChangeType(VT_BSTR,NULL);
				  recset3.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT NO_ACTIVITE,DESIGNATION FROM ACTIVITES WHERE DESIGNATION='"+st2+"'",NULL);
				  if(recset3.Find(AFX_DAO_FIRST,_T("designation='"+st2+"'"))){
						recset3.GetFieldValue(0, var);
						CString x;
						x.Format(L"%d",(LPCWSTR)var.pbstrVal);
						CString cmd=L"INSERT INTO PROPOSER VALUES('"+code_v.MakeUpper()+"','"+x+"','"+st3+"')";
						db3.Execute(cmd);
						RefreshList();
						
				  
				  }else{
				  
					CString cmd1=L"INSERT INTO ACTIVITES(DESIGNATION) VALUES('"+st2+"')";
					db3.Execute(cmd1);
					Onamod( st1, st2, st3);
				  }
				
				recset2.Close();
			}
			
			
		}

    db3.Close();
    recset1.Close();	
}

bool Activite::checkfind(){
	CString var1,var2;

    GetDlgItemText(IDC_EDIT5,var1);
    GetDlgItemText(IDC_EDIT6,var2);

    int nTokenPos = 0;
    CString strToken = var2.Tokenize(_T("+"), nTokenPos);

    if(var1=="" || strToken == "")
        return false;
    else if(var1 != "" && strToken != "")
        return true;

    return true;
}



void Activite::OnChangeEdit6()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	if(checkfind())
		GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
	else
		GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
}
