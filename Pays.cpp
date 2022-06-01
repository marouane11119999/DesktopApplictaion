// Pays.cpp : implementation file
//

#include "stdafx.h"
#include "ClubApp.h"
#include "Pays.h"
#include "afxdialogex.h"
#include "afxdao.h"
#include "modPays.h"


// Pays dialog

IMPLEMENT_DYNAMIC(Pays, CDialogEx)

Pays::Pays(CWnd* pParent /*=NULL*/)
	: CDialogEx(Pays::IDD, pParent)
	, nom_pays(_T(""))
	, nom_continent(_T(""))
	, v_delete(_T(""))
	, v_find(_T(""))
{
    add = AfxGetApp()->LoadIcon(IDI_ICON10);
	update  = AfxGetApp()->LoadIcon(IDI_ICON13);
	delet = AfxGetApp()->LoadIcon(IDI_ICON12);
	deletall =AfxGetApp()->LoadIcon(IDI_ICON11);
	Create(IDD_PAYS,pParent);
}

Pays::~Pays()
{
}

void Pays::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, nom_pays);
	DDX_Text(pDX, IDC_EDIT2, nom_continent);
	DDX_Control(pDX, IDC_LIST1, liste_pays);

	DDX_Text(pDX, IDC_EDIT3, v_delete);
	DDX_Text(pDX, IDC_EDIT4, v_find);
	DDX_Control(pDX, IDC_AJOUT, icon_add);
	DDX_Control(pDX, IDC_DELETE, icon_delet);
	DDX_Control(pDX, IDC_DELETEALL, icon_deletall);
	DDX_Control(pDX, IDC_UPDATE, icon_update);
	DDX_Control(pDX, IDC_EDIT1, C_nompays);
	DDX_Control(pDX, IDC_EDIT2, C_continent);
	DDX_Control(pDX, IDC_EDIT4, m_pays);
	DDX_Control(pDX, IDC_EDIT3, s_pays);
}


BEGIN_MESSAGE_MAP(Pays, CDialogEx)
	ON_BN_CLICKED(IDC_AJOUT, &Pays::OnClickedAjout)
	ON_BN_CLICKED(IDC_DELETEALL, &Pays::OnClickedDeleteall)
	ON_BN_CLICKED(IDC_DELETE, &Pays::OnClickedDelete)
	ON_BN_CLICKED(IDC_DELETEALL, &Pays::OnClickedDeleteall)
	ON_EN_CHANGE(IDC_EDIT2, &Pays::OnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &Pays::OnChangeEdit3)
	ON_BN_CLICKED(IDC_BUTTON1, &Pays::OnClickedFind)
	ON_BN_CLICKED(IDC_UPDATE, &Pays::OnClickedUpdate)
	ON_EN_CHANGE(IDC_EDIT4, &Pays::OnChangeEdit4)
END_MESSAGE_MAP()

BOOL Pays:: OnInitDialog()
{
		CDialogEx::OnInitDialog();
		this->SetBackgroundColor(RGB(152, 152,152 ));
		C_nompays.SetCueBanner(L"Pays");
	    C_continent.SetCueBanner(L"Continent");
		s_pays.SetCueBanner(L"Pays");
		m_pays.SetCueBanner(L"Pays");
		liste_pays.InsertColumn(0,L"Code Pays",LVCFMT_CENTER,100,-1); 	
	    liste_pays.InsertColumn(1,L"Nom Pays",LVCFMT_CENTER,100,-1); 
	    liste_pays.InsertColumn(2,L"Code Continent",LVCFMT_CENTER,100,-1); 
		liste_pays.InsertColumn(3,L"Nom Continent",LVCFMT_CENTER,100,-1); 
	    ListView_SetExtendedListViewStyle(liste_pays,LVS_EX_GRIDLINES); 
	    liste_pays.DeleteAllItems(); 
	    liste_pays.SetBkColor(RGB(255,255,255));// pour colorer la list
		GetDlgItem(IDC_AJOUT)->EnableWindow(FALSE);
		GetDlgItem(IDC_UPDATE)->EnableWindow(FALSE);
		GetDlgItem(IDC_DELETE)->EnableWindow(FALSE);
		icon_add.SetIcon(add);
	    icon_update.SetIcon(update);
	    icon_delet.SetIcon(delet);
	    icon_deletall.SetIcon(deletall);
		//vGetDlgItem(IDC_DELETEALL)->EnableWindow(FALSE);
	    RefreshList();

		return TRUE;
}
// Pays message handlers
void Pays::RefreshList()
{	
	CDaoDatabase db;  //déclaration de variable base de donnée  db
	CDaoRecordset recset(&db); //déclaration de variable recset d'enregistrement 

	COleVariant var;//start Variables
	var.ChangeType(VT_BSTR,NULL);
    CString code_pays,nom_pays,nom_continent , code_continent;//end variables
   
   liste_pays.DeleteAllItems();//clear list

   db.Open(L"GestionClubs.mdb");  
   recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT PAYS.no_pays,PAYS.Nom,PAYS.no_Continent ,CONTINENTS.Nom FROM PAYS INNER JOIN CONTINENTS ON PAYS.NO_CONTINENT=CONTINENTS.NO_CONTINENT ORDER BY 1 DESC",NULL);
   while(!recset.IsEOF())//do until eof
   {
	 int i=0;
    recset.GetFieldValue(0, var);
	code_pays.Format(L"%s",(LPCWSTR)var.pbstrVal);
	liste_pays.InsertItem(i,code_pays,0);

    recset.GetFieldValue(1,var);
	nom_pays=(LPCWSTR)var.pbstrVal;
	liste_pays.SetItemText(i,1,nom_pays);

	recset.GetFieldValue(2,var);
	code_continent=(LPCWSTR)var.pbstrVal;
	liste_pays.SetItemText(i,2,code_continent);

	recset.GetFieldValue(3,var);
	nom_continent=(LPCWSTR)var.pbstrVal;
	liste_pays.SetItemText(i,3,nom_continent);
	i=i++;
	recset.MoveNext();  
   }
}

void Pays::OnClickedAjout()
{
	CDaoDatabase db3;
    CDaoRecordset recset3(&db3);
    CString V_pays,V_continent;

    
    
	GetDlgItemText(IDC_EDIT1, V_pays);
	GetDlgItemText(IDC_EDIT2, V_continent);
	
	
		CString code_c=L"";
		for(int i=0;i<3;i++){
			code_c+=V_continent[i];
		}
    
		CString code_p=L"";
		for(int i=0;i<3;i++){
			code_p+=V_pays[i];
		}
	
		CString lpszFile=L"GestionClubs.mdb";
		//CString SqlCms3 = L"SELECT Nom from  VILLAGES where Nom='"+V_village+"'";
	
		db3.Open(lpszFile);

		CDaoRecordset recset(&db3);
		recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT Nom from  PAYS",NULL);
		if(!recset.Find(AFX_DAO_FIRST,_T("Nom ='"+V_pays+"'"))){//do until eof

			CString SqlCmd2=L"INSERT INTO PAYS(no_Pays,Nom,no_Continent) VALUES ('"+code_p.MakeUpper()+"', '"+V_pays+"', '"+code_c.MakeUpper()+"');";
		 try
	   {
			db3.Execute(SqlCmd2);
			AfxMessageBox(L"Ajout éfféctué",MB_ICONINFORMATION|MB_OK);
		 }catch (CDaoException* e)
		 {	
			
			CString SqlCmd1=L"INSERT INTO CONTINENTS(no_Continent,Nom) VALUES ('"+code_c.MakeUpper()+"', '"+V_continent+"');";    
			  db3.Execute(SqlCmd1);
			  db3.Execute(SqlCmd2);
			  AfxMessageBox(L"Ajout éfféctué",MB_ICONINFORMATION|MB_OK);
		 }
		}else{
			AfxMessageBox(L"pays déjà existent",MB_ICONINFORMATION|MB_OK);
		}

	
	

    db3.Close();
    recset3.Close();

    //GetDlgItem(IDC_NUM)->SetWindowText(L"");
    GetDlgItem(IDC_EDIT1)->SetWindowText(L"");
    GetDlgItem(IDC_EDIT2)->SetWindowText(L"");
    RefreshList();	
		 
}
		
void Pays::OnClickedDelete()
{
	CDaoDatabase db;
	CDaoRecordset recset(&db);
	CString lpszFile=L"GestionClubs.mdb";
	db.Open(lpszFile);
	CString V_pays;
	GetDlgItemText(IDC_EDIT3, V_pays);
		recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT Nom from  PAYS",NULL);
	CString sql=L"DELETE FROM PAYS WHERE NOM='"+V_pays+"'";
	
	//CDaoRecordset recset1(&db);
	


	const int result = AfxMessageBox(L" Vous êtes sûr ?!!",  MB_YESNO);
switch (result)
{
case IDYES:
			if(recset.Find(AFX_DAO_FIRST,_T("Nom ='"+V_pays+"'"))){
		       try{
			 
					db.Execute(sql);
					AfxMessageBox(L"Suppression éfféctuée",MB_ICONINFORMATION|MB_OK);
			
			
				}catch(CDaoException *e ){
					CString code_p=L"";
					for(int i=0;i<3;i++){
						code_p+=V_pays[i];
						}
					CString sql1=L"DELETE FROM VILLAGES WHERE NO_PAYS='"+code_p.MakeUpper()+"'";
					try{
					db.Execute(sql1);
					db.Execute(sql);
					AfxMessageBox(L"Suppression éfféctuée",MB_ICONINFORMATION|MB_OK);
					}catch(CDaoException *e){
						AfxMessageBox(L"Pays associé à un village ayant une activité ou plus",MB_ICONINFORMATION|MB_OK);
					
					}
				 }
	
			}
			else{
				AfxMessageBox(L"Pays n'existe pas",MB_ICONINFORMATION|MB_OK);
			}
	        break;
 case IDNO:
            break;
}
	  db.Close();
    recset.Close();
    GetDlgItem(IDC_EDIT3)->SetWindowText(L"");
	RefreshList();

}
	



void Pays::OnClickedDeleteall()
{
	// TODO: Add your control notification handler code here
	CDaoDatabase db;
	CDaoRecordset recset(&db);
	CString lpszFile=L"GestionClubs.mdb";
	db.Open(lpszFile); 
	CString SqlCmd=L"DELETE FROM PAYS";
	const int result = AfxMessageBox(L" Vous êtes sûr ?!!",  MB_YESNO);
switch (result)
{
case IDYES:
	 try
	   {
	          db.Execute(SqlCmd);
	   }catch (CDaoException* e)
		 {	
			 AfxMessageBox(L"Veuillez supprime tout les villages D'abord !!",MB_ICONINFORMATION|MB_OK);
	     }
	        break;
 case IDNO:
            break;
}
	recset.Close();
	db.Close();
}
bool Pays::checkAjout(){
	CString var1,var2,var3;
    GetDlgItemText(IDC_EDIT1,var1);
    GetDlgItemText(IDC_EDIT2,var2);

    int nTokenPos = 0;
    CString strToken = var2.Tokenize(_T("+"), nTokenPos);

    if(var1 == "" || strToken == "")
        return false;
    else if(var1 != "" && strToken != "")
        return true;
    return true;
}


void Pays::OnChangeEdit2()
{
	
	if(checkAjout()) //&& GetDlgItem(IDC_BUTTON2)==NULL)
		GetDlgItem(IDC_AJOUT)->EnableWindow(TRUE);
	else
		GetDlgItem(IDC_AJOUT)->EnableWindow(FALSE);
}

bool Pays::checksupression(){
	CString var1;
    GetDlgItemText(IDC_EDIT3,var1);
    int nTokenPos = 0;
    CString strToken = var1.Tokenize(_T("+"), nTokenPos);
    if(strToken == "")
        return false;
    else if(strToken != "")
        return true;

    return true;
}


void Pays::OnChangeEdit3()
{
	if(checksupression())
		GetDlgItem(IDC_DELETE)->EnableWindow(TRUE);
	else
		GetDlgItem(IDC_DELETE)->EnableWindow(FALSE);
}


void Pays::OnClickedFind()
{
	CDaoDatabase db3;
	CDaoRecordset recset3(&db3);

	CString   V_pays , V_Continent , V;
	
    CString lpszFile=L"GestionClubs.mdb";
	
    db3.Open(lpszFile);

    
    GetDlgItemText(IDC_EDIT4,V);
	COleVariant var;
	var.ChangeType(VT_BSTR,NULL);
	non_trouv= false;
	recset3.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT PAYS.Nom ,CONTINENTS.Nom FROM PAYS INNER JOIN CONTINENTS ON PAYS.NO_CONTINENT=CONTINENTS.NO_CONTINENT ",NULL);
	
	if(recset3.Find(AFX_DAO_FIRST,_T("PAYS.Nom='"+V+"'")))
	{
		
		recset3.GetFieldValue(L"PAYS.Nom",var);
		
		V_pays=(LPCWSTR)var.pbstrVal;
		recset3.GetFieldValue(L"CONTINENTS.Nom",var);
		V_Continent=(LPCWSTR)var.pbstrVal;
   
		UpdateData(false);
		//GetDlgItem(IDC_UPDATE)->EnableWindow(TRUE);
		v.push_back(V_pays);
		v.push_back(V_Continent);
	}
	else{
		non_trouv= true;
		AfxMessageBox(L"pays n'existe pas",MB_ICONINFORMATION|MB_OK);
	}
    recset3.Close(); 
    db3.Close();
}


void Pays::OnClickedUpdate()
{
	// TODO: Add your control notification handler code here
	OnClickedFind();
	if(non_trouv==false){
		modPays md;
		md.v1=v[0];
		md.v2=v[1];
		md.mod_pays = v[0];
		md.mod_continent = v[1];
		md.DoModal();
		if(md.t==true)
			RefreshList();
		    
	}
	 GetDlgItem(IDC_EDIT4)->SetWindowText(L"");
	GetDlgItem(IDC_UPDATE)->EnableWindow(FALSE);
	v.clear();
}


void Pays::OnsMod(CString st1)
{
	CDaoDatabase db;
	CDaoRecordset recset(&db);
	CString lpszFile=L"GestionClubs.mdb";
	db.Open(lpszFile);

		recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT Nom from  PAYS",NULL);
	CString sql=L"DELETE FROM PAYS WHERE NOM='"+st1+"'";
			if(recset.Find(AFX_DAO_FIRST,_T("Nom ='"+st1+"'"))){
				 try{
			 
					db.Execute(sql);
			
			
				}catch(CDaoException *e ){
					CString code_p=L"";
					for(int i=0;i<3;i++){
						code_p+=st1[i];
						}
					CString sql1=L"DELETE FROM VILLAGES WHERE NO_PAYS='"+code_p.MakeUpper()+"'";
					db.Execute(sql1);
					db.Execute(sql);
				 }
	
			}
			else{
				AfxMessageBox(L"Pays n'existe pas",MB_ICONINFORMATION|MB_OK);
			}

	  db.Close();
    recset.Close();
}

void Pays::Onamod(CString st1,CString st2)
{
	CDaoDatabase db3;
    CDaoRecordset recset3(&db3);
    CString V_pays,V_continent;
	
	
		CString code_c=L"";
		for(int i=0;i<3;i++){
			code_c+=st2[i];
		}
    
		CString code_p=L"";
		for(int i=0;i<3;i++){
			code_p+=st1[i];
		}
	
		CString lpszFile=L"GestionClubs.mdb";
	
		db3.Open(lpszFile);

		CDaoRecordset recset(&db3);
		recset.Open(AFX_DAO_USE_DEFAULT_TYPE,L"SELECT Nom from  PAYS",NULL);
		if(!recset.Find(AFX_DAO_FIRST,_T("Nom ='"+st1+"'"))){//do until eof

			CString SqlCmd2=L"INSERT INTO PAYS(no_Pays,Nom,no_Continent) VALUES ('"+code_p.MakeUpper()+"', '"+st1+"', '"+code_c.MakeUpper()+"');";
		 try
	   {
			db3.Execute(SqlCmd2);
		 }catch (CDaoException* e)
		 {	
			
			CString SqlCmd1=L"INSERT INTO CONTINENTS(no_Continent,Nom) VALUES ('"+code_c.MakeUpper()+"', '"+st2+"');";    
			  db3.Execute(SqlCmd1);
			  db3.Execute(SqlCmd2);
		 }
		}else{
			AfxMessageBox(L"pays déjà existent",MB_ICONINFORMATION|MB_OK);
		}

    db3.Close();
    recset3.Close();	
		 
}

bool Pays::checkfind()
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

void Pays::OnChangeEdit4()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	if(checkfind())
		GetDlgItem(IDC_UPDATE)->EnableWindow(TRUE);
	else
		GetDlgItem(IDC_UPDATE)->EnableWindow(FALSE);
}
