#include <cstdio>
#include <algorithm>
using namespace std;
int n,maxans,maxi=1,maxj=1,a[1050];
char s[1000];
int main(){
	scanf("%d",&n);
	scanf("%s",s);
	for (int i=1;i<=n;i++) if (s[i-1]=='(') a[i+n]=a[i]=1;else a[i+n]=a[i]=-1;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++){
			swap(a[i],a[j]);
			swap(a[i+n],a[j+n]);
			int cnt=0,ans=0,mincnt=0;
			for (int k=1;k<=n;k++){
				cnt+=a[k];
				mincnt=min(mincnt,cnt);
			}
			if (cnt==0){
				for (int k=1;k<=n;k++){
					cnt+=a[k];
					if (cnt==mincnt) ans++;
				}
			}
			if (ans>maxans){
				maxans=ans;
				maxi=i;
				maxj=j;
			}
			swap(a[i],a[j]);
			swap(a[i+n],a[j+n]);
		}
	printf("%d\n%d %d\n",maxans,maxi,maxj);
	return 0;
}
