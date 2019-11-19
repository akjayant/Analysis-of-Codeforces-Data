#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second
#define MP make_pair
#define PB push_back

using namespace std;



int main () {
	
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	ll e=b/c;
	for(int i=0; i<c*100; i++){
		if((b-(e*c))%d==0 && e+(b-(e*c))/d<=a){
			cout<<e<<" "<<(b-(e*c))/d<<" "<<a-e-(b-(e*c))/d;
			return 0;
		}
		e--;
		if(e<0){
			cout<<"-1";
			return 0;
		}
	}
	cout<<"-1";
	
	return 0;
}
