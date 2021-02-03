#include <bits/stdc++.h>

using namespace std;
#define Max(a, b)  a>b?a:b
const int MAXN = 2e5 + 13;
int a[MAXN];

long long solve()
{
      int n;
      long long ans = 0, k = 0;
      scanf("%d", &n);
      scanf("%d", &a[0]);
      scanf("%d", &a[1]);
      ans += abs(a[1] - a[0]);
      for(int i = 2; i < n; i++) {
            scanf("%d", &a[i]);
            ans += abs(a[i] - a[i-1]);
            k = Max(k, abs(abs(a[i] - a[i-1]) + abs(a[i-1] - a[i-2]) - abs(a[i] - a[i-2]) ));
      }
      k = Max(k, abs(a[0] - a[1]));
      k = Max(k, abs(a[n-1] - a[n-2]));
      // cout << ans << " " << k << endl;
      return ans - k;
}


int main()
{
      freopen("input.txt", "r", stdin);
      int t;
      scanf("%d", &t);
      while(t--) {
            printf("%lld\n", solve());
      }
      return 0;
}