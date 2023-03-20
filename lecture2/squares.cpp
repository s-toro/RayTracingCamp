#include <fstream>

int main() {
    int imageWidth = 640;
    int imageHeight = 480;
    int maxColorComponent = 255;
    int squareSize = 40;
    std::ofstream ppmFileStream("squares.ppm");
	ppmFileStream << "P3\n";
	ppmFileStream << imageWidth << " " << imageHeight << "\n";
	ppmFileStream << maxColorComponent << "\n";
    for ( int rowIndx = 0; rowIndx < imageHeight; rowIndx++) {
        for (int colIndx = 0; colIndx < imageWidth; colIndx++) {
            if ((rowIndx / squareSize) % 2 == (colIndx / squareSize) % 2) {
                ppmFileStream << "255 255 255 "; 
            } else {
                ppmFileStream << "0 0 0 "; 
            }
        }
        ppmFileStream << "\n";
    }
    ppmFileStream.close();

    return 0;
}