#include <bits/stdc++.h>

using namespace std;
const int MAXN = 5e2 + 13;
#define PII pair<int, int>
PII M[MAXN][MAXN];

int solve()
{
      int n, m;
      char s[505];
      scanf("%d%d", &n, &m);
      for(int i = 0; i < n; i++) {
            scanf("%s", s);
            int start = 0;
            for(int j = 0; j < m; j++) {
                  if(s[j] == '*') {
                        M[i][j] = PII(start, j);
                  }
                  else {
                        start = j + 1;
                        M[i][j] = PII(-1, -1);
                  }
            }
      }
      // for(int i = 0; i < n; i++) {
      //       for(int j = 0; j < m; j++) {
      //             printf("(%4d, %4d) ", M[i][j].first, M[i][j].second);
      //       }
      //       puts("");
      // }
      int ans = 0, len;
      for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                  if(M[i][j].first != -1) {     //如果该节点有*
                        for(int k = 0; k <= j; k++) {
                              //判断的点在范围内
                              if(i + k < n && j - k >= 0 && j + k < m) {
                                    len = M[i + k][j + k].second - M[i + k][j + k].first + 1;
                                    if(len >= (2 * k + 1)) {
                                          // printf("(%4d, %4d) -> (%4d, %4d)\n", i, j, i + k, j + k);
                                          ans++;
                                    }
                                    else {      //    一旦有一行不满足后面的也就都不满足了
                                          break;
                                    }
                              }
                        }
                  }
            }
      }
      return ans;
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