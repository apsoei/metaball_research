#include <stdio.h>
#include <vector>
#include <iostream>

#include <ysclass.h>

#include <fssimplewindow.h>

// #include <ysshellext.h>

#include "glutil.h"

////////////////////////////////////////////////////////////

class ApplicationMain
{
public:
	std::vector<float> vtx2d;
	std::vector<float> col2d;
	float tol;
	bool term=false;

	void Draw(void) const;
	bool MustTerminate(void) const;
	void RunOneStep(void);
	ApplicationMain();
	
};

ApplicationMain::ApplicationMain()
{
	int wid,hei;
	FsGetWindowSize(wid,hei);
	tol = 1e-4;
	for(float x = -1; x<1; x+=0.0005)
	{
		for(float y = -1; y<1; y+=0.0005)
		{
			if( (x*x+y*y-1) < tol && (x*x+y*y-1) > -tol)
			{
				vtx2d.push_back(wid/2 + x*10);
				vtx2d.push_back(hei/2 - y*10);
				col2d.push_back(0);col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);
			}
		}
	}
}

void ApplicationMain::RunOneStep(void)
{
	auto key=FsInkey();
	int wid,hei;
	FsGetWindowSize(wid,hei);

	if(key==FSKEY_ESC)
	{
		term = true;
	}
	if(key==FSKEY_SPACE)
	{
std::cout<<__FUNCTION__<<__LINE__<<std::endl;
		for(auto &v : vtx2d)
		{
			// v+=10;
			v = (v-wid/2)*2+wid/2;
		}
std::cout<<__FUNCTION__<<__LINE__<<std::endl;
	}
}

void ApplicationMain::Draw(void) const
{
	int wid,hei;
	FsGetWindowSize(wid,hei);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glDisable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,wid,hei,0,-1,1);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

    glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(4,GL_FLOAT,0,col2d.data());
	glVertexPointer(2,GL_FLOAT,0,vtx2d.data());
	glDrawArrays(GL_POINTS,0,vtx2d.size()/2); 
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

	FsSwapBuffers();
}
bool ApplicationMain::MustTerminate(void) const
{
	return term;
}

int main(void)
{
	FsOpenWindow(0,0,600,600,1);
	ApplicationMain app;
	while(true!=app.MustTerminate())
	{
		FsPollDevice();
		app.RunOneStep();
		app.Draw();
	}

	return 0;
}