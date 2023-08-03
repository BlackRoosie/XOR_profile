#include <iostream>

using namespace std;

#define SIZE 16 //sBox size

//here type your sBox
unsigned char sBox[SIZE] = {
    0xe, 0xd, 0xb, 0x0, 
    0x2, 0x1, 0x4, 0xf, 
    0x7, 0xa, 0x8, 0x5, 
    0x9, 0xc, 0x3, 0x6
};

int XOR_profile(){
    int diffTable[SIZE][SIZE] = {0};

    int inputXOR, outputXOR, maxi;

    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            inputXOR = int(char(i) ^ char(j));
            outputXOR = int(sBox[i] ^ sBox[j]);

            diffTable[outputXOR][inputXOR] += 1;
            
            if(diffTable[inputXOR][outputXOR] > maxi && inputXOR != 0 && outputXOR != 0)
                maxi = diffTable[inputXOR][outputXOR];
        }
    }

    return maxi;
}

int main(){

    int profile = XOR_profile();
    cout<<profile;

    return 0;
}