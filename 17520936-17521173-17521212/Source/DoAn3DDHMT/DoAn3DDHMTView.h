
// DoAn3DDHMTView.h : interface of the CDoAn3DDHMTView class
//
#include "DoAn3DDHMTDoc.h"
#include <Windows.h>
#include <iostream>
#include "include/GL/GL.H"
#include "include/GL/GLU.H"
#include "include/GL/glut.h"
#include "include/GL/GLAux.h"
#include "include/GL/glext.h"
#include <math.h>
#include <string>
using namespace std;
#pragma comment(lib, "legacy_stdio_definitions.lib")
#pragma once
#define SPHERE 1
#define CONE 2
#define CUBE 3
#define CYLINDER 4
#define TORUS 5
#define TEAPOT 6
#define DISK 7
#define PYRAMID 18
#define OCTAGON 19
#define WIRE 1
#define SOLID 2
#define POINTS 3
#define SILHOUETTE 4
#define INSIDE 1
#define OUTSIDE	2
#define FLAT 13
#define SMOOTH 14
#define CAMERA_PAN 0
#define SCENE_PAN 1
#define CAMERA_ROTATE 2
#define SCENE_ROTATE 3
#define ROTATE 10
#define TRANSLATE 11
#define SCALE 12
#define SELECT 9
#define X_VIEW 15
#define Y_VIEW 16
#define Z_VIEW 17
#define PI 3.1415926535898

class CDoAn3DDHMTView : public CView
{
protected: // create from serialization only
	CDoAn3DDHMTView() noexcept;
	DECLARE_DYNCREATE(CDoAn3DDHMTView)
public:
	int objectDraw;
	int GLPixelIndex;
	int nLEDType;
	int TypeAffine;
	int TypeShadow;
	int speed_rotate;
	int ID_SetTimer;
	int TypeCoordinateView;
	int xPointEye;
	int yPointEye;
	int AxisX;
	int AxisY;
	int AxisZ;
	double Width;
	double Height;
	double fovy;
	double zNear;
	double zFar;
	double xRotation;
	double yRotation;
	double zRotation;
	double xTranslate;
	double yTranslate;
	double zTranslate;
	double xScale;
	double yScale;
	double zScale;
	double angle;
	double AmbientRed;
	double AmbientGreen;
	double AmbientBlue;
	double DiffuseRed;
	double DiffuseGreen;
	double DiffuseBlue;
	double SpecularRed;
	double SpecularGreen;
	double SpecularBlue;
	double RotateAngle;
	double xCoordinate;
	double yCoordinate;
	double zCoordinate;

	char* PathName;
	string path_name;

	BOOL isRotate;
	GLuint texName;
	CPoint lBtnPos;
	BOOL lBtnDown;
	GLUquadricObj* pShape;
	HGLRC hGLContext;

	void Init();
	void DrawCube(int nLEDType);
	void DrawTeapot(int nLEDType);
	void DrawSphere(int nLEDType);
	void DrawCone(int nLEDType);
	void DrawCylinder(int nLEDType);
	void DrawTorus(int nLEDType);
	void DrawDisk(int nLEDType);
	void DrawPyramid(int nLEDType);
	void DrawOctagon(int nLEDType);
	void Pyramid(double size, double height);
	void Octagon(double side, double thickness);
	void Light();
	bool LoadGLTextures();
	AUX_RGBImageRec* LoadBMP(char* Filename, string str);
	// Attributes
public:
	CDoAn3DDHMTDoc* GetDocument() const;

	// Operations
public:

	// Overrides
public:
	void set_draw_cicurlar(int is_draw)
	{
		objectDraw = is_draw;
	}
	void set_draw_type(int type_draw)
	{
		nLEDType = type_draw;
	}
	void set_size_perspective(int SizeX, int SizeY, int zNear, int zFar, int fovy)
	{
		Width = SizeX;
		Height = SizeY;
		this->zNear = zNear;
		this->zFar = zFar;
		this->fovy = fovy;
	}
	void set_affine_type(int TypeAffine)
	{
		this->TypeAffine = TypeAffine;
		lBtnDown = FALSE;
	}
	void set_ambient_rgb(int R, int G, int B)
	{
		AmbientRed = (double)R / 10;
		AmbientGreen = (double)G / 10;
		AmbientBlue = (double)B / 10;
	}
	void set_diff_use_rgb(int R, int G, int B)
	{
		DiffuseRed = (double)R / 10;
		DiffuseGreen = (double)G / 10;
		DiffuseBlue = (double)B / 10;
	}
	void set_specular_rgb(int R, int G, int B)
	{
		SpecularRed = (double)R / 10;
		SpecularGreen = (double)G / 10;
		SpecularBlue = (double)B / 10;
	}
	void set_shadow_type(int TypeShadow)
	{
		this->TypeShadow = TypeShadow;
	}
	void set_status_rotate(BOOL isRotate)
	{
		this->isRotate = isRotate;
		if (this->isRotate == TRUE)
		{
			SetTimer(ID_SetTimer, 50, NULL);
		}
		else
		{
			KillTimer(ID_SetTimer);
		}
	}
	void set_speed_rotate(int speed_rotate)
	{
		this->speed_rotate = speed_rotate;
	}
	void Reset_CComputerGraphicsProjectView()
	{
		CDoAn3DDHMTView::Init();
		CDoAn3DDHMTDoc* pDoc = GetDocument();
		pDoc->is_set_path_texture(path_name);
	}
	void set_coordinate_view(int TypeCoordinateView)
	{
		this->TypeCoordinateView = TypeCoordinateView;
		switch (TypeCoordinateView)
		{
		case X_VIEW:
		{
			xCoordinate = cos(PI / 180 * (yPointEye));
			yCoordinate = 0.0;
			zCoordinate = 0.0;
			break;
		}
		case Y_VIEW:
		{
			xCoordinate = 0.0;
			yCoordinate = cos(PI / 180 * (yPointEye));
			zCoordinate = 0.0;
			break;
		}
		case Z_VIEW:
		{
			xCoordinate = 0.0;
			yCoordinate = 0.0;
			zCoordinate = cos(PI / 180 * (yPointEye));
			break;
		}
		default:
			break;
		}
	}
	void set_point_eye(int xPointEye, int yPointEye)
	{
		this->xPointEye = xPointEye;
		this->yPointEye = yPointEye;
	}
	void set_axis_rotate(int AxisX, int AxisY, int AxisZ)
	{
		this->AxisX = AxisX;
		this->AxisY = AxisY;
		this->AxisZ = AxisZ;
	}
	/*void set_disable_texture()
	{
		glDisable(GL_TEXTURE_2D);
	}*/
	//virtual void loadTexture();
	virtual void Reflection();
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

	// Implementation
public:
	BOOL CreateViewGLContext(HDC hDC);
	BOOL SetWindowPixelFormat(HDC hDC);
	void RenderScene(int objectDraw, int nLEDType);
	void ReShape(double SizeX, double Sizey, double fovy, double zNear, double zFar);
	virtual ~CDoAn3DDHMTView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void Destroy();
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DoAn3DDHMTView.cpp
inline CDoAn3DDHMTDoc* CDoAn3DDHMTView::GetDocument() const
{
	return reinterpret_cast<CDoAn3DDHMTDoc*>(pDocument);
}
#endif

