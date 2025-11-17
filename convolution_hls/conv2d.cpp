#include<hls_stream.h>
#include "conv2d.h"

void load(int *data, hls::stream<int> D_in){

    for(int i; i<H*W; i++){
        D_in.write(data[i]);
    }

}
