#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int z,x,c;
	int tc;
	cin>>tc;
	
	for(int t=1;t<=tc;t++){
		cin>>z;
		ll a1=0,s1=0,a2=0,s2=0;
		int a;
		for(int q=1;q<=z;q++){
			cin>>a;
			if(a%2==0)s1++;
			else a1++;
		}
		cin>>z;
		for(int q=1;q<=z;q++){
			cin>>a;
			if(a%2==0)s2++;
			else a2++;
		}
		ll total=0;
		total=a1*a2 + (s1*s2);
		cout<<total<<endl;
	}
}