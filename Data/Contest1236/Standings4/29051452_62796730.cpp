#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
 
using namespace std;
using namespace __gnu_pbds;     
 
#define vi vector
#define pb push_back
#define ll long long int
/*
#define pii pair< int, int>
#define ff  first
#define ss  second
#define sort(a)	sort(a.begin(),a.end())
#define rev(a)	reverse(a.begin(),a.end())
#define fo(i,a,b)	for( ll i=a; i<b; i++)
#define Fo(i,a,b)	for( ll i=a; i<=b; i++)
#define rfo(i,a,b)	for( ll i=a; i>b; i--)
#define rFo(i,a,b)	for( ll i=a; i>=b; i--)
*/
#define fio	ios_base::sync_with_stdio(), cin.tie(0), cout.tie(0)
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

int main(){		
 
	fio;

	int n;
	cin >> n;
	
	deque<int> dq[n+1];
	
	for( int i=1, val=1; i<=n; val=val+n,i++){
		for( int j=0; j<n; j++){
			dq[i].pb(val+j);
		}
	}
		
	for( int i=0; i<n; i++){
		int c=0;
		for( int j=n; j>=1; j--){
			if(c%2==0){
				cout << dq[j].back() << " ";
				dq[j].pop_back();
			}else{
				cout << dq[j].front() << " ";
				dq[j].pop_front();
			}
			c++;
		}
		cout << "\n";
	}

	return 0;
}