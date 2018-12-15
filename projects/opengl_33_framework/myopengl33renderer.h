#include "opengl33view.h"

// ----------------------------------------------------------------------------------------------------------------------------

class CMyOpenGL33Renderer : public COpenGL33Renderer
{
public:
	CMyOpenGL33Renderer();
	~CMyOpenGL33Renderer();

	bool Init();
	void Resize(int Width, int Height);
	void Render();
	bool Animate(float FrameTime);
	void Destroy();
};
