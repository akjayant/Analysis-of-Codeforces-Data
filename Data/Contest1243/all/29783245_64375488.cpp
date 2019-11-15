#include<bits/stdc++.h>
using namespace std;
int k;
int n;
int a[1100]; 
int b[1100];
int main()
{
	scanf("%d",&k);
	while(k--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) b[i]=0;
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		sort(a,a+n);
		for(int i=0;i<n;i++){
			b[a[i]]++;
		}
		for(int i=n-1;i>=1;i--){
			b[i]+=b[i+1];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(b[i]>=i){
				ans=i;
			}
		}
		printf("%d\n",ans);
	}
  return 0;
}

