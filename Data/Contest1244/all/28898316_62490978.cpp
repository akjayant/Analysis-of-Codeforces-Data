#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define LL long long 
typedef long long ll;
const int N=5e5+5;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
typedef pair<int,int> pii;
int n;ll k;
int a[N];
inline bool cmp(int a,int b){
	return a>b;
}
int main(){
	n=read();cin>>k;
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1,cmp);
	int l=1,r=n,lv=a[1],rv=a[n];
	while(l<r){
		while(l<n&&a[l+1]==lv) l++;
		while(r>1&&a[r-1]==rv) r--;
		if(l>=r||l==n||r==1) {
			puts("0");
			return 0;
		}
		if(l<(n-r+1)){
			int d=a[l]-a[l+1];
			if(k>=1ll*d*l) {
				k-=1ll*d*l;
				lv=a[l+1];
			}else {
				cout<<lv-rv-(k/l);
				return 0;
			}
		}else {
			int d=a[r-1]-a[r];
			if(k>=1ll*d*(n-r+1)) {
				k-=1ll*d*(n-r+1);
				rv=a[r-1];
			}else {
				//cout<<lv<<' '<<rv<<' '<<k<<endl;
				cout<<lv-rv-(k/(n-r+1));
				return 0;
			}
		}
	}
	cout<<0;
	return 0;
} 