#pragma once


// Acceuil dialog

class Acceuil : public CDialogEx
{
	DECLARE_DYNAMIC(Acceuil)

public:
	Acceuil(CWnd* pParent = NULL);   // standard constructor
	virtual ~Acceuil();

// Dialog Data
	enum { IDD = IDD_ACCEUIL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	DECLARE_MESSAGE_MAP();
public:
	virtual BOOL OnInitDialog();
	
};



