#include<bits/stdc++.h>
#define bclz(x) (__builtin_clz(x))
#define x first
#define y second
using namespace std;
typedef long long INT;
typedef vector<int> VI;
typedef pair<int,int> pii;
#define NN 100100
int a[NN];
map <int,int> M;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n;
	INT k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) scanf("%d",a+i),M[a[i]]++;
	sort(a+1,a+n+1);
	int nn=unique(a+1,a+n+1)-a-1;
//	cerr<<nn;
	int st=1,ed=nn;
	while(1){
		if(st==ed){
			cout<<0<<endl;
			return 0;
		}
		if(M[a[st]]<=M[a[ed]]){
			if(k>=1LL*(a[st+1]-a[st])*M[a[st]]){
				k-=1LL*(a[st+1]-a[st])*M[a[st]];
				M[a[st+1]]+=M[a[st]];
				st++;
//				cerr<<k<<' '<<i<<endl;
			}
			else {
				k/=M[a[st]];
				a[st]+=k;
				cout<<a[ed]-a[st]<<endl;
				return 0;
			}
		}
		else {
			if(k>=1LL*(a[ed]-a[ed-1])*M[a[ed]]){
//				cerr<<k;
				k-=1LL*(a[ed]-a[ed-1])*M[a[ed]];
				M[a[ed-1]]+=M[a[ed]];
				ed--;
//				cerr<<k<<' '<<i<<endl;
			}
			else {
				k/=M[a[ed]];
				a[ed]-=k;
				cout<<a[ed]-a[st]<<endl;
				return 0;
			}
		}
	}
	
	
	return 0;
}
       