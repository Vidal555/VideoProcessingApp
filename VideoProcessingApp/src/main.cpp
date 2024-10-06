#include <opencv2/opencv.hpp>
#include "../include/video_processor.h"
#include <iostream>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_video>" << std::endl;
        return -1;
    }

    std::string inputFile = argv[1];
    VideoProcessor processor(inputFile);

    // עיבוד הווידאו
    processor.processVideo(10, 20, 640, 480, 90, "Hello World", cv::Point(50, 50), "output.avi");

    return 0;
}
