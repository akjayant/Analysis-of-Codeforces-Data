#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10005;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
typedef pair<int,int> pii;
#define X first
#define Y second
int t;
int n,a,b,c;
char s[N]; 
char p[N];int d[N];
int main(){
	cin>>t;
	while(t--){
		cin>>n>>a>>b>>c;
		memset(d,0,sizeof(d));
		scanf("%s",s+1);
		int res=0;
		for(int i=1;i<=n;i++) {
			if(s[i]=='R'&&b>0) {
				b--;res++;
				d[i]=1;p[i]='P';
			} else if(s[i]=='P' && c>0){
				c--;res++;
				d[i]=1;p[i]='S';
			} else if(s[i]=='S' && a>0){
				a--;res++;
				d[i]=1;p[i]='R';
			}
		}
		if(res>=(n+1)/2) {
			puts("YES");
			for(int i=1;i<=n;i++) {
				if(d[i]) putchar(p[i]);
				else {
					if(a>0){
						a--;putchar('R');
					}else if(b>0) {
						b--;putchar('P');
					}else if(c>0) {
						c--;putchar('S');
					}
				}
			}
			puts("");
		}else {
			puts("NO");
		}
	}
	return 0;
} 