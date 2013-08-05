#include <stdint.h>
#include <stdio.h> //printf
#include <tgmath.h> // floor, pow, log10
int main(void) {
    // O(n) solution :(
    int fn = 0;   // Fn
    int fnm1 = 0; // F0
    int fnm2 = 1; // F1
    int sum = 0;  // F0
    int L = 4000000;
    for (; fn<=L;) {
	fn = fnm1 + fnm2; 
        if (fn%2==0){ 
		sum+=fn;
        	//printf("Fn: %u \n", fn);
        }
	fnm1 = fnm2;
	fnm2 = fn;
    }
    printf("Answer: %u \n", sum);
    // O(1) solution :)
    double n=floor(log10(sqrt(5.0)*L)/log10(2.0+sqrt(5.0)));
    double x=(2.0+sqrt(5.0)); 
    double y=(2.0-sqrt(5.0));
    sum = ( ( (x-pow(x,(n+1.0))) / (1.0-x) ) - ( (y-pow(y,(n+1.0))) / (1.0-y) ) )/pow(5.0, 0.5);
    printf("Answer: %u \n", sum);
    return 0;
}
