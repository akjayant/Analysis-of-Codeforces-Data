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

int main() 
{ 
 	int n;
 	sfi(n)

 	ll arr[n];

 	f(i,0,n)
 	sfl(arr[i])

 	sort(arr,arr+n,greater<ll>());

 	int mid=n/2;

 	if(n%2==1){
 		mid++;
 	}

 	ll sum1=0,sum2=0;

 	for(int i=0;i<mid;i++){
 		sum1+=arr[i];
 	}

 	for(int i=mid;i<n;i++){
 		sum2+=arr[i];
 	}

 	ll ans=sum1*sum1+sum2*sum2;

 	pfl(ans)

    return 0; 
} 