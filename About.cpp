// About.cpp : implementation file
//

#include "stdafx.h"
#include "ClubApp.h"
#include "About.h"
#include "afxdialogex.h"


// About dialog

IMPLEMENT_DYNAMIC(About, CDialogEx)

About::About(CWnd* pParent /*=NULL*/)
	: CDialogEx(About::IDD, pParent)
{
	ico = AfxGetApp()->LoadIcon(LOGO);
}

About::~About()
{
}

void About::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

}


BOOL About::OnInitDialog(){
	CDialogEx::OnInitDialog();


	SetIcon(ico, TRUE);			// Set big icon
	SetIcon(ico, FALSE);
	return TRUE;
}


BEGIN_MESSAGE_MAP(About, CDialogEx)
END_MESSAGE_MAP()


// About message handlers
