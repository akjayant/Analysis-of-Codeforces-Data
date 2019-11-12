//**AUTHOR : @sam_jn**

#include<bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define MOD 1000000007
#define pb push_back
#define ff first
#define ss second
ll pwr(ll a, ll b);
ll pwr(ll a, ll b, ll m);
int baap[200002];
int find(int i);  
bool Union(int x, int y);

//GLOBALS

int main(){
                                            #ifndef ONLINE_JUDGE
                                            freopen("input", "r", stdin);
                                            freopen("output", "w", stdout);
                                            #else
                                            // online submission
                                            #endif
//SOLUTION
    boost
    ll n, m;
    cin >> n >> m;
    ll ans;
    ans = pwr(2, m, MOD) - 1;
    ans += MOD;
    ans %= MOD;
    ll ans2 = pwr(ans, n, MOD);
    cout << ans2;
}




//DEFININTIONS
ll pwr(ll a, ll b){
    if(b==0)
        return 1 ;
    ll c = pwr(a, b/2) ;
    c = c * c;
    if(b % 2)
        return c*a;
    return c ;
}
ll pwr(ll a, ll b, ll m){
    if(b==0)
        return 1;
    ll c = pwr(a, b/2, m) % m ;
    c = (c * c) % m;    
    if(b % 2)
        return (c * a%m) % m;
    return c ;
}
int find(int i)  
{  
    if (baap[i] != i)  
        baap[i] = find(baap[i]);  
  
    return baap[i];  
}

bool Union(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x == y) return false;
    baap[x] = y;
    return true;
}  
