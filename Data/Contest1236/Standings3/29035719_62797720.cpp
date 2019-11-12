#include <bits/stdc++.h>
#define forn(i,n) for(int i=0; i<n; i++)
#define pb push_back
#define ll long long int
#define mp make_pair
#define sz(arr) (ll)arr.size()
#define MOD 1000000007

using namespace std;

int main(){
	int n;
	cin>>n;
	vector< vector<int> > arr(n);
	int cnt=0;
	int val=1;
	
	while (true){
		if (cnt<n){
			forn(i,n){
				arr[i].pb(val);
				val++;
			}
			cnt++;
		}
		else break;
		if (cnt<n){
			forn(i,n){
				arr[n-i-1].pb(val);
				val++;
			}
			cnt++;
		}
		else break;
	}
		
	forn(i,n){
		forn(j,n){
			cout<<arr[i][j]<<" ";
		}
		cout<<"\n";
	}
}
