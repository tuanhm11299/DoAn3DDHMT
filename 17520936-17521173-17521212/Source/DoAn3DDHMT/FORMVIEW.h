#pragma once
#include "DoAn3DDHMTView.h"
#include "DoAn3DDHMTDoc.h"
#include "DoAn3DDHMT.h"
#include "MainFrm.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
#define SPHERE 1
#define CONE 2
#define CUBE  3
#define CYLINDER 4
#define TORUS 5
#define TEAPOT 6
#define DISK	7
#define PYRAMID 18
#define OCTAGON 19

#define WIRE 1
#define SOLID 2
#define POINTS 3
//#define SILHOUETTE 4

#define X_VIEW 15
#define Y_VIEW 16
#define Z_VIEW 17

#define ROTATE 10
#define TRANSLATE 11
#define SCALE 12

#define FLAT 13
#define SMOOTH 14


// FORMVIEW form view

class FORMVIEW : public CFormView
{
	DECLARE_DYNCREATE(FORMVIEW)
protected:
	int objectDraw;
	int nLEDType;
	int TypeAffine;
	int TypeShadow;
	int TypeCoordinateView;
	int IDC_Draw_Type;
	int IDC_Type_Affine;
	int IDC_Type_Shadow;
	int IDC_SizeX;
	int IDC_SizeY;
	int IDC_Znear;
	int IDC_Zfar;
	int IDC_Fovy;
	int IDC_Ambient_R;
	int IDC_Ambient_G;
	int IDC_Ambient_B;
	int IDC_Diff_use_R;
	int IDC_Diff_use_G;
	int IDC_Diff_use_B;
	int IDC_Specular_R;
	int IDC_Specular_G;
	int IDC_Specular_B;

	int IDC_Axis_X;
	int IDC_Axis_Y;
	int IDC_Axis_Z;

	int IDC_View_Coordinate;

	int IDC_SpeedRotate;

	int xPointEye;
	int yPointEye;

	BOOL isRotate;
public:
	void UpdateTypeDraw();
	void UpdateTypeAffine();
	void UpdateTypeShadow();
	void UpdateTypeCoordinateView();
	void Reset();

	void is_type_shape();
	void is_set_ambient();
	void is_set_diff_use();
	void is_set_specular();
	void is_set_speedrotate();
	void is_set_axisrotate();

	CString convert_int_to_CString(int value);
	// method of class FormViewBar
public:
	CDoAn3DDHMTView* GetAppView();
protected:
	FORMVIEW();           // protected constructor used by dynamic creation
	virtual ~FORMVIEW();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FORMVIEW };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif
public:
	virtual void OnInitialUpdate();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedDrawCube();
	afx_msg void OnBnClickedDrawTeapot();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedRadio6();
	afx_msg void OnBnClickedRadio9();
	afx_msg void OnBnClickedRadio10();
	afx_msg void OnBnClickedRadio11();
	afx_msg void OnBnClickedRadio7();
	afx_msg void OnBnClickedRadio8();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	CSliderCtrl VSliderBarX;
	CSliderCtrl VSliderBarY;
	CSliderCtrl VSliderBarzNear;
	CSliderCtrl VSliderBarzFar;
	CSliderCtrl VSliderBarFovy;
	CSliderCtrl DiffuseRed;
	CSliderCtrl DiffuseGreen;
	CSliderCtrl DiffuseBlue;
	CSliderCtrl SpecularRed;
	CSliderCtrl SpecularGreen;
	CSliderCtrl SpecularBlue;
	CSliderCtrl AmbientRed;
	CSliderCtrl AmbientGreen;
	CSliderCtrl AmbientBlue;
	CSliderCtrl VSliderBarSpeedRotate;
	CSliderCtrl VSliderBarAxisZ;
	CSliderCtrl VSliderBarAxis_Y;
	CSliderCtrl VSliderBarAxisX;
	CEdit EditControlzNear;
	CEdit EditControlSizeX;
	CEdit EditControlSizeY;
	CEdit EditControlFovy;
	CEdit EditControlzFar;
	CEdit EditControlSpeedRotate;
	CEdit EditControlAxisX;
	CEdit EditControlAxisY;
	CEdit EditControlAxisZ;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};


