#include <vector>



class Curve
{
public:
    std::vector<float> vtx;
    float tol;
    Curve()
    {
        tol = 1e-4;

        // Save vertices

        for(float x = -2;  x<2; x+=0.1)
        {
            for(float y = -2; y<2; y+=0.1)
            {
                if( (x*x + y*y-1) * (x*x + y*y-1) < tol)
                vtx.push_back(x);
                vtx.push_back(y);
                vtx.push_back(x*x + y*y-1);
            }
        }
    }
    ~Curve()
    {
        vtx.clear();
        tol = 0;
    }

    // std::vector<float> Extract(void)
    // {
    //     for(float x = -2;  x<2; x+=0.1)
    //     {
    //         for(float y = -2; y<2; y+=0.1)
    //         {
    //             if( (x*x + y*y-1) * (x*x + y*y-1) < tol)
    //             vtx.push_back(x);
    //             vtx.push_back(y);
    //             vtx.push_back(x*x + y*y-1);
    //         }
    //     }
    // }
};