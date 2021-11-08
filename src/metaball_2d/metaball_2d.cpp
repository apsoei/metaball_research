#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
// #include <ysclass.h>
#include <time.h>
#include <math.h>

#include <fssimplewindow.h>

// #include <ysshellext.h>

// #include "glutil.h"


////////////////////////////////////////////////////////////

class ApplicationMain
{
public:
	std::vector<float> vtx2d;
	std::vector<float> col2d;

    std::vector<float> gridVtx;
	std::vector<float> gridCol;
    
    

	float tol;
	bool term=false;
    int resolution;
    
    

    int ballNum;

	void Draw(void) const;
	bool MustTerminate(void) const;
	void RunOneStep(void);
	ApplicationMain(int argc,char *argv[]);


    
    class Cell
    {
    public:
        // (x,y, scalar value)
        std::vector<int> a ; std::vector<int> b ;
        std::vector<int> c ; std::vector<int> d ;  
        int key;
        bool clean = false;
        int config = 0;

    };
	class Ball
    {
    public:
        float x,y,vx,vy,rad;
    };

    std::vector<Ball> balls;
    std::vector<Cell> cells;

    void update(std::vector<Cell> cells, std::vector<Ball> balls);
    
    

};

// constructor >>
ApplicationMain::ApplicationMain(int argc,char *argv[])
{
	int wid,hei;
	FsGetWindowSize(wid,hei);
	tol = 1e-4;
    ballNum = rand()%8 + 3;
    // ballNum = 1;
    if(argc>=2)
    {
        resolution = atof(argv[1]);
    }
    else
    {
        resolution = 100;
    }
    int x0=0, x1=wid;
    int y0=0, y1=hei;
    auto cellWid = (int)wid/resolution;
    auto cellHei = (int)hei/resolution;
// std::cout <<__FUNCTION__<<__LINE__<<std::endl;
//     std::cout <<cellWid << ", " << cellHei <<std::endl;

    // for(int x = 0; x<wid; x+=(int)wid/resolution)
    for(int x = 0; x<wid; x+= cellWid)
    {
        gridVtx.push_back(x);gridVtx.push_back(y0);
        gridCol.push_back(0);gridCol.push_back(0);gridCol.push_back(0);gridCol.push_back(1);

        gridVtx.push_back(x);gridVtx.push_back(y1);
        gridCol.push_back(0);gridCol.push_back(0);gridCol.push_back(0);gridCol.push_back(1);
        // for(int y = 0; y<hei; y+=(int)hei/resolution)
        for(int y = 0; y<hei; y+=cellHei)
        {
            Cell cell;
            cell.a.push_back(x);         cell.a.push_back(y);         cell.a.push_back(0);
            cell.b.push_back(x+cellWid); cell.b.push_back(y);         cell.b.push_back(0);
            cell.c.push_back(x+cellWid); cell.c.push_back(y+cellHei); cell.c.push_back(0);
            cell.d.push_back(x);         cell.d.push_back(y+cellHei); cell.d.push_back(0);
            cell.key = x*3 + y*5;

            cells.push_back(cell);
        }    
    }
    for(int y = 0; y<hei; y+=(int)hei/resolution)
    {
        gridVtx.push_back(x0);gridVtx.push_back(y);
        gridCol.push_back(0);gridCol.push_back(0);gridCol.push_back(0);gridCol.push_back(1);

        gridVtx.push_back(x1);gridVtx.push_back(y);
        gridCol.push_back(0);gridCol.push_back(0);gridCol.push_back(0);gridCol.push_back(1);

    }

    
    for(int i = 0; i<ballNum; ++i)
    {
        Ball ball;
        
        ball.vx  = (rand()%6 - 3)*0.5;
        ball.vy  = (rand()%6 - 3)*0.5;
        ball.rad = rand()%15 + 20;

        ball.x   = rand()%int(wid-ball.rad) + ball.rad;
        ball.y   = rand()%int(hei-ball.rad) + ball.rad;

        // ball.x = wid/2;
        // ball.y = hei/2;

        // ball.vx  = 0;
        // ball.vy  = 0;
        // ball.rad = 50;

        balls.push_back(ball);
    }

	
}

void ApplicationMain::update(std::vector<Cell> cells, std::vector<Ball> balls)
{
    vtx2d.clear();
    col2d.clear();
    int wid,hei;
	FsGetWindowSize(wid,hei);
    auto cellWid = (float)wid/resolution;
    auto cellHei = (float)hei/resolution;

    for(auto &cell : cells)
    {
        float a = 0,b=0,c=0,d=0;
        for(auto ball : balls)
        {
            // std::cout<< (cell.a[0] - ball.x)*(cell.a[0] - ball.x) <<std::endl;
            a+= (ball.rad*ball.rad) / 
            ((cell.a[0] - ball.x)*(cell.a[0] - ball.x) + (cell.a[1] - ball.y)*(cell.a[1] - ball.y));
            
            b+= (ball.rad*ball.rad) / 
            ((cell.b[0] - ball.x)*(cell.b[0] - ball.x) + (cell.b[1] - ball.y)*(cell.b[1] - ball.y));

            c+= (ball.rad*ball.rad) / 
            ((cell.c[0] - ball.x)*(cell.c[0] - ball.x) + (cell.c[1] - ball.y)*(cell.c[1] - ball.y));

            d+= (ball.rad*ball.rad) / 
            ((cell.d[0] - ball.x)*(cell.d[0] - ball.x) + (cell.d[1] - ball.y)*(cell.d[1] - ball.y));
        }
        
        
        if(a < 1) a =0;
        else a = 1;

        if(b < 1) b =0;
        else b = 1;

        if(c < 1) c =0;
        else c = 1;

        if(d < 1) d =0;
        else d = 1;

        cell.a[2] = a; cell.b[2] = b; cell.c[2] = c; cell.d[2] = d;
        cell.config = (int) (8*a + 4*b + 2*c + 1*d);
        
        
        switch(cell.config)
        {
            // none
            case 0:
                break;

            // d
            case 1:
                vtx2d.push_back(cell.d[0]);             vtx2d.push_back(cell.d[1] - cellHei/2);
                vtx2d.push_back(cell.d[0]+cellWid/2);   vtx2d.push_back(cell.d[1]);

                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                break;
            // c   
            case 2:
                vtx2d.push_back(cell.c[0] - cellWid/2); vtx2d.push_back(cell.c[1]);
                vtx2d.push_back(cell.c[0]);             vtx2d.push_back(cell.c[1] - cellHei/2);

                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                break;
            // c and d
            case 3:
                vtx2d.push_back(cell.d[0]);             vtx2d.push_back(cell.d[1] - cellHei/2);
                vtx2d.push_back(cell.c[0]);             vtx2d.push_back(cell.c[1] - cellHei/2);

                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                break;
            // b
            case 4:
                vtx2d.push_back(cell.b[0] - cellWid/2); vtx2d.push_back(cell.b[1]);
                vtx2d.push_back(cell.b[0]);             vtx2d.push_back(cell.b[1] + cellHei/2);

                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                break;
            // b and d
            case 5:
                vtx2d.push_back(cell.b[0] - cellWid/2); vtx2d.push_back(cell.b[1]);
                vtx2d.push_back(cell.d[0]);             vtx2d.push_back(cell.d[1] - cellHei/2);
                vtx2d.push_back(cell.b[0]);             vtx2d.push_back(cell.b[1] + cellHei/2);
                vtx2d.push_back(cell.d[0] + cellWid/2); vtx2d.push_back(cell.d[1]);   

                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);    
                break;         
            // b and c
            case 6:
                vtx2d.push_back(cell.b[0]-cellWid/2);   vtx2d.push_back(cell.b[1]);
                vtx2d.push_back(cell.c[0]-cellWid/2);   vtx2d.push_back(cell.c[1]);

                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                break;
            // b, c, d
            case 7:
                vtx2d.push_back(cell.b[0]-cellWid/2);   vtx2d.push_back(cell.b[1]);
                vtx2d.push_back(cell.d[0]);             vtx2d.push_back(cell.d[1] - cellHei/2);

                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                break;
            // a
            case 8:
                vtx2d.push_back(cell.a[0]+cellWid/2);   vtx2d.push_back(cell.a[1]);
                vtx2d.push_back(cell.a[0]);             vtx2d.push_back(cell.a[1] + cellHei/2);

                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                break;
            // a, d
            case 9:
                vtx2d.push_back(cell.a[0] + cellWid/2); vtx2d.push_back(cell.a[1]);
                vtx2d.push_back(cell.d[0] + cellWid/2); vtx2d.push_back(cell.d[1]);

                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                break;
            // a, c
            case 10:
                vtx2d.push_back(cell.a[0] + cellWid/2); vtx2d.push_back(cell.a[1]);
                vtx2d.push_back(cell.c[0]);             vtx2d.push_back(cell.c[1] - cellHei/2);
                vtx2d.push_back(cell.a[0]);             vtx2d.push_back(cell.a[1] + cellHei/2);
                vtx2d.push_back(cell.c[0] - cellWid/2); vtx2d.push_back(cell.c[1]); 

                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                break;
            // a, c, d
            case 11:
                vtx2d.push_back(cell.a[0]+cellWid/2);   vtx2d.push_back(cell.a[1]);
                vtx2d.push_back(cell.c[0]);             vtx2d.push_back(cell.c[1] - cellHei/2);

                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                break;
            // a, b
            case 12:
                vtx2d.push_back(cell.a[0]);             vtx2d.push_back(cell.a[1] + cellHei/2);
                vtx2d.push_back(cell.b[0]);             vtx2d.push_back(cell.b[1] + cellHei/2);

                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                break;
            // a, b, d
            case 13:
                vtx2d.push_back(cell.b[0]);             vtx2d.push_back(cell.b[1] + cellHei/2);
                vtx2d.push_back(cell.d[0]+cellWid/2);   vtx2d.push_back(cell.d[1]);

                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                break;
            // a, b, c
            case 14:
                vtx2d.push_back(cell.a[0]);             vtx2d.push_back(cell.a[1] + cellHei/2);
                vtx2d.push_back(cell.c[0] - cellWid/2); vtx2d.push_back(cell.c[1]);

                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                break;
            // a, b, c, d
            case 15:
                break;
        }
        
    }
    // for(auto v : vtx2d)
    // {
    //     if (v > 250 && v < 350)
    //     {
    //         std::cout << v <<std::endl;
    //     }
    // }
    
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

	}

    for(auto &b : balls)
    {
        if(b.x > (wid-b.rad) || b.x <0+b.rad ) b.vx*=-1;
        if(b.y > (hei-b.rad) || b.y <0+b.rad ) b.vy*=-1;
        
        b.x+=b.vx;
        b.y+=b.vy;
    }
    
    update(cells,balls);
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

    // Draw Metaball.
    glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(4,GL_FLOAT,0,col2d.data());
	glVertexPointer(2,GL_FLOAT,0,vtx2d.data());
	glDrawArrays(GL_LINES,0,vtx2d.size()/2); 
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

    // Draw Grid.
    glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(4,GL_FLOAT,0,gridCol.data());
	glVertexPointer(2,GL_FLOAT,0,gridVtx.data());
	glDrawArrays(GL_LINES,0,gridVtx.size()/2); 
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);


	FsSwapBuffers();
}
bool ApplicationMain::MustTerminate(void) const
{
	return term;
}

int main(int argc,char *argv[])
{
	FsOpenWindow(0,0,600,600,1);
	ApplicationMain app(argc,argv);
	while(true!=app.MustTerminate())
	{
		FsPollDevice();
		app.RunOneStep();
		app.Draw();
	}

	return 0;
}