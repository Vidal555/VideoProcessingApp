cmake_minimum_required(VERSION 3.10)
project(VideoProcessingApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# הגדרת מיקום OpenCV
set(OpenCV_DIR "C:/opencv/build/x64/vc16")

# הגדרת מיקום GStreamer
set(GSTREAMER_DIR "C:/gstreamer/1.0/msvc_x86_64")
set(GSTREAMER_INCLUDE_DIR "${GSTREAMER_DIR}/include/gstreamer-1.0")
set(GSTREAMER_LIB_DIR "${GSTREAMER_DIR}/lib")

# חיפוש חבילת OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS} include)

# חיפוש חבילת GStreamer
find_package(PkgConfig REQUIRED)
pkg_check_modules(GSTREAMER REQUIRED gstreamer-1.0 gstreamer-base-1.0)

# הוספת נתיב הספריות של GStreamer
link_directories(${GSTREAMER_LIB_DIR})
include_directories(${GSTREAMER_INCLUDE_DIR} ${GSTREAMER_INCLUDE_DIR}/gstreamer-1.0)

# הוספת קבצים 
add_executable(VideoProcessingApp 
    src/main.cpp 
    src/video_processor.cpp
)

# קישור לספריות
target_link_libraries(VideoProcessingApp ${OpenCV_LIBS} ${GSTREAMER_LIBRARIES})
