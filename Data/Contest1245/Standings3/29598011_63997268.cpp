#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef complex<double> cp;
typedef pair<int,int> pii;

const int maxn=(int)2e5+9;
const ll mod=(ll)1e9+7;
const db pi=acos(-1);
const db eps=1e-15;

#define dbg(x) cerr<<#x<<" is "<<x<<endl;

int gcd(int a,int b){
	if(!b)return a;
	return gcd(b,a%b);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int a,b;
		scanf("%d%d",&a,&b);
		if(gcd(a,b)>1){
			printf("Infinite\n");
		}else{
			printf("Finite\n");
		}
	}
	return 0;
}

