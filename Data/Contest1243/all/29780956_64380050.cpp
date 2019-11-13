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
                    string s1;
                    string s2;
                    cin>>s1;
                    cin>>s2;
                    if(s1 == s2){
                              cout<<"Yes"<<endl;
                              continue;
                    }
                    int cc = 0;
                    war(i,0,n)
                    {
                              cc += (s1[i] != s2[i]);
                    }
                    if(cc != 2){
                              cout<<"No"<<endl;
                              continue;
                    }
                    vector<int> in;
                    war(i,0,n)
                    {
                              if(s1[i] != s2[i]){
                                        in.pb(i);
                              }
                    }
                    if((s1[in[0]] == s1[in[1]]) && (s2[in[0]] == s2[in[1]]))
                    {
                              cout<<"Yes"<<endl;
                    }
                    else{
                              cout<<"No"<<endl;
                    }

          }
}
