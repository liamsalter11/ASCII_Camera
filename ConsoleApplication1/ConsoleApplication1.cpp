// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<stdio.h>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/videoio.hpp>

int main()
{
    const char shades[] = " .'` ^ \",:;Il!i><~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";
    
    const unsigned int columns = 79;
    const unsigned int rows = 29;

    cv::Mat im;
    cv::Mat image(rows, columns, CV_8U);

    cv::namedWindow("Display window");

    cv::VideoCapture cap(0);

    // Break if 'ESC' is pressed
    while (cv::waitKey(25) != 27) {
        cap >> im;
        
        resize(im, image, cv::Size(columns, rows));

        imshow("Display window", im);
        
        for (unsigned int i = 0; i < rows; i++) {
            for (unsigned int j = 0; j < columns; j++) {
                cv::Vec3b pixel = image.at<cv::Vec3b>(i, j);

                printf("%c", shades[(pixel[0] + pixel[1] + pixel[2]) * 73 / 765]);
            }
            printf("\n");
        }
        printf("\x1b[%dA", rows);
        printf("\x1b[%dD", columns);
    }

    return 0;
}
