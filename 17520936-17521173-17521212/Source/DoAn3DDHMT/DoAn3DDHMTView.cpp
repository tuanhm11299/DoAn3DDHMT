
// DoAn3DDHMTView.cpp : implementation of the CDoAn3DDHMTView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "DoAn3DDHMT.h"
#endif

#include "DoAn3DDHMTDoc.h"
#include "DoAn3DDHMTView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDoAn3DDHMTView

IMPLEMENT_DYNCREATE(CDoAn3DDHMTView, CView)

BEGIN_MESSAGE_MAP(CDoAn3DDHMTView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CDoAn3DDHMTView construction/destruction

CDoAn3DDHMTView::CDoAn3DDHMTView() noexcept
{
	// TODO: add construction code here
	CDoAn3DDHMTView::Init();
	hGLContext = NULL;

}
void CDoAn3DDHMTView::Init()
{
	xRotation = 0.0;
	yRotation = 0.0;
	zRotation = 0.0;
	lBtnPos = (0, 0);
	xTranslate = 0.0;
	yTranslate = 0.0;
	zTranslate = 0.0;
	xScale = 1.0;
	yScale = 1.0;
	zScale = 1.0;
	xPointEye = 20;
	yPointEye = 20;
	xCoordinate = cos(PI / 180 * (yPointEye));
	yCoordinate = 0.0;
	zCoordinate = 0.0;
	AxisX = 0.0;
	AxisY = 0.0;
	AxisZ = 1.0;
	lBtnDown = FALSE;
	isRotate = FALSE;
	PathName = NULL;
	path_name = "";
	texName = NULL;
	objectDraw = 0;
	GLPixelIndex = 0;
	RotateAngle = 0.0;
	nLEDType = POINTS;
	TypeAffine = ROTATE;
	TypeShadow = SMOOTH;
	TypeCoordinateView = X_VIEW;
	pShape = gluNewQuadric();
	Width = 50;
	Height = 50;
	fovy = 90;
	zNear = 1;
	zFar = 80;
	angle = 0;
	AmbientRed = 0.1;
	AmbientGreen = 0.1;
	AmbientBlue = 0.1;
	DiffuseRed = 0.5;
	DiffuseGreen = 0.5;
	DiffuseBlue = 0.5;
	SpecularRed = 1.0;
	SpecularGreen = 1.0;
	SpecularBlue = 1.0;
	speed_rotate = 5.0;
	ID_SetTimer = 1;
	
}
void CDoAn3DDHMTView::DrawCube(int nLEDType)
{
	switch (nLEDType)
	{
	case SOLID:
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		//glBegin(GL_QUADS);
		glutSolidCube(1.2);
		// Front Face
		/*glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
		glTexCoord2f(2.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
		glTexCoord2f(2.0f, 2.0f); glVertex3f(1.0f, 1.0f, 1.0f);
		glTexCoord2f(0.0f, 2.0f); glVertex3f(-1.0f, 1.0f, 1.0f);


		// Back Face
		glTexCoord2f(2.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(2.0f, 2.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
		glTexCoord2f(0.0f, 2.0f); glVertex3f(1.0f, 1.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
		// Top Face
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
		// Bottom Face
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
		// Right face
		glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
		// Left Face
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
		glEnd();*/
		
		//glDisable(GL_TEXTURE_2D);
	}

	case WIRE:
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glutSolidCube(1.2);
		break;
	}

	case POINTS:
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
		glutSolidCube(1.2);
		break;
	}
	}

}

void CDoAn3DDHMTView::DrawTeapot(int nLEDType)
{
	switch (nLEDType)
	{
	case SOLID:
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glutSolidTeapot(1.2);
		break;
	}

	case WIRE:
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glutWireTeapot(1.2);
		break;
	}

	case POINTS:
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
		glutSolidTeapot(1.2);
		break;
	}
	}
}

void CDoAn3DDHMTView::DrawSphere(int nLEDType)
{
	switch (nLEDType)
	{
	case SOLID:
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glutSolidSphere(1, 64, 64);
		break;
	}

	case WIRE:
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glutWireSphere(1, 64, 64);
		break;
	}

	case POINTS:
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
		glutSolidSphere(1, 64, 64);
		break;
	}
	}
}

void CDoAn3DDHMTView::DrawCone(int nLEDType)
{
	switch (nLEDType)
	{
	case SOLID:
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glutSolidCone(0.7, 2.3, 64, 64);
		break;
	}

	case WIRE:
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glutSolidCone(0.7, 2.3, 64, 64);
		break;
	}

	case POINTS:
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
		glutSolidCone(0.7, 2.3, 64, 64);
		break;
	}
	}
}

void CDoAn3DDHMTView::DrawCylinder(int nLEDType)
{
	switch (nLEDType)
	{
	case SOLID:
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		GLUquadricObj* quadratic_obj;
		quadratic_obj = gluNewQuadric();
		gluCylinder(quadratic_obj, 0.5, 0.5, 1.8, 64, 64);
		break;
	}

	case WIRE:
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		GLUquadricObj* quadratic_obj;
		quadratic_obj = gluNewQuadric();
		gluCylinder(quadratic_obj, 0.5, 0.5, 1.8, 64, 64);
		break;
	}

	case POINTS:
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
		GLUquadricObj* quadratic_obj;
		quadratic_obj = gluNewQuadric();
		gluCylinder(quadratic_obj, 0.5, 0.5, 1.8, 64, 64);
		break;
	}
	}
}

void CDoAn3DDHMTView::DrawTorus(int nLEDType)
{
	switch (nLEDType)
	{
	case SOLID:
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glutSolidTorus(0.4, 0.7, 20, 64);
		break;
	}

	case WIRE:
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glutSolidTorus(0.4, 0.7, 20, 64);
		break;
	}

	case POINTS:
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
		glutSolidTorus(0.4, 0.7, 20, 64);
		break;
	}
	}
}
void CDoAn3DDHMTView::DrawDisk(int nLEDType)
{
	switch (nLEDType)
	{
	case SOLID:
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		GLUquadricObj* quadratic_obj;
		quadratic_obj = gluNewQuadric();
		gluDisk(quadratic_obj, 0.5, 1, 48, 64);
		break;
	}

	case WIRE:
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		GLUquadricObj* quadratic_obj;
		quadratic_obj = gluNewQuadric();
		gluDisk(quadratic_obj, 0.5, 1, 48, 64);
		break;
	}

	case POINTS:
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
		GLUquadricObj* quadratic_obj;
		quadratic_obj = gluNewQuadric();
		gluDisk(quadratic_obj, 0.5, 1, 48, 64);
		break;
	}
	}
}
void CDoAn3DDHMTView::DrawPyramid(int nLEDType)
{
	switch (nLEDType)
	{
	case SOLID:
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		Pyramid(1, 1.5);
		break;
	}

	case WIRE:
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		Pyramid(1, 1.5);
		break;
	}

	case POINTS:
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
		Pyramid(1, 1.5);
	}
	}
}
void CDoAn3DDHMTView::DrawOctagon(int nLEDType)
{
	switch (nLEDType)
	{
	case SOLID:
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		Octagon(0.7, 1.5);
		break;
	}

	case WIRE:
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		Octagon(0.7, 1.5);
		break;
	}

	case POINTS:
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
		Octagon(0.7, 1.5);
		break;
	}
	}
}
void CDoAn3DDHMTView::Pyramid(double size, double height)
{
	double half_size = size * 0.5;
	glBegin(GL_TRIANGLES);
	
	glNormal3f(0.0, 0.0, 1.0f);
	glVertex3f(0.0f, height, 0.0f);
	glVertex3f(-half_size, 0, half_size);
	glVertex3f(half_size, 0, half_size);

	//left face
	glNormal3f(-1.0, 0.0, 0.0f);
	glVertex3f(0.0, height, 0.0);
	glVertex3f(-half_size, 0.0, -half_size);
	glVertex3f(-half_size, 0.0, half_size);

	//back face
	glNormal3f(0.0, 0.0, -1.0f);
	glVertex3f(0.0f, height, 0.0f);
	glVertex3f(-half_size, 0, -half_size);
	glVertex3f(half_size, 0, -half_size);

	//Right face
	glNormal3f(1.0, 0.0, 0.0f);
	glVertex3f(0.0, height, 0.0);
	glVertex3f(half_size, 0.0, -half_size);
	glVertex3f(half_size, 0.0, half_size);
	glEnd();

	//Bottom face
	glBegin(GL_QUADS);
	glNormal3f(0.0, -1.0, 0.0f);
	glVertex3f(half_size, 0.0, half_size);
	glVertex3f(half_size, 0.0, -half_size);
	glVertex3f(-half_size, 0.0, -half_size);
	glVertex3f(-half_size, 0.0, half_size);
	glEnd();

}
void CDoAn3DDHMTView::Octagon(double side, double thickness)
{
	double anpha = PI / 4.0;
	float x = sin(anpha) * side;
	float y = 0.5 * side;

	float z = thickness;
	float center_to_mid_size = x + y;
	for (int j = 0; j < 8; j++)
	{
		glPushMatrix();
		glTranslatef(-center_to_mid_size, 0.0, 0.0);
		glBegin(GL_QUADS);
		glNormal3f(-1.0, 0.0, 0.0);
		glVertex3f(0.0, -y, z);
		glVertex3f(0.0, y, z);
		glVertex3f(0.0, y, 0);
		glVertex3f(0.0, -y, 0);
		glEnd();
		glPopMatrix();
		glBegin(GL_TRIANGLES);
		glNormal3f(0.0, 0.0, 1.0);
		glVertex3f(0.0, 0.0, z);
		glVertex3f(-center_to_mid_size, -y, z);
		glVertex3f(-center_to_mid_size, y, z);
		glNormal3f(0.0, 0.0, -1.0);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(-center_to_mid_size, y, 0.0);
		glVertex3f(-center_to_mid_size, -y, 0.0);
		glEnd();
		glRotatef(45.0, 0.0, 0.0, 1.0);
	}

}
void CDoAn3DDHMTView::Light()
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	GLfloat light_pos[] = { 0.0, 1.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	GLfloat ambient[] = { AmbientRed, AmbientGreen, AmbientBlue, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	GLfloat diff_use[] = { DiffuseRed, DiffuseGreen, DiffuseBlue, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
	GLfloat specular[] = { SpecularRed, SpecularGreen, SpecularBlue, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	GLfloat shininess = 60.0f;
	glMateriali(GL_FRONT, GL_SHININESS, shininess);
}

bool CDoAn3DDHMTView::LoadGLTextures()
{
	CDoAn3DDHMTDoc* pDoc = GetDocument();
	path_name = pDoc->texture_name;
	PathName = new char[path_name.size()];
	copy(path_name.begin(), path_name.end(), PathName);
	PathName[path_name.size()] = '\0';
	int ret = false;
	AUX_RGBImageRec* texture_image = NULL;
	//memset(texture_image, 0, sizeof(void*) * 1);
	int size = 0;
	if (texture_image = LoadBMP(PathName, path_name))
	{
		int pet = false;
		//gen texture
		glGenTextures(1, &texName);  
		glBindTexture(GL_TEXTURE_2D, texName);
		//glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		//GL_CLAMP
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		//GL_LINEAR
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		//GL_MODULATE
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

		size = min(texture_image->sizeX, texture_image->sizeY);
		int n = 6;
		while (size > pow(2, n))
		{
			n++;
		}
		/*glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, pow(2, n - 1),
			pow(2, n - 1), 0, GL_RGB,
			GL_UNSIGNED_BYTE, texture_image->data);*/
		//glTexImage2D(GL_TEXTURE_2D, 0, 3, texture_image->sizeX, texture_image->sizeY,0,GL_RGB,GL_UNSIGNED_BYTE,texture_image->data);
		//gluBuild2DMipmaps(GL_TEXTURE_2D, 3, texture_image->sizeX, texture_image->sizeY, GL_RGB, GL_UNSIGNED_BYTE, texture_image->data);
		gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, pow(2, n - 1), pow(2, n - 1), GL_RGB, GL_UNSIGNED_BYTE, texture_image->data);
		gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, texture_image->sizeX, texture_image->sizeY, GL_RGB, GL_UNSIGNED_BYTE, texture_image->data);
	}
	else
	{
		ret = false;
		if (texture_image)
		{
			if (texture_image->data)
				free(texture_image->data);
			free(texture_image);
		}
	}
	
	return ret;
	return false;
}

AUX_RGBImageRec* CDoAn3DDHMTView::LoadBMP(char* Filename, string str)
{
	FILE* File = NULL;
	if (!Filename)
		return NULL;
	fopen_s(&File, Filename, "r");
	int32_t search_index = str.find(".bmp");
	if (File && search_index != -1)
	{
		fclose(File);
		return auxDIBImageLoadA((LPCSTR)Filename);
	}
	return NULL;
}

/*void CDoAn3DDHMTView::loadTexture()
{
	if (LoadGLTextures())
	{
		glColor3f(1.0f, 1.0f, 1.0f);
		// Front Face
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
		glTexCoord2f(2.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
		glTexCoord2f(2.0f, 2.0f); glVertex3f(1.0f, 1.0f, 1.0f);
		glTexCoord2f(0.0f, 2.0f); glVertex3f(-1.0f, 1.0f, 1.0f);


		// Back Face
		glTexCoord2f(2.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(2.0f, 2.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
		glTexCoord2f(0.0f, 2.0f); glVertex3f(1.0f, 1.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
		// Top Face
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
		// Bottom Face
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
		// Right face
		glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
		// Left Face
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
		glEnd();

		glDisable(GL_TEXTURE_2D);
	}
	
}
*/
BOOL CDoAn3DDHMTView::CreateViewGLContext(HDC hDC)
{
	hGLContext = wglCreateContext(hDC);
	if (hGLContext == NULL)
		return FALSE;
	if (wglMakeCurrent(hDC, hGLContext) == FALSE)
		return FALSE;
	return TRUE;
}

BOOL CDoAn3DDHMTView::SetWindowPixelFormat(HDC hDC)
{
	PIXELFORMATDESCRIPTOR pixelDesc;
	pixelDesc.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pixelDesc.nVersion = 1;
	pixelDesc.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER | PFD_STEREO_DONTCARE;
	pixelDesc.iPixelType = PFD_TYPE_RGBA;
	pixelDesc.cColorBits = 32;
	pixelDesc.cRedBits = 8;
	pixelDesc.cRedShift = 16;
	pixelDesc.cGreenBits = 8;
	pixelDesc.cGreenShift = 8;
	pixelDesc.cBlueBits = 8;
	pixelDesc.cBlueShift = 0;
	pixelDesc.cAlphaBits = 0;
	pixelDesc.cAlphaShift = 0;
	pixelDesc.cAccumBits = 64;
	pixelDesc.cAccumRedBits = 16;
	pixelDesc.cAccumGreenBits = 16;
	pixelDesc.cAccumBlueBits = 16;
	pixelDesc.cAccumAlphaBits = 0;
	pixelDesc.cDepthBits = 32;
	pixelDesc.cStencilBits = 8;
	pixelDesc.cAuxBuffers = 0;
	pixelDesc.iLayerType = PFD_MAIN_PLANE;
	pixelDesc.bReserved = 0;
	pixelDesc.dwLayerMask = 0;
	pixelDesc.dwVisibleMask = 0;
	pixelDesc.dwDamageMask = 0;
	GLPixelIndex = ChoosePixelFormat(hDC, &pixelDesc);
	if (GLPixelIndex == 0) // Choose default
	{
		GLPixelIndex = 1;
		if (DescribePixelFormat(hDC, GLPixelIndex,
			sizeof(PIXELFORMATDESCRIPTOR), &pixelDesc) == 0)
			return FALSE;
	}
	if (!SetPixelFormat(hDC, GLPixelIndex, &pixelDesc))
		return FALSE;
	return TRUE;
}

void CDoAn3DDHMTView::RenderScene(int objectDraw, int nLEDType)
{
	double Ex = -4 * sin(PI / 180 * (xPointEye)) * cos(PI / 180 * (yPointEye));
	double Ey = 4 * sin(PI / 180 * (yPointEye));
	double Ez = 4 * cos(PI / 180 * (xPointEye)) * cos(PI / 180 * (yPointEye));
	switch (objectDraw)
	{
	case CUBE:
	{
		gluLookAt(Ex, Ey, Ez, 0.0, 0.0, 0.0, xCoordinate, yCoordinate, zCoordinate);
		CDoAn3DDHMTView::DrawCube(nLEDType);
		break;
	}
	case TEAPOT:
	{
		gluLookAt(Ex, Ey, Ez, 0.0, 0.0, 0.0, xCoordinate, yCoordinate, zCoordinate);
		CDoAn3DDHMTView::DrawTeapot(nLEDType);
		break;
	}
	case SPHERE:
	{
		gluLookAt(Ex, Ey, Ez, 0.0, 0.0, 0.0, xCoordinate, yCoordinate, zCoordinate);
		CDoAn3DDHMTView::DrawSphere(nLEDType);
		break;
	}
	case CONE:
	{
		gluLookAt(Ex, Ey, Ez, 0.0, 0.0, 0.0, xCoordinate, yCoordinate, zCoordinate);
		CDoAn3DDHMTView::DrawCone(nLEDType);
		break;
	}
	case CYLINDER:
	{
		gluLookAt(Ex, Ey, Ez, 0.0, 0.0, 0.0, xCoordinate, yCoordinate, zCoordinate);
		CDoAn3DDHMTView::DrawCylinder(nLEDType);
		break;
	}
	case TORUS:
	{
		gluLookAt(Ex, Ey, Ez, 0.0, 0.0, 0.0, xCoordinate, yCoordinate, zCoordinate);
		CDoAn3DDHMTView::DrawTorus(nLEDType);
		break;
	}
	case DISK:
	{
		gluLookAt(Ex, Ey, Ez, 0.0, 0.0, 0.0, xCoordinate, yCoordinate, zCoordinate);
		CDoAn3DDHMTView::DrawDisk(nLEDType);
		break;
	}
	case PYRAMID:
	{
		gluLookAt(Ex, Ey, Ez, 0.0, 0.0, 0.0, xCoordinate, yCoordinate, zCoordinate);
		CDoAn3DDHMTView::DrawPyramid(nLEDType);
		break;
	}
	case OCTAGON:
	{
		gluLookAt(Ex, Ey, Ez, 0.0, 0.0, 0.0, xCoordinate, yCoordinate, zCoordinate);
		CDoAn3DDHMTView::DrawOctagon(nLEDType);
		break;
	}
	default:
		break;
	}
}

void CDoAn3DDHMTView::ReShape(double SizeX, double SizeY, double fovy, double zNear, double zFar)
{
	double aspect = (double)SizeX / (double)SizeY;
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_COLOR);
	glLoadIdentity();
	gluPerspective(fovy, aspect, zNear, zFar);
	glMatrixMode(GL_MODELVIEW);
	glDrawBuffer(GL_BACK);
	glEnable(GL_DEPTH_TEST);

}

CDoAn3DDHMTView::~CDoAn3DDHMTView()
{
	gluDeleteQuadric(pShape);
}

BOOL CDoAn3DDHMTView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}
void CDoAn3DDHMTView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	HWND hWnd = GetSafeHwnd();
	HDC hDC = ::GetDC(hWnd);
	wglMakeCurrent(hDC, hGLContext);
	CDoAn3DDHMTView::Light();
	switch (TypeShadow)
	{
	case SMOOTH:
	{
		glShadeModel(GL_SMOOTH);
		break;
	}
	case FLAT:
	{
		glShadeModel(GL_FLAT);
		break;
	}
	default:
		break;
	}
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.6f, 0.6f, 0.6f, 1.0f);
	CDoAn3DDHMTView::ReShape(Width, Height, fovy, zNear, zFar);
	CDoAn3DDHMTView::LoadGLTextures();
	glBindTexture(GL_TEXTURE_2D, texName);
	glPushMatrix();
	//glTranslatef(0.0f, 0.0f, -5.0f);//
	//glTranslatef(0.0f, 0.0f, -8.0f);
	//Affine
	glRotatef(xRotation, 1.0f, 0.0f, 0.0f);
	glRotatef(yRotation, 0.0f, 1.0f, 0.0f);
	glRotatef(RotateAngle, AxisX, AxisY, AxisZ);
	//Rotate continuously in real time
	glTranslatef(xTranslate, yTranslate, zTranslate);
	glScalef(xScale, yScale, zScale);
	glFrontFace(GL_CW);
	//loadTexture();//
	RenderScene(objectDraw, nLEDType);
	glPopMatrix();
	SwapBuffers(dc.m_ps.hdc);
}
void CDoAn3DDHMTView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	CSize size(cx, cy);
	// Set OpenGL perspective, viewport and mode
	glViewport(0, 0, size.cx, size.cy);
}

int CDoAn3DDHMTView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	HWND hWnd = GetSafeHwnd();
	HDC hDC = ::GetDC(hWnd);
	if (SetWindowPixelFormat(hDC) == FALSE)
		return 0;
	if (CreateViewGLContext(hDC) == FALSE)
		return 0;
	return 0;
}

void CDoAn3DDHMTView::Destroy()
{
	if (wglGetCurrentContext() != NULL)
		wglMakeCurrent(NULL, NULL);
	if (hGLContext != NULL)
	{
		wglDeleteContext(hGLContext);
		hGLContext = NULL;
	}
	CView::OnDestroy();
}
// CDoAn3DDHMTView drawing

void CDoAn3DDHMTView::OnDraw(CDC* /*pDC*/)
{
	CDoAn3DDHMTDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CDoAn3DDHMTView printing

void CDoAn3DDHMTView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}
BOOL CDoAn3DDHMTView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDoAn3DDHMTView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDoAn3DDHMTView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CDoAn3DDHMTView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDoAn3DDHMTView::OnLButtonUp(UINT nFlags, CPoint point)
{
	lBtnDown = FALSE;
	lBtnPos = point;
	CView::OnLButtonUp(nFlags, point);
}

void CDoAn3DDHMTView::OnLButtonDown(UINT nFlags, CPoint point)
{
	lBtnDown = TRUE;
	lBtnPos = point;
	CView::OnLButtonDown(nFlags, point);
}

void CDoAn3DDHMTView::OnMouseMove(UINT nFlags, CPoint point)
{
	if (lBtnDown)
	{
		switch (TypeAffine)
		{
		case ROTATE:
		{
			yRotation -= (double)(lBtnPos.x - point.x) / 9.0f;
			xRotation -= (double)(lBtnPos.y - point.y) / 9.0f;
			lBtnPos = point;
			Invalidate(FALSE);
			break;
		}
		case TRANSLATE:
		{
			if (isRotate == FALSE)
			{
				xTranslate += (double)(point.x - lBtnPos.x) / 54.0f;
				yTranslate += (double)(point.y - lBtnPos.y) / 54.0f;
				lBtnPos = point;
				Invalidate(FALSE);
			}
			break;
		}
		case SCALE:
		{
			xScale += (double)(point.x - lBtnPos.x) / 27.0f;
			yScale += (double)(point.y - lBtnPos.y) / 27.0f;
			lBtnPos = point;
			Invalidate(FALSE);
			break;
		}
		default:
			break;
		}
	}
	CView::OnMouseMove(nFlags, point);
}

void CDoAn3DDHMTView::OnTimer(UINT nIDEvent)
{
	switch (nIDEvent)
	{
	case 1:
	{
		RotateAngle += speed_rotate;
		Invalidate(FALSE);
	}
	default:
		break;
	}
	CView::OnTimer(nIDEvent);
}
void CDoAn3DDHMTView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS

#endif
}
// CDoAn3DDHMTView diagnostics

#ifdef _DEBUG
void CDoAn3DDHMTView::AssertValid() const
{
	CView::AssertValid();
}

void CDoAn3DDHMTView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDoAn3DDHMTDoc* CDoAn3DDHMTView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDoAn3DDHMTDoc)));
	return (CDoAn3DDHMTDoc*)m_pDocument;
}
#endif //_DEBUG


// CDoAn3DDHMTView message handlers
void CDoAn3DDHMTView::Reflection()
{
	glTranslatef(0.0f, 0.0f, -8.0f);
	glPushMatrix();
	glRotatef(xRotation, 1.0f, 0.0f, 0.0f);
	//RenderScene(objectDraw, nLEDType);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0f, -3.0f, 0.0f);
	glScalef(1.0f, -1.0f, 1.0f);
	glRotatef(xRotation, 1.0f, 0.0f, 0.0f);
	//RenderScene(objectDraw, nLEDType);
	glPopMatrix();
	// Draw bottom of floor
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texName);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-5.0f, -1.5f, 5.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-5.0f, -1.5f, -5.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(5.0f, -1.5f, -5.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(5.0f, -1.5f, 5.0f);
	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}