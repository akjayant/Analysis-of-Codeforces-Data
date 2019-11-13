#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//typedef __int128 LL;
//typedef unsigned long long ull;
//#define F first
//#define S second
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
const ld PI=acos(-1);
const ld eps=1e-9;
//unordered_map<int,int>mp;
/*int head[M],cnt;
struct EDGE{int to,nxt,val;}ee[M];
void add(int x,int y,int z){ee[++cnt].nxt=head[x],ee[cnt].to=y,ee[cnt].val=z,head[x]=cnt;}*/
#define ls (o<<1)
#define rs (o<<1|1)
#define pb push_back
const int seed=131;
const int M = 1e5+7;
int a[M];
int main()
{
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	int k,n;
  	cin>>k;
  	while(k--)
 	 {
  		cin>>n;
  		for(int i=1;i<=n;i++)
  		cin>>a[i];
  		sort(a+1,a+1+n);
  		int ma=0;
  		for(int i=1;i<=n;i++)
  		ma=max(ma,min(n-i+1,a[i]));
  		cout<<ma<<endl;
   } 
  	
	return 0;
}