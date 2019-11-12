#include<bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define ld long double
#define endl "\n"
#define ld long double
#define ff first
#define ss second
#define pi pair<float,int> 
#define PI 3.141592653589793238462643383279502884L
#define mp make_pair
#define pb push_back
#define forall(i,n) for(int i=0;i<n;i++)
ll mod = 998244353;
ll mod1 = 1e9 + 7;
const int N= 1e5+5;

int n;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		int a,b,c;
		cin>>a>>b>>c;
		int ans=0;
	    int x=c/2;
	    x=min(b,c/2);
	    b-=x;
	    ans+=3*x;
	    int y=b/2;
	    y=min(a,y);
	    ans+=3*y;
	    cout<<ans<<endl;
	    
	}
	
	
	return 0;
}