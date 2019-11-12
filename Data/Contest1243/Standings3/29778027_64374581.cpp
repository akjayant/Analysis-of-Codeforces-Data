#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pop pop_back
#define ll long long
#define fr first
#define sc second
#define inf 180000000;
#define FASTIOS ios_base::sync_with_stdio(false);  cin.tie(NULL);cout.tie(NULL);
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
#define sz(a) int((a).size())
ll n,m,i,j,k,t,ans;
ll arr[1500];
int main(){
	FASTIOS
	cin >> t;
	while(t--){
	cin >> n;
	for(i=1;i<=n;i++)
	cin >> arr[i];
	sort(arr+1,arr+n+1);
	reverse(arr+1,arr+n+1);
	j=0;
	for(i=1;i<=n;i++)
		if(arr[i]>=i) j=i;
	cout << j << '\n';
}
}