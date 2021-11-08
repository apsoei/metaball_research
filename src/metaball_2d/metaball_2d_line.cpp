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

    std::vector<float> inputVtx;
    std::vector<float> inputCol;
    
    

	float tol;
	bool term=false;
    int resolution;

    bool updated = false;
    
    bool gridOn = false;

    int ballNum;
    int lineNum;

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

        // edges R,L,U,D
        // one edge: (x1,y1,x2,y2)
        
        // std::vector<int> up;
        // std::vector<int> left;
        // std::vector<int> right;
        // std::vector<int> down;

        Cell *right = nullptr;
        Cell *left = nullptr;
        Cell *up = nullptr;
        Cell *down = nullptr;

        int GetKey(void)
        {
            return key;
        }
        
        
    };
	std::unordered_map <int , Cell> cellMap;

    class Line
    {
    public:
        std::vector<float> vtx1;
        std::vector<float> vtx2;

        // threshold.
        float R;
    };

    
    std::vector<Cell> cells;
    std::vector<Line> lines;

    void update(std::vector<Cell> cells, std::vector<Line> lines);

    float square_dist(float x, float y, float ballx, float bally);

    float linear_interp(float pt1, float pt2, float f1, float f2);

    void getValue(Cell &cell, std::vector<Line> lines);

    float distanceToLine(float cellx, float celly, Line line);
    
    

};

// constructor >>
ApplicationMain::ApplicationMain(int argc,char *argv[])
{
	int wid,hei;
	FsGetWindowSize(wid,hei);
	tol = 1e-4;
    ballNum = rand()%8 + 5;
    lineNum = 3;
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

            cell.key = cell.a[0]*3 + cell.a[1]*5 + cell.b[0]*7 + cell.b[1]*11;
            // if(0==x) cell.left = nullptr;
            // if(0==y) cell.up = nullptr;
            // if(wid-cellWid==x) cell.right = nullptr;
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


    int s = 1;

    // 3 lines: triangle
    // point 1: wid/2 , hei/2
    // point 2: 3*wid/4, 3*hei/4
    // point 3: wid/4, 3*hei/4

    // line1 : point1 , 2
    // line2 : point2 , 3
    // line3 : point3 , 1


    Line line1,line2,line3;
    line1.vtx1.push_back(wid/2);line1.vtx1.push_back(hei/2);
    line1.vtx2.push_back(3*wid/4);line1.vtx2.push_back(3*hei/4);
    line1.R = 50;

    line2.vtx1.push_back(3*wid/4);line2.vtx1.push_back(3*hei/4);
    line2.vtx2.push_back(wid/4);line2.vtx2.push_back(3*hei/4);
    line2.R = 50;

    line3.vtx1.push_back(wid/4);line3.vtx1.push_back(3*hei/4);
    line3.vtx2.push_back(wid/2);line3.vtx2.push_back(hei/2);
    line3.R = 50;

    lines.push_back(line1);
    lines.push_back(line2);
    lines.push_back(line3);

    for(auto line : lines)
    {
        inputVtx.push_back(line.vtx1[0]);inputVtx.push_back(line.vtx1[1]);
        inputVtx.push_back(line.vtx2[0]);inputVtx.push_back(line.vtx2[1]);
        inputCol.push_back(1);inputCol.push_back(0);inputCol.push_back(0);inputCol.push_back(1);
        inputCol.push_back(1);inputCol.push_back(0);inputCol.push_back(0);inputCol.push_back(1);
    }

	
}

float ApplicationMain::square_dist(float x, float y, float ballx, float bally)
{
    
    
    float dist = sqrt( (x-ballx)*(x-ballx) + (y-bally)*(y-bally) );
    
    return dist;
    
}


float ApplicationMain::distanceToLine(float cellx, float celly, Line line)
{
// std::cout << __FUNCTION__ <<__LINE__<< std::endl;
    float dist = 0;
    // line AB, cell point C

    // vector AB
    std::vector<float> AB;
    AB.push_back(line.vtx2[0]- line.vtx1[0]);
    AB.push_back(line.vtx2[1]- line.vtx1[1]);

    // vector BC
    std::vector<float> BC;
    BC.push_back(cellx - line.vtx2[0]);
    BC.push_back(celly - line.vtx2[1]);

    // vector AC
    std::vector<float> AC;
    AC.push_back(cellx - line.vtx1[0]);
    AC.push_back(celly - line.vtx1[1]);

    // dot product.
    float AB_BC = AB[0]*BC[0] + AB[1]*BC[1];
    float AB_AC = AB[0]*AC[0] + AB[1]*AC[1];

    if(AB_BC > 0)
    {
        float y = celly - line.vtx2[1];
        float x = cellx - line.vtx2[0];
        dist = sqrt(x*x +y*y);
    }
    else if(AB_AC < 0)
    {
        float y = celly - line.vtx1[1];
        float x = cellx - line.vtx1[0];
        dist = sqrt(x*x +y*y);
    }
    else
    {
        float x1 = AB[0];
        float y1 = AB[1];
        float x2 = AC[0];
        float y2 = AC[1];
        float denom = sqrt(x1 * x1 + y1 * y1);
        dist = abs(x1 * y2 - y1 * x2) / denom;
    }
    return dist;
    
 
}

float ApplicationMain::linear_interp(float pt1, float pt2, float f1, float f2)
{
    // pt1 and 2: 2 points on the edge either having same x or y value.
    // f1 and f2: corresponding field value.

    float interp_pt = pt1 + (pt2 - pt1)* (1 - f1)/(f2 - f1);

    return interp_pt;
}

void ApplicationMain::getValue(Cell &cell, std::vector<Line> lines)
{
    float a = 0,b=0,c=0,d=0;
    for(auto line : lines)
    {
// std::cout << __FUNCTION__ <<__LINE__<< std::endl;
        float distA = distanceToLine(cell.a[0],cell.a[1],line);
        float distB = distanceToLine(cell.b[0],cell.b[1],line);
        float distC = distanceToLine(cell.c[0],cell.c[1],line);
        float distD = distanceToLine(cell.d[0],cell.d[1],line);

        if(distA < line.R)
        {
            a += 1 + cos(PI*distA/line.R);
            // std::cout << a << std::endl;
        }
        if(distB < line.R)
        {

            b += 1 + cos(PI*distB/line.R);
        }
        if(distC < line.R)
        {

            c += 1 + cos(PI*distC/line.R);
        }
        if(distD < line.R)
        {

            d += 1 + cos(PI*distD/line.R);
        }
        // for(auto line : lines)
        // {
        //     a+= (line.R*line.R) / (distA*distA);
                
            
        //     b+= (line.R*line.R) / (distB*distB);
                

        //     c+= (line.R*line.R) / (distC*distC);
                

        //     d+= (line.R*line.R) / (distD*distD);
                
        // }
    }
    cell.a[2] = a;
    cell.b[2] = b;
    cell.c[2] = c;
    cell.d[2] = d;
}


void ApplicationMain::update(std::vector<Cell> cells, std::vector<Line> lines)
{

    vtx2d.clear();
    col2d.clear();
    int wid,hei;
	FsGetWindowSize(wid,hei);
    auto cellWid = (float)wid/resolution;
    auto cellHei = (float)hei/resolution;

    for(auto &cell : cells)
    {
        getValue(cell,lines);

        float a=0,b=0,c=0,d=0;

        if(cell.a[2] == 0) a =0;
        else a = 1;
        
        if(cell.b[2] == 0) b =0;
        else b = 1;

        if(cell.c[2] == 0) c =0;
        else c = 1;

        if(cell.d[2] == 0) d =0;
        else d = 1;


        // if(cell.a[2] < 1) a =0;
        // else a = 1;
        
        // if(cell.b[2] < 1) b =0;
        // else b = 1;

        // if(cell.c[2] < 1) c =0;
        // else c = 1;

        // if(cell.d[2] < 1) d =0;
        // else d = 1;
        

        cell.config = (int) (8*a + 4*b + 2*c + 1*d);
// std::cout << cell.config <<std::endl;
        
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

    if(updated==false)
    {
        update(cells,lines);
        updated = true;
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



    // Draw input lines.
    glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(4,GL_FLOAT,0,inputCol.data());
	glVertexPointer(2,GL_FLOAT,0,inputVtx.data());
	glDrawArrays(GL_LINES,0,inputVtx.size()/2); 
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