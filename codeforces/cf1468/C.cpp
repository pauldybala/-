#include <bits/stdc++.h>

using namespace std;
const int MAXN = 5e5 + 4;
bool flag[MAXN];
struct Node {
      int id, m;
      Node(int id, int m) {
            this->id = id;
            this->m = m;
      }
      bool operator<(const Node &a) const {
            if(m == a.m) {
                  return id > a.id;
            }
            else
                  return m < a.m;
      }
};


int main()
{
      freopen("input.txt", "r", stdin);
      int q, id, N;
      scanf("%d", &q);
      priority_queue<Node> pq;
      memset(flag, 0, sizeof(flag));
      id = 0;
      N = 1;
      bool start = 0;
      while(q--) {
            int t, m;
            scanf("%d", &t);
            if(t == 1) {
                  id++;
                  scanf("%d", &m);
                  pq.push(Node(id, m));
            }
            else if(t == 2) {
                  while(flag[N])    N++;
                  flag[N] = 1;
                  if(start) printf(" ");
                  printf("%d", N++);
                  start = 1;
            }
            else if(t == 3) {
                  Node p = pq.top();
                  while(flag[p.id]) {
                        pq.pop();
                        p = pq.top();
                  }
                  if(start) printf(" ");
                  printf("%d", p.id);
                  flag[p.id] = 1;
                  pq.pop();
                  start = 1;
            }
      }
      puts("");
      return 0;
}