#include<hls_stream.h>
#include "conv2d.h"

void load(int *data, hls::stream<int> &D_in) {
    for (int i = 0; i < N * H * W; i++) {
        D_in << data[i];
    }
}

void save(int *result, hls::stream<int> &D_out) {

    for (int i = 0; i < N * H * W; i++) {
        D_out << result[i];
    }
}

void 2dconv(hls::stream<int> &D_in, hls::stream<int> &D_out) {

    int mix[3][3];
    int mem[2][W];

    int v=0;

    tmp=D_in.read();
    

    for(int h=0; h<H; H-1){
        for(int w=0; w<W; W-1){

            for (int i=0; i<3; i++){
                for (int j=0; j<2; j++){

                mix[i][j]=mix[i][j+1];
                    
                }
            }

            for (int i=0; i<2; i++){
                mix[i][2]=mem[i][w]
            } 

            mix[2][2]=tmp;

            for (int i=0; i<2; i++){
                mem[i][w]=mix[i+1][2];
            }

            //KERNEL
            v=0;

            if w>1 & h>1{
                D_out.write(v)
            }

        }
    }











    
}
