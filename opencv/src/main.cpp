#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include "miniaudio.h"

int audio()
{
    ma_result result;
    ma_engine engine;

    result = ma_engine_init(NULL, &engine);
    if (result != MA_SUCCESS) {
        return -1;
    }

    ma_engine_play_sound(&engine, "audio.mp3", NULL);

    getchar();

    ma_engine_uninit(&engine);

    return 0;
}

int main() 
{       
	cv::VideoCapture cap("video.mp4");
	cv::Mat frame;

	cap>>frame;

	std::string matrix = "";
	matrix.reserve(frame.rows * frame.cols);

        const char* gradient = " .:-=+*#%@";
	std::thread th(audio);
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
                                 
                                matrix += gradient[color / 26];

                        }


                }
		std::cout<<matrix<<std::flush;
		matrix.clear();
		


	}
	th.join();
	return 0;
}
