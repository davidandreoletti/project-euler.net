//
// Run: clang++ -stdlib=libc++ -std=c++98 -pedantic main.cpp; time ./a.out;
//

#include <cstdint> // uint64_t
#include <cstdio> //printf
#include <ctgmath> //floor

int main(void) {
    // Solution using some optimisation hints
    // Solve the following system of equations for integers a,b,c  :
    // a^2 + b^2 = c^2                          (eq0)
    // a + b + c = 1000  <==> c = 1000 - a - b  (eq1)
    // 0 < a < b < c                            (eq2)
    //
    // Replacing (eq0) with (eq1)
    // a^2 + b^2 = (1000 - (a + b))^2 <==> a^2 + b^2 = 1000^2 + (a + b)^2 - 2*1000*(a+b)
    //                                     a^2 + b^2 = 1000^2 + a^2 + b^2 + 2ab - 2*1000*(a+b)
    //                                     0         = 1000^2 + 2ab - 2*1000*(a+b)
    //                                     - 2ab + 2*1000*(a+b)    = 1000^2
    //                                     - 2ab + 2000a + 2000b    = 1000^2
    //                                     - 2ab + 2000a     = 1000^2 - 2000b
    //                                     2a(1000 - b)     = 1000^2 - 2000b
    //                                     2a     = (1000^2 - 2000b)/(1000 -b)
    //                                     2a     = (2*2*500^2 - 2000b)/(1000 -b)
    //                                     a     = (2*500^2 - 1000b)/(1000 -b)
    // We get:
    // a     = (2*500^2 - 1000b)/(1000 -b)      (eq3)
    // c = 1000 - a - b                         (eq1)
    // 0 < a < b < c                            (eq2)
    //
    // Using (eq2) with (eq3)
    // 0 < a  <==> 0 < (2*500^2 - 1000b)/(1000 -b)
    //             0 < 2*500^2 - 1000b
    //             2*500^2 > 1000b
    //             500^2   >  500b
    //             500   >  b
    //
    // We get:
    // c = 1000 - a - b                         (eq1)
    // 0 < a < b < c                            (eq2)
    // a = (2*500^2 - 1000b)/(1000 - b)         (eq3)
    // 500   >  b                               (eq4)
    //
    // We get:
    // c = 1000 - a - b                         (eq1)
    // 0 < a < b < c                            (eq2)
    // a = (2*500^2 - 1000b)/(1000 - b)         (eq3)
    // 500   >  b  > 0                          (eq5)
    double a = 0;
    uint64_t b = 0;
    uint64_t c = 0;
    uint64_t p = 0;
    for (b=1; b<500 ;b++){
        a = (double)(2*500*500 - 1000*b)/(1000 - b);
        if (!(a - floor(a))) { // check a is an integer 
            c = 1000 - a -b;
            if (c*c == (a*a + b*b)) {
                    p = a*b*c;
                    break;
            }
        }
    }
    printf("Answer: %llu \n", p);
    return 0;
}


