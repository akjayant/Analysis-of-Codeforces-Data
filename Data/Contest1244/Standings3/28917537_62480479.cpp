#include <bits/stdc++.h>
#define x first
#define y second
#define ll long long
#define pi pair<int,int>
#define pl pair<ll,ll>
#define pd pair<double,double>
#define ld long double
#define pld pair<ld,ld>
#define lg length()
#define sz size()
#define vi vector<int>
#define vl vector<ll>
#define vp vector<pi>
#define vpl vector<pl>
#define pb push_back
#define INF 1000000005
#define LINF 1000000000000000005
using namespace std;
ll n , p , d , w;
int main(){
    cin >> n >> p >> w >> d;
    ll t = 0;
    if(p%(__gcd(w,d))!= 0){
        cout << -1;
        return 0;
    }
    while(t*d % w != p%w){
        t++;
    }
    ll st = (p - t*d)/w;
    if(st + t <= n && st >= 0){
        cout << st << ' ' << t << ' ' << n - st - t;
    }else{
        cout << -1;
    }
    return 0;
}
