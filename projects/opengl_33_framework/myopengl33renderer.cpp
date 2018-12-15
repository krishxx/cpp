#include "myopengl33renderer.h"

// ----------------------------------------------------------------------------------------------------------------------------

CMyOpenGL33Renderer::CMyOpenGL33Renderer()
{
}

CMyOpenGL33Renderer::~CMyOpenGL33Renderer()
{
}

bool CMyOpenGL33Renderer::Init()
{
	return true;
}

void CMyOpenGL33Renderer::Resize(int Width, int Height)
{
	this->Width = Width;
	this->Width = Height;

	glViewport(0 , 0, Width, Height);
}

void CMyOpenGL33Renderer::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

bool CMyOpenGL33Renderer::Animate(float FrameTime)
{
	return false;
}

void CMyOpenGL33Renderer::Destroy()
{
}
