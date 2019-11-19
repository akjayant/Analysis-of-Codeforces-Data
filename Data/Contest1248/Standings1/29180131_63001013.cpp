#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
char s[505];

int main(){
	int n;
	scanf("%d%s",&n,s);
	int mx=0,x=0,y=0;
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++){
			swap(s[i],s[j]);
			int sum=0,cnt=0,id,Mx=-1e9;
			for(int k=0;k<n;k++){
				if(s[k]=='(')sum--;
				else sum++;
				if(sum>Mx)Mx=sum,id=k;
			}
			if(sum==0){
				id++;
				id%=n;

				for(int k=0;k<n;k++){
					if(s[(k+id)%n]=='(')sum--;
					else sum++;
					if(sum==0)cnt++;
				}
				if(cnt>mx)mx=cnt,x=i,y=j;
			}
			swap(s[i],s[j]);
		}
	printf("%d\n",mx);
	printf("%d %d\n",x+1,y+1);
}