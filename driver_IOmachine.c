#include <stdio.h>
#include <string.h>
#include "IOmachine.h"

int main(){
	int i, j;
	MapMatrix R1, R2, R3, RK;
	ReadMap_FileExt(&R1, &R2, &R3, &RK);
	for (i = 1; i <= M; i++){
		for (j = 1; j <= N; j++){
			printf("%s", R1.T[i][j]);
		}
		printf("\n");
	}
	return 0;
}