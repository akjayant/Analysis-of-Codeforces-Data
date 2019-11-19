/*            ,%%%%%%%%%%%,
             ,%%/\%%%%%%/\%%
            ,%%%\c  """  J/%%
            %%%%/  O   O \%%%
 %.         %%%%         |%%%
 ~%%.        `%%%%(__Y__)%%'
  ~%%         ;%%%%`\_/%%%'
          /   '%%%%%%%'
  <<      ,            |
   \\    .       \     |
    \\  /        /   | |
     \\/        /    | |
      \          __  | |___
           ((           ))))))
*/
#include"bits/stdc++.h"
//next_permutation(str,str+n) 
//getline(cin,s) 
#include"iostream"
#include"string"
#include"cstring"
#include"algorithm"
#include"cmath"
#include"map"
#include"queue"
#include"vector"
#include"cstdio"
#include"cstdlib"
#include"set"
#include"sstream"
#include"stack"
#define f(i,a,b) for(int i=a;i<=b;i++)
#define fill(a,b) memset(a,b,sizeof(a))
#define PI acos(-1)
#define INF 0x3f3f3f3f
#define _mod (ll)(1e9+7)
#define gc() getchar()
#define lowbit(x) (x&(-x))
//#define sd(n) scanf("%d",&n)
//#define sd(n,m) scanf("%d%d",&n,&m)
typedef long long ll ;
typedef unsigned long long ull;
using namespace std;
inline int read(){
    int res=0,f=0;char c;c=gc();
    while(!isdigit(c)){if(c=='-')f=1;c=gc();}
    while(isdigit(c)){res=res*10+c-48;c=gc();}
    if(f)return -res;return res;
}
const int maxn=2e3+5;
struct node {
	ll x,y,k,c;
}str[maxn];
struct Node{
	int from,to;
	ll v;
	Node(){
	}
	Node(int a,int b,ll c){
		from=a,to=b,v=c;
	}
	bool operator <(const Node &x) const{
		return x.v<v;
	}
};
int pre[maxn],n,vis[maxn];
int s[maxn][maxn];
int find(int x) {
	return pre[x]==x?x:pre[x]=find(pre[x]); 
}
priority_queue<Node> Q;
ll solve(){
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ll p=((str[i].k+str[j].k)*(abs(str[i].x-str[j].x)+abs(str[i].y-str[j].y)));
			Q.push(Node(i,j,p));
		}
	}
	while(!Q.empty()){
		Node p=Q.top(); Q.pop();
		int x=find(p.from),y=find(p.to);
		if(x!=y){
			ans+=p.v;
			pre[x]=y;
			s[p.to][p.from]=s[p.from][p.to]=1;
		}
	}
	return ans;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++) {
		cin>>str[i].x>>str[i].y; 
	}
	for(int i=1;i<=n;i++) {
		cin>>str[i].c;
		Q.push(Node(0,i,str[i].c));
	}
	for(int i=1;i<=n;i++) cin>>str[i].k,pre[i]=i;
	cout<<solve()<<endl;
	int count=0,P[maxn],u=1;
	for(int i=1;i<=n;i++){
		if(s[0][i]) {
			count++;
			P[i]=1;
		}
	}
	cout<<count<<endl; 
	for(int i=1;i<=n;i++) {
		 if(s[0][i]){
		 	if(u==count) cout<<i<<endl;
		 	else cout<<i<<" ";
		 	u++;
		 }
	}
	cout<<n-count<<endl;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(s[i][j]) cout<<i<<" "<<j<<endl;
		}
	}
    return 0;
}










