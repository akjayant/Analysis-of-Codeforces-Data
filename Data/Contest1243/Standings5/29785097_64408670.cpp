#include<bits/stdc++.h>
using namespace std;
int n,k,cnt,num[1005],lastbj,ans[1005][5],tmp;
bool f;
char a[105],b[105];
int main(){
	scanf("%d",&k);
	while(k--){
		scanf("%d",&n);
		scanf("%s",a);
		scanf("%s",b);
		int answer=1;
		for(int i=0;i<26;i++)num[i]=0;
		for(int i=0;i<n;i++){
			num[a[i]-'a']++;
			num[b[i]-'a']++;
		}
		for(int i=0;i<26;i++){
			if(num[i]&1)answer=0;
		}
		if(answer){
			puts("Yes");
			cnt=0;
			for(int i=n-1;i>=0;i--)
				if(a[i]!=b[i]){
					lastbj=i;
					break;
				}
			for(int i=0;i<n;i++){
				if(a[i]!=b[i]){
					f=false;
					for(int j=i+1;j<n;j++){
						if(a[i]==a[j] && a[j]!=b[j]){
							ans[cnt][0]=j;
							ans[cnt][1]=i;
							cnt++;
							
							tmp=a[j];
							a[j]=b[i];
							b[i]=tmp;
							f=true;
							break;
						}
					}
					if(!f)
						for(int j=i+1;j<n;j++){
							if(a[i]==b[j] && a[j]!=b[j]){
								ans[cnt][0]=lastbj;
								ans[cnt][1]=j;
								cnt++;
								ans[cnt][0]=lastbj;
								ans[cnt][1]=i;
								cnt++;
								
								tmp=b[j];
								b[j]=a[lastbj];
								a[lastbj]=b[i];
								b[i]=tmp;
								f=true;
								break;
							}
						}
				}
			}
			printf("%d\n",cnt);
			for(int i=0;i<cnt;i++){
				printf("%d %d\n",ans[i][0]+1,ans[i][1]+1);
			}
		}
		else{
			puts("No");
		}
	}
}
