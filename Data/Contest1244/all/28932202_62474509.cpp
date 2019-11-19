#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1003;
int t,n;
char s[N];
int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		scanf("%s",s+1);
		int fir=-1,lst=-1;
		for(int i=1;i<=n;i++)
			if(s[i]=='1') {
				if(fir==-1)
					fir=i;
				lst=i;
			}
		if(fir==-1) printf("%d\n",n);
		else printf("%d\n",2*max(lst,n-fir+1));
	}
	return 0;
}