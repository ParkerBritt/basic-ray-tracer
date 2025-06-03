#include <iostream>
#include <color.h>

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

int main()
{
    int image_width = 1000;
    int image_height = 1000;

    std::cout << "P3\n";
    std::cout << image_width << ' ' << image_height << "\n";
    std::cout << 255 << "\n";

    for (int j=0; j<image_height; ++j)
    {
        displayProgress(static_cast<float>(j)/(image_height-1));
        for(int i=0; i<image_width; ++i)
        {
            float r = static_cast<float>(i)/(image_width-1);
            float g = static_cast<float>(j)/(image_height-1);
            float b = 0;

            writeColor(std::cout, color(r,g,b));
        }
    }
    std::clog << "\n-----------\nRender Complete                                \n";
}
