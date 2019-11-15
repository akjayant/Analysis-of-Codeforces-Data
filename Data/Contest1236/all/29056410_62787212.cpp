/* Author : Aaryan Srivastava ^__^ */ 
#include <bits/stdc++.h>
#include <random>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#define pb push_back
#define popb pop_back
#define mt make_tuple 
#define eb emplace_back
#define mp make_pair
#define ff first
#define ss second 
#define ull unsigned long long  
#define pii pair<int, int>
#define piii pair<int,pii>
#define beg begin
#define rep(i,n) for(int (i) = 0 ; i < (n) ; i++)
#define repA(i,x,y) for(int i = (x) ; i <= (y) ; i++)
#define repD(i,x,y) for(int i = (x) ; i >= (y) ; i--)
#define all(c) (c).begin(),(c).end()
#define fill(a,val) memset(a,val,sizeof(a))
#define Randomize mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define int ll
using ll = long long;
const int N = 3*1e5 +5 ;
const int mod = 1e9 + 7 ;
const int inf = 1e18 ;
const int SZ = 101 ;
const double eps = 1e-9 ;
using namespace __gnu_pbds;
using namespace std;
using ordered_set =  tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ;

#ifdef AaryanS
#define mycout cout
#define mycerr cerr 
#endif

#ifndef AaryanS
#define mycout if(false) cout
#define mycerr if(false) cerr
#endif

int po(int x , int y){
	int res = 1;
	while(y){
		if(y&1) res = (res * x) % mod ;
		x = (x * x) % mod ;
		y >>= 1;
	}
	return res; 
}
void solve()
{
	int n, m;
	cin >> n >> m;
	cout << (po((po(2 , m)-1) , n) ) % mod << endl ;
}   

     
int32_t main(int32_t argc, char *argv[])
{
    double t1 = clock() ;
    ios::sync_with_stdio(0);    
    cin.tie(0); cout.tie(0);
    int TC = 1, t = 0;
    //cin >> TC ;
    while(t++ < TC)
    {
        //cout << "Case #" << t << ": " ;
        solve();
        //cout << endl ;
    }
    mycerr << "Time : " << 1000 *(clock() - t1)/CLOCKS_PER_SEC << " ms\n" ;
    return 0;
}