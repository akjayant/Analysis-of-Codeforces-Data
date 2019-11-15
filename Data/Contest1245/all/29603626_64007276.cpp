#include <bits/stdc++.h>
using namespace std;
const int N=105;
char ss[N],t[N];
int main (){
	int T;scanf ("%d",&T);
	while (T--){
		memset (t,0,sizeof(t));
		int n;scanf ("%d",&n);
		int r,p,s;
		scanf ("%d%d%d",&r,&p,&s);
		scanf ("%s",ss+1);
		int R=0,P=0,S=0;
		for (int i=1;i<=n;i++)
			if (ss[i]=='R') R++;
			else if (ss[i]=='P') P++;
			else S++;
		int win=min(r,S)+min(p,R)+min(s,P);
		if (win>=(n+1)/2) {
			puts("YES");
			for (int i=1;i<=n;i++)
				if (ss[i]=='R') {
					if (p) t[i]='P',--p;
				}else if (ss[i]=='P'){
					if (s) t[i]='S',--s;
				}else{
					if (r) t[i]='R',--r;
				}
			for (int i=1;i<=n;i++)
				if (!t[i]){
					if (p) t[i]='P',--p;
					else if (s) t[i]='S',--s;
					else t[i]='R';
				}
			for (int i=1;i<=n;i++)
				printf ("%c",t[i]);
			puts("");
		}else puts("NO");
	}
	return 0;
}