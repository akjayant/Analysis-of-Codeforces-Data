/*input
4
5
4 3 1 4 5
4
4 4 4 4
3
1 1 1
5
5 5 1 1 5
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


signed main(){
T{
	int n;
	cin >> n;
	vi v(n);
	loop(i,0,n)	cin>>v[i];
	sort(v.begin(), v.end());
	int ans = 0;
	for(int i=0;i<n;i++){
		ans = max(ans,min(n-i,v[i]));
	}
	cout << ans << "\n";
}
}
