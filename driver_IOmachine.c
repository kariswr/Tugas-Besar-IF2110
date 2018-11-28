/* driver IOmachine.c */

#include "IOmachine.h"
#include "library.h"
#include <stdio.h>

int main() {
	MapMatrix R1, R2, R3, RK;
	ReadMap_FileExt(&R1,&R2,&R3,&RK);
	int i,j;
	for (i = 1; i <= M; i++) {
		for (j = 1; j <= N; j++) {
			printf("%c", R1.T[i][j][1]);
			printf("%c", R1.T[i][j][2]);
		}
		printf(" %d \n", i);
	}
	printf("\n");
	for (i = 1; i <= M; i++) {
		for (j = 1; j <= N; j++) {
			printf("%c", R2.T[i][j][1]);
			printf("%c", R2.T[i][j][2]);
		}
		printf(" %d \n", i);
	}
	printf("\n");
	for (i = 1; i <= M; i++) {
		for (j = 1; j <= N; j++) {
			printf("%c", R3.T[i][j][1]);
			printf("%c", R3.T[i][j][2]);
		}
		printf(" %d \n", i);
	}
	printf("\n");
	for (i = 1; i <= M; i++) {
		for (j = 1; j <= N; j++) {
			printf("%c", RK.T[i][j][1]);
			printf("%c", RK.T[i][j][2]);
		}
		printf(" %d \n", i);
	}
	printf("\n");
	return 0;
}
