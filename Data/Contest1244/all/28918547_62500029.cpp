#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>

#define ll long long

using namespace std;

void TaskA(){
	int t;
	scanf("%d",&t);
	while(t--){
		int a,b,c,d,e;
		scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
		int x=(a-1)/c+1,y=(b-1)/d+1;

		if(x+y>e)puts("-1");
		else printf("%d %d\n",e-y,y);
	}
}

void TaskB(){
	int t;
	scanf("%d",&t);
	char c[1005];
	while(t--){
		int N;
		int op=-1;
		int ed=-1;
		scanf("%d %s",&N,c+1);
		for(int i=1;i<=N;i++)
			if(c[i]=='1')ed=i;
		for(int i=N;i>=1;i--)
			if(c[i]=='1')op=i;
		if(ed==-1){
			printf("%d\n",N);
			continue;
		}
		printf("%d\n",max(op-1,N-ed)*2+(ed-op+1)*2);
	}
}

void extended(long long a,long long b,long long& x,long long& y) {
	if(!b) {
		x=1,y=0;
		return ;
	}
	extended(b,a%b,y,x);
	y-=a/b*x;
}
void TaskC(){
	ll a,b,c,d,g,base=0;
	ll e=0,x=0,y=0,o=0,tmp=0,fo=0;
	ll cnt=0;
	scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
	g=__gcd(d,c);
	if(b%g){ puts("-1");return;}
	b/=g,c/=g,d/=g;
	if(d!=1) {
		e=b/(c*d);
		b-=e*c*d,base=e*d;
		extended(c,d,x,y);
		x=(x%d+d)%d;
		o=x*c/d;
		tmp=b/d;
		fo=(b%d)*x+base;
		tmp-=(b%d)*o;
	} else {
		fo=b/c;
		tmp=b%c;
	}

	if(tmp<0) {
		cnt=(-tmp)/c;
		tmp+=(cnt+1)*c;
		fo-=(cnt+1)*d;
	}
	cnt=tmp/c;
	tmp-=cnt*c;
	fo+=cnt*d;
	if(fo<0||fo+tmp>a) puts("-1");
	else printf("%lld %lld %lld\n",fo,tmp,a-fo-tmp);
}
const int N = 4e5 + 2;

void TaskE(){
	int n,l,r,now;
	ll m;
	scanf("%d %lld",&n,&m);
	std::vector<int> A(n+1);
	for(int i=1; i<=n; ++i)
		scanf("%d",&A[i]);
	sort(A.begin()+1,A.end());
	l=1,r=n;
	while(l<r) {
		now=A[l];
		while(A[l+1]==now)++l;
		now=A[r];
		while(A[r-1]==now)--r;
		if(l>=r)break;
		if(l<n-r+1) {
			if(m>=1ll*l*(A[l+1]-A[l])) {
				m-=1ll*l*(A[l+1]-A[l]);
				++l;
			} else break;
		} else {
			if(m>=1ll*(n-r+1)*(A[r]-A[r-1])) {
				m-=1ll*(n-r+1)*(A[r]-A[r-1]);
				--r;
			} else break;
		}
	}

	// printf("%d %d\n",l,r);
	if(l>=r)printf("0\n");
	else printf("%lld\n",A[r]-A[l]-m/min(l,n-r+1));
}

ll a[1000005],b[1000005];
bool ed[1000005];
void TaskG(){
	ll n,k;
	
	cin >> n >> k;
	if(k < n * (n + 1) / 2)
	{
		cout << -1 << endl;
		return ;
	}
	ll now = n * (n + 1) / 2;
	ll cnt = 2 * n + 1;
	for(int i = n;i >= 1;i--)
	{
		if(now + cnt / 2 - i <= k)
			a[i] = cnt / 2,now += cnt / 2 - i,cnt--;
		else
		{
			a[i] = i + k - now;
			now = k;
			for(int j = i - 1;j >= 1;j--)
				a[j] = j;
			break;
		}
	}
	cnt = 0;
	for(int i = 1;i <= n;i++)
		if(a[i] != a[i + 1])
			b[++cnt] = a[i],ed[a[i]] = true;
	for(int i = 1;i <= n;i++)
		if(!ed[i])
			b[++cnt] = i;
	cout << now << endl;
	for(int i = 1;i <= n;i++)
		cout << i << " ";
	cout << endl;
	cnt = 0;
	for(int i = 1;i <= n;i++)
		cout << b[i] << " ";
	cout << endl;
}
signed main(){

	#ifndef ONLINE_JUDGE
       	freopen("input.txt","r",stdin);
    #endif
	
	//TaskA();
	//TaskB();
	//TaskC();
	//TaskD();
	//TaskE();
	//TaskF();
    TaskG();
}