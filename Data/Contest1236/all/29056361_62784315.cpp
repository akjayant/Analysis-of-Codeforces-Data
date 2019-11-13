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

long long i,j,k,l,n,m;

long long a[DIM];

int main(){
 
	fast; 

	int a,b,c,nt,res;
	cin>>nt;
	while(nt--){
		cin>>a>>b>>c;
		res=min(b,c/2)*3;
		b-=min(b,c/2);
		c-=2*min(b,c/2);
		res+=min(a,b/2)*3;
		cout<<res<<endl;
	}

	amen;
}