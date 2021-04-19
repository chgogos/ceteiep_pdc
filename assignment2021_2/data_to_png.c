#include "data_to_png.h"

#define MAXIMUM(A,B) (A>B?A:B)

void data_to_png(char* data_fn, char* png_fn){
	FILE* fp;
	fp = fopen(data_fn, "r");
	if (fp==NULL){
		printf("File %s does not exist\n", data_fn);
		exit(-1);
	}
	int buffer_length=4096;
	int width, height;
	char buffer[buffer_length];
	fgets(buffer, buffer_length, fp);
	width = atoi(buffer);
	fgets(buffer, buffer_length, fp);
	height = atoi(buffer);
	double *data = (double*) malloc(sizeof(double)*width*height);
	double max = 0;
	double min = 1000;
	for (int i =0;i<height;i++){
		fgets(buffer, buffer_length, fp);
		int j = 0;
		char* token =  strtok(buffer, " ");
		while(token != NULL){
			double value = atof(token);
			if (value>max){
				max = value;
			}
			if (value < min){
				min = value;
			}
			data[i*width +j] = value;
			token = strtok(NULL, " ");
			j++;
		}
	}

	unsigned char *image = (unsigned char*) malloc(sizeof(unsigned char) * width * height * 4);
	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++){
			int k = i * width + j;
			// https://stackoverflow.com/questions/20792445/calculate-rgb-value-for-a-range-of-values-to-create-heat-map
			double ratio = 2 * (data[k]-min) / (max - min);
			int green = (int)(MAXIMUM(0, 255*(1 - ratio)));
			int red = (int)(MAXIMUM(0, 255*(ratio - 1)));
    		int blue = 255 - green - red;
			image[k*4] = red;
			image[k*4 + 1] = blue;
			image[k*4 + 2] = green;
			image[k*4 + 3] = 255;
		}
	}

	lodepng_encode32_file(png_fn, image, width, height);
	free(image);
}