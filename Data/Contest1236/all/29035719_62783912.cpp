#include <bits/stdc++.h>
#define forn(i,n) for(int i=0; i<n; i++)
#define pb push_back
#define ll long long int
#define mp make_pair
#define sz(arr) (ll)arr.size()
#define MOD 1000000007

using namespace std;

void func(){
	int a,b,c;
	cin>>a>>b>>c;
	int tot=0;
	tot+=3*min(c/2,b);
	b-=tot/3;
	tot+=3*min(b/2,a);
	cout<<tot<<"\n";
}

int main(){
	int T;
	cin>>T;
	forn(_,T) func();
}
