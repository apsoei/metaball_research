#include <vector>
#include <stdio.h>
#include "fssimplewindow.h"
#include <ysclass.h>
#include <iostream>

#include "glutil.h"
// #include "util.h"
#include <unordered_map>
#include <unordered_set>

#define PI 3.141592

class ApplicationMain
{
public:
	std::vector<float> vtx3d;
	std::vector<float> col3d;

    std::vector<float> gridVtx;
	std::vector<float> gridCol;

    std::vector<float> cubeVtx;
    std::vector<float> cubeCol;

    std::vector<float> lineVtx;
    std::vector<float> lineCol;
    
    // 3D visual >>>>>
    YsMatrix4x4 GetProjection(void) const;
	YsMatrix4x4 GetModelView(void) const;
    YsMatrix4x4 Rc;
	double d;
    

	double originalDistance;
	int prevMx, prevMy;
	YsVec3 t;

    // 3D visual <<<<<

	float tol;
	bool term=false;
    int resolution;
    
    bool cubeOn = false;

    int ballNum;

	void Draw(void) const;
	bool MustTerminate(void) const;
	void RunOneStep(void);
	ApplicationMain(int argc,char *argv[]);

    
    int minX,maxX,minY,maxY,minZ,maxZ,gap;
    
    
    
    int step;

    class Line
    {
    public:
        std::vector<float> vtx1;
        std::vector<float> vtx2;

        // threshold.
        float R;      
    };
    std::vector<Line> lines;

    class Cell
    {
    public:
        // corners
        std::vector<float> c1 {0,0,0,0}; std::vector<float> c2 {0,0,0,0};
        std::vector<float> c3 {0,0,0,0}; std::vector<float> c4 {0,0,0,0};
        std::vector<float> c5 {0,0,0,0}; std::vector<float> c6 {0,0,0,0};
        std::vector<float> c7 {0,0,0,0}; std::vector<float> c8 {0,0,0,0};

        int key;
        bool clean = false;

        float thres = 0.5;
        class Edge
        {
            // vtx 1 and 2
            bool clean;
            
        };
        Edge edge[3];
        
        struct face
        {
            bool clean = false;
            std::vector<std::vector<float>> edge1;
            std::vector<std::vector<float>> edge2;
            std::vector<std::vector<float>> edge3;
            std::vector<std::vector<float>> edge4;
        
        } front,back,right,left,up,down;

        std::vector<face> faces;

        float GetDistance(std::vector<float> pt, ApplicationMain::Line line);
        float Norm(std::vector<float> a);
        std::vector<float> CrossProduct(std::vector<float> a, std::vector<float> b);
        float GetValue(std::vector<float> vtx, std::vector<ApplicationMain::Line> lines)
        {
            float a = 0;
            for(auto &line : lines)
            {

                float dist = GetDistance(vtx,line);

                if(dist < line.R)
                {


                    a += 1 + cos(PI*dist/line.R);

                }
              
           
            }
            a-=0.2;

            return a;
        }
        void Initialize(int x, int y, int z, int step,std::vector<ApplicationMain::Line> lines)
        {
            // {0,0,0,0}
            // front
            c1[0] = x;      c1[1] = y;      c1[2] = z;
            c2[0] = x;      c2[1] = y+step; c2[2] = z;
            c3[0] = x+step; c3[1] = y+step; c3[2] = z;
            c4[0] = x+step; c4[1] = y;      c4[2] = z;
            // back
            c8[0] = x;      c8[1] = y;      c8[2] = z+step;
            c7[0] = x;      c7[1] = y+step; c7[2] = z+step;
            c6[0] = x+step; c6[1] = y+step; c6[2] = z+step;
            c5[0] = x+step; c5[1] = y;      c5[2] = z+step;
            // store field values
            c1[3] = GetValue(c1,lines); c2[3] = GetValue(c2,lines);
            c3[3] = GetValue(c3,lines); c4[3] = GetValue(c4,lines);
            c5[3] = GetValue(c5,lines); c6[3] = GetValue(c6,lines);
            c7[3] = GetValue(c7,lines); c8[3] = GetValue(c8,lines);

            front.edge1.push_back(c1); front.edge1.push_back(c2); front.edge2.push_back(c2); front.edge2.push_back(c3);
            front.edge3.push_back(c3); front.edge3.push_back(c4); front.edge4.push_back(c4); front.edge4.push_back(c1);
            if( (0==c1[3] && 0==c2[3] && 0==c3[3] && 0==c4[3]) || 
                (0!=c1[3] && 0!=c2[3] && 0!=c3[3] && 0!=c4[3]) )
            {
                front.clean = true;
            }
            back.edge1.push_back(c5); back.edge1.push_back(c6); back.edge2.push_back(c6); back.edge2.push_back(c7);
            back.edge3.push_back(c7); back.edge3.push_back(c8); back.edge4.push_back(c8); back.edge4.push_back(c5);
            if( (0==c5[3] && 0==c6[3] && 0==c7[3] && 0==c8[3]) || 
                (0!=c5[3] && 0!=c6[3] && 0!=c7[3] && 0!=c8[3]) )
            {
                back.clean = true;
            }

            right.edge1.push_back(c4); right.edge1.push_back(c3); right.edge2.push_back(c3); right.edge2.push_back(c6);
            right.edge3.push_back(c6); right.edge3.push_back(c5); right.edge4.push_back(c5); right.edge4.push_back(c4);
            if( (0==c3[3] && 0==c4[3] && 0==c5[3] && 0==c6[3]) || 
                (0!=c3[3] && 0!=c4[3] && 0!=c5[3] && 0!=c6[3]) )
            {
                right.clean = true;
            }
            left.edge1.push_back(c8); left.edge1.push_back(c7); left.edge2.push_back(c7); left.edge2.push_back(c2);
            left.edge3.push_back(c2); left.edge3.push_back(c1); left.edge4.push_back(c1); left.edge4.push_back(c8);
            if( (0==c1[3] && 0==c2[3] && 0==c7[3] && 0==c8[3]) || 
                (0!=c1[3] && 0!=c2[3] && 0!=c7[3] && 0!=c8[3]) )
            {
                left.clean = true;
            }
            
            up.edge1.push_back(c8); up.edge1.push_back(c1); up.edge2.push_back(c1); up.edge2.push_back(c4);
            up.edge3.push_back(c4); up.edge3.push_back(c5); up.edge4.push_back(c5); up.edge4.push_back(c8);
            if( (0==c1[3] && 0==c4[3] && 0==c5[3] && 0==c8[3]) || 
                (0!=c1[3] && 0!=c4[3] && 0!=c5[3] && 0!=c8[3]) )
            {
                up.clean = true;
            }
            down.edge1.push_back(c2); down.edge1.push_back(c7); down.edge2.push_back(c7); down.edge2.push_back(c6);
            down.edge3.push_back(c6); down.edge3.push_back(c3); down.edge4.push_back(c3); down.edge4.push_back(c2);
            if( (0==c2[3] && 0==c3[3] && 0==c6[3] && 0==c7[3]) || 
                (0!=c2[3] && 0!=c3[3] && 0!=c6[3] && 0!=c7[3]) )
            {
                down.clean = true;
            }
            if(true==front.clean && true==back.clean &&
               true==left.clean && true==right.clean &&
               true==up.clean && true==down.clean)
               {
                   clean = true;
               }
               
            faces.push_back(front);faces.push_back(back);
            faces.push_back(right);faces.push_back(left);
            faces.push_back(up);faces.push_back(down);
        
            key = 3*x + 5*y + 7*z;
        }
    };

    std::unordered_map <int, Cell> grid3d;

    // int keyFromVtx(std::vector<float> vtx);

    

    std::vector<float> linear_interp(std::vector<float> vtx1,
                                     std::vector<float> vtx2);
                                     

    // void getValue(Cell &cell, std::vector<Line> lines);

    
    void MarchingCube(void);

    void StoreVtx3d(void);

    void StoreCubeVtx3d(void);

    void Update(void);


};

void ApplicationMain::Update(void)
{
    MarchingCube();
    StoreVtx3d();
    StoreCubeVtx3d();
}

void ApplicationMain::StoreCubeVtx3d(void)
{
    cubeVtx.clear();
    cubeCol.clear();
    for(int x = minX; x<= maxX; x+=step)
    {
        for(int y = minY; y<= maxY; y+=step)
        {
            cubeVtx.push_back(x);cubeVtx.push_back(y);cubeVtx.push_back(minZ);
            cubeVtx.push_back(x);cubeVtx.push_back(y);cubeVtx.push_back(maxZ);
            cubeCol.push_back(0);cubeCol.push_back(0);cubeCol.push_back(0);cubeCol.push_back(1);
            cubeCol.push_back(0);cubeCol.push_back(0);cubeCol.push_back(0);cubeCol.push_back(1);
        }
        for(int z = minZ; z<=maxZ; z+=step)
        {
            cubeVtx.push_back(x);cubeVtx.push_back(minY);cubeVtx.push_back(z);
            cubeVtx.push_back(x);cubeVtx.push_back(maxY);cubeVtx.push_back(z);
            cubeCol.push_back(0);cubeCol.push_back(0);cubeCol.push_back(0);cubeCol.push_back(1);
            cubeCol.push_back(0);cubeCol.push_back(0);cubeCol.push_back(0);cubeCol.push_back(1);
        }
    }
    for(int z = minZ; z<=maxZ; z+=step)
    {
        for(int y =minY; y<=maxY; y+=step)
        {
            cubeVtx.push_back(minX);cubeVtx.push_back(y);cubeVtx.push_back(z);
            cubeVtx.push_back(maxX);cubeVtx.push_back(y);cubeVtx.push_back(z);
            cubeCol.push_back(0);cubeCol.push_back(0);cubeCol.push_back(0);cubeCol.push_back(1);
            cubeCol.push_back(0);cubeCol.push_back(0);cubeCol.push_back(0);cubeCol.push_back(1);
        }
    }
}

void ApplicationMain::MarchingCube(void)
{
    int wid, hei;
    FsGetWindowSize(wid,hei);
    int depth = hei;
    bool init = false;
    
    for(auto line : lines)
    {
        if(true!=init)
        {
            init = true;
            minX = (int) (std::min(line.vtx1[0],line.vtx2[0]) - line.R - gap);
            maxX = (int) (std::max(line.vtx1[0],line.vtx2[0]) + line.R + gap);

            minY = (int) (std::min(line.vtx1[1],line.vtx2[1]) - line.R - gap);
            maxY = (int) (std::max(line.vtx1[1],line.vtx2[1]) + line.R + gap);

            minZ = (int) (std::min(line.vtx1[2],line.vtx2[2]) - line.R - gap);
            maxZ = (int) (std::max(line.vtx1[2],line.vtx2[2]) + line.R + gap);
        }
        else
        {
            minX = (int) (std::min(line.vtx1[0],(float)minX) - line.R - gap);
            minX = (int) (std::min(line.vtx2[0],(float)minX) - line.R - gap);
            maxX = (int) (std::max(line.vtx1[0],(float)maxX) + line.R + gap);
            maxX = (int) (std::max(line.vtx2[0],(float)minX) + line.R + gap);

            minY = (int) (std::min(line.vtx1[0],(float)minY) - line.R - gap);
            minY = (int) (std::min(line.vtx2[0],(float)minY) - line.R - gap);
            maxY = (int) (std::max(line.vtx1[0],(float)maxY) + line.R + gap);
            maxY = (int) (std::max(line.vtx2[0],(float)minY) + line.R + gap);

            minZ = (int) (std::min(line.vtx1[0],(float)minZ) - line.R - gap);
            minZ = (int) (std::min(line.vtx2[0],(float)minZ) - line.R - gap);
            maxZ = (int) (std::max(line.vtx1[0],(float)maxZ) + line.R + gap);
            maxZ = (int) (std::max(line.vtx2[0],(float)minZ) + line.R + gap);
            
        }
        
        
    }
    std::cout<<__FUNCTION__<<__LINE__<<std::endl;

    std::cout <<"min: "<<minX<<", "<<minY<<","<<minZ<<std::endl;
    std::cout <<"max: "<<maxX<<", "<<maxY<<","<<maxZ<<std::endl;
    std::cout <<"line vtx1: "<< lines[0].vtx1[0] <<", "<< lines[0].vtx1[1] <<", "<< lines[0].vtx1[2] << std::endl;
    std::cout <<"line vtx1: "<< lines[0].vtx2[0] <<", "<< lines[0].vtx2[1] <<", "<< lines[0].vtx2[2] << std::endl;
    std::cout <<"step = " <<step<<std::endl;
    

    grid3d.clear();
    for(int x= minX; x < maxX; x+=step)
    {
        for(int y= minY; y < maxY; y+=step)
        {
            for(int z= minZ; z < maxZ; z+=step)
            {
                Cell cell;
                cell.Initialize(x,y,z,step,lines);
                if(true!=cell.clean)
                {
                    grid3d[cell.key] = cell;
                }
                
            }
        }
    }
        // std::cout << " y done" <<std::endl;
    
    std::cout << " Done" <<std::endl;
}
void ApplicationMain::StoreVtx3d(void)
{
    vtx3d.clear();
    col3d.clear();
    for(auto &iter : grid3d)
    {
        auto currCell = iter.second;
        auto currFaces = currCell.faces;

        for(auto &face : currFaces)
        {

            if(true!=face.clean)
            {

                if( face.edge1[0][3] != face.edge1[1][3])
                {
std::cout<<__FUNCTION__<<__LINE__<<std::endl;
std::cout<<"f1 = "<<face.edge1[0][3]<<std::endl;
std::cout<<"f2 = "<<face.edge1[1][3]<<std::endl;
                    auto interp = linear_interp(face.edge1[0],face.edge1[1]);
                    vtx3d.push_back(interp[0]);vtx3d.push_back(interp[1]);vtx3d.push_back(interp[2]);
                    col3d.push_back(0);col3d.push_back(0);col3d.push_back(1);col3d.push_back(1);
                }
                if( (0!=face.edge2[0][3] && 0==face.edge2[1][3]) ||
                    (0==face.edge2[0][3] && 0!=face.edge2[1][3]) )
                {
                    auto interp = linear_interp(face.edge2[0],face.edge2[1]);
                    vtx3d.push_back(interp[0]);vtx3d.push_back(interp[1]);vtx3d.push_back(interp[2]);
                    col3d.push_back(0);col3d.push_back(0);col3d.push_back(1);col3d.push_back(1);
                }
                if( (0!=face.edge3[0][3] && 0==face.edge3[1][3]) ||
                    (0==face.edge3[0][3] && 0!=face.edge3[1][3]) )
                {
                    auto interp = linear_interp(face.edge3[0],face.edge3[1]);
                    vtx3d.push_back(interp[0]);vtx3d.push_back(interp[1]);vtx3d.push_back(interp[2]);
                    col3d.push_back(0);col3d.push_back(0);col3d.push_back(1);col3d.push_back(1);
                }
                if( (0!=face.edge4[0][3] && 0==face.edge4[1][3]) ||
                    (0==face.edge4[0][3] && 0!=face.edge4[1][3]) )
                {
                    auto interp = linear_interp(face.edge4[0],face.edge4[1]);
                    vtx3d.push_back(interp[0]);vtx3d.push_back(interp[1]);vtx3d.push_back(interp[2]);
                    col3d.push_back(0);col3d.push_back(0);col3d.push_back(1);col3d.push_back(1);
                }
            }
        }
   
    }

       
}

// int ApplicationMain::keyFromVtx(std::vector<float> vtx)
// {
//     if(vtx.size()!=3)
//     {
//         std::cout << "Wrong input vertex size" <<std::endl;
//         return 0;
//     }
//     int key = vtx[0] * 3 + vtx[1] * 5 + vtx[2] * 7;

//     return key;
// }

std::vector<float> ApplicationMain::Cell::CrossProduct(std::vector<float> a, std::vector<float> b)
{
    std::vector<float> ans;
    ans.push_back(a[1]*b[2] - a[2]*b[1]);
    ans.push_back(a[2]*b[0] - a[0]*b[2]);
    ans.push_back(a[0]*b[1] - a[1]*b[0]);

    return ans;
}
float ApplicationMain::Cell::Norm(std::vector<float> a)
{
    float ans = sqrt( a[0]*a[0] + a[1]*a[1] + a[2]*a[2] );
    return ans;
}

float ApplicationMain::Cell::GetDistance(std::vector<float> pt, Line line)
{

    // LINE SEGMENT AB TO POINT C (grid point).
    if(line.vtx1[0]==line.vtx2[0] && line.vtx1[1]==line.vtx2[1] && line.vtx1[2]==line.vtx2[2])
    {
        auto x = pt[0] - line.vtx2[0];
        auto y = pt[1] - line.vtx2[1];
        auto z = pt[2] - line.vtx2[2];
        auto dist = Norm({x,y,z});
        return dist;
    }
    // line vector AB
    std::vector<float> AB;
    AB.push_back(line.vtx2[0]-line.vtx1[0]);
    AB.push_back(line.vtx2[1]-line.vtx1[1]);
    AB.push_back(line.vtx2[2]-line.vtx1[2]);

    // vector AC
    std::vector<float> AC;
    AC.push_back(pt[0] - line.vtx1[0]);
    AC.push_back(pt[1] - line.vtx1[1]);
    AC.push_back(pt[2] - line.vtx1[2]);

    // vector BC
    std::vector<float> BC;
    BC.push_back(pt[0] - line.vtx2[0]);
    BC.push_back(pt[1] - line.vtx2[1]);
    BC.push_back(pt[2] - line.vtx2[2]);

    // dot product.
    float AB_BC = AB[0]*BC[0] + AB[1]*BC[1] + AB[2]*BC[2];
    float AB_AC = AB[0]*AC[0] + AB[1]*AC[1] + AB[2]*AC[2];

    float dist = 0;
    if(AB_BC > 0)
    {
// std::cout<<__FUNCTION__<<__LINE__<<std::endl;
        float z = pt[2] - line.vtx2[2];
        float y = pt[1] - line.vtx2[1];
        float x = pt[0] - line.vtx2[0];
        dist = sqrt(x*x +y*y + z*z);
// std::cout<<dist<<std::endl;
    }
    else if(AB_AC < 0)
    {
// std::cout<<__FUNCTION__<<__LINE__<<std::endl;
        float z = pt[2] - line.vtx1[2];
        float y = pt[1] - line.vtx1[1];
        float x = pt[0] - line.vtx1[0];
        dist = sqrt(x*x +y*y + z*z);
// std::cout<<dist<<std::endl;
    }
    else
    {
// std::cout<<__FUNCTION__<<__LINE__<<std::endl;
        auto cross = CrossProduct(AB,AC);
        cross[0]/=Norm(AB); cross[1]/=Norm(AB); cross[2]/=Norm(AB); 
        dist = Norm(cross);
        // dist = Norm(CrossProduct(AB,AC)) / Norm(AB);
// std::cout<<dist<<std::endl;
    }

// std::cout<<__FUNCTION__<<__LINE__<<std::endl;
// std::cout<<dist<<std::endl;
    return dist;
}


std::vector<float> ApplicationMain::linear_interp(std::vector<float> vtx1,
                                                  std::vector<float> vtx2)
                                                  
{
    // f1 and f2: corresponding field value.
    std::vector<float> interpVtx = {0,0,0};
    // std::cout <<__FUNCTION__<<__LINE__<<std::endl;
    // std::cout<< "------------->"<<vtx1[3] << ", " << vtx2[3] <<std::endl;
    auto f1 = vtx1[3];
    auto f2 = vtx2[3];
    float pt1,pt2;
    int id;
    for(int i = 0; i<3; ++i)
    {
        if(vtx1[i]!=vtx2[i])
        {
            id = i;
            pt1 = vtx1[i];
            pt2 = vtx2[i];
        }
        else
        {
            interpVtx[i] = vtx1[i];
        }
    }



    // float interp_pt = pt1 + (pt2 - pt1)* (0 - f1)/(f2 - f1);
    float interp_pt = vtx1[id] + (vtx2[id] - vtx1[id])* (0 - vtx1[3])/(vtx2[3] - vtx1[3]);

std::cout<<__FUNCTION__<<__LINE__<<std::endl;
std::cout<<"f1 = "<< f1<<std::endl;
std::cout<<"f2 = "<< f1<<std::endl;
std::cout<<"interp between " <<pt1 <<" and "<<pt2 <<": "<<interp_pt<<std::endl;




    interpVtx[id] = interp_pt;

    return interpVtx;
}

bool ApplicationMain::MustTerminate(void) const
{
    return term;
}


void ApplicationMain::Draw(void) const
{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	int wid,hei;
	FsGetWindowSize(wid,hei);
	auto aspect=(double)wid/(double)hei;
	glViewport(0,0,wid,hei);

    YsMatrix4x4 projection=GetProjection();
	GLfloat projectionGl[16];
	projection.GetOpenGlCompatibleMatrix(projectionGl);

    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMultMatrixf(projectionGl);

	YsMatrix4x4 globalToCamera=Rc;
	globalToCamera.Invert();

    YsMatrix4x4 modelView=GetModelView();

	GLfloat modelViewGl[16];
	modelView.GetOpenGlCompatibleMatrix(modelViewGl);

	glShadeModel(GL_SMOOTH);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

    GLfloat lightDir[]={0,1.0f/(float)sqrt(2.0f),1.0f/(float)sqrt(2.0f),0};
	glLightfv(GL_LIGHT0,GL_POSITION,lightDir);

	glMultMatrixf(modelViewGl);

    // draw cubes.
    if(true==cubeOn)
    {
        glEnable(GL_COLOR_MATERIAL);
        glDisable(GL_LIGHTING);
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);
        glColorPointer(4,GL_FLOAT,0,cubeCol.data());
        glVertexPointer(3,GL_FLOAT,0,cubeVtx.data());
        glLineWidth(2);
        glDrawArrays(GL_LINES,0,cubeVtx.size()/3);
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_COLOR_ARRAY);
    }
    
    // draw metaball (lines).
    glEnable(GL_COLOR_MATERIAL);
    glDisable(GL_LIGHTING);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glColorPointer(4,GL_FLOAT,0,col3d.data());
    glVertexPointer(3,GL_FLOAT,0,vtx3d.data());
    glLineWidth(5);
    glDrawArrays(GL_LINES,0,vtx3d.size()/3);
    // glPointSize(3);
    // glDrawArrays(GL_POINTS,0,vtx3d.size()/3);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

    // draw original line.
    glEnable(GL_COLOR_MATERIAL);
    glDisable(GL_LIGHTING);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glColorPointer(4,GL_FLOAT,0,lineCol.data());
    glVertexPointer(3,GL_FLOAT,0,lineVtx.data());
    glLineWidth(5);
    glDrawArrays(GL_LINES,0,lineVtx.size()/3);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

    FsSwapBuffers();
 
}


void ApplicationMain::RunOneStep(void)
{

	// get all status variables
	auto key=FsInkey();
	int mx,my,lb,mb,rb;
	int evt=FsGetMouseEvent(lb,mb,rb,mx,my);
	int wid,hei;
	FsGetWindowSize(wid,hei);

	
    if(FsGetKeyState(FSKEY_LEFT))
    {
        Rc.RotateXZ(YsPi/60.0);
    }
    if(FsGetKeyState(FSKEY_RIGHT))
    {
        Rc.RotateXZ(-YsPi/60.0);
    }
    if(FsGetKeyState(FSKEY_UP))
    {
        Rc.RotateYZ(YsPi/60.0);
    }
    if(FsGetKeyState(FSKEY_DOWN))
    {
        Rc.RotateYZ(-YsPi/60.0);
    }

    if(key==FSKEY_Q)
    {
        for(auto &line: lines)
        {
            if(line.R>step) line.R-=5;
            Update();
        }
    }
    if(key==FSKEY_W)
    {
        for(auto &line: lines)
        {
            line.R+=5;
            Update();
        }
    }

    

    // ORBIT
    if(evt==FSMOUSEEVENT_RBUTTONDOWN)
    {
        prevMx = mx;
        prevMy = my;
    }
    if(rb)
    {
        Rc.RotateXZ((mx - prevMx) * 0.075 * (YsPi/60.0));
        Rc.RotateYZ((my - prevMy) * -0.075 * (YsPi/60.0));
        prevMx = mx;
        prevMy = my;
    }
   
    
    // EXIT PROGRAM
    if(FSKEY_ESC==key)
    {
        term=true;
    }

    // ZOOM IN
    if(key==FSKEY_WHEELUP)
    {

        d+=0.03*d;
    }

    // ZOOM OUT
    if(key==FSKEY_WHEELDOWN)
    {

        d-=0.03*d;
    }
    
    // VIEW RESET
    if(FsGetKeyState(FSKEY_SPACE))
    {
        d = originalDistance;
        
        Rc.Set11(1),Rc.Set12(0),Rc.Set13(0),Rc.Set14(0);
        Rc.Set21(0),Rc.Set22(1),Rc.Set23(0),Rc.Set24(0);
        Rc.Set31(0),Rc.Set32(0),Rc.Set33(1),Rc.Set34(0);
        Rc.Set41(0),Rc.Set42(0),Rc.Set43(0),Rc.Set44(1);
    }

    // Toggle cubic grid on/ off
    if(key==FSKEY_1)
    {
        cubeOn = true;
    }
    if(key==FSKEY_2)
    {
        cubeOn = false;
    }

	
	
	
	// std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

YsMatrix4x4 ApplicationMain::GetProjection(void) const
{
	int wid,hei;
	FsGetWindowSize(wid,hei);
	auto aspect=(double)wid/(double)hei;
	return MakePerspective(45.0,aspect,d/10.0,d*2.0);
}
YsMatrix4x4 ApplicationMain::GetModelView(void) const
{
	YsMatrix4x4 globalToCamera=Rc;
// 
	
	globalToCamera.Invert();

	YsMatrix4x4 modelView;
	modelView.Translate(0,0,-d);
	modelView*=globalToCamera;
	modelView.Translate(-t);
	return modelView;
}

// CONSTRUCTOR . . .
ApplicationMain::ApplicationMain(int argc,char *argv[])
{
    int wid,hei;
	FsGetWindowSize(wid,hei);
    d=10.0;
	t=YsVec3::Origin();
    gap = 50;
    
    if(2<=argc)
    {

        resolution = atof(argv[1]);
    }
    else
    {

        resolution = 100;
    }
    
    // d=(bbx[1]-bbx[0]).GetLength()*1.2;
    
    Line line;
    int centerX = wid/2;
    int centerY = wid/2 ;
    int centerZ = wid/2 ;
    int len = 25;
    line.vtx1.push_back(centerX-len/2);line.vtx1.push_back(centerY-len/2);line.vtx1.push_back(centerZ-len/2);
    // line.vtx2.push_back(centerX-len/2);line.vtx2.push_back(centerY-len/2);line.vtx2.push_back(centerZ-len/2);
    line.vtx2.push_back(centerX+len/2);line.vtx2.push_back(centerY+len/2);line.vtx2.push_back(centerZ+len/2);
    
    // line.vtx2.push_back(centerX-len/2+10);line.vtx2.push_back(centerY-len/2);line.vtx2.push_back(centerZ-len/2);
    line.R = 50;

    lines.push_back(line);

    for(auto line : lines)
    {
        lineVtx.push_back(line.vtx1[0]);lineVtx.push_back(line.vtx1[1]);lineVtx.push_back(line.vtx1[2]);
        lineVtx.push_back(line.vtx2[0]);lineVtx.push_back(line.vtx2[1]);lineVtx.push_back(line.vtx2[2]);
        lineCol.push_back(1);lineCol.push_back(0);lineCol.push_back(0);lineCol.push_back(1);
        lineCol.push_back(1);lineCol.push_back(0);lineCol.push_back(0);lineCol.push_back(1);
    }

    YsVec3 bbx[2];
    bbx[0].SetX(0);bbx[0].SetY(0);bbx[0].SetZ(0);
    bbx[1].SetX(wid);bbx[1].SetY(hei);bbx[1].SetZ(wid);
    t=(bbx[0]+bbx[1])/2.0;
    d=(bbx[1]-bbx[0]).GetLength()*1.2;
    originalDistance = d;

    step = wid/resolution;

    MarchingCube();
    StoreVtx3d();
    StoreCubeVtx3d();



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