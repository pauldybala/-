#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define PII pair<int, int>
const int MAXN = 2e5 + 13;
int A[MAXN], B[MAXN], CntA[MAXN], CntB[MAXN];

ll solve()
{
      map<PII, int> M;
      int a, b, k;
      scanf("%d%d%d", &a, &b, &k);
      memset(CntA, 0, sizeof(CntA));
      memset(CntB, 0, sizeof(CntB));
      for(int i = 0; i < k; i++) {
            scanf("%d", &A[i]);
            CntA[A[i]]++;
      }
      for(int i = 0; i < k; i++) {
            scanf("%d", &B[i]);
            CntB[B[i]]++;
            M[PII(A[i], B[i])]++;
      }
      ll ans = 0;
      int sum = k-1;
      for(int i = 0; i < k; i++) {
            CntA[A[i]]--;
            CntB[B[i]]--;
            M[PII(A[i], B[i])]--;
            ans += (sum - CntA[A[i]] - CntB[B[i]] + M[PII(A[i], B[i])]);
            // scout << sum << " , " <<  CntA[A[i]] << " , " <<  CntB[B[i]]  << " , " << M[PII(A[i], B[i])] << endl;
            sum--;
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