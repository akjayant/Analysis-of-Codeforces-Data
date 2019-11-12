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
	int f[26]={};
	for(char c:s1)	f[c-'a']++;
	for(char c:s2)	f[c-'a']++;
	bool ok = true;
	for(int i=0;i<26;i++){
		if(f[i]%2 == 1){
			ok = false;
			break;
		}
	}
	if(!ok){
		cout<<"no\n";	continue;
	}
	cout<<"yes\n";
	vector<pii>v;
	for(int i=0;i<n;i++){
		if(s1[i] == s2[i]){
			continue;
		}
		for(int j=i+1;j<n;j++){
			if(s1[j] == s1[i]){
				v.pb(mp(j,i));	swap(s1[j],s2[i]);	break;
			}
			if(s2[j] == s1[i]){
				v.pb(mp(j,j));	swap(s1[j],s2[j]);
				v.pb(mp(j,i));	swap(s1[j],s2[i]);	break;
			}
		}
	}
	cout << v.size() << "\n";
	for(pii p:v){
		cout << p.ff+1<<" "<<p.ss+1<<"\n";
	}
}
}
