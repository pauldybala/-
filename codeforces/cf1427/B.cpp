#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e5 + 13;
char s[MAXN];
int num[MAXN];

int solve()
{
      int n, k;
      scanf("%d%d", &n, &k);
      scanf("%s", s);
      memset(num, 0, sizeof(num));
      int w = 0, l =0;      //记录W的个数
      int w_streaks = 0, l_streaks = 0;
      int ans = 0;
      for(int i = 0; i < n; i++) {
            if(s[i] == 'W') {
                  w++;
                  if(i == 0 || s[i-1] == 'L') {
                        w_streaks++;
                  }
            }
            else {
                  l++;
                  if(i == 0 || s[i-1] == 'W') {
                        l_streaks++;
                  }
                  num[l_streaks-1]++;
            }
      }
      if(k >= l) return 2*n - 1;
      if(w == 0) {
            if(k == 0)  return 0;
            else  return 2*k - 1;
      }
      if(s[0] == 'L')   num[0] = 1e8;
      if(s[n-1] == 'L') num[l_streaks-1] = 1e8;
      sort(num, num + l_streaks);
      w += k;
      for(int i = 0; i < l_streaks; i++) {
            if(k >= num[i]) {
                  k -= num[i];
                  w_streaks--;
            }
            else {
                  break;
            }
      }
      return 2*w - w_streaks;
}

int main()
{
      freopen("input.txt", "r", stdin);
      int t;
      scanf("%d", &t);
      while(t--) {
            printf("%d\n", solve());
      }
      return 0;
}