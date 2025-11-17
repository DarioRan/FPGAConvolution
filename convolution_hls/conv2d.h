#define N (128)
#define H (500)
#define W (500)

#include<hls_stream.h>

typedef int dtype;
void load(int *data, hls::stream<int> D_in);
void move_data_hw(hls::stream<int> D_in, int* mem);
void conv2d_hw(int* mix, int* kernel);
void save(int* result, hls::stream<int>);

