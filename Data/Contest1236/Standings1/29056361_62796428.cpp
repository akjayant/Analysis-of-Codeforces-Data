#include<bits/stdc++.h>

using namespace std;

#define DIM 300009
#define INF ((long long)1e18+9ll)
#define pairll pair<long long,long long>
#define fi first
#define se second
#define ld long double
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define amen exit(0)
#define endl '\n'
#define MODULO 1000000007

long long i,j,k,l,n,m;

long long a[DIM];

long long mpow(long long n,long long m){
	long long res=1,curr=n;
	while(m){
		if(m&1)res=(res*curr)%MODULO;
		curr=(curr*curr)%MODULO;
		m/=2;
	}
	return res;
}

int main(){
 
	fast; 

	cin>>n>>m;

	cout<<mpow(mpow(2,m)-1,n)<<endl;

	amen;
}