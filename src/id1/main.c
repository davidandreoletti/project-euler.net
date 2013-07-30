#include <stdint.h>
#include <stdio.h> //printf
#include <tgmath.h> // floor

int main(void) {
    // Brute force solution
    int sum = 0;
    short i = 0;
    for (i=0; i<1000; i++) {
        if ((i%3 == 0) || (i%5==0)){ sum+=i;}
    }
    printf("Answer: %u \n", sum);

    // Arithmetic Progression Sum solution
    // F1: S_n = (n/2) * (a_1 + a_n) where  n=number of term to sum up
    //                                      a_1=First term
    //                                      a_n=Last term
    //                                      S_n=Sum of n terms from a_1 to a_n
    //
    // a) Sum for all terms multiple of 3 from 3 to 1000:
    //
    // a_1 = 3
    // a_n ?
    //   // Arithmetic Progression
    //   F2: a_n = a_1 + (n-1)d where n=nth term
    //                                d=common difference. Eg: 3 for 3,6,9,12
    //                                a_n=nth term of the sequence
    //       999 = a_1 + (n-1)d  ==> n = 333
    //       So a_333 = 3+(333-1)3 = 999
    // 
    // n = 333
    // S_333 = (333/2) * (3+999) = 166833
    //
    // b) Same for multiple of 5:
    // a_1 = 5
    // a_n ? 
    //   999 = a_1 + (n-1)d ==> n = int(199.8) => 199
    //   So a_199 = 5+(199-1)5 = 995
    // n = 199
    // S_199 = (199/2) * (5+995) = 99500
    //
    // Warning: Counting twice terms both multiple of 3 and 5
    // c) Sum for all terms multiple of 3 AND 5 from 5 to 1000
    // => Multiple of 3 and 5 are all multiples of 15.
    // a_1 = 15
    // a_n = ?
    //   999 = a_1 + (n-1)d ==> n = 66.6... => int(66.6...) => 66
    //   So a_66 = 15+(66-1)15 = 990
    // n=66
    // S_66 = (66/2) * (15+990) = 33165
    //
    // S_999 = S_333 + S_199 - S_66
    double s333 = (((double)333)/2)*(3+999);
    double s199 = (((double)199)/2)*(5+995);
    double s66 = (((double)66)/2)*(15+990);
    double sum2 = s333 + s199 - s66;
    printf("Answer: %g \n", sum2);
    return 0;
}
