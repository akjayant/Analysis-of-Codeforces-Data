#include<iostream>
#include<algorithm>
using namespace std;
const int maxN = 2e5 + 2;
typedef long long ll;
int n;
ll a[maxN];
ll aa, bb;
int main()
{
        ios::sync_with_stdio(false);
        cin >> n;
      for(int i = 0; i < n; i++)
          cin >> a[i];
        sort(a,a+n);
      int len = n/2;
      for(int i= len; i < n; i++)
        aa += a[i];
      for(int i = 0; i < len; i++)
        bb += a[i];
      cout << aa*aa + bb*bb << '\n';
      return 0;
}