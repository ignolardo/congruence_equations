/*

    CALCULATE SOLUTIONS OF CONGRUENCE ECUATION ax ≡ b (mod m)

*/

#include <stdio.h>

int ext_eucl_algorithm(int a, int b, int *x, int *y);

int main(int argc, char **argv) {

    if (argc != 5) {
        printf("Not enough arguments.\n");
        return 0;
    }

    int a, b, m, n;
    
    sscanf_s(argv[4], "%i", &n);
    if (n<1) {
        printf("The number of solutions must be greater than or equal to 1.\n");
        return 0;
    }
    sscanf_s(argv[1], "%i", &a);
    sscanf_s(argv[2], "%i", &b);
    sscanf_s(argv[3], "%i", &m);

    int x;
    int d = ext_eucl_algorithm(m,a,NULL,&x);

    if (b%d != 0) {
        printf("There is no solutions.\n");
        return 0;
    }
    /* One solution */
    x = b*x;

    printf("Solutions of %ix = %i (mod %i) :\n", a, b, m);
    for (register int i=0; i<n; i++) {
        printf("%i\n", x + i*(m/d));
    }

    return 0;
}

int ext_eucl_algorithm(int a, int b, int *x, int *y) {

    register int remainder;
    register int div;

    int unPrev = 1;
    int vnPrev = 0;
    int unCur = 0;
    int vnCur = 1;

    while (b!=0) {
        remainder = a%b;
        div = a/b;
        a = b;
        b = remainder;

        int unNew = unPrev - div * unCur;
        int vnNew = vnPrev - div * vnCur;

        unPrev = unCur;
        vnPrev = vnCur;
        unCur = unNew;
        vnCur = vnNew;
    }

    if (x != NULL) *x=unPrev;
    if (y != NULL) *y=vnPrev;

    return a;
}