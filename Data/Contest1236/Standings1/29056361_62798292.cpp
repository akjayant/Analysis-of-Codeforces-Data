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

vector<long long>res[DIM];

int main(){
 
	fast; 

	cin>>n;

	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i%2==1)res[j].push_back((i-1)*n+j);
			else res[n-j+1].push_back((i-1)*n+j);
		}
	}

	for(i=1;i<=n;i++){
		for(auto to:res[i])cout<<to<<' ';
		cout<<endl;
	}

	amen;
}