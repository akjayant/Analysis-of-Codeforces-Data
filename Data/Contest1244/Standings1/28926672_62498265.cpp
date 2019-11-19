#include "bits/stdc++.h"
using namespace std;

const int MAXN = 2e5 + 5;

int n, k;
string s;
int stable[MAXN], p[MAXN];
vector<int> adj[MAXN];
bool unstable;

int main(){
	cin >> n >> k;
	cin >> s;
	memset(stable, -1, sizeof stable);
	for(int i = 0; i < n; ++i){
		if(s[(i-1+n)%n] == s[i] || s[(i+1)%n] == s[i]){
			stable[i] = 0;
			unstable = false;
		}
		adj[i].push_back((i-1+n)%n);
		adj[i].push_back((i+1)%n);
	}
	if(unstable){
		if(k%2 == 1)
		for(int i = 0; i < n; ++i){
			s[i] = (s[i] == 'W') ? 'B':'W';
		}
		cout << s << endl;
		return 0;
	}
	queue<int> q;
	for(int i = 0; i < n; ++i){
		if(stable[i] == 0)
			q.push(i);
	}
	while(!q.empty()){
		int top = q.front(); q.pop();
		for(int i : adj[top]) if(stable[i] == -1){
			stable[i] = stable[top]+1;
			p[i] = top;
			q.push(i);
		}
	}

	vector<int> lis;
	for(int i = 0; i < n; ++i) if(stable[i] > 0){
		lis.push_back(i);
	}
	sort(lis.begin(), lis.end(), [](int a, int b){return stable[a] < stable[b];});
	for(auto i : lis){
		if(stable[i] > k)
			break;
		s[i] = s[p[i]];
	}
	if(k%2 == 1)
	for(int i = 0; i < n; ++i){
		if(stable[i] > k){
			s[i] = (s[i] == 'W') ? 'B':'W';
		}
	}
	cout << s << endl;
}