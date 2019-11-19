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
int a[33],b[33];
ll dp[33][2][3][3];
ll rec(int pos,int last,int x,int y){
	if(pos==30)
		return (!last and x<=1 and y<=1);
	ll &ret=dp[pos][last][x][y];
	if(~ret)
		return ret;ret=0;
	int xx,yy;		
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++){
			if(i^j!=i^j^last)
				continue;
			xx=x;yy=y;	
			if(a[pos]>i)
				xx=1;
			if(a[pos]<i)
				xx=2;	
			if(b[pos]>j)
				yy=1;
			if(b[pos]<j)
				yy=2;	
			ret+=rec(pos+1,(i+j+last)>1,xx,yy);	
		}
	return ret;	
}
ll rec(int x,int y){
//	cout<<x<<" "<<y<<endl;
	if(x<0 or y<0)
		return 0;	
	for(int i=0;i<30;i++){
		a[i]=(x>>i&1);
		b[i]=(y>>i&1);
	}
	memset(dp,-1,sizeof dp);
//	cout<<rec(0,0,0,0)<<endl;
	return rec(0,0,0,0);
}
int main(){
    //freopen("file.in", "r", stdin);
    int t;
    scanf("%d",&t);
    while(t--){
    	int l,r;
		scanf("%d%d",&l,&r);
		printf("%lld\n",rec(r,r)-rec(l-1,r)-rec(r,l-1)+rec(l-1,l-1));	
    }
	return 0;
}
