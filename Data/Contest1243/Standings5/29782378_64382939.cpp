#include<cstdio>
using namespace std;
const int maxn=1000000;


char ch1[maxn];
char ch2[maxn];

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		scanf("%s", ch1);
		scanf("%s", ch2);
		int x=-1;
		int y=-1;
		bool pd=true;
		for (int i=0;i<n;i++) {
			if (ch1[i]!=ch2[i]) {
				if (x==-1) {
					x=i;
				} else if (y==-1) {
					y=i;
				} else {
					pd=false;
				}
			}
		}
		if (y==-1) {
			pd=false;
		}
		if (ch1[x]!=ch1[y] || ch2[x]!=ch2[y]) {
			pd=false;
		}
		if (pd) {printf("Yes\n");}
		else {printf("No\n");}
	}
}
