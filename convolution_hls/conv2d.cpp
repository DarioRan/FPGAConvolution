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

    int mix[N][N];
    int mem[2][W];


    int kernel[N][N]={{1,0,0},};
    kernel[0][0]=1;
    kernel[0][1]=0;
    kernel[0][2]=0;
    kernel[1][0]=0;
    kernel[1][1]=0;
    kernel[1][2]=0;
    kernel[2][0]=0;
    kernel[2][1]=0;
    kernel[2][2]=0;

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

            v=0;
            for(i=0;i<N;i++){
                for(j=0;j<N;j++){
                    v+=mix[i][j]*kernel[i][j];
                }
            }
        

            if w>1 & h>1{
                D_out.write(v)
            }

        }
    }











    
}
