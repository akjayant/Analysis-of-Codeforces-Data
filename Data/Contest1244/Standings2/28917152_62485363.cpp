#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
signed main()
{
  int n, k;
  cin>>n>>k;
  map<int, int> ma;
  deque<pair<int, int>> d;
  for(int i = 0; i < n; i++)
  {
      int a;
      cin>>a;
      ma[a]++;
  }
  for(auto i : ma)
      d.push_back(i);
  while(k)
  {
      if(d.size() == 1)
          break;
      if(d.front().second < d.back().second)
      {
 
          int merge_price = (d[1].first - d[0].first) * (d[0].second);
          if(merge_price > k)
          {
              int cnt = k / d[0].second;
              d[0].first += cnt;
              k = 0;
              break;
          }
          else
          {
              pair<int, int> new_elem = {d[1].first, d[0].second + d[1].second};
              d.pop_front(), d.pop_front();
              d.push_front(new_elem);
              k -= merge_price;
          }
          continue;
      }
      else
      {
          int sz = d.size();
          int merge_price = (d[sz - 1].first - d[sz - 2].first) * d[sz - 1].second;
        //  cout<<merge_price<<endl;
          if(merge_price > k)
          {
              int cnt = k / d[sz - 1].second;
              d[sz - 1].first -= cnt;
              k = 0;
              break;
          }
          else
          {
              pair<int, int> new_elem = {d[sz - 2 ].first, d[sz - 1].second + d[sz - 2].second};
              d.pop_back(), d.pop_back();
              d.push_back(new_elem);
              k -= merge_price;
          }
      }
  }
  cout<<d[d.size() - 1].first - d[0].first<<endl;
}