#include <bits/stdc++.h>

using namespace std;

int main()
{
      int N;
      scanf("%d", &N);
      vector<int> vec(N + 1);
      int a, b, c;
      printf("? 1 3\n");
      fflush(stdout);
      scanf("%d", &a);
      printf("? 1 2\n");
      fflush(stdout);
      scanf("%d", &b);
      printf("? 2 3\n");
      fflush(stdout);
      scanf("%d", &c);
      vec[2] = b + c - a;
      vec[1] = b - vec[2];
      vec[3] = c - vec[2];
      for(int i = 4; i <= N; i++) {
            printf("? %d %d\n", i-1, i);
            fflush(stdout);
            scanf("%d", &a);
            vec[i] = a - vec[i-1];
      }
      printf("!");
      for(int i = 1; i <= N; i++) {
            printf(" %d", vec[i]);
      }
      printf("\n");
      return 0;
}