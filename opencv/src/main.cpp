#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
int main() 
{       
	cv::VideoCapture cap("/home/monika/Загрузки/badapplescale.mp4");
	cv::Mat frame;

	cap>>frame;

	std::string matrix = "";
	matrix.reserve(frame.rows * frame.cols);

	while (1)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(33));
		cap>>frame;

		if (frame.empty()) break;

                for (int r = 0; r < frame.rows; ++r)
                {
			cv::Vec3b* pixel = frame.ptr<cv::Vec3b>(r);
                        
                        for(int c = 0; c < frame.cols; ++c)
                        {
                                
                                //cv::Vec3b pixel = frame.at<cv::Vec3b>(r, c);
                                //int color = round((pixel[0] + pixel[1] + pixel[2]) / 3.0);

				int color = ((pixel[c][0] + pixel[c][1] + pixel[c][2]) / 3.0);
                                if(color >= 255)
                                { 
                                        matrix += "@";
                                }
                                else if(color >= 204)
                                {
                                        matrix += "#";
                                }
				else if(color >= 153)
				{
					matrix += "*";
				}
				else if(color >= 102)
				{
					matrix += "+";
				}
				else
				{
					matrix += ".";
				}

                        }


                }
                std::cout<<matrix<<std::endl;
		matrix.clear();


	}
	return 0;
}
