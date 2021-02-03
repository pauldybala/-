#include <bits/stdc++.h>

using namespace std;

int main()
{
      int t;
      scanf("%d", &t);
      while(t--) {
            vector<int> vec;
            int n;
            long long sum, odd;
            scanf("%d", &n);
            vec.resize(n+1);
            odd = 0;
            sum = 0;
            for(int i = 1; i <= n; i++) {
                  scanf("%d", &vec[i]);
                  sum += vec[i];
                  if(i % 2) odd += (vec[i] - 1); //奇数位误差相加
            }
            if(2 * odd <= sum) {
                  //奇数位误差满足，则奇数位全部置1
                  printf("1");
                  for(int i = 2; i <= n; i++) {
                        if(i % 2)   printf(" 1");
                        else  printf(" %d", vec[i]);
                  }
                  printf("\n");
            }
            else {
                  //奇数位误差不满足要求，则偶数位全部置 1
                  printf("%d", vec[1]);
                  for(int i = 2; i <= n; i++) {
                        if(i % 2)   printf(" %d", vec[i]);
                        else  printf(" 1");
                  }
                  printf("\n");
            }
      }
      return 0;
}