#include <iostream>
#include <omp.h>

int main()
{
 using namespace std;
 int i, n = 10000;
 double sum = 0.0, x, h, pi;
 int a = 3, b = 4;
 h = (double)(b - a) /(double)n;
#pragma omp parallel private(x,i) shared(sum,n,h) num_threads(16)
 {
  double l_sum = 0.0;
#pragma omp for
  for (i = 1; i <= n-1; i++) {
   x = a + h * (double)i;
   l_sum += x * x;
   }
#pragma omp atomic
  sum += l_sum;
 }
 pi = (h / 2.0) * (a * a + b * b + 2 * sum);
 cout << pi << endl;
}
