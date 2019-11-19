#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i = 0; i < e; i++)
#define forsn(i,s,e) for(int i = s; i < e; i++)
#define rforn(i,s) for(int i = s; i >= 0; i--)
#define rforsn(i,s,e) for(int i = s; i >= e; i--)
#define testcases(t) int t,myzx;cin>>myzx;forsn(t,1,myzx+1) 
#define clz(a) __builtin_clz(a) // count leading zeroes
#define ctz(a) __builtin_ctz(a) // count trailing zeroes
#define popc(a) __builtin_popcount(a) // count set bits 
#define ln "\n"
#define kyahai(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cout<<ln; }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << "\t\t";
	err(++it, args...);
}
#define sz(n) (int)n.size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(n) n.begin() , n.end() 
#define tfi first.first
#define tse first.second
#define tth second
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32; 
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef map<int,int> m32;
typedef pair< pair<int,int> , int> tri;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; 
//like set just find_by_order() and order_of_key() are extra
 
#pragma GCC optimize ("-O3")
template < typename tp > void in( tp & dig ){
    char ch=getchar();dig=0;ll flag=0;
    while(!isdigit(ch)){ if(ch=='-')flag=1;ch=getchar(); }
    while(isdigit(ch))dig=dig*10+ch-'0',ch=getchar();
    if(flag)dig=-dig;
}
const int LIM = 2e5+5 ,MOD = 1e9+7;
const double EPS = 1e-9;
int n , m , t , x ,y ;
int board[12][12];
ld dp[12][12][2];
int convert(int i, int j){
	if((i%2)==0) return (10*i+j);
	else return (10*i + 9-j);
}
int backconverti(int num){
	return num/10;
} 
int backconvertj(int num){
	if((backconverti(num)%2)==0){
		return num%10;
	}
	else return 9-num%10;
}
ld recurse(int i, int j, int state){
	int num= convert(i, j);
	if(num==99) return 0	;
	if(dp[i][j][state]!=-1) return dp[i][j][state];
	dp[i][j][state]=0;
	// kyahai(num,state);
	if(state==0){
		ld p=0;
		for(int t=1; t<=6; t++){
			int nextsq= num+t;
			if(nextsq>99) {
				p=(ld)(7-t)/6;
				dp[i][j][0]= (dp[i][j][0]+p)/(1-p);
				return dp[i][j][0];
			} 
			dp[i][j][0]+=((1+(recurse(backconverti(nextsq),backconvertj(nextsq),1)))/6) ;
		}
		return dp[i][j][0];
	}
	if(state==1){
		if (board[i][j]==0){
			dp[i][j][1]=recurse(i,j,0);
		}
		else{
			dp[i][j][1]= min(recurse(i, j, 0), recurse(i+board[i][j], j, 0));
		}
		return dp[i][j][1];
	}
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	for(int i=9; i>=0; i--){
		for(int j=0; j<10; j++){
			cin>>board[i][j];
		}
	}
	for(int i=0; i<11; i++){
		for(int j=0; j<11; j++){
			dp[i][j][0]=-1;
			dp[i][j][1]=-1;
		}
	}
	dp[backconverti(99)][backconvertj(99)][0]=0;
	dp[backconverti(99)][backconvertj(99)][1]=0;
	cout<<setprecision(10)<<fixed;
	cout<<recurse(0, 0, 0);
}