#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
#define endl '\n'
#define mod 1000000007
const int inf = 1000000000;


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);cout.tie(NULL);

  ll n;
  cin >> n;
  deque< ll > arr;
  for(int i = 0; i < n; i ++)
  {
    int a;
    cin >> a;
    arr.push_back(a);
  }
  sort(arr.rbegin(), arr.rend());
  ll x = 0, y = 0;
  while(arr.size())
  {
    int f = arr.front();
    arr.pop_front();
    x += f;
    if(arr.size())
    {
      int s = arr.back();
      arr.pop_back();
      y += s;
    }
  }
  cout << 1ll*x*x + 1ll*y*y;
  return 0;
}
