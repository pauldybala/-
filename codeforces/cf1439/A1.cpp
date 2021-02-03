#include <bits/stdc++.h>

using namespace std;
struct Node {
      int x1, y1, x2, y2, x3, y3;
      Node(){}
      Node(int a, int b, int c, int d, int e, int f) {
            x1 = a, y1 =b;
            x2 = c, y2 = d;
            x3 = e, y3 = f;
      }
};
const int MAXN = 1e2 + 13;
char s[MAXN];

void solve()
{
      int n, m;
      scanf("%d%d", &n, &m);
      vector<Node > vec;
      for(int i = 1; i <= n; i++) {
            scanf("%s", s);
            for(int j = 1; j <= m; j++) {
                  //坐标(i，j)为1
                  if(s[j-1] == '1') {
                        //第一行
                        if(i % n == 1) {
                              if(j < m) {
                                    vec.push_back(Node(i, j, i+1, j, i+1, j+1));
                                    vec.push_back(Node(i, j, i+1, j, i, j+1));
                                    vec.push_back(Node(i, j, i, j+1, i+1, j+1));
                              }
                              //最后一列
                              else {
                                    vec.push_back(Node(i, j, i+1, j, i+1, j-1));
                                    vec.push_back(Node(i, j, i, j-1, i+1, j));
                                    vec.push_back(Node(i, j, i, j-1, i+1, j-1));
                              }
                        }
                        else {
                              if(j < m) {
                                    vec.push_back(Node(i, j, i-1, j+1, i, j+1));
                                    vec.push_back(Node(i, j, i-1, j, i, j+1));
                                    vec.push_back(Node(i, j, i-1, j, i-1, j+1));
                                    
                              }
                              else {
                                    vec.push_back(Node(i, j, i-1, j, i-1, j-1));
                                    vec.push_back(Node(i, j, i, j-1, i-1, j));
                                    vec.push_back(Node(i, j, i, j-1, i-1, j-1));

                              }
                        }
                  }
            }
      }
      printf("%d\n", vec.size());
      for(int i = 0; i < vec.size(); i++) {
            printf("%d %d %d %d %d %d\n", vec[i].x1, vec[i].y1, vec[i].x2, vec[i].y2, vec[i].x3, vec[i].y3);
      }
}

int main()
{
      int t;
      scanf("%d", &t);
      while(t--) {
            solve();
      }
      return 0;
}