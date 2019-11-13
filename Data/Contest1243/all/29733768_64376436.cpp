#include <bits/stdc++.h> 
using namespace std;
#define pb push_back
#define vi vector<int>
#define vpi vector<pair<ll,ll> >
#define mp make_pair
#define F first
#define S second
#define ll long long int
#define mod 1000000007
#define wh(a) cerr<<#a<<"  is  "<<a<<endl;
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t=1;
	
	cin>>t;
	while(t--){
		int n,i;
		cin>>n;
		int num[n];
		for(i=0;i<n;++i){
			cin>>num[i];
		}
		sort(num,num+n);
		int cur,max=0;
		for(i=0;i<n;++i){
			cur=MIN(num[i],n-i);
			if(cur>max){
				max=cur;
			}
		}
		cout<<max<<endl;
	}
	return 0;
}