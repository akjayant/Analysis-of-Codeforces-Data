#include "bits/stdc++.h"
#define MAXN 100009
#define INF 1000000007
#define mp(x,y) make_pair(x,y)
#define all(v) v.begin(),v.end()
#define pb(x) push_back(x)
#define wr cout<<"----------------"<<endl;
#define ppb() pop_back()
#define tr(ii,c) for(__typeof((c).begin()) ii=(c).begin();ii!=(c).end();ii++)
#define ff first
#define ss second
#define my_little_dodge 46
#define debug(x)  cerr<< #x <<" = "<< x<<endl;
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
template<class T>bool umin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T>bool umax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
int dp[MAXN][2],n;
char s[MAXN];
int rec(int pos,int a){
	if(pos==n)
		return 1;
	int &ret=dp[pos][a];
	if(~ret)
		return ret;
	ret=rec(pos+1,0);
	if(pos+1<n and s[pos]==s[pos+1] and (s[pos]=='u' or s[pos]=='n') and !a)
		ret+=rec(pos+1,1);
	if(ret>=INF)
		ret-=INF;
	return ret;					
}
int main(){
//   / freopen("file.in", "r", stdin);
    scanf("%s",s);
    n=strlen(s);
    for(int i=0;i<n;i++)
    	if(s[i]=='m' or s[i]=='w')
    		return puts("0")*0;
    memset(dp,-1,sizeof dp);
    printf("%d\n",rec(0,0));
	return 0;
}
