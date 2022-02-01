#include <vector>
#include <stdio.h>
#include "fssimplewindow.h"
#include <ysclass.h>
#include <iostream>
#include <math.h>
#include <iostream>
#include <fstream>

#include "glutil.h"
// #include "util.h"
#include <unordered_map>
#include <unordered_set>

#include "fileHandle.h"

#include "util.h"
#include <unordered_set>
#include <unordered_map>

#define PI 3.141592
const float tol = 1e-6;
int uniqueNum = 1;

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

    std::vector<float> interpVtx;
    std::vector<float> interpCol;

    std::vector<float> istcTestVtx;
    std::vector<float> istcTestCol;

    std::vector<float> inputEdVtx;
    std::vector<float> inputEdCol;
    
    // For highlighting one cube (debugging)
    std::vector<float> highVtx;
    std::vector<float> highCol;

    // FOR SAVING N-POLYGONS TO .OBJ >>

    std::vector<float> objVtx;
    std::vector<int> objFace;

    // << FOR SAVING N-POLYGONS TO .OBJ

    bool point = false;
    bool highlight = false;
    bool showInput = false;

    // cube numbers in x,y,z dir.
    int xc=0,yc=0,zc=0;
    float thres = 0.1;
    int cubeNum = 24;
    
    // 3D visual >>>>>
    YsMatrix4x4 GetProjection(void) const;
	YsMatrix4x4 GetModelView(void) const;
    YsMatrix4x4 Rc;
	double d;
    

	double originalDistance;
	int prevMx, prevMy;

    // view target.
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

    
    int nx,ny,nz;
    // int minX,maxX,minY,maxY,minZ,maxZ,gap;
    float minX,maxX,minY,maxY,minZ,maxZ,gap;
    std::vector<float> fvals;
    int step;
    // int xStep, yStep, zStep;
    float xStep, yStep, zStep;
    bool fromFile = false;


    float Norm(std::vector<float> a);
    std::vector<float> CrossProduct(std::vector<float> a, std::vector<float> b);


    class Line
    {
    public:
        std::vector<float> vtx1;
        std::vector<float> vtx2;

        // threshold.
        float R;      
    };
    std::vector<Line> lines;

    float GetDistance(float pt[], Line line);
    float GetValue(float vtx[])
    {
        // float a = 9e9;
        float dist = sqrt((maxX - minX)*(maxX - minX) + (maxY - minY)*(maxY - minY) + (maxZ - minZ)*(maxZ - minZ));
        float thickness = lines[0].R;
        for(auto &line : lines)
        {

            float distCandidate = GetDistance(vtx,line);
            if(distCandidate<dist)
            {
                dist = distCandidate;
                thickness = line.R;
            } 
        
        }
        // if(a>0) 
        // {
        //     std::cout<<__FUNCTION__<<__LINE__<<std::endl;
        //     std::cout<< a << std::endl;
        // }
        
        
        // a-=line.R;
        // a-=0.2;
        if(dist-thickness<0)
        {
std::cout <<__FUNCTION__<<__LINE__<<std::endl;
std::cout << dist-thickness << std::endl;
        }

        return dist-thickness;
    }

    class Cube
    {
    public:
        
        bool boundary = false;
        int key;
        bool clean = false;

        // Cube *a,r,o,u,n,d;
        // Cube *next;
        
        int xInd,yInd,zInd;
        class Edge
        {
            // vtx 1 and 2
        public:
            float vtx1[3];
            float vtx2[3];

            float val1, val2;

            float interp[3] = {PI,PI,PI};
            // float interp[3] ;
            int vtIdent = 0;
            bool clean = false;
            
            int edKey;
            void RegisterKey(void)
            {
                edKey =(int) (vtx1[0]*3 + vtx1[1]*5 + vtx1[2]*7 + 
                        vtx2[0]*11 + vtx2[1]*13 + vtx2[2]*17);
            }
            
        };
        // Edge edge[3];
        std::vector<Edge> edge {3};

        // intersections in the following order :
        // top: edge    0,3,5,1
        // bottom: edge 8,9,10,11
        // right: edge  3,4,8,7
        // left: edge   1,6,10,2
        // front: edge  0,2,9,4
        // back: edge   5,7,11,6
        class itscVtx
        {
        public:
            int vtident = 0;
            float x,y,z;
        };
        std::vector<itscVtx> itscs;

        // This is pair of which face itscVtx is and index to find it in itscVtx.
        std::vector<std::pair<int,int>> itscFaceNums;




        // CUBE CONSTRUCTOR        
        Cube(float x, float y, float z, float xStep, float yStep, float zStep, int nx, int ny, 
                        int nz, int xi, int yi, int zi)
        {
            xInd = xi;
            yInd = yi;
            zInd = zi;
            if(xInd==nx-1 || yInd==ny-1 || zInd==nz-1)
            {
                boundary=true;
            }
            if(true==boundary)
            {
                edge.resize(12);
            }
            edge[0].vtx1[0] = x;        edge[0].vtx1[1] = y;        edge[0].vtx1[2] = z;
            edge[0].vtx2[0] = x+xStep;  edge[0].vtx2[1] = y;        edge[0].vtx2[2] = z;
            

            edge[1].vtx1[0] = x;        edge[1].vtx1[1] = y;        edge[1].vtx1[2] = z;
            edge[1].vtx2[0] = x;        edge[1].vtx2[1] = y;        edge[1].vtx2[2] = z+zStep;

            edge[2].vtx1[0] = x;        edge[2].vtx1[1] = y;        edge[2].vtx1[2] = z;
            edge[2].vtx2[0] = x;        edge[2].vtx2[1] = y+yStep;  edge[2].vtx2[2] = z;
            if(true==boundary)
            {   
                edge[3].vtx1[0] = x+xStep;      edge[3].vtx1[1] = y;            edge[3].vtx1[2] = z;
                edge[3].vtx2[0] = x+xStep;      edge[3].vtx2[1] = y;            edge[3].vtx2[2] = z+zStep;

                edge[4].vtx1[0] = x+xStep;      edge[4].vtx1[1] = y;            edge[4].vtx1[2] = z;
                edge[4].vtx2[0] = x+xStep;      edge[4].vtx2[1] = y+yStep;      edge[4].vtx2[2] = z;

                edge[5].vtx1[0] = x;            edge[5].vtx1[1] = y;            edge[5].vtx1[2] = z+zStep;
                edge[5].vtx2[0] = x+xStep;      edge[5].vtx2[1] = y;            edge[5].vtx2[2] = z+zStep;

                edge[6].vtx1[0] = x;            edge[6].vtx1[1] = y;            edge[6].vtx1[2] = z+zStep;
                edge[6].vtx2[0] = x;            edge[6].vtx2[1] = y+yStep;      edge[6].vtx2[2] = z+zStep;

                edge[7].vtx1[0] = x+xStep;      edge[7].vtx1[1] = y;            edge[7].vtx1[2] = z+zStep;
                edge[7].vtx2[0] = x+xStep;      edge[7].vtx2[1] = y+yStep;      edge[7].vtx2[2] = z+zStep;

                edge[8].vtx1[0] = x+xStep;      edge[8].vtx1[1] = y+yStep;      edge[8].vtx1[2] = z;
                edge[8].vtx2[0] = x+xStep;      edge[8].vtx2[1] = y+yStep;      edge[8].vtx2[2] = z+zStep;

                edge[9].vtx1[0] = x;            edge[9].vtx1[1] = y+yStep;      edge[9].vtx1[2] = z;
                edge[9].vtx2[0] = x+xStep;      edge[9].vtx2[1] = y+yStep;      edge[9].vtx2[2] = z;

                edge[10].vtx1[0] = x;           edge[10].vtx1[1] = y+yStep;     edge[10].vtx1[2] = z;
                edge[10].vtx2[0] = x;           edge[10].vtx2[1] = y+yStep;     edge[10].vtx2[2] = z+zStep;

                edge[11].vtx1[0] = x;           edge[11].vtx1[1] = y+yStep;     edge[11].vtx1[2] = z+zStep;
                edge[11].vtx2[0] = x+xStep;     edge[11].vtx2[1] = y+yStep;     edge[11].vtx2[2] = z+zStep;

            }
            for(auto &e : edge)
            {
                e.RegisterKey();
            }

            

            key = (int)3*x+7*y+11*z;

        }


    };

    std::vector<Cube> cubes;

    // Cubes with intersections but no interpolation points from function values.
    std::vector<Cube> unusedItscCube;

    std::unordered_map <int, Cube> cubeMap;

    std::unordered_set <int> edHashSet;

    void insertHash(Cube cube)
    {
        for(auto &e : cube.edge)
        {
            if(edHashSet.find(e.edKey)==edHashSet.end())
            {
                edHashSet.insert(e.edKey);
            }
        }
    }
    

    // int keyFromVtx(std::vector<float> vtx);

    

    // float * linear_interp(Cube::Edge edge);
    std::vector<float> linear_interp(Cube::Edge edge);
                                     
                                     

    // void getValue(Cube &Cube, std::vector<Line> lines);

    void GenerateCubes(void);
    
    void MarchingCube(void);

    void StoreVtx3d(void);


    void Update(void);

    void SaveToObj(void);

    void Swap(int *a, int *b);

    void SwapPairs(std::vector<std::vector<int>> &target, int id1, int id2);


    // FOR INPUT EDGE PROCESSING . . . > > > > >
    std::vector<Line> inputEdges;
    
    // plane eqn: n_x * x + n_y * y + n_z * z = d
    // returns {n_x,n_y,n_z,d}

    bool getIntersection(std::vector<Line> inputEdges, std::vector<Cube::Edge> myEdges, Cube &cube);

    std::vector<std::vector<int>> Split(const std::vector <int> srcPlg,const std::vector<int> split);

    
    // for finding the cube that is capturing one 3d point.
    // returns cube index from cubes.
    int whichCubeFromPoint(double x, double y, double z);

    // for finding the cube from polygon vertices.
    // input poly vertices will always be 2 vertices that is enough to find unique cube that produced this polygon.
    int whichCubeFromPoly(std::vector<std::vector<float>> polyVert);


    
    // FOR INPUT EDGE PROCESSING . . . < < < < <

    // DEBUGGER : find which cube is missing intersection points .
    std::vector<std::vector<float>> polyVert;
    bool foundWhichCube = false;
    std::vector<float> debugVtx;
    std::vector<float> debugCol;

    std::vector<float> intersectionsVtx;
    std::vector<float> intersectionsCol;
    void saveItscForDebug(void);


    float debugCubeCen[3];


    // float* pushItscs(void);



    YsVec3 bbx[2];
    // FUNCTION TO MAKE PHYSICAL MARCHING CUBE WIRE.
    // THIS MAKES LINE INPUTS WITH THICKNESS TO BE USED IN THE MARCHING CUBE AND GENERATE .OBJ ^.^
    // Returns min xyz and max xyz.
    std::vector<float> MakeWire(float cen,int len, int t, int cubeNum);


    
};

std::vector<float> ApplicationMain::MakeWire(float cen,int len, int t, int cubeNum)
{
    
    float xMin,xMax,yMin,yMax,zMin,zMax;
    std::vector<float> bounding = {xMin,yMin,zMin,xMax,yMax,zMax};
    xMin = cen - len/2; xMax = cen + len/2;
    yMin = xMin; yMax = xMax;
    zMin = xMin; zMax = xMax;
    float step = (float)len / cubeNum;
    for(float x = xMin; x<=xMax; x+=step)
    {
        for(float y = yMin; y<=yMax; y+=step)
        {
            Line line;
            line.R = t;
            line.vtx1 = {x,y,zMin};
            line.vtx2 = {x,y,zMax};
            lines.push_back(line);
        }
        for(float z = zMin; z<=zMax; z+=step)
        {
            Line line;
            line.R = t;
            line.vtx1 = {x,yMin,z};
            line.vtx2 = {x,yMax,z};
            lines.push_back(line);
        }

    }
    for(float y =yMin; y<=yMax; y+=step)
    {
        for(float z = zMin; z<=zMax; z+=step)
        {
            Line line;
            line.R = t;
            line.vtx1 = {xMin,y,z};
            line.vtx2 = {xMax,y,z};
            lines.push_back(line);
        }
    }
    std::cout <<__FUNCTION__<<__LINE__<<std::endl;
    for(auto line : lines)
    {
        printf("line vt1: %f, %f, %f\n",line.vtx1[0],line.vtx1[1],line.vtx1[2]);
        printf("line vt2: %f, %f, %f\n",line.vtx2[0],line.vtx2[1],line.vtx2[2]);
        lineVtx.push_back(line.vtx1[0]);lineVtx.push_back(line.vtx1[1]);lineVtx.push_back(line.vtx1[2]);
        lineVtx.push_back(line.vtx2[0]);lineVtx.push_back(line.vtx2[1]);lineVtx.push_back(line.vtx2[2]);
        lineCol.push_back(1);lineCol.push_back(0);lineCol.push_back(0);lineCol.push_back(1);
        lineCol.push_back(1);lineCol.push_back(0);lineCol.push_back(0);lineCol.push_back(1);
    }
    // getchar();

    return bounding;

}

// float* ApplicationMain::pushItscs(void)
// {
//     // record distance moved {dx1,dy1,dz1,dx2,dy2,dz2,. . .}
//     float distXYZ[unusedItscCube.size()*3];
//     if(unusedItscCube.size()==0)
//     {
//         return distXYZ;
//     }

//     for(auto cube : unusedItscCube)
//     {
//         //TODO:
//         // 1. Find neighboring cube whose side(one of the 6 planes) is closest to the intersection points of this cube.
//         //    (The neighboring cube should have interpolated points)
//         // OR
//         // 1. Find the cube that shares the plane which the 
//         // 1.1 Need hashtable to do (1.) ? 
//         // 2. 
//     }

// }

void ApplicationMain::saveItscForDebug(void)
{
    for(auto cube : cubes)
    {
        if(cube.itscs.size()>0)
        {
            for(auto vtx : cube.itscs)
            {
                intersectionsVtx.push_back(vtx.x);
                intersectionsVtx.push_back(vtx.y);
                intersectionsVtx.push_back(vtx.z);
                intersectionsCol.push_back(1);intersectionsCol.push_back(0);intersectionsCol.push_back(1);intersectionsCol.push_back(1);
            }
        }
    }
}

// for finding the cube that is capturing one 3d point.
int ApplicationMain::whichCubeFromPoint(double x, double y, double z)
{
    int id = -1;
    int count = 0;
    for(auto cube : cubes)
    {
        auto xMin = cube.edge[0].vtx1[0];
        auto xMax = cube.edge[0].vtx2[0];
        auto yMin = cube.edge[2].vtx1[1];
        auto yMax = cube.edge[2].vtx2[1];
        auto zMin = cube.edge[1].vtx1[2];
        auto zMax = cube.edge[1].vtx2[2];

        if( x >= xMin && x <= xMax && y >= yMin && y <= yMax && z >= zMin && z <= zMax )
        {
            id = count;
            break;
        }
        count++;
    }




    return id;
}

// for finding the cube from polygon vertices.
// input poly vertices will always be 2 vertices that is enough to find unique cube that produced this polygon.
int ApplicationMain::whichCubeFromPoly(std::vector<std::vector<float>> polyVert)
{
    std::cout<<__FUNCTION__<< "- - - - -" <<__LINE__<<std::endl;
    
    int id = -1;
    int count = 0;
    // for(auto cube : cubes)
    // {
    //     // TODO
    //     cube.edge
    // }

    return id;

}

bool ApplicationMain::getIntersection(std::vector<Line> inputEdges, std::vector<Cube::Edge> myEdges, Cube &cube)
{
    // myEdges -> top, bot, right, left, front, back.
    // top:   edge 0 and 5  -> y fixed
    // bot:   edge 9 and 11 -> y fixed
    // right: edge 3 and 8  -> x fixed
    // left:  edge 1 and 10 -> x fixed
    // front: edge 0 and 9  -> z fixed
    // back:  edge 5 and 11 -> z fixed

    bool has = false;
    
    for(int i =0; i<myEdges.size()-1; i+=2)
    {
        float x,y,z;
        float c1Vtx[3];
        float c2Vtx[3];
        float s1,s2;

        // corner 1 of plane
        c1Vtx[0] = myEdges[i].vtx1[0];
        c1Vtx[1] = myEdges[i].vtx1[1];
        c1Vtx[2] = myEdges[i].vtx1[2];

        // corner 2 of plane
        c2Vtx[0] = myEdges[i+1].vtx2[0];
        c2Vtx[1] = myEdges[i+1].vtx2[1];
        c2Vtx[2] = myEdges[i+1].vtx2[2];

        // printf("corner 1: %f,%f,%f\n",c1Vtx[0],c1Vtx[1],c1Vtx[2]);
        // printf("corner 2: %f,%f,%f\n",c2Vtx[0],c2Vtx[1],c2Vtx[2]);
        // printf("- - - - - - - \n");

        

        for(auto line : inputEdges)
        {
            // face numbering scheme: top: 1 bot: 2 rig: 3 lef: 4 fro: 5 bac: 6


            // top:   edge 0 and 5  -> y fixed
            // bot:   edge 9 and 11 -> y fixed
            int face;
            if(i<4)
            {
                y = myEdges[i].vtx1[1];  
                s1 = (line.vtx2[0] - line.vtx1[0]) / (line.vtx2[1] - line.vtx1[1]);
                x = s1*y + line.vtx1[0] - line.vtx1[1] * s1;
                s2 = (line.vtx2[2] - line.vtx1[2]) / (line.vtx2[1] - line.vtx1[1]);
                z = s2*y + line.vtx1[2] - line.vtx1[1] * s2;
                if(0==i) face = 0;
                else face = 1;
                
            }
            // right: edge 3 and 8  -> x fixed
            // left:  edge 1 and 10 -> x fixed
            else if(i<8)
            {
                x = myEdges[i].vtx1[0];  
                s1 = (line.vtx2[1] - line.vtx1[1]) / (line.vtx2[0] - line.vtx1[0]);
                y = s1*x + line.vtx1[1] - line.vtx1[0] * s1;
                s2 = (line.vtx2[2] - line.vtx1[2]) / (line.vtx2[0] - line.vtx1[0]);
                z = s2*x + line.vtx1[2] - line.vtx1[0] * s2;
                if(i==4) face = 2;
                else face = 3;
            }
            // front: edge 0 and 9  -> z fixed
            // back:  edge 5 and 11 -> z fixed
            else
            {
                z = myEdges[i].vtx1[2];  
                s1 = (line.vtx2[0] - line.vtx1[0]) / (line.vtx2[2] - line.vtx1[2]);
                x = s1*z + line.vtx1[0] - line.vtx1[2] * s1;
                s2 = (line.vtx2[1] - line.vtx1[1]) / (line.vtx2[2] - line.vtx1[2]);
                y = s2*z + line.vtx1[1] - line.vtx1[2] * s2;
                if(8==i) face = 4;
                else face = 5;
            }     

// TODO: GET BACK TO THIS PART> > >

            if( x>= c1Vtx[0] && x <= c2Vtx[0] &&
                y>= c1Vtx[1] && y <= c2Vtx[1] && 
                z>= c1Vtx[2] && z <= c2Vtx[2])
            {
                float vec1[3],vec2[3];
                vec1[0] = x - line.vtx1[0]; vec1[1] = y - line.vtx1[1]; vec1[2] = z - line.vtx1[2];
                vec2[0] = x - line.vtx2[0]; vec2[1] = y - line.vtx2[1]; vec2[2] = z - line.vtx2[2];

                // dot prod
                float dotProd = vec1[0]*vec2[0] + vec1[1]*vec2[1] + vec1[2]*vec2[2];

                if(dotProd <= 0)
                {
                    
                    Cube::itscVtx temp;
                    temp.x = x; 
                    temp.y = y;
                    temp.z = z;
                    cube.itscs.push_back(temp);
                    cube.itscFaceNums.push_back(std::make_pair(face, cube.itscs.size()-1));
                    has = true;
                    break;
                    
                }
                
                
            }
        }
    }

    if(true==foundWhichCube)
    {
std::cout<<__FUNCTION__ <<__LINE__<<std::endl;
std::cout<<cube.itscs.size()<<std::endl;
        // printf(__FUNCTION____LINE__);
    }

    return has;
    
    
}

std::vector<std::vector<int>> ApplicationMain::Split(const std::vector <int> srcPlg, const std::vector<int> split)
{
    std::vector<std::vector<int>> plgs;
    std::vector<int> usedNotItsc;
    
    int notItsc = srcPlg.size() - split.size();
    int total = 0;
    
    // std::unordered_set<int,int> splitSet;
    // for(auto spl: splitSet)
    // {
    //     if(splitSet.find(spl)==splitSet.end())
    //     {
    //         splitSet.insert(spl);
    //     }
    // }

    int size = split.size();
    plgs.resize(size);
    int id = 0;
    for(int src: srcPlg)
    {
        for(int spl : split)
        {
            if(src==spl)
            {
                plgs[id % size].push_back(src);
                id++;
                // break;
            }
        }
        plgs[id % size].push_back(src);
    }
    if(split.size()>2)
    {
        std::vector<int> temp;
        for(int spl : split)
        {
            temp.push_back(spl);
        }
        plgs.push_back(temp);
    }


// std::cout << "total polygon numbers after split : " << plgs.size() <<std::endl;
    return plgs;



}



void ApplicationMain::Swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;

}
void ApplicationMain::SwapPairs(std::vector<std::vector<int>> &target, int id1, int id2)
{
    auto a = target[id1];
    auto b = target[id2];

    target[id1][0] = b[0]; target[id1][1] = b[1];
    target[id2][0] = a[0]; target[id2][1] = a[1];
}

// TODO: Write FUNCTION to save vtx to .obj
void ApplicationMain::SaveToObj(void)
{
    const char fName[] = "wireModel.obj";
    FILE *fp = fopen(fName,"w+");
    char vertex[2] = "v";
    char face[2]   = "f";
    char space[] = " ";
    // VERTEX
    for(int i =0; i+2<objVtx.size(); i+=3)
    {
        fprintf(fp,"v %f %f %f\n",objVtx[i],objVtx[i+1],objVtx[i+2]);
    }

    // FACE
    
    for(int i =0; i<objFace.size(); ++i)
    {
        if(i==0)
        {
            fprintf(fp,"f");
        }
        
        if(objFace[i]==0)
        {
            if(i < objFace.size()-1)
            {
                fprintf(fp,"\nf");
            }
            else
            {
                fprintf(fp,"\n");
            }
        }
        else
        {
            fprintf(fp," %i",objFace[i]);
        }
        
    }
    fclose(fp);

    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    const char fName2[] = "savedPolygons.txt";
    FILE *fp2 = fopen(fName2,"w+");
    char vertex2[2] = "v";
    char face2[2]   = "f";
    // vertex
    for(int i =0; i+2<objVtx.size(); i+=3)
    {
        fprintf(fp2,"v %f %f %f\n",objVtx[i],objVtx[i+1],objVtx[i+2]);
    }

    // FACE
    
    for(int i =0; i<objFace.size(); ++i)
    {
        if(i==0)
        {
            fprintf(fp2,"f");
        }
        
        if(objFace[i]==0)
        {
            if(i < objFace.size()-1)
            {
                fprintf(fp2,"\nf");
            }
            else
            {
                fprintf(fp2,"\n");
            }
        }
        else
        {
            fprintf(fp2," %i",objFace[i]);
        }
        
    }
    
    fclose(fp2);
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
}



void ApplicationMain::GenerateCubes(void)
{
    
    cubes.clear();
    int xi=0,yi=0,zi=0;
    std::cout << minX <<"," <<minY<<"," <<minZ<<std::endl;
    std::cout << maxX <<"," <<maxY<<"," <<maxZ<<std::endl;
    std::cout << xStep <<"," <<yStep<<"," <<zStep<<std::endl;
    // for(int x= minX; x < maxX; x+=step)
    for(float z= minZ; z < maxZ; z+=zStep)
    {

        yi=0;
        for(float y= minY; y < maxY; y+=yStep)
        {
            xi=0;
            // for(int z= minZ; z < maxZ; z+=step)
            for(float x= minX; x < maxX; x+=xStep)
            {

                Cube cube(x,y,z,xStep,yStep,zStep,nx,ny,nz,
                          xi,yi,zi);

                // ed HASH >>>>>>>>>>>>>>>>>
                // edHashSet.insert()
                // ed HASH <<<<<<<<<<<<<<<<<



                // cube.xInd = xi; cube.yInd = yi; cube.zInd = zi;
                
        

                // TOP
                cubeVtx.push_back(x);       cubeVtx.push_back(y);   cubeVtx.push_back(z);
                cubeVtx.push_back(x+xStep); cubeVtx.push_back(y);   cubeVtx.push_back(z);

                cubeVtx.push_back(x+xStep); cubeVtx.push_back(y);   cubeVtx.push_back(z);
                cubeVtx.push_back(x+xStep); cubeVtx.push_back(y);   cubeVtx.push_back(z+zStep);

                cubeVtx.push_back(x+xStep); cubeVtx.push_back(y);   cubeVtx.push_back(z+zStep);
                cubeVtx.push_back(x);       cubeVtx.push_back(y);   cubeVtx.push_back(z+zStep);

                cubeVtx.push_back(x);       cubeVtx.push_back(y);   cubeVtx.push_back(z+zStep);
                cubeVtx.push_back(x);       cubeVtx.push_back(y);   cubeVtx.push_back(z);

                // BOTTOM
                cubeVtx.push_back(x);       cubeVtx.push_back(y+yStep); cubeVtx.push_back(z);
                cubeVtx.push_back(x+xStep); cubeVtx.push_back(y+yStep); cubeVtx.push_back(z);

                cubeVtx.push_back(x+xStep); cubeVtx.push_back(y+yStep); cubeVtx.push_back(z);
                cubeVtx.push_back(x+xStep); cubeVtx.push_back(y+yStep); cubeVtx.push_back(z+zStep);

                cubeVtx.push_back(x+xStep); cubeVtx.push_back(y+yStep); cubeVtx.push_back(z+zStep);
                cubeVtx.push_back(x);       cubeVtx.push_back(y+yStep); cubeVtx.push_back(z+zStep);

                cubeVtx.push_back(x);       cubeVtx.push_back(y+yStep); cubeVtx.push_back(z+zStep);
                cubeVtx.push_back(x);       cubeVtx.push_back(y+yStep); cubeVtx.push_back(z);

                // SIDE 4
                cubeVtx.push_back(x);       cubeVtx.push_back(y);       cubeVtx.push_back(z);
                cubeVtx.push_back(x);       cubeVtx.push_back(y+yStep); cubeVtx.push_back(z);

                cubeVtx.push_back(x+xStep); cubeVtx.push_back(y);       cubeVtx.push_back(z);
                cubeVtx.push_back(x+xStep); cubeVtx.push_back(y+yStep); cubeVtx.push_back(z);

                cubeVtx.push_back(x+xStep); cubeVtx.push_back(y);       cubeVtx.push_back(z+zStep);
                cubeVtx.push_back(x+xStep); cubeVtx.push_back(y+yStep); cubeVtx.push_back(z+zStep);

                cubeVtx.push_back(x);       cubeVtx.push_back(y);       cubeVtx.push_back(z+zStep);
                cubeVtx.push_back(x);       cubeVtx.push_back(y+yStep); cubeVtx.push_back(z+zStep);

                for(int i =0; i<24; ++i)
                {
                    cubeCol.push_back(0);cubeCol.push_back(0);cubeCol.push_back(0);cubeCol.push_back(1);
                }

                cubes.push_back(cube);
                if(z==minZ && y==minY)
                {
                    xc++;
                }
                xi++;
            }
            
            if(z==minZ) yc++;
            yi++;

        }

        
        zi++;

        zc++;
        
    }

// std::cout<<xc << "," <<yc<< ","<<zc<<std::endl;
}

void ApplicationMain::Update(void)
{
    MarchingCube();
    StoreVtx3d();
    // StoreCubeVtx3d();
}

void ApplicationMain::StoreVtx3d(void)
{

    // x + y*WIDTH + Z*WIDTH*DEPTH
    // (width * height * z) + (width * y) + x
    vtx3d.clear();
    col3d.clear();
    int vtIdent = 1;
    Cube::Edge edge0,edge1,edge2,edge3,edge4,edge5,edge6,edge7,edge8,edge9,edge10,edge11;
    // std::cout<<"number of cubes= "<< cubes.size() <<std::endl;
    int cubeNum = 1;

    for(auto &cube : cubes)
    {
std::cout << __FUNCTION__ << " ---- " <<__LINE__<< std::endl;
std::cout<<nx<<","<<ny<<","<<nz<<std::endl;
std::cout <<cube.xInd <<","<<cube.yInd<<","<<cube.zInd<<std::endl;

        // std::cout<<"current cube Num = " <<cubeNum <<std::endl;
        cubeNum++;
        if(cube.xInd< nx-1 && cube.yInd < ny-1 && cube.zInd < nz-1)
        {
std::cout << __FUNCTION__ << " ---- " <<__LINE__<< std::endl;
            auto currX = cube.xInd;
            auto currY = cube.yInd;
            auto currZ = cube.zInd;
            edge0 = cube.edge[0];
            edge1 = cube.edge[1];
            edge2 = cube.edge[2];
            // get every edge for boundary cubes.

            // borrow edges from neigboring cubes.
            

            edge3 =    cubes[(nx)*(ny)*currZ     + (nx)*currY     + currX +1].edge[1];
            edge4 =    cubes[(nx)*(ny)*currZ     + (nx)*currY     + currX +1].edge[2];
            edge5 =    cubes[(nx)*(ny)*(currZ+1) + (nx)*currY     + currX   ].edge[0];
            edge6 =    cubes[(nx)*(ny)*(currZ+1) + (nx)*currY     + currX   ].edge[2];
            edge7 =    cubes[(nx)*(ny)*(currZ+1) + (nx)*currY     + currX +1].edge[2];
            edge8 =    cubes[(nx)*(ny)*currZ     + (nx)*(currY+1) + currX +1].edge[1];
            edge9 =    cubes[(nx)*(ny)*currZ     + (nx)*(currY+1) + currX   ].edge[0];
            edge10 =   cubes[(nx)*(ny)*currZ     + (nx)*(currY+1) + currX   ].edge[1];
            edge11 =   cubes[(nx)*(ny)*(currZ+1) + (nx)*(currY+1) + currX   ].edge[0];

    // std::cout << __FUNCTION__ << " ---- " <<__LINE__<< std::endl;
            std::vector<Cube::Edge> edges;
            edges.push_back(edge0);edges.push_back(edge1);edges.push_back(edge2);edges.push_back(edge3);
            edges.push_back(edge4);edges.push_back(edge5);edges.push_back(edge6);edges.push_back(edge7);
            edges.push_back(edge8);edges.push_back(edge9);edges.push_back(edge10);edges.push_back(edge11);
            std::vector<bool> flags;
            for(auto &ed : edges)
            {
                if(true==ed.clean) 
                {
                    flags.push_back(true);
                }
                else 
                {
                    flags.push_back(false);
                }
            }
        // ''' GETTING PLANE - LINE INTERSECTION >>>>>>>>>>> GETTING PLANE - LINE INTERSECTION >>>>>>>>>>> GETTING PLANE - LINE INTERSECTION >>>>>>>>>>> '''
            bool hasItsc;
            if(inputEdges.size()>0)
            {
                // top:   edge 0 and 5  -> y fixed
                // bot:   edge 9 and 11 -> y fixed
                // right: edge 3 and 8  -> x fixed
                // left:  edge 1 and 10 -> x fixed
                // front: edge 0 and 9  -> z fixed
                // back:  edge 5 and 11 -> z fixed
                
                hasItsc = getIntersection(inputEdges,{edge0,edge5,edge9,edge11,edge3,edge8,edge1,edge10,edge0,edge9,edge5,edge11},cube);
                
            }




    // ''' GETTING PLANE - LINE INTERSECTION <<<<<<<<<<< GETTING PLANE - LINE INTERSECTION <<<<<<<<<<< GETTING PLANE - LINE INTERSECTION <<<<<<<<<<< '''


            // Find which side of the cube the intersection happened.
        
    // std::cout << __FUNCTION__ << " ---- " <<__LINE__<< std::endl;
            // top    (0): edge  0,3,5,1
            // bottom (1): edge  8,9,10,11
            // right  (2): edge  3,4,8,7
            // left   (3): edge  1,6,10,2
            // front  (4): edge  0,2,9,4
            // back   (5): edge  5,7,11,6

            // int idx[24] = {0,3,5,1,
            //                8,9,10,11,
            //                3,4,8,7,
            //                1,6,10,2,
            //                0,2,9,4,
            //                5,7,11,6};

            // int idx[6][4] = { {0,3,5,1},
            //                   {8,9,10,11},
            //                   {3,4,8,7},
            //                   {1,6,10,2},
            //                   {0,2,9,4},
            //                   {5,7,11,6} };
            std::vector<std::vector<int>> idx = { {0,3,5,1},
                                                {8,9,10,11},
                                                {3,4,8,7},
                                                {1,6,10,2},
                                                {0,2,9,4},
                                                {5,7,11,6} }; 

            
            std::vector<int> tempFace;
            std::vector<bool> isItscVtx;
            std::unordered_set<int> itscSet;
            std::vector<std::vector<int>> tempPair;
   
            
            int num = 0;
            for(auto plane : idx)
            {    
                bool itsc_exist = false;
                int itscIdx;
                //          >>>>
                // NOTE: This method will only work if and only if there's at most one intersection per side of a cube.
                //                                                                  <<<<
                for(auto facePair : cube.itscFaceNums)
                {   
                    if(facePair.first ==num)
                    {
                        itsc_exist = true;
                        itscIdx = facePair.second;
                        break; 
                    }
                }
                bool hasFirst = false;
                bool inserted = false;
                for(int e : plane)
                {
std::cout << "11 " <<std::endl;
// getchar();                
             
                    if(flags[e] == false)
                    {
std::cout << "22 " <<std::endl;
// getchar();                
                        if(true==hasFirst && true==itsc_exist && true!=inserted)
                        {
    
                            inserted = true;
                            vtx3d.push_back(cube.itscs[itscIdx].x);
                            vtx3d.push_back(cube.itscs[itscIdx].y);
                            vtx3d.push_back(cube.itscs[itscIdx].z);
                            col3d.push_back(0);col3d.push_back(1);col3d.push_back(0);col3d.push_back(1);
                            vtx3d.push_back(cube.itscs[itscIdx].x);
                            vtx3d.push_back(cube.itscs[itscIdx].y);
                            vtx3d.push_back(cube.itscs[itscIdx].z);
                            col3d.push_back(0);col3d.push_back(1);col3d.push_back(0);col3d.push_back(1);
                            // FOR SAVING TO OBJ
                            
                            objVtx.push_back(cube.itscs[itscIdx].x);
                            objVtx.push_back(cube.itscs[itscIdx].y);
                            objVtx.push_back(cube.itscs[itscIdx].z);
                            if(cube.itscs[itscIdx].vtident == 0)
                            {
                                cube.itscs[itscIdx].vtident = vtIdent;
                                vtIdent++;
                            }
                            tempFace.push_back(cube.itscs[itscIdx].vtident);
                            tempFace.push_back(cube.itscs[itscIdx].vtident);

    // TODO: GET BACK TO THIS . > > >
                            // if(itscSet.find(cube.itscs[itscIdx].vtident) == itscSet.end())
                            // {
                                itscSet.insert(cube.itscs[itscIdx].vtident);
                            // }
                            isItscVtx.push_back(true);
                            isItscVtx.push_back(true);
                            
                            // corners?
                            // else if(cube.itscs.size()==3)
                            // {

                            // }
                            

                        }
                        
                        vtx3d.push_back(edges[e].interp[0]);
                        vtx3d.push_back(edges[e].interp[1]);
                        vtx3d.push_back(edges[e].interp[2]);
                        col3d.push_back(0);col3d.push_back(0);col3d.push_back(1);col3d.push_back(1);

                        hasFirst = true;

                        if(0==edges[e].vtIdent)
                        {
                            // FOR SAVING TO OBJ
                            objVtx.push_back(edges[e].interp[0]);
                            objVtx.push_back(edges[e].interp[1]);
                            objVtx.push_back(edges[e].interp[2]);
                            edges[e].vtIdent=vtIdent;
                            vtIdent++;
                        }
                        tempFace.push_back(edges[e].vtIdent);
                        isItscVtx.push_back(false);
                        

    // std::cout << "current idx in false flag loop: " << e <<std::endl;
                        
                            
                    }
                }
                
    // std::cout << "one plane done "<<std::endl;
                num++;
                
                // if(flags[i]==false)
                // {
                    
                //     // FOR RENDERING.
                //     vtx3d.push_back(edges[i].interp[0]);
                //     vtx3d.push_back(edges[i].interp[1]);
                //     vtx3d.push_back(edges[i].interp[2]);
                //     col3d.push_back(0);col3d.push_back(0);col3d.push_back(1);col3d.push_back(1);

                //     // FOR SAVING TO OBJ
                //     if(0==edges[i].vtIdent)
                //     {
                //         objVtx.push_back(edges[i].interp[0]);
                //         objVtx.push_back(edges[i].interp[1]);
                //         objVtx.push_back(edges[i].interp[2]);
                //         edges[i].vtIdent=vtIdent;
                //         vtIdent++;
                //     }


                    
                //     tempFace.push_back(edges[i].vtIdent);
                    
                // }
            }

            if(tempFace.size()>0)
            {
                // std::cout<< "printing tempFace . . . \n";
                for(int i=0; i<tempFace.size()-1; i+=2)
                {
                    // std::cout<< tempFace[i] <<","<< tempFace[i+1] <<std::endl;
                    tempPair.push_back({tempFace[i],tempFace[i+1]});
                }
            }
            else if(true==hasItsc)
            {
                unusedItscCube.push_back(cube);
            }
    // std::cout << __FUNCTION__<<"--------"<< __LINE__<<std::endl;
            auto edgeSet = tempPair;
    // std::cout << "--------"<< std::endl;
    // std::cout << "--------"<< std::endl;
    // std::cout << "--------"<< std::endl;
    // std::cout << "--------"<< std::endl;
    // std::cout << __FUNCTION__<<"--------"<< __LINE__<<std::endl;

            // Unmodified initial polygon.
            std::vector<int> plg;

            while(edgeSet.size()>0)
            {
                auto e = edgeSet[0];
                edgeSet.erase(edgeSet.begin());
                int init = e[0];
                int common = e[1];
                auto current = e;
                
                
                // if(itscSet.size()==0)
                if(itscSet.size()<2)
                {
                    objFace.push_back(init);
                }
                
                plg.push_back(init);
                
                

                bool loop = false;
                while(false==loop)
                {
                    for(int i =0; i<edgeSet.size(); ++i)
                    {

                        if(common == edgeSet[i][0])
                        {
                            // if(itscSet.size()==0)
                            if(itscSet.size()<2)
                            {
                                objFace.push_back(common);
                            }
                            plg.push_back(common);
                            
                            
                            
                            common = edgeSet[i][1];
                            current = edgeSet[i];
                            
                            edgeSet.erase(edgeSet.begin()+i);
                            // loop closed.
                            if(common == init)
                            {
                                loop = true;
                                // if(itscSet.size()==0)
                                if(itscSet.size()<2)
                                {
                                    objFace.push_back(0);
                                }
                                
                                // objFace.push_back(init);
                                break;
                            } 
                        }
                        else if(common == edgeSet[i][1])
                        {
                            // if(itscSet.size()==0)
                            if(itscSet.size()<2)
                            {
                                objFace.push_back(common);
                            }
                            plg.push_back(common);
                            
                            
                            common = edgeSet[i][0];
                            current = edgeSet[i];
                            edgeSet.erase(edgeSet.begin()+i);
                            // loop closed.
                            if(common == init)
                            {
                                loop = true;
                                // if(itscSet.size()==0)
                                if(itscSet.size()<2)
                                {
                                    objFace.push_back(0);
                                }
                                // plg.push_back(0);
                                // objFace.push_back(init);
                                break;
                            } 

                        }
                        

                    }
                }
std::cout << __FUNCTION__ << " - - - - - - - - - -" <<__LINE__<< std::endl;
std::cout << " LOOP OUT 1\n";
                
                
            }
std::cout << " LOOP OUT 2\n";
           
            

            // Split POLYGONS by the GIVEN EDGE INTERSECTIONS . . .
            if(itscSet.size()>1)
            {
                std::vector<int> splits;
                for(auto spl : itscSet)
                {
    // std::cout<<spl<<std::endl;
                    splits.push_back(spl);
                }
                auto splitPlgs = Split(plg,splits);
    // std::cout << __FUNCTION__ << " - - - - - - - - - -" <<__LINE__<< std::endl;
                for(auto pl : splitPlgs)
                {
                    for(int p : pl)
                    {
                        // std::cout<< p <<"-";
                        objFace.push_back(p);
                    }
                    // std::cout<<std::endl;
                    objFace.push_back(0);
                }
    // std::cout << __FUNCTION__ << " - - - - - - - - - -" <<__LINE__<< std::endl;
            }

        }
    }
std::cout<<"vtx vector size: "<<vtx3d.size()<<std::endl;

}



void ApplicationMain::MarchingCube(void)
{
    // for(auto &cube : cubes)
    float valA, valB, valC, valD;
    float A1,B1,C1,D1;
    auto valX = nx+1;
    auto valY = ny+1;
    auto valZ = nz+1;
    for(int i = 0; i<cubes.size(); ++i)
    {

        auto xInd = cubes[i].xInd;
        auto yInd = cubes[i].yInd;
        auto zInd = cubes[i].zInd;


        valA = GetValue(cubes[i].edge[0].vtx1);
        valB = GetValue(cubes[i].edge[0].vtx2);
        valC = GetValue(cubes[i].edge[1].vtx2);
        valD = GetValue(cubes[i].edge[2].vtx2);

        if(0 < valA && 0 < valB || 0 > valA && 0 > valB) cubes[i].edge[0].clean = true;
        else
        {

            cubes[i].edge[0].val1 = valA;
            cubes[i].edge[0].val2 = valB;
            auto vtx = linear_interp(cubes[i].edge[0]);
            cubes[i].edge[0].interp[0] = vtx[0];
            cubes[i].edge[0].interp[1] = vtx[1];
            cubes[i].edge[0].interp[2] = vtx[2];


            // interpVtx.push_back(vtx[0]);interpVtx.push_back(vtx[1]);interpVtx.push_back(vtx[2]);
            // interpCol.push_back(0);interpCol.push_back(1);interpCol.push_back(0);interpCol.push_back(1);


        }
        
        if(0 < valA && 0 < valC || 0 > valA && 0 > valC) cubes[i].edge[1].clean = true;
        else
        {

            cubes[i].edge[1].val1 = valA;
            cubes[i].edge[1].val2 = valC;
            auto vtx = linear_interp(cubes[i].edge[1]);
            cubes[i].edge[1].interp[0] = vtx[0];
            cubes[i].edge[1].interp[1] = vtx[1];
            cubes[i].edge[1].interp[2] = vtx[2];
            


            // interpVtx.push_back(vtx[0]);    interpVtx.push_back(vtx[1]);    interpVtx.push_back(vtx[2]);
            // interpCol.push_back(0);interpCol.push_back(1);interpCol.push_back(0);interpCol.push_back(1);

        }
        if(0 < valA && 0 < valD || 0 >valA && 0 >valD) cubes[i].edge[2].clean = true;
        else
        {
            cubes[i].edge[2].val1 = valA;
            cubes[i].edge[2].val2 = valD;
            auto vtx = linear_interp(cubes[i].edge[2]);
            cubes[i].edge[2].interp[0] = vtx[0];
            cubes[i].edge[2].interp[1] = vtx[1];
            cubes[i].edge[2].interp[2] = vtx[2];


            // interpVtx.push_back(vtx[0]);interpVtx.push_back(vtx[1]);interpVtx.push_back(vtx[2]);
            // interpCol.push_back(0);interpCol.push_back(1);interpCol.push_back(0);interpCol.push_back(1);

        }        

    }
            
   
}




std::vector<float> ApplicationMain::CrossProduct(std::vector<float> a, std::vector<float> b)
{
    std::vector<float> ans;
    ans.push_back(a[1]*b[2] - a[2]*b[1]);
    ans.push_back(a[2]*b[0] - a[0]*b[2]);
    ans.push_back(a[0]*b[1] - a[1]*b[0]);

    return ans;
}
float ApplicationMain::Norm(std::vector<float> a)
{
    float ans = sqrt( a[0]*a[0] + a[1]*a[1] + a[2]*a[2] );
    return ans;
}

float ApplicationMain::GetDistance(float pt[], Line line)
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
        // auto cross = CrossProduct(AB,AC);
        // cross[0]/=Norm(AB); cross[1]/=Norm(AB); cross[2]/=Norm(AB); 
        // dist = Norm(cross);
        dist = Norm(CrossProduct(AB,AC)) / Norm(AB);
// std::cout<<dist<<std::endl;
    }

    return dist;
}


// float * ApplicationMain::linear_interp(Cube::Edge edge)  
std::vector<float> ApplicationMain::linear_interp(Cube::Edge edge)    
{
    // f1 and f2: corresponding field value.
    std::vector<float> itpVt {0,0,0};
 
    auto f1 = edge.val1;
    auto f2 = edge.val2;
    
    float pt1,pt2;
    int id;
    for(int i = 0; i<3; ++i)
    {
        if(edge.vtx1[i]!=edge.vtx2[i])
        {
            id = i;
            pt1 = edge.vtx1[i];
            pt2 = edge.vtx2[i];
        }
        else
        {
            itpVt[i] = edge.vtx1[i];
        }
    }



    float interp_pt = pt1 + (pt2 - pt1)* (0 - f1)/(f2 - f1);
    // float interp_pt = edge.vtx1[id] + (edge.vtx2[id] - edge.vtx1[id])* (0 - f1)/(f2-f1);

std::cout<<__FUNCTION__<<__LINE__<<std::endl;
std::cout<<"f1 = "<< f1<<std::endl;
std::cout<<"f2 = "<< f2<<std::endl;
std::cout<<"vtx1 = " <<edge.vtx1[0] << ", "<< edge.vtx1[1]<< ", "<< edge.vtx1[2] <<std::endl;
std::cout<<"vtx2 = " <<edge.vtx2[0] << ", "<< edge.vtx2[1]<< ", "<< edge.vtx2[2] <<std::endl;






    itpVt[id] = interp_pt;

std::cout<<"INTERPOLATED vtx = " <<itpVt[0] <<", "<<itpVt[1]<<", "<<itpVt[2] <<std::endl;

    return itpVt;
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
        // glDrawArrays(GL_LINES,0,cubeNum*24);
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
    if(point==true)
    {
        glPointSize(5);
        glDrawArrays(GL_POINTS,0,lineVtx.size()/3);    
    }
    else
    {
        glLineWidth(5);
        glDrawArrays(GL_LINES,0,lineVtx.size()/3);
    }
    
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

    // Draw interp points.

    glEnable(GL_COLOR_MATERIAL);
    // glDisable(GL_LIGHTING);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glColorPointer(4,GL_FLOAT,0,interpCol.data());
    glVertexPointer(3,GL_FLOAT,0,interpVtx.data());
    glPointSize(50);
    glDrawArrays(GL_POINTS,0,interpVtx.size()/3);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);



    // Draw test plane - line intersection points.
    glEnable(GL_COLOR_MATERIAL);
    glDisable(GL_LIGHTING);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glColorPointer(4,GL_FLOAT,0,istcTestCol.data());
    glVertexPointer(3,GL_FLOAT,0,istcTestVtx.data());
    glPointSize(5);
    glDrawArrays(GL_POINTS,0,istcTestVtx.size()/3);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

    // Draw debug point vertices.
    glEnable(GL_COLOR_MATERIAL);
    glDisable(GL_LIGHTING);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glColorPointer(4,GL_FLOAT,0,intersectionsCol.data());
    glVertexPointer(3,GL_FLOAT,0,intersectionsVtx.data());
    glPointSize(10);
    glDrawArrays(GL_POINTS,0,intersectionsVtx.size()/3);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

    // draw highlight cube if exists. . .
    if(true==highlight)
    {
        glEnable(GL_COLOR_MATERIAL);
        glDisable(GL_LIGHTING);
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);
        glColorPointer(4,GL_FLOAT,0,highCol.data());
        glVertexPointer(3,GL_FLOAT,0,highVtx.data());
        glLineWidth(12);
        glDrawArrays(GL_LINES,0,highVtx.size()/3);
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_COLOR_ARRAY);
    }

    // Draw input edge lines . . .
    if(inputEdges.size()>0 && true == showInput)
    {
        glEnable(GL_COLOR_MATERIAL);
        glDisable(GL_LIGHTING);
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);
        glColorPointer(4,GL_FLOAT,0,inputEdCol.data());
        glVertexPointer(3,GL_FLOAT,0,inputEdVtx.data());
        glLineWidth(5);
        glDrawArrays(GL_LINES,0,inputEdVtx.size()/3);
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_COLOR_ARRAY);
    }
    


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
            if(line.R>step) 
            {
                line.R-=1;
                Update();
            }
        }
// std::cout<<__FUNCTION__<<__LINE__<<std::endl;
    }
    if(key==FSKEY_W)
    {
        for(auto &line: lines)
        {
            line.R+=1;
            Update();
        }
// std::cout<<__FUNCTION__<<__LINE__<<std::endl;
    }
    if(key==FSKEY_LBRACKET)
    {
        if(thres>0.1)
        {
            thres-=0.1;
            Update();
        }

    }
    if(key==FSKEY_RBRACKET)
    {
        thres+=0.1;
        Update();
    }

    if(key==FSKEY_ENTER)
    {
// std::cout<< "total cube num: "<< (cubeVtx.size()/3)/24 <<std::endl;
// std::cout<< "displaying cube num: "<< cubeNum/24 <<std::endl;
        if(cubeNum < vtx3d.size()/3) 
        {
            cubeNum+=1;
// std::cout<<__FUNCTION__<<__LINE__<<std::endl;
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
    if(key == FSKEY_SPACE)
    {
        d = originalDistance;
        Rc.Print();
        
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

    // Highlight one cube for debugging purpose . . .
    if(key == FSKEY_H)
    {
std::cout<<__FUNCTION__<<__LINE__<<std::endl;
        if(true!=highlight) highlight = true;
        else highlight = false;
    }

    if(key == FSKEY_I)
    {
        if(true!=showInput) showInput = true;
        else showInput = false;
    }

    // debug cube
    if(key == FSKEY_D)
    {
        if(t.x() == debugCubeCen[0] && t.y() == debugCubeCen[1] && t.z() == debugCubeCen[2] )
        {
            t.SetX(0); t.SetY(0); t.SetZ(0);
        }
        else
        {
            t.SetX(debugCubeCen[0]);
            t.SetY(debugCubeCen[1]);
            t.SetZ(debugCubeCen[2]);
        }
        
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
	
	globalToCamera.Invert();

	YsMatrix4x4 modelView;
	modelView.Translate(0,0,-d);
	modelView*=globalToCamera;
    modelView.Translate(-t);

// printf("value of t = %f,%f,%f\n",t.x(),t.y(),t.z());

	return modelView;
}

// CONSTRUCTOR . . .
// take inputs: length, thickness, number of cubes, nx,ny,nz
ApplicationMain::ApplicationMain(int argc, char *argv[])
{

    int wid,hei;
	FsGetWindowSize(wid,hei);
    // int cen = std::min(wid/2,hei/2);
    d=10.0;
	t=YsVec3::Origin();
    gap = 50;
    if(argc<5) term = true;
    
    else
    {
std::cout << " 1 "<<std::endl;   
std::cout << " 1 "<<std::endl;   
std::cout << " 1 "<<std::endl;   
        int len,thick,numCube;
        len = atoi(argv[1]);
        thick = atoi(argv[2]);
        numCube = atoi(argv[3]);
        nx = atoi(argv[4]);
        ny = atoi(argv[5]);
        nz = atoi(argv[6]);


        float cen = 0;
        


        // float resolution = 10;
        minX = cen - len/2 * 2; maxX = cen + len/2 * 2;
        minY = cen - len/2 * 2; maxY = cen + len/2 * 2;
        minZ = cen - len/2 * 2; maxZ = cen + len/2 * 2;
// std::cout<<nx<<","<<ny<<","<<nz<<std::endl;
        xStep = (maxX - minX) / nx;
        yStep = (maxY - minY) / ny;
        zStep = (maxZ - minZ) / nz;


        

        
        MakeWire(cen,len,thick,numCube);
        
        GenerateCubes();

        MarchingCube();
        
        StoreVtx3d();
        
        SaveToObj();
        
        saveItscForDebug();
    }
    
        
    




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