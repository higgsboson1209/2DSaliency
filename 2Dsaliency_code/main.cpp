#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/saliency.hpp>
#include <iostream>
using namespace cv;
using namespace std;
using namespace saliency;
/*Matrix where we will store The saliency map*/
Mat Saliency_Map;
/*The Original Image*/
Mat image;
/*A better Saliency map since the values have been scaled on the range [0,255] from [0,1]*/
Mat Thresh_Map;
int main()
{
    /*Giving the path of the image*/
    image = imread("/media/saksham/HDD/Downloads/wallpaper.png");
    /*Using cv2.saliency module and creating an object sm of the class StaticSaliencyFineGrained This is the place where you can change saliency algorithms*/
    auto *sm=new StaticSaliencyFineGrained();
    /*Computing the saliency*/
    sm->computeSaliency(image,Saliency_Map);
    /*done to extract contour or extract each salient region*/
    threshold(Saliency_Map,Thresh_Map,0,255,3);
    imshow("MAP",Thresh_Map);
    waitKey(0);

}