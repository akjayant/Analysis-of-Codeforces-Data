/*input
64
*/
#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define MAX 100005
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define mii map<int,int>
#define vi vector<int>
#define ff first
#define ss second
#define T int t;cin>>t;while(t--)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define umi unordered_map<int,int>
#define maxheap priority_queue<int>
#define minheap priority_queue<int,vector<int>,greater<int> >
#define inp(n) for(int i=0;i<n;i++)
#define N 2000005

using namespace std;
using namespace std::chrono;

bool isprime(int n){
	if(n<=1)	return false;
	for(int i=2;i*i<=n;i++){
		if(n%i==0)	return false;
	}
	return true;
}
signed main(){
	int n;
	cin >> n;
	int ans = n;
	for(int i=2;i*i<=n;i++){
		if(n%i == 0){
			ans = i;	break;
		}
	}
	if(ans == n){
		cout << n << "\n";	return 0;
	}
	while(n > 1){
		if(n%ans != 0){
			cout << "1\n";	return 0;
		}
		n/=ans;
	}
	cout << ans << "\n";
}
