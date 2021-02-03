#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define PII pair<int, int>
const int MAXN = 1e5 + 3;

int w[MAXN];
int d[MAXN];

void solve()
{
      int N;
      ll ans = 0;
      scanf("%d", &N);
      memset(w, 0, sizeof(w));
      memset(d, 0, sizeof(d));
      for(int i = 1; i <= N; i++) {
            scanf("%d", &w[i]);
            ans += w[i];
      }
      for(int i = 1; i < N; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            d[a]++;
            d[b]++;
      }
      vector<PII> vec;
      for(int i = 1; i <= N; i++) {
            vec.push_back(make_pair(w[i], d[i]));
      }
      sort(vec.begin(), vec.end(), greater<PII>() );
      printf("%lld", ans);
      int pos = 0;
      for(int i = 2; i < N; i++) {
            while(pos < vec.size() && vec[pos].second <= 1) {
                  pos++;
            }
            if(pos == vec.size()) {
                  printf(" %lld", ans);
                  continue;
            }
            ans += vec[pos].first;
            vec[pos].second--;
            printf(" %lld", ans);
      }
      printf("\n");
}


int main()
{
      //freopen("input.txt", "r", stdin);
      int T;
      scanf("%d", &T);
      while(T--) {
            solve();
      }
      return 0;
}