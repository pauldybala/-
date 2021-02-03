#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define PLL pair<ll, ll>
#define Max(a,b) a>b?a:b
#define Min(a,b) a<b?a:b

const int MAXN = 2e5 + 13;
int  a[MAXN];

bool Comp(const PLL &a,const PLL &b)
{
      if(a.first == b.first)
            return a.second > b.second;
      else  return a.first < b.first;
}

ll solve()
{
      int n;
      scanf("%d", &n);
      for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
      }
      int b;
      vector<PLL> vec(n);
      for(int i = 0; i < n; i++) {
            scanf("%d", &b);
            vec[i] = PLL(a[i], b);
      }
      sort(vec.begin(), vec.end(), Comp);
      ll sum = 0;
      ll ans = LONG_LONG_MAX;
      for(int i = vec.size() - 1; i >= 0; i--) {
            ll res = Max(sum, vec[i].first);
            ans = Min(ans, res);
            sum += vec[i].second;
            // cout << vec[i].first << " , " <<  vec[i].second << endl;
      }
      ans = Min(ans, sum);
      return ans;
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