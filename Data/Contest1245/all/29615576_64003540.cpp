#include <bits/stdc++.h>
using namespace std;

#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define in_range(x,l,r) (lb(all(x),r+1)-lb(all(x),l))
#define per(i,n) for (int i=(int)(n)-1;i>=0;i--)
#define For(i,n) for (int i=1;i<=(int)(n);i++)
#define Rep(i,n) for (int i=0;i<=(int)(n);i++)
#define rep(i,n) for (int i=0;i<(int)(n);i++)
#define set0(i) memset(i,0,sizeof(i))
#define all(x) (x).begin(),(x).end()
#define Max(a,b,c) max(a,max(b,c))
#define Min(a,b,c) min(a,min(b,c))
#define fore(i,x) for (auto &i:x)
#define cmax(x,y) x=max(x,y)
#define cmin(x,y) x=min(x,y)
#define pii pair<int,int>
#define vi vector <int>
#define lb lower_bound
#define ub upper_bound
#define ll long long
#define pb push_back
#define re return
#define se second
#define fi first
const int INF=0x7fffffff;
const int MAXN=+3;
const int MOD=1e9+7;

string s;
int n,f[100003][2];

int main(){
	cin>>s;
	s="@"+s;
	n=s.size();
	f[0][0]=1;
	for (int i=1;i<n;i++){
		char c=s[i];
		if (c=='w'|| c=='m'){
			cout<<0<<endl;
			re 0;
		}
		if ((c=='u' || c=='n') && c==s[i-1]){
			f[i][1]+=f[i-1][0];
			if (f[i][1]>=MOD) f[i][1]-=MOD;
		}
		f[i][0]=f[i-1][0]+f[i-1][1];
		if (f[i][0]>=MOD) f[i][0]-=MOD;
	}
	cout<<(f[n-1][0]+f[n-1][1])%MOD<<endl;
	re 0;
}