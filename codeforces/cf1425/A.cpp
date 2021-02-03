#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll solve(ll N) {
      ll ans = 0;
      bool flag = 1;
      while(N) {
            ll res;
            if(N%2 == 0) {
                  if(N%4 == 1) {
                        res = N/2;
                        N/=2;  
                  }
                  else {
                        res = 1;
                        N--;
                  }
            }
            else {
                  res = 1;
                  N--;
            }
            if(flag)    ans += res;
            flag = !flag;
      }
      return ans;
}

int main()
{
      int T;
      ll N;
      scanf("%d", &T);
      while(T--) {
            scanf("%lld", &N);
            printf("%lld\n", solve(N));
      }
      return 0;
}