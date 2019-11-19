#include <bits/stdc++.h>
using namespace std;
#define asp ""
#define aps ''
#define one 1
#define two 2
#define dif !=
typedef long long ll;
vector<int> g;
vector<int> f;


int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		g.push_back(a);
	}
	sort(g.begin(),g.end());

	int mini = n/two;

	ll suma=0;
	ll sumb = 0;

	for(int i=0;i<mini;i++){
		suma += g[i];
	}
	for(int i=mini;i<n;i++){
		sumb += g[i];
	}

	suma *= suma;
	sumb *= sumb;

	suma += sumb;
	cout << suma << endl;
}