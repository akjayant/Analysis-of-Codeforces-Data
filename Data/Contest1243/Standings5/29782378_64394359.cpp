#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1000;

char ch1[maxn];
char ch2[maxn];

struct Pair{
	int x;
	int y;
} ans[maxn*2];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int ansn=0;
		int n;
		scanf("%d", &n);
		scanf("%s",ch1+1);
		scanf("%s",ch2+1);
		for (int i=1;i<=n;i++) {
			if (ch1[i]!=ch2[i]) {
				bool flag=false;
				for (int j=i+1;j<=n;j++) {
					if (flag){break;}
					if (ch1[j]==ch1[i]) {
						flag=true;
						swap(ch2[i],ch1[j]);
						ansn++;
						ans[ansn].x=j;
						ans[ansn].y=i;
					}
				}
				for (int j=i+1;j<=n;j++) {
					if (flag){break;}
					if (ch2[j]==ch2[i]) {
						flag=true;
						swap(ch1[i],ch2[j]);
						ansn++;
						ans[ansn].x=i;
						ans[ansn].y=j;
					}
				}
				if (!flag) {
					swap(ch1[i],ch2[i]);
					ansn++;
					ans[ansn].x=i;
					ans[ansn].y=i;
				}
				for (int j=i+1;j<=n;j++) {
					if (flag){break;}
					if (ch1[j]==ch1[i]) {
						flag=true;
						swap(ch2[i],ch1[j]);
						ansn++;
						ans[ansn].x=j;
						ans[ansn].y=i;
					}
				}
				for (int j=i+1;j<=n;j++) {
					if (flag){break;}
					if (ch2[j]==ch2[i]) {
						flag=true;
						swap(ch1[i],ch2[j]);
						ansn++;
						ans[ansn].x=i;
						ans[ansn].y=j;
					}
				}
			}
		}
		int p=0;
		for (int i=1;i<=n;i++) {
			if (ch1[i]!=ch2[i]) {
				p=i;
				break;
			}
		}
		if (p==0) {
			printf("YES\n%d\n", ansn);
			for (int i=1;i<=ansn;i++) {
				printf("%d %d\n", ans[i].x,ans[i].y);
			}
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
