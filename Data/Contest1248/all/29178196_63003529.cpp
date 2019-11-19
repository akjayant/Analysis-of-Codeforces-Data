#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
#define endl '\n'
#define mod 1000000007
const int inf = 1000000000;

ll n, m, mem[100009], add[100009];

ll solve(int i)
{
  if(i == m)
    return 1;
  if(mem[i] != -1)
    return mem[i];
  int ret = solve(i + 1);
  if(i + 2 <= m)
    ret += solve(i + 2),
    ret %= mod;
  ret %= mod;
  return mem[i] = ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);cout.tie(NULL);
  memset(mem, -1, sizeof mem);
  cin >> n >> m;
  ll init = solve(0) * 2ll;
  init %= mod;
  add[0] = add[1] = 2;
  for(int i = 2; i < 100009; i ++)
    add[i] = add[i - 1] + add[i - 2],
    add[i] %= mod;

  for(int i = 1 ;i < 100009; i ++)
    add[i] += add[i - 1],
    add[i] %= mod;

  init += (n == 1 ? 0 : add[n - 2]);
  init %= mod;
  cout << init;

  return 0;
}
