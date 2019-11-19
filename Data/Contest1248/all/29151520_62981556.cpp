/*input
4
1 1 2 2
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
int n,sum=0,sum2 = 0;
cin>>n;
vi v(n);
loop(i,0,n){
	cin>>v[i];
	sum += v[i];
}
sort(v.begin(), v.end());
loop(i,0,n/2)	sum2+=v[i];
sum-=sum2;
cout << sum*sum + sum2*sum2 << "\n";
}
