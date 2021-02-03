#include <bits/stdc++.h>

using namespace std;

int solve()
{
      int n, sum;
      scanf("%d", &n);
      vector<int> a(n + 1);
      bool flag = 1;
      sum = 0;
      for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
            if(flag && i > 0) flag = (a[i] == a[i-1]);
      }
      if(flag)    return 0;
      int ans = 0;
      for(int j = n - 1; j >= 1; j--) {
            ans++;
            if(sum % j != 0)  continue;
            int p = sum / j;
            int res = 0;
            bool isok;
            for(int k = 0; k < n; k++) {
                  res += a[k];
                  isok = false;
                  if(res > p)     break;
                  else if(res < p)  continue;
                  else {
                        isok = true;
                        res = 0;
                  }
            }
            if(isok)    break;
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