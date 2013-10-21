#include "Buddhabrot.h"
#include <vector>
using namespace std;



void Buddhabrot::gen_fractal()
{

   
	// Real (-2.5, 1)
	// Imaginary (-1, 1)
    int height=get_height();
    int width=get_width();
    const int npixels=height*width;
    vector<int> bucket (npixels);
    
    int n=0;
    while (n<10000)
    {
            int i=rand()%npixels;
            bucket[i]+=1;
            int x=i%height;
            int y=i/height;
            double c_r=(((double)x/width)*3.0-2.25);
            double c_i=(((double)y)/height*3.0-1.5);
            double z_r=0;
            double z_i=0;
            double z_temp;
            int n=0;
            vector<int>temp;
            while(pow(z_r,2)+pow(z_i,2)<4&&n<1000)
            {
                z_temp=pow(z_r,2)-pow(z_i,2)+c_r;
                z_i=z_r*z_i*2+c_i;
                z_r=z_temp;
                n++;
            }
        
        }
    }
    
    // Initialize a bucket array (one integer for each pixel) (this is the outer bucket array)
    
    // iterate over the following several thousand times (at least more times than # of pixels)
  
        // Create a temporary bucket array (one integer for each pixel
        //
        // Let C be a random point in the complex plane
        //
        // Trace the orbit of C, incrementing the temporary bucket that z falls in for each iteration
        // If Z is in the mandelbrot set, discard the temporary bucket
        // Else, merge the temporary bucket with the outer bucket array
        

     // Normalize the global bucket array by dividing each value by the maximum value
     // Color each pixel however you wish
     //
     // Parallelizing this function is tricky. It helps to have a list of temporary bucket arrays
     // Which are merged after the computation has finished.
     
     // Parallelizing is not required, but will save you a lot of time.
     

}
    

