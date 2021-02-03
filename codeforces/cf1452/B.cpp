#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define Max(a,b) a>b?a:b
const int MAXN = 2e5 + 13;
ll a[MAXN];

ll solve()
{
      int n;
      ll sum = 0, M = 0;
      scanf("%d", &n);
      for(int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            sum += a[i];
            M = Max(M, a[i]);
      }
      M = Max(M, ceil(1.0*sum/(n-1)));
      ll k = 1ll*(n-1)*M - sum;
      return k;
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