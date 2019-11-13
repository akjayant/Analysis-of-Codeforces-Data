//I read the news today, oh boy
//About a lucky man who made the grade
 
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(x) int((x).size())
#define all(v) (v).begin(),(v).end()
#define trace(x) cerr << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define For(i,a,b) for(int i = int(a); i < int(b); ++i)
#define roF(i,a,b) for(int i = int(a); i >= int(b); i--)
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int N=1e5+5;
const ll MOD = 1e9+7;

ll dp[N];

int main(){
	fastio;
	string s; cin>>s;
	int n = sz(s);
	bool chi=1;
	For(i,0,n) if(s[i]=='w' || s[i]=='m') chi=0;
	if(!chi) cout<<0<<endl;
	else{
		dp[0]=dp[1]=1;
		For(i,2,n+1){
			if((s[i-1]=='u' && s[i-2]=='u') || (s[i-1]=='n' && s[i-2]=='n')){
				dp[i]=(dp[i-1]+dp[i-2])%MOD;
			}else dp[i]=dp[i-1];
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}