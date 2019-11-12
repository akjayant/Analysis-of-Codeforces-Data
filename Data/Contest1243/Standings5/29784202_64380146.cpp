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
char s[M],s2[M];
int di[6];
int main()
{
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	int k,n,sz;
  	cin>>k;
  	while(k--)
 	 {
 	 	cin>>n;
  		cin>>s>>s2;
  		sz=0;
  	//	n=strlen(s);
  		for(int i=0;i<n;i++)
  		if(s[i]!=s2[i])di[++sz]=i;
  		if(sz==2&&s[di[1]]==s[di[2]]&&s2[di[2]]==s2[di[1]]||sz==0)
  		{
  			cout<<"Yes"<<endl;
		}
		else
		cout<<"No"<<endl;
   } 
  	
	return 0;
}