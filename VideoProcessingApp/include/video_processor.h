#ifndef VIDEO_PROCESSOR_H
#define VIDEO_PROCESSOR_H

#include <opencv2/opencv.hpp>
#include <string>

class VideoProcessor {
public:
    VideoProcessor(const std::string& filePath);
    void processVideo(double startSec, double endSec, int width, int height, int angle, const std::string& text, const cv::Point& position, const std::string& outputFile);
    
private:
    cv::VideoCapture cap;
    cv::VideoWriter writer;
    std::string inputFile;
    cv::Mat frame;
};

#endif // VIDEO_PROCESSOR_H
