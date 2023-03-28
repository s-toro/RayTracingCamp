#include <fstream>
#include <cmath>

/// Output image resolution
static const int imageWidth = 640;
static const int imageHeight = 480;

static const int maxColorComponent = 255;

//aspect ratio
static const float aspectRatio = imageWidth / imageHeight;

int main() {
	std::ofstream ppmFileStream("crt_output_image.ppm", std::ios::out | std::ios::binary);
	ppmFileStream << "P3\n";
	ppmFileStream << imageWidth << " " << imageHeight << "\n";
	ppmFileStream << maxColorComponent << "\n";

	for (int rowIdx = 0; rowIdx < imageHeight; ++rowIdx) {
		for (int colIdx = 0; colIdx < imageWidth; ++colIdx) {
			//convert pixel to NDC coordinates
            float x_pxl =  (colIdx + 0.5) / imageWidth;
            float y_pxl = (rowIdx + 0.5) / imageHeight;
			//convert pixel coordinates to screen space
            x_pxl = (2.0 * x_pxl) - 1.0;
            y_pxl = 1.0 - (2.0 * y_pxl);
			//account image aspect ratio
			x_pxl *= aspectRatio;
			//camera space???
			//x_pxl *= tan((90*3.14/180)/2);
			//y_pxl *= tan((90*3.14/180)/2);
			//length of vector
			float vec_length = sqrt(x_pxl*x_pxl + y_pxl*y_pxl + 1);
			int r = abs((x_pxl/vec_length) * maxColorComponent);
			int g = abs((y_pxl/vec_length) * maxColorComponent);
			int b = abs((1/vec_length) * maxColorComponent);
			ppmFileStream << r << " " <<  g << " " << b << "\t";
		}
		ppmFileStream << "\n";
	}

	ppmFileStream.close();

	return 0;
}
