#include <omp.h>
#include <cstdlib>
#include <cstdio>

int main() {
    // Flow Dependence 
    // https://www.openmp.org/wp-content/uploads/openmp-examples-5-0-1.pdf#page=99
    int x = 1;
    #pragma omp parallel
    #pragma omp single
    {
        #pragma omp task shared(x) depend(out: x)
            x = 2;
        #pragma omp task shared(x) depend(in: x)
            printf("x = %d\n", x);
    }

    // Anti-dependence
    x = 1;
    #pragma omp parallel
    #pragma omp single
    {
        #pragma omp task shared(x) depend(in: x)
            printf("x = %d\n", x);
        #pragma omp task shared(x) depend(out: x)
            x = 2;
    }

    // Mutually Exclusive Execution with Dependences
    // https://www.openmp.org/wp-content/uploads/openmp-examples-5-0-1.pdf#page=111
    int a, b, c, d;
    #pragma omp parallel
    #pragma omp single
    {
        #pragma omp task depend(out: c)
            c = 1; /* Task T1 */
        #pragma omp task depend(out: a)
            a = 2; /* Task T2 */
        #pragma omp task depend(out: b)
            b = 3; /* Task T3 */
        #pragma omp task depend(in: a) depend(mutexinoutset: c)
            c += a; /* Task T4 */
        #pragma omp task depend(in: b) depend(mutexinoutset: c)
            c += b; /* Task T5 */
        #pragma omp task depend(in: c)
            d = c; /* Task T6 */
    }
    printf("d = %1d\n", d);

    return 0;
}
