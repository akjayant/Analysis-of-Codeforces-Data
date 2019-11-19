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
 	int t;
 	sfi(t)

 	while(t--){
 		int n;
 		sfi(n)
 		ll od1=0,ev1=0,od2=0,ev2=0;

 		for(int i=0;i<n;i++){
 			int temp;
 			sfi(temp)

 			if(temp%2==1)
 				od1++;
 			else
 				ev1++;
 		}

 		int m;
 		sfi(m)

 		f(i,0,m){
 			int temp;
 			sfi(temp)

 			if(temp%2==1)
 				od2++;
 			else
 				ev2++;

 		}

 		ll ans=ev1*ev2+od1*od2;

 		pfln(ans)
 	}
    return 0; 
} 