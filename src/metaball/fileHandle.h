#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <string>

#include <algorithm>
#include <iterator>

// int main( int argc, char* argv[] )
// {
//     // print all command line arguments
//     std::cout << "name of program: " << argv[0] << '\n' ;

//     if( argc > 1 )
//     {
//         std::cout << "there are " << argc-1 << " (more) arguments, they are:\n" ;

//         std::copy( argv+1, argv+argc, std::ostream_iterator<const char*>( std::cout, "\n" ) ) ;
//     }
// }

class FileHandler
{
public:
    // Number of boxes in xyz directions
    int cubeDim[3];
    // minx miny minz maxx maxy maxz   3D space that the boxes cover
    float cubeCover[6];
    // fvalues on vertices.
    // value                           <- (0,0,0)
    // value                           <- (1,0,0)
    // value
    // value
    // value
    // :
    // :
    // :
    // value                           <- (nx,ny,nz)
    std::vector<float> values;
    bool Read(int argc, char * argv[])
    {
        std::ifstream myfile;
            // print all command line arguments
        std::cout << "name of program: " << argv[0] << '\n' ;

        if( argc > 1 )
        {
            std::cout << "there are " << argc-1 << " (more) arguments, they are:\n" ;

            std::copy( argv+1, argv+argc, std::ostream_iterator<const char*>( std::cout, "\n" ) ) ;

        }
        
        if(2<=argc)
        {

            // myfile.open(argv[2], std::ios_base::in);
            myfile.open(argv[1]);
            // std::string fileDir = argv[2];

        }
        if(!myfile)
        {
            std::cout<< "unable to open file\n";
            return false;
        }

        float a;

        int count = 0;
        while (myfile >> a)
        {

            if(count<3)
            {
                cubeDim[count] = (int)a;
            }
            else if(count<9)
            {
                cubeCover[count-3] = (float)a;
            }
            else
            {
                values.push_back(a);
            }
            // printf("%f\n ", a);
            // std::cout << a<< std::endl;
            
            count++;
        }

        myfile.close();
        return true;
        

    }

    std::vector<std::vector<float>> inputEdges;

    bool readEdges(int argc, char * argv[])
    {
        std::ifstream lineFile;
        if(3<=argc)
        {
            lineFile.open(argv[2]);
        }
        if(!lineFile)
        {
            std::cout<< "unable to open file\n";
            return false;
        }
        std::vector<float> tempLine;
        int count = 0;
        float a;
        while(lineFile >> a)
        {
// printf("%f ", a);

            tempLine.push_back(a);
            count++;
            if(0 < count && 0==count%6)
            {
                inputEdges.push_back(tempLine);
                tempLine.clear();
// printf("\n");
            }
        }
        lineFile.close();
        return true;

    }
};

