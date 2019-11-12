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



ll n;
string s,t;


void Solve(){
    cin>>n>>s>>t;
    vi v;
    FT(i,0,n) if(s[i]!=t[i]) v.pb(i);
    if(v.size()==0){
        cout<<"Yes\n";
        return;
    }
    if(v.size()!=2){
        cout<<"No\n";
        return;
    }
    swap(s[v[0]],t[v[1]]);
    FT(i,0,n) if(s[i]!=t[i]){
        cout<<"No\n";
        return;
    }
    cout<<"Yes\n";
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
