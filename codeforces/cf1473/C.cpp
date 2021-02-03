#include <bits/stdc++.h>

using namespace std;

void solve()
{
      int n, k;
      scanf("%d%d", &n, &k);
      int pos = k - (n - k);
      int x = k;
      for(int i = 1; i <= k; i++) {
            if(i > 1)   printf(" ");
            if(i >= pos) {
                  printf("%d", x--);
            }
            else printf("%d", i);
      }
      printf("\n");
}

int main()
{
      //freopen("input.txt", "r", stdin);
      int t;
      scanf("%d", &t);
      while(t--) {
            solve();
      }
      return 0;
}