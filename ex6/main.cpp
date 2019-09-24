#include <bits/stdc++.h>
using namespace std;

float *newton(float *x)
{

  float v[2];

  for (int i = 0; i < 2; i++)
  {
    v[i] = x[i];
  }

  // x[0] -= (-sqrt(3 * pow(v[1], 2) - 5) / v[0]) + (3 / (2 * v[0])) * sqrt((-pow(v[0], 2) + 5) / 2);
  // x[1] -= (sqrt(3 * pow(v[1], 2) - 5) / (2 * v[1])) - (1 / (2 * v[1])) * sqrt((-pow(v[0], 2) + 5) / 2);

  x[0] -= (((5 * pow(v[0], 2)) - 5) / (10 * v[0]));
  x[1] -= (((5 * pow(v[1], 2)) - 10) / (10 * v[1]));

  return x;
}

void printX(float *x)
{
  for (int i = 0; i < 2; i++)
    printf("x%d = %.8f\n", i + 1, x[i]);
  //cout << "x" << i + 1 << " = " << x[i] << endl;
}

int main()
{

  float *x;
  int n;

  x = (float *)malloc(sizeof(float) * 2);

  for (int i = 0; i < 2; i++)
    cin >> x[i];

  cin >> n;

  for (int i = 2; i <= n; i++)
  {

    x = newton(x);
    cout << "X" << i << ":" << endl;
    printX(x);
  }

  return 0;
}