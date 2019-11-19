/*input
3
3
1 3 2
2
0 3
1
1
1
1
1
2
1
1

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
	int n1,n2,x;
	cin>>n1;
	int o1=0,o2=0,e1=0,e2=0;
	while(n1--){
		cin>>x;
		o1+=(x%2);
		e1+=(!(x%2));
	}
	cin>>n2;
	while(n2--){
		cin>>x;
		o2+=(x%2);
		e2+=(!(x%2));
	}
	cout << o1*o2+e1*e2<<"\n";
}
}
