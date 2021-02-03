# pair的比较函数源码分析
### 源码
```c++
template<typename _T1, typename _T2>
    inline _GLIBCXX_CONSTEXPR bool
    operator<(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
    { return __x.first < __y.first
	     || (!(__y.first < __x.first) && __x.second < __y.second); }
```
### 分析
从代码中可以看出，`pair<T1, T2>`优先比较first，根据first的值判断pair的大小，first小的为小。如果first的值相同，则根据second值判断大小，second小的为小。
如果使用sort进行排序，则默认的是小的`pair<T1, T2>`在前。
```c++
#define PII pair<int, int>
sort(vec.begin(), vec.end(), greater<PII>());
//greater表示大的在前, less表示小的在前，但默认的就是
```
在优先队列中使用时，需注意：优先队列是让更大的对象在队首。
```c++
priority_queue<PII, vector<PII>, greater<PII> > pq;  
//greater表示小的在前，less表示大的在前，但默认的就是
```
### 推广
有比较函数，我们可以进一步学习到：
(1) 重载<号的比较，在对sort使用时，对于对象，就是使用<更小的对象在前。而优先队列是更大的在前，这里的更小是逻辑上的，不是实际意义上的。
```c++
struct node {
      int a, b;
      bool operator<(const node &t) const {
            return a > t.a;
      }
};
```
举个例子就是`node(3, 4) < node(1, 4)`那么其实`node(3, 4)`是更小的。
(2) 使用自定义比较函数时，若想让大的在前，让`a`比`b`大为真就好，反之亦然。
```c++
bool cmp(const PII &a,const  PII &b) {
      return a.first > b.first;
}
sort(vec.begin(), vec.end(), cmp);  //大的在前
```
