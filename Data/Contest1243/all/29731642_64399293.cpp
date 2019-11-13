#include<bits/stdc++.h>
using namespace std;
const int maxn=100+10;
struct node{
	int x,y;
}a[maxn*2];
char s[maxn],t[maxn];
map<int,int>mp;
int main()
{
	int k,n;
	scanf("%d",&k);
	while(k--){
		mp.clear();
		scanf("%d",&n);
		scanf("%s %s",s,t);
		for(int i=0;i<n;i++){
			mp[s[i]]++;
			mp[t[i]]++;
		}
		bool flag=0;
		for(char i='a';i<='z';i++){
			if(mp[i]&1) flag=1;
		}

		if(flag) printf("No\n");
		else{
			printf("Yes\n");
			int op=0;
			for(int i=0;i<n;i++){
				if(s[i]!=t[i]){
					for(int j=i+1;j<n;j++){
						if(s[i]==s[j]){
							a[op].x=j; a[op].y=i;
							swap(s[j],t[i]); op++;
							break;
						}
						else if(t[i]==t[j]){
							a[op].x=i; a[op].y=j;
							swap(s[i],t[j]); op++;
							break;
						}
						else if(s[i]==t[j]){
							a[op].x=j; a[op].y=j;
							swap(s[j],t[j]); op++;

							a[op].x=j; a[op].y=i;
							swap(s[j],t[i]); op++;
							break;
						}
						else if(t[i]==s[j]){
							a[op].x=j; a[op].y=j;
							swap(s[j],t[j]); op++;

							a[op].x=i; a[op].y=j;
							swap(s[i],t[j]); op++;
							break;
						}
					}
				}
			}
			printf("%d\n",op);
			for(int i=0;i<op;i++){
				printf("%d %d\n",a[i].x+1,a[i].y+1);
			}
		}
	}
	return 0;
}