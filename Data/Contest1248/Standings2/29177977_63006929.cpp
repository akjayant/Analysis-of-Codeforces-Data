#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e2+10;
char s[maxn];
int sum[maxn];
int mxl[maxn],mxr[maxn];
int n;
void print(int *a){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
int f(char x){
	if(x=='(')return 1;
	return -1;
}
int ans=0,x=0,y=0;
int get(){
	sum[0]=f(s[0]);
	for(int i=1;i<n;i++){
		sum[i]=sum[i-1]+f(s[i]);
	}
	if(sum[n-1])return 0;
	mxr[n-1]=sum[n-1];
	mxl[0]=sum[0];
	for(int i=n-2;i>=0;i--){
		mxr[i]=min(mxr[i+1],sum[i]);
		mxl[n-i-1]=min(mxl[n-i-2],sum[n-i-1]);
	}
	int ans=0;
	for(int i=0;i<n;i++){
		if(sum[i]<=mxr[i]&&sum[i]<=mxl[i])ans++;
	}
/*/	print(sum);
	print(mxl);
	print(mxr);*/
	return ans;
}
void swap(int x,int y){
	char t=s[x];
	s[x]=s[y];
	s[y]=t;
}
int main(){
	cin>>n;
	cin>>s;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			swap(i,j);
			//cout<<i<<" "<<j<<endl;
			int aa=get();
			if(aa>ans){
				ans=aa;
				x=i;y=j;
			}
			swap(i,j);
		}
	}
	cout<<ans<<endl;
	x++;y++;
	cout<<x<<" "<<y<<endl;
}
//-3 -15 0 1 12 -15 19
//