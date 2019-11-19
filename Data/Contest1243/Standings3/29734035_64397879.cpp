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
vi p;


void Solve(){
    cin>>n;
    FTB(i,2,sqrt(n)){
        if(n%i==0){
            p.pb(i);
            if(i*i!=n) p.pb(n/i);
        }
    }
    if(p.size()==0){
        cout<<n;
        return;
    }
    FT(i,0,p.size()) FT(j,i+1,p.size()){
        if(__gcd(p[i],p[j])==1){
            cout<<1;
            return;
        }
    }
    cout<<p[0];
}


int main(){
    ios::sync_with_stdio(0);cin.tie(0);

//    freopen("1.inp","r",stdin);
//    freopen("1.out","w",stdout);


    int Test_numbers=1;
//    cin>>Test_numbers;

    while(Test_numbers--) Solve();

	return 0;
}
