#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define lim 1000000007
#define ll long long
int n,m,t,ans,an,a,b,c,cc[200005],aa[200005],bb[200005];
map<int ,int > mm;
priority_queue<int > q;
char s[205],ss[205];
vector<int > ee[200005];
struct yo{
	int x,y;
	bool operator < (const yo & tt) const{
		return x<tt.x;
	}
};
int main(){
	scanf("%d",&t);
	for (int i=0;i<t;i++){
		scanf("%d",&n);
		scanf("%d%d%d\n",&a,&b,&c);
		memset(s,NULL,sizeof(s));
		gets(s);
		ans = 0;
		for (int j=0;j<n;j++){
			if (s[j] == 'R' && b>0){
				ans ++;
				b--;
				ss[j] = 'P';
			}else if (s[j] == 'P' && c>0){
				ans ++;
				c--;
				ss[j] = 'S';
			}else if (s[j] == 'S' && a>0){
				ans ++;
				a--;
				ss[j] = 'R';
			}else ss[j] = '?';
		}
		if (ans>=(n+1)/2){
			printf("YES\n");
			for (int j=0;j<n;j++){
				if (ss[j]!='?') printf("%c",ss[j]);
				else{
					if (a>0){
						printf("R");
						a--;
					}else if (b>0){
						printf("P");
						b--;
					}else if (c>0){
						printf("S");
						c--;
					}
				}
			}
			printf("\n");
		}else printf("NO\n");
	}
	return 0;
}