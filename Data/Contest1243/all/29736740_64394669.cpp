#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  vector<long long> pr;
  long long tm = n;
  for(long long i = 2; i * i <= n; i++)
  {
    if(tm % i == 0)
    {
      pr.push_back(i);
      while(tm % i == 0)
      {
        tm /= i;
      }
    }
  }
  if(tm != 1) pr.push_back(tm);
  long long sz = pr.size();
  if(sz == 1)
  {
    cout << pr[0] << endl;
  }
  else cout << "1" << endl;
  return 0;
}
