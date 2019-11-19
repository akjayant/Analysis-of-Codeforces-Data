#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define war(i,s,n) for(long long i=s;i<n;i++)
#define pb push_back
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL)
#define fr first
#define sc second
#define mod 1000000007
#define vctr2d vector<vector<long long>>
#define vctr vector<long long>
#define pll pair<long long,long long>
#define rz(n) resize(n)
#define all(v) v.begin(),v.end()
#define mkp make_pair
#define mod2  998244353
#define arrin(a,n) for(int i = 0; i < n ; i++){cin>>a[i];}
#define arrout(a,n) for(int i = 0;i < n; i++){cout<<a[i]<<" ";}
#define ex(s) cout<<s<<endl;exit(0);
#define itr iterator
#define tra(it,m) for(it=m.begin();it!=m.end();++it)
//___________________________________________________________________________________________________________________________________________________________
const int N = 100005;
ll dp1[N][2];
ll dp2[N][2];
int main()
{
          int n,m;
          cin>>n>>m;
          dp1[1][0] = dp1[1][1] = 1;
          dp1[2][0] = dp1[2][1] = 2;
          war(i,3,m+1)
          {
                    dp1[i][0] = dp1[i-1][1] + dp1[i-2][1];
                    dp1[i][1] = dp1[i-1][0] + dp1[i-2][0];
                    dp1[i][0] %= mod;
                    dp1[i][1] %= mod;
          }
          dp1[m][0]--;
          dp1[m][1]--;
          dp2[1][0] = dp2[1][1] = 1;
          dp2[2][0] = dp2[2][1] = 2;
          war(i,3,n+1)
          {
                    dp2[i][0] = dp2[i-1][1] + dp2[i-2][1];
                    dp2[i][1] = dp2[i-1][0] + dp2[i-2][0];
                    dp2[i][0] %= mod;
                    dp2[i][1] %= mod;
          }
          ll ans = dp1[m][0] + dp1[m][1] + dp2[n][0] + dp2[n][1];
          
          ans %= mod;
          cout<<ans<<endl;
}
