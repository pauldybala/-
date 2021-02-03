#include <bits/stdc++.h>

using namespace std;
#define eps 1e-9

double solve()
{
      int n, m;
      scanf("%d%d", &n, &m);
      vector<int> a(n + 1);
      vector<double> p(n + 1);
      int pos = 1;
      for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
      }
      for(int i = n; i >= 1; i--) {
            if(a[i] != i) {
                  pos = i;
                  break;
            }
      }
      bool ok = false;
      double ans = 1.0;
      for(int i = 0; i < m; i++) {
            int ri;
            double pi;
            scanf("%d%lf", &ri, &pi);
            if(ri >= pos && fabs(pi - 0) > eps) {
                  if(fabs(pi - 1) < eps)  ok = true;
                  ans = ans * (1 - pi);
            }
      }
      if(ok || pos == 1)      return 1.0;
      return 1.0-ans;
}

int main()
{
      freopen("input.txt", "r", stdin);
      int t;
      scanf("%d", &t);
      while(t--) {
            printf("%.6f\n", solve());
      }

}