#include<bits/stdc++.h>
#define maxn 2005
#define maxm 500005
#define inf 0x7fffffff
#define ll long long

using namespace std;
char str[maxn]; stack<char> s;
int ok1[maxn],ok2[maxn];
int n;

inline int read(){
    int x=0,f=1; char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}

inline int calc(){
	while(!s.empty()) s.pop();
	int siz=0,num1=0;
	for(int i=1;i<=n;i++){
		if(str[i]=='(') s.push(str[i]),siz++,num1++;
		else if(!s.empty() && s.top()=='(') s.pop(),siz--,num1--;
		else s.push(str[i]),siz++;
		if(!num1) ok1[i]=siz;
		else ok1[i]=-1;
	}
	while(!s.empty()) s.pop();
	siz=0,num1=0;
	for(int i=n;i>=1;i--){
		if(str[i]==')') s.push(str[i]),siz++,num1++;
		else if(!s.empty() && s.top()==')') s.pop(),siz--,num1--;
		else s.push(str[i]),siz++;
		if(!num1) ok2[i]=siz;
		else ok2[i]=-1;
		//cout<<siz<<" "<<ok2[i]<<endl;
	}
	int res=0;
	for(int i=0;i<n;i++)
		{if(ok1[i]==ok2[i+1] && ok1[i]!=-1) res++;}
	return res;
}

int main(){
	n=read(); cin>>str+1;
	for(int i=1;i<=n;i++) str[i+n]=str[i];
	int num=0;
	for(int i=1;i<=n;i++){
		if(str[i]=='(') num++;
		else num--;
	}
	int ans=calc(),pl=1,pr=1;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			swap(str[i],str[j]),swap(str[i+n],str[j+n]);
			int t=calc(); if(t>ans) ans=t,pl=i,pr=j;
			swap(str[i],str[j]),swap(str[i+n],str[j+n]);
		}
	cout<<ans<<endl<<pl<<" "<<pr<<endl;
	return 0;
}
