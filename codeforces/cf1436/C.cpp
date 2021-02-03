#include <bits/stdc++.h>

using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;

ll A(ll a, ll b) {
      ll res = 1;
      for(ll i = a - b + 1; i <= a; i++) {
            res = res * i % MOD;
      }
      return res;
}

ll solve()
{
      int x, n, pos;
      scanf("%d%d%d", &n, &x, &pos);
      int left = 0, right = n, mid;
      int sl, sr;
      sl = sr = 0;
      while(left < right) {
            mid = (left + right) >> 1;
            if(mid <= pos) {
                  if(mid != pos)
                        sl++; //小的++
                  left = mid + 1;
            }
            else {
                  sr++;
                  right = mid;
            }
      }
      // cout << sl << " , " << sr << endl;
      ll ans = 1, res = 0;
      if(sl >= x || sr > (n - x))   return 0;
      if(sl != 0) {
            ans = ans * A(x-1, sl) % MOD;
      }
      if(sr != 0) {
            ans = ans * A(n-x, sr) % MOD;
      }
      ans = ans * A(n - sl - sr - 1, n - sl - sr - 1) % MOD;
      return ans;
}

int main()
{
      //freopen("input.txt", "r", stdin);
      printf("%lld\n", solve());
      return 0;
}