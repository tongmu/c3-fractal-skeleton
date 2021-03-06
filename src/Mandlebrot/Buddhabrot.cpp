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
    int max=0;
    
    while (n<900000)
    {
        int i=rand()%npixels;
        //bucket[i]+=1;
        int x=i%height;
        int y=i/height;
        double c_r=(((double)x/width)*3.0-2.25);
        double c_i=(((double)y)/height*3.0-1.5);
        double z_r=0;
        double z_i=0;
        double z_temp;
        int c=0;
        vector<int>temp;
        bool b=true;
        while(pow(z_r,2)+pow(z_i,2)<4&&c<1000)
        {
            z_temp=pow(z_r,2)-pow(z_i,2)+c_r;
            z_i=z_r*z_i*2+c_i;
            //cout<<"z_i: "<<z_i<<endl;
            z_r=z_temp;
            //cout<<"z_r: "<<z_r<<endl;
            c++;
            int x2=((z_r+2.25)/3)*width;
            //cout<<"x2: "<<x2<<endl;
            int y2=((z_i+1.5)/3)*height;
            //cout<<"y2: "<<y2<<endl;
            int npixels2=y2*width+x2;
            if(npixels2>=90000||npixels2<0)
            {
                b=false;
                break;
            }
            temp.push_back(npixels2);
            
        }
        if(b)
        {
            n++;
            if(c!=1000)
            {
                for(int q=0; q<temp.size(); q++)
                {
                    max++;
                    bucket[temp[q]]+=1;
                }
            }
        }
    }
    int len = bucket.size();
//    int max_index = 0;
    for (int i=0; i<len; i++)
//    {
        cout << i << ": " << bucket[i] << endl;
//        if (bucket[i] > bucket[max_index])
//        {
//            max_index = i;
//        }
//    }
//    int max = bucket[max_index];
    cout<<"max: "<<max<<endl;
    for(int w=0; w<len; w++)
    {
        int x=w%height;
        int y=w/height;
        m_bitmap[x*m_height*4+y*4+0]=pow((((double)bucket[w])/1000),.6)*255;
        m_bitmap[x*m_height*4+y*4+1]=pow((((double)bucket[w])/1000),.5)*255;
        m_bitmap[x*m_height*4+y*4+1]=pow((((double)bucket[w])/1000),.4)*255;
        m_bitmap[x*m_height*4+y*4+3]=255;
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
    

