#include<bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
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
#define small -1000000000000000000
#define big 1000000000000000000
#define arrin(a,n) for(int i = 0; i < n ; i++){cin>>a[i];}
#define arrout(a,n) for(int i = 0;i < n; i++){cout<<a[i]<<" ";}
#define ex(s) cout<<s<<endl;exit(0);
#define itr iterator
#define tra(it,m) for(it=m.begin();it!=m.end();++it)
//__________________________________________________________________________________________________________________________________________________________
int main()
{
          int t;
          cin>>t;
          while(t--)
          {
                    int n;
                    cin>>n;
                    int a[n];
                    arrin(a,n);
                    int ans = 1;
                    war(i,1,1002)
                    {
                              int cc = 0;
                              war(j,0,n)
                              {
                                        if(a[j] >= i){cc++;}
                              }
                              if(cc >= i){
                                        ans = max(ans,(int)i);
                              }
                    }
                    cout<<ans<<endl;
          }
}
