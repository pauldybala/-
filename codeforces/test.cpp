#include <bits/stdc++.h>

using namespace std;
#define PII pair<int, int>

bool cmp(const PII &a,const  PII &b) {
      return a.first > b.first;
}



int main()
{
      freopen("input.txt", "r", stdin);
      int a, b;
      vector<PII> vec;
      priority_queue<PII, vector<PII>, greater<PII> > pq;
      while(scanf("%d%d", &a, &b) != EOF) {
            vec.push_back(make_pair(a, b));
            pq.push(make_pair(a, b));
      }
      sort(vec.begin(), vec.end(), cmp);
      cout << "--------------------" << endl;
      for(auto v:vec) {
            cout << v.first << " " << v.second << endl;
      }
      while(!pq.empty()) {
            cout << pq.top().first << " " << pq.top().second << endl;
            pq.pop();
      }
      return 0;
}