#include<bits/stdc++.h>
using namespace std;

const int N=10010;
int T,n;
char a[N],b[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%s",a+1);
		scanf("%s",b+1);
		int tot=0;
		bool tf=true;
		char fir,sec;
		for(int i=1;i<=n;i++){
			if(a[i]!=b[i]){
				if(tot && (a[i]!=fir || b[i]!=sec)){tf=false;break;}
				else if(tot) tot++;
				else fir=a[i],sec=b[i],tot=1;
			}
		}
		if(!tf || tot>2 || tot==1) printf("No\n");
		else printf("Yes\n");
	}
}