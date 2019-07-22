#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>


using namespace std;

//Ref : https://docs.microsoft.com/en-us/windows/win32/medfound/image-stride

//Unusable byte:
// stride - width = unusable image part
// .....** star is unusable part
// .....**
// .....**


//for grayscale :
// for(row)
//      for(col)
//         b channel-> pxl[(row*stride) + col]

struct gray_img{
    int width;
    int height;
    size_t stride;
    uint8_t* data;
};



//for color :
// 3 channels
// rgbrgbrgbrgb**
// rgbrgbrgbrgb**
// rgbrgbrgbrgb**
// for(row)
//      for(col < cols*channels)
//          pxl[(row*stride) + col]
//          pxl[(row*stride) + col +1]
//          pxl[(row*stride) + col +2]

struct rgb_img {
    int width;
    int height;
    int nchannels;
    int none; // used for padding
    size_t stride;
    uint8_t* data;
};


int main()
{

    //GRAYSCALE ---------------------------------------------------------------------------

    cv::Mat img = cv::imread("/home/anubhav/Pictures/p2.jpg",cv::IMREAD_GRAYSCALE);

    if(img.empty())
        return -1;


    cv::imshow("Input",img);


    gray_img gray;
    gray.data = img.data;
    gray.width = img.cols;
    gray.height = img.rows;
    gray.stride = img.step;

    std::cout<<"\nIMg Height : "<<gray.height;
    std::cout<<"\nIMg Width : "<<gray.width;
    std::cout<<"\nIMg Stride : "<<gray.stride;

    for(int r = 0; r < gray.height; r++) {
        for(int c =0; c < gray.width; c++){
            if(gray.data[((r*gray.stride) + c)] > 120){
                gray.data[((r*gray.stride) + c)] = 10;
            }
        }
    }

    cv::Mat in(gray.height,gray.width,CV_8UC1,gray.data,gray.width);

    cv::imshow("Gray",in);




    //RGB IMAGE ---------------------------------------------------------------------------

    cv::Mat rimg = cv::imread("/home/anubhav/Pictures/p2.jpg");

    if(rimg.empty())
        return -1;


    cv::imshow("COLR Input",rimg);


    rgb_img rgb;
    rgb.data = rimg.data;
    rgb.width = rimg.cols;
    rgb.height = rimg.rows;
    rgb.stride = rimg.step;
    rgb.nchannels = rimg.channels();

    std::cout<<"\nCIMg Height : "<<rgb.height;
    std::cout<<"\nCIMg Width : "<<rgb.width;
    std::cout<<"\nCIMg Stride : "<<rgb.stride;

    for(int r = 0; r < rgb.height; r++) {
        for(int c =0; c < rgb.width* rgb.nchannels; c++){

//            rgb.data[((r*rgb.stride) + c)] = 120;
//            rgb.data[((r*rgb.stride) + c+1)] = 120;
//            rgb.data[((r*rgb.stride) + c+2)] = 120;

            if(rgb.data[((r*rgb.stride) + c)] > 180){
                rgb.data[((r*rgb.stride) + c)] = 10;
            }


            if(rgb.data[((r*rgb.stride) + c +1)] > 180){
                rgb.data[((r*rgb.stride) + c +1)] = 10;
            }


            if(rgb.data[((r*rgb.stride) + c +2)] > 180){
                rgb.data[((r*rgb.stride) + c +2)] = 10;
            }
        }
    }

    cv::Mat inrgb(rgb.height,rgb.width,CV_8UC3,rgb.data,rgb.width*rgb.nchannels);

    cv::imshow("COLOR",inrgb);




    cv::waitKey();

    return 0;
}
