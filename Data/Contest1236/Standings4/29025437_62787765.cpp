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
    ll t;
    cin >> t;
    while(t--){
        ll a, b, c;
        cin >> a >> b >> c;
        ll ans1 = 0, ans2 = 0, ans11, ans22;
        ans1 = min(a, b / 2);
        ans11 = ans1 + min(b - ans1 * 2, c / 2);

        ans2 = min(b, c / 2);
        ans22 = ans2 + min(a, (b - ans2) / 2);

        cout << 3 * max(ans11, ans22) << endl;
    }
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
