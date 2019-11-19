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

  int t;
  cin >> t;
  while(t --)
  {
    ll ec1 = 0, ec2 = 0, oc1 = 0, oc2 = 0;
    int n;
    cin >> n;
    while(n --)
    {
      int a;
      cin >> a;
      if(a % 2 == 0)
        ec1 ++;
      else oc1 ++;
    }
    cin >> n;
    while(n --)
    {
      int a;
      cin >> a;
      if(a % 2 == 0)
        ec2 ++;
      else oc2 ++;
    }
    cout << ec1 * ec2 + oc2 * oc1 << endl;
  }
  return 0;
}
