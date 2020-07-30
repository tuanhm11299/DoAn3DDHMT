// FORMVIEW.cpp : implementation file
//

#include "pch.h"
#include "DoAn3DDHMT.h"
#include "FORMVIEW.h"


// FORMVIEW

IMPLEMENT_DYNCREATE(FORMVIEW, CFormView)

FORMVIEW::FORMVIEW()
	: CFormView(IDD_FORMVIEW)
{
	objectDraw = 0;
	nLEDType = POINTS;

	TypeAffine = ROTATE;
	TypeShadow = SMOOTH;
	TypeCoordinateView = X_VIEW;

	IDC_Draw_Type = IDC_RADIO1;
	IDC_Type_Affine = IDC_RADIO4;
	IDC_Type_Shadow = IDC_RADIO7;
	IDC_View_Coordinate = IDC_RADIO9;

	IDC_SizeX = 50;
	IDC_SizeY = 50;
	IDC_Fovy = 90;
	IDC_Znear = 1;
	IDC_Zfar = 80;

	IDC_Ambient_R = 1;
	IDC_Ambient_G = 1;
	IDC_Ambient_B = 1;

	IDC_Diff_use_R = 5;
	IDC_Diff_use_G = 5;
	IDC_Diff_use_B = 5;

	IDC_Specular_R = 10;
	IDC_Specular_G = 10;
	IDC_Specular_B = 10;

	IDC_SpeedRotate = 5.0;

	IDC_Axis_X = 0.0;
	IDC_Axis_Y = 0.0;
	IDC_Axis_Z = 1.0;

	xPointEye = 20.0;
	yPointEye = 20.0;

	isRotate = FALSE;
}

FORMVIEW::~FORMVIEW()
{
}
void FORMVIEW::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	VSliderBarX.SetRange(1, 100, FALSE);
	VSliderBarY.SetRange(1, 100, FALSE);
	VSliderBarFovy.SetRange(0, 180, FALSE);
	VSliderBarzNear.SetRange(1, 10, FALSE);
	VSliderBarzFar.SetRange(1, 100, FALSE);

	AmbientRed.SetRange(0, 10, FALSE);
	AmbientGreen.SetRange(0, 10, FALSE);
	AmbientBlue.SetRange(0, 10, FALSE);

	DiffuseRed.SetRange(0, 10, FALSE);
	DiffuseGreen.SetRange(0, 10, FALSE);
	DiffuseBlue.SetRange(0, 10, FALSE);

	SpecularRed.SetRange(0, 10, FALSE);
	SpecularGreen.SetRange(0, 10, FALSE);
	SpecularBlue.SetRange(0, 10, FALSE);

	VSliderBarSpeedRotate.SetRange(1, 10, FALSE);

	VSliderBarAxisX.SetRange(0, 20);
	VSliderBarAxis_Y.SetRange(0, 20);
	VSliderBarAxisZ.SetRange(0, 20);

	VSliderBarX.SetPos(IDC_SizeX);
	VSliderBarY.SetPos(IDC_SizeY);
	VSliderBarFovy.SetPos(IDC_Fovy);
	VSliderBarzNear.SetPos(IDC_Znear);
	VSliderBarzFar.SetPos(IDC_Zfar);

	AmbientRed.SetPos(IDC_Ambient_R);
	AmbientGreen.SetPos(IDC_Ambient_G);
	AmbientBlue.SetPos(IDC_Ambient_B);

	DiffuseRed.SetPos(IDC_Diff_use_R);
	DiffuseGreen.SetPos(IDC_Diff_use_G);
	DiffuseBlue.SetPos(IDC_Diff_use_B);

	SpecularRed.SetPos(IDC_Specular_R);
	SpecularGreen.SetPos(IDC_Specular_G);
	SpecularBlue.SetPos(IDC_Specular_B);

	VSliderBarSpeedRotate.SetPos(IDC_SpeedRotate);

	VSliderBarAxisX.SetPos(IDC_Axis_X);
	VSliderBarAxis_Y.SetPos(IDC_Axis_Y);
	VSliderBarAxisZ.SetPos(IDC_Axis_Z);

	EditControlzNear.SetWindowTextW(convert_int_to_CString(IDC_Znear));
	EditControlSizeX.SetWindowTextW(convert_int_to_CString(IDC_SizeX));
	EditControlSizeY.SetWindowTextW(convert_int_to_CString(IDC_SizeY));
	EditControlFovy.SetWindowTextW(convert_int_to_CString(IDC_Fovy));
	EditControlzFar.SetWindowTextW(convert_int_to_CString(IDC_Zfar));
	EditControlSpeedRotate.SetWindowTextW(convert_int_to_CString(IDC_SpeedRotate));
	EditControlAxisX.SetWindowTextW(convert_int_to_CString(IDC_Axis_X));
	EditControlAxisY.SetWindowTextW(convert_int_to_CString(IDC_Axis_Y));
	EditControlAxisZ.SetWindowTextW(convert_int_to_CString(IDC_Axis_Z));

	FORMVIEW::UpdateTypeDraw();
	FORMVIEW::UpdateTypeAffine();
	FORMVIEW::UpdateTypeShadow();
	FORMVIEW::UpdateTypeCoordinateView();
}
void FORMVIEW::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	CButton* pButton1 = (CButton*)GetDlgItem(IDC_RADIO1);
	pButton1->SetCheck(true);
	CButton* pButton4 = (CButton*)GetDlgItem(IDC_RADIO4);
	pButton4->SetCheck(true);
	CButton* pButton7 = (CButton*)GetDlgItem(IDC_RADIO7);
	pButton7->SetCheck(true);
	CButton* pButton9 = (CButton*)GetDlgItem(IDC_RADIO9);
	pButton9->SetCheck(true);

	DDX_Control(pDX, IDC_SLIDER1, VSliderBarX);
	DDX_Control(pDX, IDC_SLIDER2, VSliderBarY);
	DDX_Control(pDX, IDC_SLIDER4, VSliderBarzNear);
	DDX_Control(pDX, IDC_SLIDER5, VSliderBarzFar);
	DDX_Control(pDX, IDC_SLIDER3, VSliderBarFovy);
	DDX_Control(pDX, IDC_SLIDER6, AmbientRed);
	DDX_Control(pDX, IDC_SLIDER7, AmbientGreen);
	DDX_Control(pDX, IDC_SLIDER8, AmbientBlue);
	DDX_Control(pDX, IDC_SLIDER9, DiffuseRed);
	DDX_Control(pDX, IDC_SLIDER10, DiffuseGreen);
	DDX_Control(pDX, IDC_SLIDER11, DiffuseBlue);
	DDX_Control(pDX, IDC_SLIDER12, SpecularRed);
	DDX_Control(pDX, IDC_SLIDER13, SpecularGreen);
	DDX_Control(pDX, IDC_SLIDER14, SpecularBlue);
	DDX_Control(pDX, IDC_SLIDER15, VSliderBarSpeedRotate);
	DDX_Control(pDX, IDC_SLIDER18, VSliderBarAxisZ);
	DDX_Control(pDX, IDC_SLIDER16, VSliderBarAxisX);
	DDX_Control(pDX, IDC_SLIDER17, VSliderBarAxis_Y);
	DDX_Control(pDX, IDC_EDIT4, EditControlzNear);
	DDX_Control(pDX, IDC_EDIT1, EditControlSizeX);
	DDX_Control(pDX, IDC_EDIT2, EditControlSizeY);
	DDX_Control(pDX, IDC_EDIT3, EditControlFovy);
	DDX_Control(pDX, IDC_EDIT5, EditControlzFar);
	DDX_Control(pDX, IDC_EDIT6, EditControlSpeedRotate);
	DDX_Control(pDX, IDC_EDIT7, EditControlAxisX);
	DDX_Control(pDX, IDC_EDIT8, EditControlAxisY);
	DDX_Control(pDX, IDC_EDIT9, EditControlAxisZ);
}

BEGIN_MESSAGE_MAP(FORMVIEW, CFormView)
	ON_BN_CLICKED(ID_DRAW_CUBE, &FORMVIEW::OnBnClickedDrawCube)
	ON_BN_CLICKED(ID_DRAW_TEAPOT, &FORMVIEW::OnBnClickedDrawTeapot)
	ON_BN_CLICKED(IDC_BUTTON8, &FORMVIEW::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON1, &FORMVIEW::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &FORMVIEW::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON9, &FORMVIEW::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON2, &FORMVIEW::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &FORMVIEW::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON10, &FORMVIEW::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_RADIO1, &FORMVIEW::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &FORMVIEW::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &FORMVIEW::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &FORMVIEW::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5, &FORMVIEW::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_RADIO6, &FORMVIEW::OnBnClickedRadio6)
	ON_BN_CLICKED(IDC_RADIO9, &FORMVIEW::OnBnClickedRadio9)
	ON_BN_CLICKED(IDC_RADIO10, &FORMVIEW::OnBnClickedRadio10)
	ON_BN_CLICKED(IDC_RADIO11, &FORMVIEW::OnBnClickedRadio11)
	ON_BN_CLICKED(IDC_RADIO7, &FORMVIEW::OnBnClickedRadio7)
	ON_BN_CLICKED(IDC_RADIO8, &FORMVIEW::OnBnClickedRadio8)
	ON_BN_CLICKED(IDC_BUTTON5, &FORMVIEW::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &FORMVIEW::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &FORMVIEW::OnBnClickedButton7)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
	ON_WM_HSCROLL()
	//ON_BN_CLICKED(IDC_BUTTON11, &FORMVIEW::OnBnClickedButton11)
END_MESSAGE_MAP()


// FORMVIEW diagnostics

#ifdef _DEBUG
void FORMVIEW::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void FORMVIEW::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// FORMVIEW message handlers


void FORMVIEW::UpdateTypeDraw()
{
	switch (IDC_Draw_Type)
	{
	case IDC_RADIO1:
	{
		CButton* pButton1 = (CButton*)GetDlgItem(IDC_RADIO1);
		pButton1->SetCheck(true);
		CButton* pButton2 = (CButton*)GetDlgItem(IDC_RADIO2);
		pButton2->SetCheck(false);
		CButton* pButton3 = (CButton*)GetDlgItem(IDC_RADIO3);
		pButton3->SetCheck(false);
		break;
	}
	case IDC_RADIO2:
	{
		CButton* pButton1 = (CButton*)GetDlgItem(IDC_RADIO1);
		pButton1->SetCheck(false);
		CButton* pButton2 = (CButton*)GetDlgItem(IDC_RADIO2);
		pButton2->SetCheck(true);
		CButton* pButton3 = (CButton*)GetDlgItem(IDC_RADIO3);
		pButton3->SetCheck(false);
		break;
	}
	case IDC_RADIO3:
	{
		CButton* pButton1 = (CButton*)GetDlgItem(IDC_RADIO1);
		pButton1->SetCheck(false);
		CButton* pButton2 = (CButton*)GetDlgItem(IDC_RADIO2);
		pButton2->SetCheck(false);
		CButton* pButton3 = (CButton*)GetDlgItem(IDC_RADIO3);
		pButton3->SetCheck(true);
		break;
	}
	default:
		break;
	}
}
void FORMVIEW::UpdateTypeAffine()
{
	switch (IDC_Type_Affine)
	{
	case IDC_RADIO4:
	{
		CButton* pButton4 = (CButton*)GetDlgItem(IDC_RADIO4);
		pButton4->SetCheck(true);
		CButton* pButton5 = (CButton*)GetDlgItem(IDC_RADIO5);
		pButton5->SetCheck(false);
		CButton* pButton6 = (CButton*)GetDlgItem(IDC_RADIO6);
		pButton6->SetCheck(false);
		break;
	}
	case IDC_RADIO5:
	{
		CButton* pButton4 = (CButton*)GetDlgItem(IDC_RADIO4);
		pButton4->SetCheck(false);
		CButton* pButton5 = (CButton*)GetDlgItem(IDC_RADIO5);
		pButton5->SetCheck(true);
		CButton* pButton6 = (CButton*)GetDlgItem(IDC_RADIO6);
		pButton6->SetCheck(false);
		break;
	}
	case IDC_RADIO6:
	{
		CButton* pButton4 = (CButton*)GetDlgItem(IDC_RADIO4);
		pButton4->SetCheck(false);
		CButton* pButton5 = (CButton*)GetDlgItem(IDC_RADIO5);
		pButton5->SetCheck(false);
		CButton* pButton6 = (CButton*)GetDlgItem(IDC_RADIO6);
		pButton6->SetCheck(true);
		break;
	}
	default:
		break;
	}
}
void FORMVIEW::UpdateTypeShadow()
{
	switch (IDC_Type_Shadow)
	{
	case IDC_RADIO7:
	{
		CButton* pButton7 = (CButton*)GetDlgItem(IDC_RADIO7);
		pButton7->SetCheck(true);
		CButton* pButton8 = (CButton*)GetDlgItem(IDC_RADIO8);
		pButton8->SetCheck(false);
		break;
	}
	case IDC_RADIO8:
	{
		CButton* pButton7 = (CButton*)GetDlgItem(IDC_RADIO7);
		pButton7->SetCheck(false);
		CButton* pButton8 = (CButton*)GetDlgItem(IDC_RADIO8);
		pButton8->SetCheck(true);
		break;
	}
	default:
		break;
	}
}
void FORMVIEW::UpdateTypeCoordinateView()
{
	switch (IDC_View_Coordinate)
	{
	case IDC_RADIO9:
	{
		CButton* pButton9 = (CButton*)GetDlgItem(IDC_RADIO9);
		pButton9->SetCheck(true);
		CButton* pButton10 = (CButton*)GetDlgItem(IDC_RADIO10);
		pButton10->SetCheck(false);
		CButton* pButton11 = (CButton*)GetDlgItem(IDC_RADIO11);
		pButton11->SetCheck(false);
		break;
	}
	case IDC_RADIO10:
	{
		CButton* pButton9 = (CButton*)GetDlgItem(IDC_RADIO9);
		pButton9->SetCheck(false);
		CButton* pButton10 = (CButton*)GetDlgItem(IDC_RADIO10);
		pButton10->SetCheck(true);
		CButton* pButton11 = (CButton*)GetDlgItem(IDC_RADIO11);
		pButton11->SetCheck(false);
		break;
	}
	case IDC_RADIO11:
	{
		CButton* pButton9 = (CButton*)GetDlgItem(IDC_RADIO9);
		pButton9->SetCheck(false);
		CButton* pButton10 = (CButton*)GetDlgItem(IDC_RADIO10);
		pButton10->SetCheck(false);
		CButton* pButton11 = (CButton*)GetDlgItem(IDC_RADIO11);
		pButton11->SetCheck(true);
		break;
	}
	default:
		break;
	}
}
void FORMVIEW::Reset()
{
	objectDraw = 0;
	nLEDType = POINTS;

	TypeAffine = ROTATE;
	TypeShadow = SMOOTH;
	TypeCoordinateView = X_VIEW;

	IDC_Draw_Type = IDC_RADIO1;
	IDC_Type_Affine = IDC_RADIO4;
	IDC_Type_Shadow = IDC_RADIO7;
	IDC_View_Coordinate = IDC_RADIO9;

	IDC_SizeX = 50;
	IDC_SizeY = 50;
	IDC_Fovy = 90;
	IDC_Znear = 1;
	IDC_Zfar = 80;

	IDC_Ambient_R = 1;
	IDC_Ambient_G = 1;
	IDC_Ambient_B = 1;

	IDC_Diff_use_R = 5;
	IDC_Diff_use_G = 5;
	IDC_Diff_use_B = 5;

	IDC_Specular_R = 10;
	IDC_Specular_G = 10;
	IDC_Specular_B = 10;

	IDC_SpeedRotate = 5.0;

	IDC_Axis_X = 0.0;
	IDC_Axis_Y = 0.0;
	IDC_Axis_Z = 1.0;

	xPointEye = 20.0;
	yPointEye = 20.0;

	EditControlzNear.SetWindowTextW(convert_int_to_CString(IDC_Znear));
	EditControlSizeX.SetWindowTextW(convert_int_to_CString(IDC_SizeX));
	EditControlSizeY.SetWindowTextW(convert_int_to_CString(IDC_SizeY));
	EditControlFovy.SetWindowTextW(convert_int_to_CString(IDC_Fovy));
	EditControlzFar.SetWindowTextW(convert_int_to_CString(IDC_Zfar));
	EditControlSpeedRotate.SetWindowTextW(convert_int_to_CString(IDC_SpeedRotate));
	EditControlAxisX.SetWindowTextW(convert_int_to_CString(IDC_Axis_X));
	EditControlAxisY.SetWindowTextW(convert_int_to_CString(IDC_Axis_Y));
	EditControlAxisZ.SetWindowTextW(convert_int_to_CString(IDC_Axis_Z));

	isRotate = FALSE;
	CButton* pButton1 = (CButton*)GetDlgItem(IDC_RADIO1);
	pButton1->SetCheck(true);
	CButton* pButton2 = (CButton*)GetDlgItem(IDC_RADIO2);
	pButton2->SetCheck(false);
	CButton* pButton3 = (CButton*)GetDlgItem(IDC_RADIO3);
	pButton3->SetCheck(false);
	CButton* pButton4 = (CButton*)GetDlgItem(IDC_RADIO4);
	pButton4->SetCheck(true);
	CButton* pButton5 = (CButton*)GetDlgItem(IDC_RADIO5);
	pButton5->SetCheck(false);
	CButton* pButton6 = (CButton*)GetDlgItem(IDC_RADIO6);
	pButton6->SetCheck(false);
	CButton* pButton7 = (CButton*)GetDlgItem(IDC_RADIO7);
	pButton7->SetCheck(true);
	CButton* pButton8 = (CButton*)GetDlgItem(IDC_RADIO8);
	pButton8->SetCheck(false);
	CButton* pButton9 = (CButton*)GetDlgItem(IDC_RADIO9);
	pButton9->SetCheck(true);
	CButton* pButton10 = (CButton*)GetDlgItem(IDC_RADIO10);
	pButton10->SetCheck(false);
	CButton* pButton11 = (CButton*)GetDlgItem(IDC_RADIO11);
	pButton11->SetCheck(false);
	FORMVIEW::OnInitialUpdate();
	if (GetAppView())
	{
		GetAppView()->set_status_rotate(isRotate);
		GetAppView()->Reset_CComputerGraphicsProjectView();
		GetAppView()->Invalidate(FALSE);
	}
}
void FORMVIEW::is_type_shape()
{
	if (GetAppView())
	{
		GetAppView()->set_size_perspective(IDC_SizeX, IDC_SizeY, IDC_Znear, IDC_Zfar, IDC_Fovy);
		GetAppView()->Invalidate(FALSE);
	}
}

void FORMVIEW::is_set_ambient()
{
	if (GetAppView())
	{
		GetAppView()->set_ambient_rgb(IDC_Ambient_R, IDC_Ambient_G, IDC_Ambient_B);
		GetAppView()->Invalidate(FALSE);
	}
}

void FORMVIEW::is_set_diff_use()
{
	if (GetAppView())
	{
		GetAppView()->set_diff_use_rgb(IDC_Diff_use_R, IDC_Diff_use_G, IDC_Diff_use_B);
		GetAppView()->Invalidate(FALSE);
	}
}

void FORMVIEW::is_set_specular()
{
	if (GetAppView())
	{
		GetAppView()->set_specular_rgb(IDC_Specular_R, IDC_Specular_G, IDC_Specular_B);
		GetAppView()->Invalidate(FALSE);
	}
}

void FORMVIEW::is_set_speedrotate()
{
	if (GetAppView())
	{
		GetAppView()->set_speed_rotate(IDC_SpeedRotate);
		GetAppView()->Invalidate(FALSE);
	}
}

void FORMVIEW::is_set_axisrotate()
{
	if (GetAppView())
	{
		GetAppView()->set_axis_rotate(IDC_Axis_X, IDC_Axis_Y, IDC_Axis_Z);
		GetAppView()->Invalidate(FALSE);
	}
}

CString FORMVIEW::convert_int_to_CString(int value)
{
	CString str;
	str.Format(_T("%d"), value);
	return str;
}
CDoAn3DDHMTView* FORMVIEW::GetAppView()
{
	CDoAn3DDHMTApp* pApp = (CDoAn3DDHMTApp*)AfxGetApp();
	CMainFrame* pMainFrame = (CMainFrame*)pApp->m_pMainWnd;
	CDoAn3DDHMTView* pLeftView = (CDoAn3DDHMTView*)pMainFrame->GetMainView();
	return pLeftView;
}
void FORMVIEW::OnBnClickedDrawCube()
{
	objectDraw = CUBE;
	if (GetAppView())
	{
		GetAppView()->set_draw_cicurlar(objectDraw);
		GetAppView()->Invalidate(FALSE);
	}
	// TODO: Add your control notification handler code here
}


void FORMVIEW::OnBnClickedDrawTeapot()
{
	objectDraw = TEAPOT;
	if (GetAppView())
	{
		GetAppView()->set_draw_cicurlar(objectDraw);
		GetAppView()->Invalidate(FALSE);
	}
	// TODO: Add your control notification handler code here
}


void FORMVIEW::OnBnClickedButton8()
{
	objectDraw = DISK;
	if (GetAppView())
	{
		GetAppView()->set_draw_cicurlar(objectDraw);
		GetAppView()->Invalidate(FALSE);
	}
	// TODO: Add your control notification handler code here
}


void FORMVIEW::OnBnClickedButton1()
{
	objectDraw = SPHERE;
	if (GetAppView())
	{
		GetAppView()->set_draw_cicurlar(objectDraw);
		GetAppView()->Invalidate(FALSE);
	}
	// TODO: Add your control notification handler code here
}


void FORMVIEW::OnBnClickedButton4()
{
	objectDraw = TORUS;
	if (GetAppView())
	{
		GetAppView()->set_draw_cicurlar(objectDraw);
		GetAppView()->Invalidate(FALSE);
	}
	// TODO: Add your control notification handler code here
}


void FORMVIEW::OnBnClickedButton9()
{
	objectDraw = PYRAMID;
	if (GetAppView())
	{
		GetAppView()->set_draw_cicurlar(objectDraw);
		GetAppView()->Invalidate(FALSE);
	}
	// TODO: Add your control notification handler code here
}


void FORMVIEW::OnBnClickedButton2()
{
	objectDraw = CONE;
	if (GetAppView())
	{
		GetAppView()->set_draw_cicurlar(objectDraw);
		GetAppView()->Invalidate(FALSE);
	}
	// TODO: Add your control notification handler code here
}


void FORMVIEW::OnBnClickedButton3()
{
	objectDraw = CYLINDER;
	if (GetAppView())
	{
		GetAppView()->set_draw_cicurlar(objectDraw);
		GetAppView()->Invalidate(FALSE);
	}
	// TODO: Add your control notification handler code here
}


void FORMVIEW::OnBnClickedButton10()
{
	objectDraw = OCTAGON;
	if (GetAppView())
	{
		GetAppView()->set_draw_cicurlar(objectDraw);
		GetAppView()->Invalidate(FALSE);
	}
	// TODO: Add your control notification handler code here
}


void FORMVIEW::OnBnClickedRadio1()
{
	nLEDType = POINTS;
	IDC_Draw_Type = IDC_RADIO1;
	if (GetAppView())
	{
		GetAppView()->set_draw_type(nLEDType);
		GetAppView()->Invalidate(FALSE);
	}
	// TODO: Add your control notification handler code here
}


void FORMVIEW::OnBnClickedRadio2()
{
	nLEDType = WIRE;
	IDC_Draw_Type = IDC_RADIO2;
	if (GetAppView())
	{
		GetAppView()->set_draw_type(nLEDType);
		GetAppView()->Invalidate(FALSE);
	}
	// TODO: Add your control notification handler code here
}


void FORMVIEW::OnBnClickedRadio3()
{
	nLEDType = SOLID;
	IDC_Draw_Type = IDC_RADIO3;
	if (GetAppView())
	{
		GetAppView()->set_draw_type(nLEDType);;
		GetAppView()->Invalidate(FALSE);
	}
	// TODO: Add your control notification handler code here
}


void FORMVIEW::OnBnClickedRadio4()
{
	TypeAffine = ROTATE;
	IDC_Type_Affine = IDC_RADIO4;
	if (GetAppView())
	{
		GetAppView()->set_affine_type(TypeAffine);
		GetAppView()->Invalidate(FALSE);
	}
	// TODO: Add your control notification handler code here
}


void FORMVIEW::OnBnClickedRadio5()
{
	TypeAffine = TRANSLATE;
	IDC_Type_Affine = IDC_RADIO5;
	if (GetAppView())
	{
		GetAppView()->set_affine_type(TypeAffine);
		GetAppView()->Invalidate(FALSE);
	}
	// TODO: Add your control notification handler code here
}


void FORMVIEW::OnBnClickedRadio6()
{
	TypeAffine = SCALE;
	IDC_Type_Affine = IDC_RADIO6;
	if (GetAppView())
	{
		GetAppView()->set_affine_type(TypeAffine);
		GetAppView()->Invalidate(FALSE);
	}
	// TODO: Add your control notification handler code here
}


void FORMVIEW::OnBnClickedRadio9()
{
	TypeCoordinateView = X_VIEW;
	IDC_View_Coordinate = IDC_RADIO9;
	if (GetAppView())
	{
		GetAppView()->set_coordinate_view(TypeCoordinateView);
		GetAppView()->Invalidate(FALSE);
	}
	// TODO: Add your control notification handler code here
}


void FORMVIEW::OnBnClickedRadio10()
{
	TypeCoordinateView = Y_VIEW;
	IDC_View_Coordinate = IDC_RADIO10;
	if (GetAppView())
	{
		GetAppView()->set_coordinate_view(TypeCoordinateView);
		GetAppView()->Invalidate(FALSE);
	}
	// TODO: Add your control notification handler code here
}


void FORMVIEW::OnBnClickedRadio11()
{
	TypeCoordinateView = Z_VIEW;
	IDC_View_Coordinate = IDC_RADIO11;
	if (GetAppView())
	{
		GetAppView()->set_coordinate_view(TypeCoordinateView);
		GetAppView()->Invalidate(FALSE);
	}
	// TODO: Add your control notification handler code here
}


void FORMVIEW::OnBnClickedRadio7()
{
	TypeShadow = SMOOTH;
	IDC_Type_Shadow = IDC_RADIO7;
	if (GetAppView())
	{
		GetAppView()->set_shadow_type(TypeShadow);
		GetAppView()->Invalidate(FALSE);
	}
	// TODO: Add your control notification handler code here
}


void FORMVIEW::OnBnClickedRadio8()
{
	TypeShadow = FLAT;
	IDC_Type_Shadow = IDC_RADIO8;
	if (GetAppView())
	{
		GetAppView()->set_shadow_type(TypeShadow);
		GetAppView()->Invalidate(FALSE);
	}
	// TODO: Add your control notification handler code here
}


void FORMVIEW::OnBnClickedButton5()
{
	isRotate = TRUE;
	if (GetAppView())
	{
		GetAppView()->set_status_rotate(isRotate);
		GetAppView()->Invalidate(FALSE);
	}
	// TODO: Add your control notification handler code here
}


void FORMVIEW::OnBnClickedButton6()
{
	isRotate = FALSE;
	if (GetAppView())
	{
		GetAppView()->set_status_rotate(isRotate);
		GetAppView()->Invalidate(FALSE);
	}
	// TODO: Add your control notification handler code here
}


void FORMVIEW::OnBnClickedButton7()
{
	FORMVIEW::Reset();
	// TODO: Add your control notification handler code here
}

void FORMVIEW::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: Add your message handler code here and/or call default
	switch (pScrollBar->GetDlgCtrlID())
	{
	case IDC_SLIDER1:
	{
		IDC_SizeX = VSliderBarX.GetPos();
		EditControlSizeX.SetWindowTextW(convert_int_to_CString(IDC_SizeX));
		FORMVIEW::is_type_shape();
		break;
	}
	case IDC_SLIDER2:
	{
		IDC_SizeY = VSliderBarY.GetPos();
		EditControlSizeY.SetWindowTextW(convert_int_to_CString(IDC_SizeY));
		FORMVIEW::is_type_shape();
		break;
	}
	case IDC_SLIDER3:
	{
		IDC_Fovy = VSliderBarFovy.GetPos();
		EditControlFovy.SetWindowTextW(convert_int_to_CString(IDC_Fovy));
		FORMVIEW::is_type_shape();
		break;
	}
	case IDC_SLIDER4:
	{
		IDC_Znear = VSliderBarzNear.GetPos();
		EditControlzNear.SetWindowTextW(convert_int_to_CString(IDC_Znear));
		FORMVIEW::is_type_shape();
		break;
	}
	case IDC_SLIDER5:
	{
		IDC_Zfar = VSliderBarzFar.GetPos();
		EditControlzFar.SetWindowTextW(convert_int_to_CString(IDC_Zfar));
		FORMVIEW::is_type_shape();
		break;
	}
	case IDC_SLIDER6:
	{
		IDC_Ambient_R = AmbientRed.GetPos();
		FORMVIEW::is_set_ambient();
		break;
	}
	case IDC_SLIDER7:
	{
		IDC_Ambient_G = AmbientGreen.GetPos();
		FORMVIEW::is_set_ambient();
		break;
	}
	case IDC_SLIDER8:
	{
		IDC_Ambient_B = AmbientBlue.GetPos();
		FORMVIEW::is_set_ambient();
		break;
	}
	case IDC_SLIDER9:
	{
		IDC_Diff_use_R = DiffuseRed.GetPos();
		FORMVIEW::is_set_diff_use();
		break;
	}
	case IDC_SLIDER10:
	{
		IDC_Diff_use_G = DiffuseGreen.GetPos();
		FORMVIEW::is_set_diff_use();
		break;
	}
	case IDC_SLIDER11:
	{
		IDC_Diff_use_B = DiffuseBlue.GetPos();
		FORMVIEW::is_set_diff_use();
		break;
	}
	case IDC_SLIDER12:
	{
		IDC_Specular_R = SpecularRed.GetPos();
		FORMVIEW::is_set_specular();
		break;
	}
	case IDC_SLIDER13:
	{
		IDC_Specular_G = SpecularGreen.GetPos();
		FORMVIEW::is_set_specular();
		break;
	}
	case IDC_SLIDER14:
	{
		IDC_Specular_B = SpecularBlue.GetPos();
		FORMVIEW::is_set_specular();
		break;
	}
	case IDC_SLIDER15:
	{
		IDC_SpeedRotate = VSliderBarSpeedRotate.GetPos();
		EditControlSpeedRotate.SetWindowTextW(convert_int_to_CString(IDC_SpeedRotate));
		FORMVIEW::is_set_speedrotate();
		break;
	}
	case IDC_SLIDER16:
	{
		IDC_Axis_X = VSliderBarAxisX.GetPos();
		EditControlAxisX.SetWindowTextW(convert_int_to_CString(IDC_Axis_X));
		FORMVIEW::is_set_axisrotate();
		break;
	}
	case IDC_SLIDER17:
	{
		IDC_Axis_Y = VSliderBarAxis_Y.GetPos();
		EditControlAxisY.SetWindowTextW(convert_int_to_CString(IDC_Axis_Y));
		FORMVIEW::is_set_axisrotate();
		break;
	}
	case IDC_SLIDER18:
	{
		IDC_Axis_Z = VSliderBarAxisZ.GetPos();
		EditControlAxisZ.SetWindowTextW(convert_int_to_CString(IDC_Axis_Z));
		FORMVIEW::is_set_axisrotate();
		break;
	}
	default:
		break;
	}
	CFormView::OnHScroll(nSBCode, nPos, pScrollBar);
}
