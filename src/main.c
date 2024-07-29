#include <stdio.h>
#include "kernel.h"

int main(){
	
	kernel k1 = getKernel(2);
	readKernel(k1);
	return 0;
}