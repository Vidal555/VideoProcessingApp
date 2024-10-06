#include "video_processor.h"
#include <iostream>

VideoProcessor::VideoProcessor(const std::string& filePath) : inputFile(filePath) {
    cap.open(inputFile);
    if (!cap.isOpened()) {
        std::cerr << "Error opening video file: " << inputFile << std::endl;
    }
}

void VideoProcessor::processVideo(double startSec, double endSec, int width, int height, int angle, const std::string& text, const cv::Point& position, const std::string& outputFile) {
    // פותחים את VideoWriter
    writer.open(outputFile, cv::VideoWriter::fourcc('M','J','P','G'), cap.get(cv::CAP_PROP_FPS), cv::Size(width, height));
    
    if (!writer.isOpened()) {
        std::cerr << "Error opening output file: " << outputFile << std::endl;
        return;
    }

    cap.set(cv::CAP_PROP_POS_MSEC, startSec * 1000); // מתחילים מהשניה הרצויה
    while (cap.read(frame) && cap.get(cv::CAP_PROP_POS_MSEC) <= endSec * 1000) {
        // שינוי גודל
        cv::resize(frame, frame, cv::Size(width, height));

        // סיבוב
        cv::rotate(frame, frame, angle == 90 ? cv::ROTATE_90_CLOCKWISE : cv::ROTATE_90_COUNTERCLOCKWISE);

        // הוספת טקסט
        cv::putText(frame, text, position, cv::FONT_HERSHEY_SIMPLEX, 1.0, cv::Scalar(255, 255, 255), 2);

        // הוספת פילטר גווני אפור
        cv::cvtColor(frame, frame, cv::COLOR_BGR2GRAY);

        // כתיבת המסגרת לקובץ הפלט
        writer.write(frame);

        // הצגת המסגרת על המסך
        cv::imshow("Processed Video", frame);
        if (cv::waitKey(30) >= 0) break; // אם נלחץ על מקש, יוצאים מהלולאה
    }

    writer.release(); // משחררים את הווידיאו
}
