#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
// #include <ysclass.h>
#include <time.h>
#include <math.h>

#include <fssimplewindow.h>

#define PI 3.141592

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
    
    bool gridOn = false;

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

    float square_dist(float x, float y, float ballx, float bally);

    float linear_interp(float pt1, float pt2, float f1, float f2);

    void getValue(Cell &cell, std::vector<Ball> balls);

    
    
    

};

// constructor >>
ApplicationMain::ApplicationMain(int argc,char *argv[])
{
	int wid,hei;
	FsGetWindowSize(wid,hei);
	tol = 1e-4;
    ballNum = rand()%8 + 5;
    // ballNum = 1;
    if(argc>=2)
    {
        resolution = atof(argv[1]);
    }
    else
    {
        resolution = 100;
    }
    if(argc>=3)
    {
        if(atof(argv[2])==1)
        {
            gridOn = true;
        }
        else
        {

        }
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
        gridCol.push_back(0.5);gridCol.push_back(0.5);gridCol.push_back(0.5);gridCol.push_back(1);

        gridVtx.push_back(x1);gridVtx.push_back(y);
        gridCol.push_back(0.5);gridCol.push_back(0.5);gridCol.push_back(0.5);gridCol.push_back(1);

    }

    
    for(int i = 0; i<ballNum; ++i)
    {
        Ball ball;
        
        ball.vx  = 1.5*(rand()%10 - 5);
        ball.vy  = 1.5*(rand()%10 - 5);
        ball.rad = rand()%25 + 40;

        ball.x   = rand()%int(wid-1.5*ball.rad) + 1.5*ball.rad;
        ball.y   = rand()%int(hei-1.5*ball.rad) + 1.5*ball.rad;

        // ball.x = wid/2;
        // ball.y = hei/2;

        // ball.vx  = 0;
        // ball.vy  = 0;
        // ball.rad = 50;

        balls.push_back(ball);
    }

	
}

float ApplicationMain::square_dist(float x, float y, float ballx, float bally)
{
    
    
    float dist = sqrt( (x-ballx)*(x-ballx) + (y-bally)*(y-bally) );
    
    return dist;
    
}
float ApplicationMain::linear_interp(float pt1, float pt2, float f1, float f2)
{
    
    float interp_pt = pt1 + (pt2 - pt1)* (1 - f1)/(f2 - f1);

    return interp_pt;
}

void ApplicationMain::getValue(Cell &cell, std::vector<Ball> balls)
{
    std::vector<float> values;
    float a = 0,b=0,c=0,d=0;
    for(auto ball : balls)
    {
        float distA = square_dist(cell.a[0],cell.a[1],ball.x,ball.y);
        float distB = square_dist(cell.b[0],cell.b[1],ball.x,ball.y);
        float distC = square_dist(cell.c[0],cell.c[1],ball.x,ball.y);
        float distD = square_dist(cell.d[0],cell.d[1],ball.x,ball.y);
        if(distA < ball.rad)
        {
// std::cout <<__FUNCTION__ << __LINE__<<std::endl;        
            a += 1 + cos(2*PI*distA/ball.rad);
        }
        if(distB < ball.rad)
        {
// std::cout <<__FUNCTION__ << __LINE__<<std::endl;        
            b += 1 + cos(2*PI*distB/ball.rad);
        }
        if(distC < ball.rad)
        {
// std::cout <<__FUNCTION__ << __LINE__<<std::endl;        
            c += 1 + cos(2*PI*distC/ball.rad);
        }
        if(distD < ball.rad)
        {
// std::cout <<__FUNCTION__ << __LINE__<<std::endl;        
            d += 1 + cos(2*PI*distD/ball.rad);
        }
    }
    cell.a[2] = a;
    cell.b[2] = b;
    cell.c[2] = c;
    cell.d[2] = d;
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
        getValue(cell,balls);

        float a=0,b=0,c=0,d=0;

        if(cell.a[2] == 0) a =0;
        else a = 1;
        
        if(cell.b[2] == 0) b =0;
        else b = 1;

        if(cell.c[2] == 0) c =0;
        else c = 1;

        if(cell.d[2] == 0) d =0;
        else d = 1;
        

        cell.config = (int) (8*a + 4*b + 2*c + 1*d);
        
        float interp_ab = linear_interp(cell.a[0],cell.b[0],cell.a[2],cell.b[2]);
        float interp_bc = linear_interp(cell.b[1],cell.c[1],cell.b[2],cell.c[2]);
        float interp_cd = linear_interp(cell.c[0],cell.d[0],cell.c[2],cell.d[2]);
        float interp_da = linear_interp(cell.a[1],cell.d[1],cell.a[2],cell.d[2]);
        
        switch(cell.config)
        {
            // none
            case 0:
                break;

            // d
            case 1:
                vtx2d.push_back(cell.d[0]);             vtx2d.push_back(interp_da);
                vtx2d.push_back(interp_cd);             vtx2d.push_back(cell.d[1]);

                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                break;
            // c   
            case 2:
                vtx2d.push_back(interp_cd);             vtx2d.push_back(cell.c[1]);
                vtx2d.push_back(cell.c[0]);             vtx2d.push_back(interp_bc);

                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                break;
            // c and d
            case 3:
                vtx2d.push_back(cell.d[0]);             vtx2d.push_back(interp_da);
                vtx2d.push_back(cell.c[0]);             vtx2d.push_back(interp_bc);

                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                break;
            // b
            case 4:
                vtx2d.push_back(interp_ab);             vtx2d.push_back(cell.b[1]);
                vtx2d.push_back(cell.b[0]);             vtx2d.push_back(interp_bc);

                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                break;
            // b and d
            case 5:
                vtx2d.push_back(interp_ab);             vtx2d.push_back(cell.b[1]);
                vtx2d.push_back(cell.d[0]);             vtx2d.push_back(interp_da);
                vtx2d.push_back(cell.b[0]);             vtx2d.push_back(interp_bc);
                vtx2d.push_back(interp_cd);             vtx2d.push_back(cell.d[1]);   

                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);    
                break;         
            // b and c
            case 6:
                vtx2d.push_back(interp_ab);             vtx2d.push_back(cell.b[1]);
                vtx2d.push_back(interp_cd);             vtx2d.push_back(cell.c[1]);

                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                break;
            // b, c, d
            case 7:
                vtx2d.push_back(interp_ab);             vtx2d.push_back(cell.b[1]);
                vtx2d.push_back(cell.d[0]);             vtx2d.push_back(interp_da);

                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                break;
            // a
            case 8:
                vtx2d.push_back(interp_ab);             vtx2d.push_back(cell.a[1]);
                vtx2d.push_back(cell.a[0]);             vtx2d.push_back(interp_da);

                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                break;
            // a, d
            case 9:
                vtx2d.push_back(interp_ab); vtx2d.push_back(cell.a[1]);
                vtx2d.push_back(interp_cd); vtx2d.push_back(cell.d[1]);

                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                break;
            // a, c
            case 10:
                vtx2d.push_back(interp_ab);             vtx2d.push_back(cell.a[1]);
                vtx2d.push_back(cell.c[0]);             vtx2d.push_back(interp_bc);
                vtx2d.push_back(cell.a[0]);             vtx2d.push_back(interp_da);
                vtx2d.push_back(interp_cd);             vtx2d.push_back(cell.c[1]); 

                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                break;
            // a, c, d
            case 11:
                vtx2d.push_back(interp_ab);             vtx2d.push_back(cell.a[1]);
                vtx2d.push_back(cell.c[0]);             vtx2d.push_back(interp_bc);

                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                break;
            // a, b
            case 12:
                vtx2d.push_back(cell.a[0]);             vtx2d.push_back(interp_da);
                vtx2d.push_back(cell.b[0]);             vtx2d.push_back(interp_bc);

                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                break;
            // a, b, d
            case 13:
                vtx2d.push_back(cell.b[0]);             vtx2d.push_back(interp_bc);
                vtx2d.push_back(interp_cd);             vtx2d.push_back(cell.d[1]);

                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                break;
            // a, b, c
            case 14:
                vtx2d.push_back(cell.a[0]);             vtx2d.push_back(interp_da);
                vtx2d.push_back(interp_cd);             vtx2d.push_back(cell.c[1]);

                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                col2d.push_back(0);col2d.push_back(0);col2d.push_back(1);col2d.push_back(1);
                break;
            // a, b, c, d
            case 15:
                break;
        }
        
    }
//     std::cout<< vtx2d.size() <<std::endl;
//     for(int i = 0; i<10; ++i)
//     {
//         std::cout << vtx2d[i] <<std::endl;
//     }
// std::cout <<__FUNCTION__ << __LINE__<<std::endl;   
    
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
    float tol = 1e-1;
    for(auto &b : balls)
    {
        if( (b.x > (wid-b.rad - tol) && b.vx > 0) || ( b.x <0+b.rad + tol  && b.vx < 0) )
        {
            b.vx*=-1;
        } 
        if((b.y > (hei-b.rad - tol) && b.vy > 0) || ( b.y <0+b.rad + tol && b.vy < 0) )
        {
            b.vy*=-1;
        } 
        
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

    // Draw Grid.
    if(gridOn==true)
    {
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);
        glColorPointer(4,GL_FLOAT,0,gridCol.data());
        glVertexPointer(2,GL_FLOAT,0,gridVtx.data());
        glDrawArrays(GL_LINES,0,gridVtx.size()/2); 
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_COLOR_ARRAY);
    }
    

    // Draw Metaball.
    glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(4,GL_FLOAT,0,col2d.data());
	glVertexPointer(2,GL_FLOAT,0,vtx2d.data());
	glDrawArrays(GL_LINES,0,vtx2d.size()/2); 
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

    


	FsSwapBuffers();
    FsSleep(25);
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