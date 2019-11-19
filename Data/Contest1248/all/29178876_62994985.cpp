#include<iostream>
using namespace std;
const int maxN = 2e5 + 2;
typedef long long ll;
const ll mod = 1e9 + 7;
int n, m;
ll d[maxN][2] = {0};
int main()
{
      cin >> n >> m;
      d[1][1] = 2;
      d[1][0] = 0;
      int len = max(m,n);
      for(int i = 2; i <= len; i++)
      {
            d[i][1] = (d[i-1][1] + d[i-1][0]) % mod;
            d[i][0] = d[i-1][1];
      }
      cout << ((d[m][0]+d[m][1])%mod-2 + (d[n][0]+d[n][1])%mod)%mod << '\n';
      //for()
      return 0;
}