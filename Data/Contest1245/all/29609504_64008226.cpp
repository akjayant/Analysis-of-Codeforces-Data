#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double db;
typedef pair<int,int> pr;
#define mpr make_pair
#define int ll
#define case int ___T; scanf("%d", &___T); for(int cas=1;cas<=___T;cas++)
template<typename T>inline void rd(T&x){int fl=0,ch;while(ch=getchar(),ch<48||57<ch)fl^=!(ch^45);x=(ch&15);while(ch=getchar(),47<ch&&ch<58)x=x*10+(ch&15);if(fl)x=-x;}
template<typename T>inline void pt(T x){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int ch){pt(x),putchar(ch);}
const ll INF = 0x3f3f3f3f3f3f3f3f;
const db eps = 1e-7;
const ll maxn = 1e3+5;
const ll maxm = 1e7;
const ll mod = 1e9+7;

int uu[maxn],ans[maxn];
char s[maxn];

map<char,int> mp;

signed main()
{
	int t;rd(t);
	while(t--)
	{
		int n;
		rd(n);
		for(int i=1;i<=3;i++) rd(uu[i]);
		scanf("%s",&s);
		int as = 0;
		for(int i=0;i<n;i++){
			if(s[i]=='R'&&uu[2]){
				ans[i] = 2;
				uu[2]--;as++;
			}
			else if(s[i]=='S'&&uu[1]){
				ans[i] = 1;
				uu[1]--;as++;
			}
			else if(s[i]=='P'&&uu[3]){
				ans[i] = 3;
				uu[3]--;as++;
			}
			else ans[i] = 0;
		}
		
		if(as>=(n+1)/2){
			cout<<"YES"<<endl;
			for(int i=0;i<n;i++)
			{
				if(ans[i]==1){
					cout<<"R";
				}
				else if(ans[i]==2){
					cout<<"P";
				}
				else if(ans[i]==3){
					cout<<"S";
				}
				else{
					for(int j=1;j<=3;j++)
						if(uu[j]){
							uu[j]--;
							ans[i] = j;
							break;
						}
					if(ans[i]==1){
						cout<<"R";
					}
					if(ans[i]==2){
						cout<<"P";
					}
					if(ans[i]==3){
						cout<<"S";
					}
				}
			}
			cout<<endl;
		}
		else cout<<"NO"<<endl;
		
	}
	return 0;
}
