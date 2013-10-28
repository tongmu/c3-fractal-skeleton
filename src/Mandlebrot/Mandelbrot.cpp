#include "Mandelbrot.h"
#include <cmath>

void Mandelbrot::gen_fractal()
{
	// Real (-2.5, 1)
	// Imaginary (-1, 1)
    
    // Iterate over each pixel and determine the corresponding complex coordinate (or several complex coordinates if you're anti-aliasing)
    int height=get_height();
    int width=get_width();
    int i, npixels=height*width;
    for(i=0; i<npixels;i++)
    {
        int x=i%height;
        int y=i/height;
        double c_r=(((double)x/width)*3.0-2.25);
        double c_i=(((double)y)/height*3.0-1.5);
        double z_r=0;
        double z_i=0;
        double z_temp;
        int n=0;
        while(pow(z_r,2)-pow(z_i,2)<4&&n<1000)
        {
            z_temp=pow(z_r,2)-pow(z_i,2)+c_r;
            z_i=z_r*z_i*2+c_i;
            z_r=z_temp;
            n++;
        }
        if(n==1000)
        {
            m_bitmap[x*m_height*4+y*4+0]=0;
            m_bitmap[x*m_height*4+y*4+1]=0;
            m_bitmap[x*m_height*4+y*4+1]=0;
            m_bitmap[x*m_height*4+y*4+3]=255;
        }
        else
        {
        m_bitmap[x*m_height*4+y*4+0]=pow((((double)n)/1000),.6)*255;
        m_bitmap[x*m_height*4+y*4+1]=pow((((double)n)/1000),.5)*255;
        m_bitmap[x*m_height*4+y*4+1]=pow((((double)n)/1000),.4)*255;
        m_bitmap[x*m_height*4+y*4+3]=255;
        }
        
    }
    

        // For each pixel, compute the corresponding complex coordinate C (or multiple sub-coordinates, for AA)   

        // let z_r and z_i be 0
        // Begin iterating... while z is not infinity and not too many iterations have passed...
        
            // Z = Z^2 + C
            // increment an iteration counter

        // Color each pixel...

}
