// Acceuil.cpp : implementation file
//

#include "stdafx.h"
#include "ClubApp.h"
#include "Acceuil.h"
#include "afxdialogex.h"


// Acceuil dialog

IMPLEMENT_DYNAMIC(Acceuil, CDialogEx)

Acceuil::Acceuil(CWnd* pParent /*=NULL*/)
	: CDialogEx(Acceuil::IDD, pParent)
{
	Create(IDD_ACCEUIL,pParent);
}

Acceuil::~Acceuil()
{
}

void Acceuil::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Acceuil, CDialogEx)
END_MESSAGE_MAP()


// Acceuil message handlers
BOOL Acceuil::OnInitDialog(){
	CDialogEx::OnInitDialog();
	return TRUE;
}