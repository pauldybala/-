#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll solve()
{
      ll p, q;
      scanf("%lld%lld", &p, &q);
      if(p%q != 0)      return p;
      ll ans = 0;
      for(int i = 2; i <= sqrt(q); i++) {
            if(q%i == 0) {
                  ll k = p;
                  while(k%i == 0)   k/=i;
                  ll res = 1;
                  while(q%i == 0)   q/=i, res*=i;
                  res/=i;
                  ans = max(ans, res*k);
            }
      }
      if(q!=1) {
            while(p%q == 0) p/=q;
            ans = max(ans, p);
      }
      return ans;
}

int main()
{
      int t;
      scanf("%d", &t);
      while(t--) {
            printf("%lld\n", solve());
      }
      return 0;
}