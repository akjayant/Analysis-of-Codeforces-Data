/*input
4
5
souse
houhe
3
cat
dog
2
aa
az
3
abc
bca

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
	string s1,s2;
	cin >> s1 >> s2;
	vi v;
	for(int i=0;i<n;i++){
		if(s1[i] != s2[i])	v.pb(i);
	}
	int x = v.size();
	if(x == 0){
		cout << "yes\n";	continue;
	}
	if(x >2){
		cout<<"no\n";	continue;
	}
	if(x == 1){
		cout << "no\n";
	}
	else{
		swap(s1[v[0]],s2[v[1]]);
		if(s1 == s2){
			cout<<"yes\n";
		}
		else{
			cout<<"no\n";
		}
	}

}
}
