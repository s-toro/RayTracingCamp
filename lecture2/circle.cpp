#include <fstream>
#include <cmath>


int main() {
/// Output image resolution
    static const int imageWidth = 1920;
    static const int imageHeight = 1080;
    static const int maxColorComponent = 255;
    int r = 300;
	std::ofstream ppmFileStream("circle.ppm", std::ios::out | std::ios::binary);
	ppmFileStream << "P3\n";
	ppmFileStream << imageWidth << " " << imageHeight << "\n";
	ppmFileStream << maxColorComponent << "\n";

	for (int rowIdx = 0; rowIdx < imageHeight; ++rowIdx) {
		for (int colIdx = 0; colIdx < imageWidth; ++colIdx) {
            //if (pow(colIdx - imageWidth, 2) + pow(rowIdx - imageHeight, 2) <= r*r) {
            if (pow(abs(rowIdx - imageHeight/2), 2) + pow(abs(colIdx - imageWidth/2), 2) < r*r) {
                ppmFileStream << "255 0 0 ";
            } else {
                ppmFileStream << "255 255 255 ";
            } 
		}
		ppmFileStream << "\n";
	}

	ppmFileStream.close();
	return 0;
}

