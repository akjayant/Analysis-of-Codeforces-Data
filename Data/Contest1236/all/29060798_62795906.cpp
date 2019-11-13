#include <cstring>
#include <cassert>
#include <utility>
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <bitset>
#include <chrono>
#include <cstdlib>
#include <functional>
#include <tuple>
#include <climits>
#include <limits>
#include <deque>
#include <list>
#include <array>
#include <stack>
#include <queue>
#include <random>
#include <complex>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
 
#define init ios::sync_with_stdio(0); cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007
#define PI atan(1)*4
#define NO cout<<"NO\n"
#define YS cout<<"YES\n"
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define mk make_pair
#define flush cout.flush()
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define endc "\n"
#define meme(a) memset((a) , 0 , sizeof((a)))
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;
 
ll gcd(ll a, ll b){
    if(a>b)
        swap(a,b);
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
}
 
ll powerMod(ll x,ll y){
    ll res = 1;
    x %= MOD;
    while(y>0){
        if(y&1)res = (res*x)%MOD;
        y = y>>1;
        x = (x*x)%MOD;
    }
    return res%MOD;
}
 
//  =========     /\       /|    |====/|
//      |        /  \       |    |   / |
//      |       /____\      |    |  /  |
//      |      /      \     |    | /   |
//  ========= /        \  =====  |/====|  
//  code

int main(){
    init;
    int n,m,i,j,k,l;
    cin>>n;
    int a[n][n];
    for(j = 0; j < n ; j++){
        if(j % 2 == 0){
            for(i = 0; i < n; i++){
                a[i][j] = j*n + i + 1;
            }
        }
        else{
            for(i = 0; i < n; i++){
                a[i][j] = j*n + n - i;
            }
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++)
            cout<<a[i][j]<<" ";
        cout<<endc;
    }
    return 0;
}