#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e3+20;
const ll MOD = 1e9+7;
int num[MAXN];
int main()
{
  int _;
  cin >> _;
  while (_--){
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> num[i];
    }
    sort(num,num+n,greater<int>());
    num[n]=0;
    int minn=num[0];
    int i=0;
    for (i = 0; i <= n; ++i) {
      minn=min(minn,num[i]);
      if(i+1>minn)break;
    }
    cout << i << endl;
  }
}
