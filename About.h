#pragma once


// About dialog

class About : public CDialogEx
{
	DECLARE_DYNAMIC(About)

public:
	HICON ico;
	virtual BOOL OnInitDialog();
	About(CWnd* pParent = NULL);   // standard constructor
	virtual ~About();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
