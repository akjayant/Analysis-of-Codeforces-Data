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
          int q;
          cin>>q;
          while(q--)
          {
                    int n;
                    cin>>n;
                    string s1,s2;
                    cin>>s1;
                    cin>>s2;
                    int fr[26];
                    memset(fr,0,sizeof fr);
                    war(i,0,s1.size()){
                              fr[s1[i]-'a']++;
                    }
                    war(i,0,n){
                              fr[s2[i]-'a']++;
                    }
                    bool ff = true;
                    war(i,0,26)
                    {
                              if(fr[i] & 1)
                              {
                                        ff = false;
                              }
                    }
                    if(!ff){
                              cout<<"No"<<endl;
                              continue;
                    }
                    cout<<"Yes"<<endl;
                    vector<pair<int,int>> ans;
                    war(i,0,n)
                    {
                              if(s1[i] == s2[i]){continue;}
                              int in = -1;
                              war(j,i+1,n){
                                        if(s1[j] == s1[i]){
                                                  in = j;
                                                  break;
                                        }
                              }
                              if(in != -1){
                                        ans.pb(mkp(in+1,i+1));
                                        swap(s1[in],s2[i]);
                              }
                              else{
                                        war(j,i+1,n){
                                                  if(s2[j] == s1[i])
                                                  {
                                                            in = j;
                                                            break;
                                                  }
                                        }
                                        ans.pb(mkp(n,in+1));
                                        swap(s1[n-1],s2[in]);
                                        ans.pb(mkp(n,i+1));
                                        swap(s1[n-1],s2[i]);
                              }
                    }
                    if(ans.size() == 0){
                              ans.pb(mkp(1,1));
                    }
                    cout<<ans.size()<<endl;
                    war(i,0,ans.size()){
                              cout<<ans[i].fr<<" "<<ans[i].sc<<endl;
                    }
          }
}
