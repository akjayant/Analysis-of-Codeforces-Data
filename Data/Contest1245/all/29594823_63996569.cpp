 
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
 
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define ll long long
 
using namespace std;
 
 
using namespace std;
void file(){
	#ifndef ONLINE_JUDGE
    	freopen("tst.txt", "r", stdin);
	#endif	
}
int tc;
const int N=1e6+5,MOD=1e9+7;

int main()
{	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 	file();

 	scanf("%d",&tc);

 	while(tc--){
 		int a,b;
 		scanf("%d %d",&a,&b);

 		if(__gcd(a,b)!=1){
 			printf("Infinite\n");
 		}
 		else	printf("Finite\n");
 	}

}