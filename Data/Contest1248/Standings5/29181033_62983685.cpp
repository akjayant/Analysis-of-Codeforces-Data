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
int main()
{
          int t;
          cin>>t;
          while(t--)
          {
                    int n;
                    cin>>n;
                    int pp[n];
                    arrin(pp,n);
                    int m;
                    cin>>m;
                    int qq[m];
                    arrin(qq,m);
                    ll pp_o,qq_o;
                    pp_o = qq_o = 0;
                    war(i,0,n)
                    {
                              pp_o += (pp[i]%2);
                    }
                    war(i,0,m)
                    {
                              qq_o += (qq[i]%2);
                    }
                    ll ans = pp_o*qq_o;
                    ans += (n-pp_o)*(m-qq_o);
                    cout<<ans<<endl;
          }


}
