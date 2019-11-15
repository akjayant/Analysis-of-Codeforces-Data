#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define U 998244353
#define N 1000005
#define int long long
#define sz(c) (int)c.size()
#define fr first
#define ll long long 
#define sc second
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define rep(i,a,n) for(int i=a ; i<n ; i++)
#define r0 return 0;
#define endl '\n'
#define INF (int)1e15
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	std::cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');std::cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
signed main()
{
	ios_base::sync_with_stdio(0);
	int TESTS=1;
	cin>>TESTS;
	while(TESTS--)
	{   
		int n;
		cin>>n;
		string s,t;
		cin>>s>>t;
		set<int> ss[26];
		set<int> ts[26];
		vector<pair<int,int>> seq;
		int freq[26]={};
		for(auto j:s) freq[j-'a']++;
		for(auto j:t) freq[j-'a']++;
		string sn=s,tn=t;
		rep(i,0,26){
			if(freq[i]%2){
				cout<<"No"<<endl;
				goto ou;
			}
		}
		rep(i,0,n){
			ss[s[i]-'a'].insert(i);
			ts[t[i]-'a'].insert(i);
		}
		rep(i,0,n){
			ss[s[i]-'a'].erase(i);
			ts[t[i]-'a'].erase(i);
			// trace(sz(seq),i,s,t);
			if(s[i]==t[i]){
				continue;
			}
			else{
				// trace(i);
				char a = s[i]-'a';
				char b = t[i]-'a';
				if(sz(ss[a])){
					// trace(i);
					seq.pb({*ss[a].begin(), i});
					swap(s[*ss[a].begin()], t[i]);
					ss[b].insert(*ss[a].begin());
					ss[a].erase(ss[a].begin());
					// trace(sz(ss[b]),b);
				}
				else if(sz(ts[b])){
					seq.pb({i, *ts[b].begin()});
					swap(s[i], t[*ts[b].begin()]);
					ts[a].insert(*ts[b].begin());
					ts[b].erase(ts[b].begin());
				}
				else if(sz(ss[b]) && sz(ts[a])){
					seq.pb({*ss[b].begin(), *ts[a].begin()});
					swap(s[*ss[b].begin()], t[*ts[a].begin()]);
					ss[a].insert(*ss[b].begin());
					ts[b].insert(*ts[a].begin());
					ss[b].erase(ss[b].begin());
					ts[a].erase(ts[a].begin());
					seq.pb({i, *ts[b].begin()});
					swap(s[i], t[*ts[b].begin()]);
					ts[a].insert(*ts[b].begin());
					ts[b].erase(ts[b].begin());
				}
				else{
					cout<<"No"<<endl;
					goto ou;
				}
			}
		}
		cout<<"Yes"<<endl;
		cout<<sz(seq)<<endl;
		for(auto j:seq) cout<<j.fr+1<<" "<<j.sc+1<<endl;
		ou:;
	}   
}     