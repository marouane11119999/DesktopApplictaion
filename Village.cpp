// Village.cpp : implementation file
//
#include<iostream>
#include<cctype>
#include "stdafx.h"
#include "ClubApp.h"
#include "Village.h"
#include "modVillage.h"
#include "afxdialogex.h"
#include "afxdao.h"
#include<vector>
#include<stdlib.h>
#include<stdio.h>



// Village dialog

IMPLEMENT_DYNAMIC(Village, CDialogEx)

Village::Village(CWnd* pParent /*=NULL*/)
	: CDialogEx(Village::IDD, pParent)
	, nom_village(_T(""))
	, nom_pays(_T(""))
	, nom_continent(_T(""))
	, v_supression(_T(""))
	, v_find(_T(""))
{
	add = AfxGetApp()->LoadIcon(IDI_ICON10);
	update  = AfxGetApp()->LoadIcon(IDI_ICON13);
	delet = AfxGetApp()->LoadIcon(IDI_ICON12);
	deletall =AfxGetApp()->LoadIcon(IDI_ICON11);
	Create(IDD_VILLAGES,pParent);

}

Village::~Village()
{
}

void Village::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, nom_village);
	DDX_Text(pDX, IDC_EDIT2, nom_pays);
	DDX_Control(pDX, IDC_LIST1, liste_village);
	DDX_Text(pDX, IDC_EDIT3, nom_continent);
	DDX_Text(pDX, IDC_EDIT4, v_supression);
	DDX_Text(pDX, IDC_EDIT5, v_find);
	DDX_Control(pDX, IDC_BUTTON2, ico_add);
	DDX_Control(pDX, IDC_BUTTON3, icon_delet);
	DDX_Control(pDX, IDC_BUTTON1, icon_add);
	DDX_Control(pDX, IDC_BUTTON4, icon_deletall);
	DDX_Control(pDX, IDC_EDIT1, c_nomvillage);
	DDX_Control(pDX, IDC_EDIT2, c_nompays);
	DDX_Control(pDX, IDC_EDIT3, c_continent);
	DDX_Control(pDX, IDC_EDIT4, s_village);
	DDX_Control(pDX, IDC_EDIT5, m_village);
}



BEGIN_MESSAGE_MAP(Village, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Village::On_ajouter)
	ON_BN_CLICKED(IDC_BUTTON2, &Village::Onmodifier)
	ON_BN_CLICKED(IDC_BUTTON3, &Village::Onsupprimer)
	ON_BN_CLICKED(IDC_BUTTON4, &Village::Onsupprimertout)
	ON_BN_CLICKED(IDC_EDIT5, &Village::OnClickedFind)
	ON_EN_CHANGE(IDC_EDIT1, &Village::OnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT3, &Village::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &Village::OnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT5, &Village::OnChangeFind)
END_MESSAGE_MAP()

BOOL Village::OnInitDialog(){
	CDialogEx::OnInitDialog();
	c_nomvillage.SetCueBanner(L"Village");
	c_nompays.SetCueBanner(L"Pays");
	c_continent.SetCueBanner(L"Continent");
	s_village.SetCueBanner(L"Village");
	m_village.SetCueBanner(L"Village");
	this->SetBackgroundColor(RGB(152,152,152));
	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
	icon_add.SetIcon(add);
	ico_add.SetIcon(update);
	icon_delet.SetIcon(delet);
	icon_deletall.SetIcon(deletall);
	liste_village.InsertColumn(0,L"Code Village",LVCFMT_CENTER,120,-1); 	
	liste_village.InsertColumn(1,L"Nom Village",LVCFMT_CENTER,120,-1); 
	liste_village.InsertColumn(2,L"Nom Pays",LVCFMT_CENTER,120,-1); 
	ListView_SetExtendedListViewStyle(liste_village,LVS_EX_GRIDLINES); 
	liste_village.DeleteAllItems(); 
	liste_village.SetBkColor(RGB(255,255,255));// pour colorer la list
	RefreshList();

	return TRUE;
}
bool Village::checkAjout(){
	CString var1,var2,var3;
    GetDlgItemText(IDC_EDIT1,var1);
    GetDlgItemText(IDC_EDIT2,var2);
	GetDlgItemText(IDC_EDIT3,var3);


    int nTokenPos = 0;
    CString strToken = var3.Tokenize(_T("+"), nTokenPos);

    if(var1 == "" || var2 == "" || strToken == "")
        return false;
    else if(var1 != "" && var2 != "" && strToken != "")
        return true;

    return true;
}

void Village::RefreshList()
{	
	CDaoDatabase db;  //déclaration de variable base de donnée  db
	CDaoRecordset recset(&db); //déclaration de variable recset d'enregistrement 

	COleVariant var;//start Variables
	var.ChangeType(VT_BSTR,NULL);
      CString code_village,nom_village,nom_pays;//end variables
   
   liste_village.DeleteAllItems();//clear list
   db.Open(L"GestionClubs.mdb");  
   recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT VILLAGES.no_village,VILLAGES.Nom,PAYS.Nom FROM VILLAGES  INNER JOIN PAYS ON VILLAGES.NO_PAYS=PAYS.NO_PAYS ORDER BY 1 DESC",NULL);
   while(!recset.IsEOF())//do until eof
   {
	   int i=0;
    recset.GetFieldValue(0, var);
	code_village.Format(L"%s",(LPCWSTR)var.pbstrVal);
	liste_village.InsertItem(i,code_village,0);

    recset.GetFieldValue(1,var);
	nom_village=(LPCWSTR)var.pbstrVal;
	liste_village.SetItemText(i,1,nom_village);
	recset.GetFieldValue(2,var);
	nom_pays=(LPCWSTR)var.pbstrVal;
	liste_village.SetItemText(i,2,nom_pays);
	i=i++;
	recset.MoveNext();   }
}

// Village message handlers


void Village::On_ajouter()
{
	// TODO: Add your control notification handler code here
	CDaoDatabase db3;
    CDaoRecordset recset3(&db3);
    CString V_village,V_pays,V_continent;

    
    GetDlgItemText(IDC_EDIT1,V_village);
	GetDlgItemText(IDC_EDIT2, V_pays);
	GetDlgItemText(IDC_EDIT3, V_continent);
	
	
		CString code_v=L"";
		for(int i=0;i<3;i++){
			code_v+=V_village[i];
		}
    
		CString code_p=L"";
		for(int i=0;i<3;i++){
			code_p+=V_pays[i];
		}
	
		CString lpszFile=L"GestionClubs.mdb";
		//CString SqlCms3 = L"SELECT Nom from  VILLAGES where Nom='"+V_village+"'";
	
		db3.Open(lpszFile);

		CDaoRecordset recset(&db3);
		recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT Nom from  VILLAGES",NULL);
		if(!recset.Find(AFX_DAO_FIRST,_T("Nom ='"+V_village+"'"))){//do until eof

			CString SqlCmd2=L"INSERT INTO VILLAGES(no_Village,Nom,no_Pays) VALUES ('"+code_v.MakeUpper()+"', '"+V_village+"', '"+code_p.MakeUpper()+"');";
		 try
	   {
			db3.Execute(SqlCmd2);
			AfxMessageBox(L"Ajout éfféctué",MB_ICONINFORMATION|MB_OK);
		 }catch (CDaoException* e)
		 {		
			 CString code_c=L"";
			for(int i=0;i<3;i++){
				code_c+=V_continent[i];
				}
			CString SqlCmd1=L"INSERT INTO PAYS(no_Pays,Nom,no_Continent) VALUES ('"+code_p.MakeUpper()+"', '"+V_pays+"', '"+code_c.MakeUpper()+"');";    
			  db3.Execute(SqlCmd1);
			  db3.Execute(SqlCmd2);
			  AfxMessageBox(L"Ajout éfféctué",MB_ICONINFORMATION|MB_OK);
		 }
		}else{
			AfxMessageBox(L"village déjà existent",MB_ICONINFORMATION|MB_OK);
		}

    db3.Close();
    recset3.Close();

    //GetDlgItem(IDC_NUM)->SetWindowText(L"");
    GetDlgItem(IDC_EDIT1)->SetWindowText(L"");
    GetDlgItem(IDC_EDIT2)->SetWindowText(L"");
	GetDlgItem(IDC_EDIT3)->SetWindowText(L"");
    
    RefreshList();	

}


void Village::Onmodifier()
{
	// TODO: Add your control notifhereication handler code 
	OnClickedFind();
	if(non_trouv==false){
		modVillage md;
		md.v1=v[0];
		md.v2=v[1];
		md.v3=v[2];
		md.mod_village = v[0];
		md.mod_pays = v[1];
		md.mod_continent = v[2];
		md.DoModal();
		if(md.t==true)
			RefreshList();
	
	}
	GetDlgItem(IDC_EDIT5)->SetWindowText(L"");
	GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
	v.clear();
}


void Village::Onsupprimer()
{
	// TODO: Add your control notification handler code here
	CDaoDatabase db3;
    CDaoRecordset recset3(&db3);
    CString V_village;
	
    CString lpszFile=L"GestionClubs.mdb";
	//CString SqlCms3 = L"SELECT Nom from  VILLAGES where Nom='"+V_village+"'";
	
    db3.Open(lpszFile);


    GetDlgItemText(IDC_EDIT4,V_village);
	recset3.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT Nom from  VILLAGES",NULL);
	const int result = AfxMessageBox(L" Vous êtes sûr ?!!",  MB_YESNO);
switch (result)
{
case IDYES:
	if(recset3.Find(AFX_DAO_FIRST,_T("Nom ='"+V_village+"'"))){//do until eof

		CString SqlCmd2=L"DELETE FROM VILLAGES WHERE NOM='"+V_village+"'";
	 try
   {
		db3.Execute(SqlCmd2);
		AfxMessageBox(L"Suppression éfféctuée",MB_ICONINFORMATION|MB_OK);
	 }catch (CDaoException* e)
	 {		
		AfxMessageBox(L"village associé à une ou plusieurs activitées",MB_ICONINFORMATION|MB_OK);
	 }
	}else{
		AfxMessageBox(L"village n'existe pas",MB_ICONINFORMATION|MB_OK);
	}

	db3.Close();
    recset3.Close();
	GetDlgItem(IDC_EDIT4)->SetWindowText(L"");
     break;
 case IDNO:
    break;
}
	RefreshList();
}


void Village::Onsupprimertout()
{
	// TODO: Add your control notification handler code here
	CDaoDatabase db;
	CDaoRecordset recset(&db);
	CString lpszFile=L"GestionClubs.mdb";
	db.Open(lpszFile); 
	const int result = AfxMessageBox(L" Vous êtes sûr ?!!",  MB_YESNO);
	CString SqlCmd=L"DELETE FROM VILLAGES";
switch (result)
{
case IDYES:
	db.Execute(SqlCmd);
	recset.Close();
	db.Close();
     break;
 case IDNO:
    break;
}
	RefreshList();
}


void Village::OnClickedFind()
{
	// TODO: Add your control notification handler code here
	CDaoDatabase db3;
	CDaoRecordset recset3(&db3);
	CDaoRecordset recset4(&db3);
	CString V_village , V_pays , V_Continent , V;
	
    CString lpszFile=L"GestionClubs.mdb";
	//CString SqlCms3 = L"SELECT Nom from  VILLAGES where Nom='"+V_village+"'";
	
    db3.Open(lpszFile);

    
    GetDlgItemText(IDC_EDIT5,V);
	COleVariant var;
	var.ChangeType(VT_BSTR,NULL);
	non_trouv=false;
	recset3.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT VILLAGES.Nom as n1,PAYS.Nom as n2,PAYS.no_Continent as c FROM VILLAGES  INNER JOIN PAYS ON VILLAGES.NO_PAYS=PAYS.NO_PAYS",NULL);
	if(recset3.Find(AFX_DAO_FIRST,_T("n1='"+V+"'")))
	{
		recset3.GetFieldValue(L"n1",var);
		V_village=(LPCWSTR)var.pbstrVal;

		recset3.GetFieldValue(L"n2",var);
		V_pays=(LPCWSTR)var.pbstrVal;
	

		recset3.GetFieldValue(L"c",var);
		V_Continent=(LPCWSTR)var.pbstrVal;
	
		
		//GetDlgItemText(IDC_EDIT5,s);
   
		UpdateData(false);
		GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
		v.push_back(V_village);
		v.push_back(V_pays);
		v.push_back(V_Continent);
	}
	else{
		non_trouv=true;
		AfxMessageBox(L"village n'existe pas",MB_ICONINFORMATION|MB_OK);
	}
    recset3.Close(); 
    db3.Close();


}
void Village::OnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	if(checkAjout() && GetDlgItem(IDC_BUTTON2)==NULL)
		GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	else
		GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
}


void Village::OnEnChangeEdit3()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	if(checkAjout())
		GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	else
		GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
}

bool Village::checksupression()
{
	CString var1;
    GetDlgItemText(IDC_EDIT4,var1);


    int nTokenPos = 0;
    CString strToken = var1.Tokenize(_T("+"), nTokenPos);

    if(strToken == "")
        return false;
    else if(strToken != "")
        return true;

    return true;
}

void Village::OnChangeEdit4()
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


void Village::OnsMod(CString st1)
{
	// TODO: Add your control notification handler code here
	CDaoDatabase db3;
    CDaoRecordset recset3(&db3);
    CString V_village;
	
    CString lpszFile=L"GestionClubs.mdb";
	//CString SqlCms3 = L"SELECT Nom from  VILLAGES where Nom='"+V_village+"'";
	
    db3.Open(lpszFile);


    
	recset3.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT Nom from  VILLAGES",NULL);
	

	if(recset3.Find(AFX_DAO_FIRST,_T("Nom ='"+st1+"'"))){//do until eof

		CString SqlCmd2=L"DELETE FROM VILLAGES WHERE NOM='"+st1+"'";
	 try
   {
		db3.Execute(SqlCmd2);
	 }catch (CDaoException* e)
	 {		
		
	 }
	}else{
		AfxMessageBox(L"village n'existe pas",MB_ICONINFORMATION|MB_OK);
	}

	db3.Close();
    recset3.Close();
	//GetDlgItem(IDC_EDIT4)->SetWindowText(L"");
 
	
}

void Village::Onamod(CString st1,CString st2,CString st3)
{
	// TODO: Add your control notification handler code here
	CDaoDatabase db3;
    CDaoRecordset recset3(&db3);
    CString V_village,V_pays,V_continent;

  
	
	    supp = true;
		CString code_v=L"";
		for(int i=0;i<3;i++){
			code_v+=st1[i];
		}
    
		CString code_p=L"";
		for(int i=0;i<3;i++){
			code_p+=st2[i];
		}
	
		CString lpszFile=L"GestionClubs.mdb";
		//CString SqlCms3 = L"SELECT Nom from  VILLAGES where Nom='"+V_village+"'";
	
		db3.Open(lpszFile);

		CDaoRecordset recset(&db3);
		recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT Nom from  VILLAGES",NULL);



		if(!recset.Find(AFX_DAO_FIRST,_T("Nom ='"+st1+"'"))){//do until eof
			 supp = false;
			CString SqlCmd2=L"INSERT INTO VILLAGES(no_Village,Nom,no_Pays) VALUES ('"+code_v.MakeUpper()+"', '"+st1+"', '"+code_p.MakeUpper()+"');";
		 try
	   {     
			db3.Execute(SqlCmd2);
		 }catch (CDaoException* e)
		 {		
			 CString code_c=L"";
			for(int i=0;i<3;i++){
				code_c+=st3[i];
				}
			CString SqlCmd1=L"INSERT INTO PAYS(no_Pays,Nom,no_Continent) VALUES ('"+code_p.MakeUpper()+"', '"+st2+"', '"+code_c.MakeUpper()+"');";    
			  db3.Execute(SqlCmd1);
			  db3.Execute(SqlCmd2);
		 }
		}else{
			AfxMessageBox(L"village déjà existent",MB_ICONINFORMATION|MB_OK);
		}
    db3.Close();
    recset3.Close();

    
    
   

}

bool Village::checkfind(){
	CString var1;
    GetDlgItemText(IDC_EDIT5,var1);


    int nTokenPos = 0;
    CString strToken = var1.Tokenize(_T("+"), nTokenPos);

    if(strToken == "")
        return false;
    else if(strToken != "")
        return true;

    return true;
}

void Village::OnChangeFind()
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
