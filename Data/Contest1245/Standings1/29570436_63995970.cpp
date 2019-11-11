#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000005;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
typedef pair<int,int> pii;
#define X first
#define Y second
int t;
int a,b;
inline int gcd(int x,int y){
	return !y?x:gcd(y,x%y);
}
int main(){
	cin>>t;
	while(t--){
		cin>>a>>b;
		if(gcd(a,b)!=1) puts("Infinite");
		else puts("Finite");
	}
	return 0;
} 