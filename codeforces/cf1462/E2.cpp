#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int MAXN = 2e5 + 3;
ll mod = 1e9 + 7;
ll Fac[MAXN];

ll pow(ll a, ll b)
{
      ll ans = 1;
      while(b) {
            if(b&1)     ans = (ans * a) % mod;
            b>>=1;
            a = a*a%mod;
      }
      return ans;
}

void Pre()
{
      Fac[0] = 1;
      for(int i = 1; i < MAXN; i++) {
            Fac[i] = Fac[i - 1] * i % mod;
      }
}

//求C(a,b)
ll C(ll a, ll b)
{
      if(a < b)   return 0;
      ll ans = 1;
      ll res = Fac[b] * Fac[a-b] % mod;
      ans = Fac[a] * pow(res, mod - 2) % mod;
      return ans%mod;
}

ll solve()
{
      int n, m, k, a;
      scanf("%d%d%d", &n, &m, &k);
      vector<ll> Cnt(n+k+1);
      for(int i = 0; i < n; i++) {
            scanf("%d", &a);
            Cnt[a]++;
      }
      ll sum = 0, ans = 0;
      for(int i = 1; i <= k + 1; i++) {
            sum += Cnt[i];
      }
      for(int j = 1; j <= Cnt[1]; j++) {
            // cout << "C(" << sum - j << " , " << m - 1 << ") : " << C(sum - j, m - 1) << endl;
            ans = (ans + C(sum - j, m - 1)) % mod;
      }
      for(int i = 2; i <= n; i++) {
            sum += Cnt[i + k];
            sum -= Cnt[i - 1];
            for(int j = 1; j <= Cnt[i]; j++) {
                  // cout << "C(" << sum - j << " , " << m - 1 << ") : " << C(sum - j, m - 1) << endl;
                  ans = (ans + C(sum - j, m - 1)) % mod;
            }
      }
      return ans;
}

int main()
{
      freopen("input.txt", "r", stdin);

      Pre();
      int t;
      scanf("%d", &t);
      while(t--) {
            printf("%lld\n", solve());
      }

      return 0;
}