#define N (3)
#define H (500)
#define W (500)

#include<hls_stream.h>

typedef int dtype;
void load(int *data, hls::stream<int> D_in);
void 2dconv(hls::stream<int> D_in, hls::stream<int> D_out);
void save(int* result, hls::stream<int>);

