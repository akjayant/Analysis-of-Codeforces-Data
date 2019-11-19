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
    ll n , p , w , d;
    cin>>n>>p>>w>>d;
    ll g = __gcd(w , d);
    if(p % g){
        cout<<-1<<endl;
        return 0;
    } 
    w /= g; d /=g; p /= g;
    // cout<<w<<" "<<d<<" "<<p<<endl;
    for(ll i = 0 ; i < w; i++){
        if ((i * d) % w == p % w){
            ll x = min(n - i , (p - i * d) / w);
            ll y = (p - w * x)/ d;
            ll z = n - x - y;
            if(x < 0 || y < 0 || z < 0 ) break;
            cout<<x<<" "<<y<<" "<<z<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}