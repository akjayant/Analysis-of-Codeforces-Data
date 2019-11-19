#include<bits/stdc++.h>
using namespace std;
#define pfi(a) printf("%d",a);
#define pfl(a) printf("%lld",a);
#define pfin(a) printf("%d\n",a);
#define pfln(a) printf("%lld\n",a);
#define sfi(a) scanf("%d",&a);
#define sfl(a) scanf("%lld",&a);
#define pb push_back
#define f(i,a,b) for(int i=a;i<b;i++)
#define ll long long
using namespace std;

const int MAXN=2e5+2;
const int M=1e9+7;
ll n, m, dp1[100005][2], dp2[100005][2];
int main() 
{ 
	cin  >> n >> m;

	int m1=max(n,m);
	int n1=min(n,m);

	n=n1;
	m=m1;
	
	ll arr1[MAXN],arr2[MAXN],arr3[MAXN];
	arr1[1]=1;
	arr1[2]=2;

	for(int i=3;i<=m;i++){
		arr1[i]=(arr1[i-1]+arr1[i-2])%M;
	}

	arr2[1]=1;
	arr2[2]=1;

	arr3[1]=1;
	arr3[2]=2;

	for(int i=3;i<=n;i++){
		arr2[i]=(arr2[i-1]+arr2[i-2])%M;
		arr3[i]=(arr3[i-1]+arr2[i])%M;
	}

	cout<<((arr1[m]+arr3[n-1])*2)%M;


    return 0; 
} 