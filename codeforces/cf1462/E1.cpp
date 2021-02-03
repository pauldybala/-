#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MAXN = 2e5 + 13;
int N;

ll solve() {
      int a;
      vector<ll> Sum(N + 1);
      for(int i = 0; i < N; i++) {
            scanf("%d", &a);
            Sum[a]++;
      }
      ll ans = 0;
      for(int j = 1; j <= N; j++) {
            ll a, b, c;
            a = Sum[j];
            if(j+1 > N) b = 0;
            else b = Sum[j + 1];
            if(j+2 > N) c = 0;
            else c = Sum[j + 2];
            // cout << a << " " << b << " " << c << endl;
            ans += a * b * c;
            ans += b * (b-1) * a / 2;
            ans += a * c * (c-1) / 2;
            ans += a * (a - 1) * b / 2;
            ans += a * (a - 1) * c / 2;
            ans += a * (a-1) * (a-2) / 6;
      }
      
      return ans;
}

int main()
{
      freopen("input.txt", "r", stdin);
      int t;
      scanf("%d", &t);
      while(t--) {
            scanf("%d", &N);
            
            printf("%lld\n", solve());
      }
      return 0;
}