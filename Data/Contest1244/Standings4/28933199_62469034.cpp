#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <math.h>

using namespace std;

#define x first
#define y second
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define all(x) x.begin(),x.end()
#define SZ(x) int(x.size())
#define rep(i, a, b) for(int i = a; i < b; i++)
#define per(i, a, b) for(int i = b-1; i >= a; i--)
#define DBG(x) cerr << (#x) << "=" << x << "\n";
#define ll long long
#define inf 1000000007
#define mod 1000000007
#define N 100001

template<typename U, typename V> void Min(U &a, const V & b){if(a > b)a = b;}
template<typename U, typename V> void Max(U &a, const V & b){if(a < b)a = b;}
template<typename U, typename V> void add(U &a, const V & b){a = (a + b) % mod;}
template<typename U> U gcd(U a, U b){
    if(a == 0)return b;
    if(b == 0)return a;
    if(a >= b)return gcd(a % b, b);
    else return gcd(a, b % a);
}
int pow(int a, int b){
    int ans = 1;
    while(b){
        if(b & 1)ans = 1LL * ans * a % mod;
        a = 1LL * a * a % mod;
        b >>= 1;
    }
    return ans;
}
int pow(int a, int b, int c){
    int ans = 1;
    while(b){
        if(b & 1)ans = 1LL * ans * a % c;
        a = 1LL * a * a % c;
        b >>= 1;
    }
    return ans;
}

char s[105];
int main(){
    int T, i, j, k, m, n, K;
    scanf("%d", &T);
    while(T--){
        scanf("%d%s", &n, s);
        int ans = 0;
        rep(i, 0, n)if(s[i] == '1'){
            Max(ans, max(i+1, n-i));
        }
        printf("%d\n", max(n, ans * 2));
    }
}
