#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
#define endl "\n"
#define debug cout<<"debug\n"
#define pb push_back
#define fi first
#define se second
#define all(s) s.begin(),s.end()
#define FTB(i,a,b) for(ll i=a,_b=b;i<=_b;i++)
#define FT(i,a,b) for(ll i=a,_b=b;i<_b;i++)
#define FGB(i,a,b) for(ll i=a,_b=b;i>=_b;i--)
#define FG(i,a,b) for(ll i=a,_b=b;i>_b;i--)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>



ll n,dems[26],demt[26];
string s,t,lus,lut;


void Solve(){
    cin>>n>>s>>t;
    vii res;
    FT(i,0,n){
        if(s[i]!=t[i]){
            FT(j,i+1,n){
                if(t[i]==t[j]){
                    res.pb({i,j});
                    swap(s[i],t[j]);
                    break;
                }
            }
        }
        if(s[i]!=t[i]){
            FT(j,i+1,n){
                if(s[i]==s[j]){
                    res.pb({j,i});
                    swap(s[j],t[i]);
                    break;
                }
            }

        }
        if(s[i]!=t[i]){
            FT(j,i+1,n){
                if(s[i]==t[j]){
                    res.pb({n-1,j});
                    swap(s[n-1],t[j]);
                    res.pb({n-1,i});
                    swap(s[n-1],t[i]);
                    break;
                }
            }
        }
        if(s[i]!=t[i]){
            FT(j,i+1,n){
                if(t[i]==s[j]){
                    res.pb({j,n-1});
                    swap(s[j],t[n-1]);
                    res.pb({i,n-1});
                    swap(s[i],t[n-1]);
                    break;
                }
            }
        }
    }
    if(s==t){
        cout<<"Yes\n";
        cout<<res.size()<<endl;
        for(auto [a,b]:res) cout<<a+1<<" "<<b+1<<endl;
    }
    else cout<<"No\n";
}


int main(){
    ios::sync_with_stdio(0);cin.tie(0);

//    freopen("1.inp","r",stdin);
//    freopen("1.out","w",stdout);


    int Test_numbers=1;
    cin>>Test_numbers;

    while(Test_numbers--) Solve();

	return 0;
}
