#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e6 + 13;
char s[MAXN];
int num[30];

struct Node
{
      char c;
      int num;
      Node(char cc, int nn){
            c = cc;
            num = nn;
      }
      bool operator <(const Node &t) const {
            return c > t.c;
      }
};

bool solve()
{
      int n, k;
      priority_queue<Node> pa1, pa2, pb1, pb2;
      scanf("%d%d", &n, &k);
      scanf("%s", s);
      memset(num, 0, sizeof(num));
      for(int i = 0; i < n; i++) {
            num[s[i] - 'a']++;
      }
      for(int i = 0; i < 26; i++) {
            pa1.push(Node('a' + i, num[i] / k));
            pa2.push(Node('a' + i, num[i] % k));
      }
      scanf("%s", s);
      memset(num, 0, sizeof(num));
      for(int i = 0; i < n; i++) {
            num[s[i] - 'a']++;
      }
      for(int i = 0; i < 26; i++) {
            pb1.push(Node('a' + i, num[i] / k));
            pb2.push(Node('a' + i, num[i] % k));
      }
      int sum = 0;
      while(!pa1.empty()) {
            sum += pa1.top().num;
            if(sum < pb1.top().num) return false;
            sum -= pb1.top().num;
            pa1.pop();
            pb1.pop();
      }
      while(!pa2.empty()) {
            if(pa2.top().num != pb2.top().num) {
                  return false;
            }
            pa2.pop();
            pb2.pop();
      }
      // while(!pa1.empty())
      // {
      //       cout << "str1 : " << pa1.top().c << " , " << pa1.top().num << endl;
      //       cout << "str1 : " << pa2.top().c << " , " << pa2.top().num << endl;
      //       pa1.pop();
      //       pa2.pop();
      // }
      // while(!pb1.empty())
      // {
      //       cout << "str2 : " << pb1.top().c << " , " << pb1.top().num << endl;
      //       cout << "str2 : " << pb2.top().c << " , " << pb2.top().num << endl;
      //       pb1.pop();
      //       pb2.pop();
      // }
      return true;
}

int main()
{
      freopen("input.txt", "r", stdin);
      int t;
      scanf("%d", &t);
      while(t--) {
            if(solve()) {
                  puts("Yes");
            }
            else puts("No");
      }
      return 0;
}