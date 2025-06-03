#include <iostream>
#include "color.h"
#include "ray.h"

void displayProgress(float progress)
{
    int barWidth = 20;
    std::string progressCenter = ""; 

    int percent = progress*100;

    for(int i=0; i<barWidth; ++i)
    {
        if(progress*(barWidth-1)>=i)
        {
            progressCenter += "█";
        }
        else
        {
            progressCenter += "-";
        }
    }
    std::clog << "\r[" << progressCenter << "]" << " " << percent << "%" << std::flush;
}

color rayColor(const ray& r)
{
    return color(0.0, 0.0, 0.0);
}

int main()
{
    auto aspectRatio = 16.0/9.0;
    int imageWidth = 1000;
    int imageHeight = imageWidth*aspectRatio;

    vec3 cameraCenter(0.0, 0.0, 0.0);
    double focalLength = 1.0;

    auto viewportHeight = 2.0;
    auto viewportWidth = viewportHeight * (static_cast<double>(imageWidth)/imageHeight);

    vec3 viewportU(viewportWidth, 0.0, 0.0);
    vec3 viewportV(0.0, -viewportHeight, 0.0);

    vec3 pixelDeltaU = viewportU/imageWidth;
    vec3 pixelDeltaV = viewportV/imageHeight;

    vec3 viewportUpperLeft = 
    (
        cameraCenter - // start in camera center
        vec3(0.0, 0.0, -focalLength) - // move back by focal lenngth
        viewportU/2 - // move to left edge
        viewportV/2 // move to top edge
    );

    // add half a pixel of padding fro the edge
    vec3 firstPixelCenter = viewportUpperLeft + 0.5 * (pixelDeltaU + pixelDeltaV);

    std::cout << "P3\n";
    std::cout << imageWidth << ' ' << imageHeight << "\n";
    std::cout << 255 << "\n";

    for (int j=0; j<imageHeight; ++j)
    {
        displayProgress(static_cast<float>(j)/(imageHeight-1));
        for(int i=0; i<imageWidth; ++i)
        {
            auto pixelCenter = firstPixelCenter + (i*pixelDeltaU) + (j*pixelDeltaV);
            auto rayDirection = pixelCenter - cameraCenter;

            auto r = ray(cameraCenter, rayDirection);
            color pixelColor = rayColor(r);

            // color pixelColor
            // (
            //     static_cast<float>(i)/(imageWidth-1),
            //     static_cast<float>(j)/(imageHeight-1),
            //     0
            // );

            writeColor(std::cout, pixelColor);
        }
    }
    std::clog << "\n-----------\nRender Complete                                \n";
}
