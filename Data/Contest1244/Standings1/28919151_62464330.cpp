#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define scanVec(vec , n) for(int i = 0; i < n ; i++){ cin>>vec[i];}
#define printVec(vec , n) for(int i = 0; i < n ; i++){ cout<<vec[i]<<" ";}
#define S second
#define F first
const int  MOD = 1e9 + 7;
const int  N = 1e5 + 7;

int main(){
    ios::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
    ll t ,a  , b , c , d , k; cin>>t;
    while(t--){
        cin>>a>>b>>c>>d>>k;
        ll x = (a + c - 1) / c ;
        ll y = (b + d - 1) / d;
        if(x + y <= k) cout<<x<<" "<<y<<endl;
        else cout<<-1<<endl;
    }


    return 0;
}