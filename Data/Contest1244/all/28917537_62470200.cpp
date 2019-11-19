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
int te;
int a , b , c , d , k;
int main(){
    cin >> te;
    while(te--){
    cin >> a >> b >> c >> d >> k;
    int t = (a+c-1)/c;
    int f = (b + d -1)/d;
    if(f+t <= k){
        cout << t << ' ' << f << '\n';
    }else{
        cout << -1 << '\n';
    }
    }
    return 0;
}
