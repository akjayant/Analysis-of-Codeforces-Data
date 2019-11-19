#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 1e5 + 1;


const long long INF = 1e18;

vector <long long> order;


vector <long long> g[MAXN];



void dfs(long long v, long long prev = -1){

	order.push_back(v);

	for(long long to : g[v]){
		if(to != prev){
			dfs(to, v);
		}
	}
}




int main(){

	long long n; cin >> n;


	vector < vector <long long> > c(n, vector <long long>(3));


	for(long long i = 0; i < n; i++){
		cin >> c[i][0];
	}

	for(long long i = 0; i < n; i++){
		cin >> c[i][1];
	}

	for(long long i = 0; i < n; i++){
		cin >> c[i][2];
	}




	// if(n == 1){
	// 	cout << min(c[0][0], min(c[0][1], c[0][2])) << endl;

	// }

	vector <long long> deg(n);


	long long a, b;
	for(long long i = 0; i < n - 1; i++){
		cin >> a >> b;
		a--; b--;
		deg[a]++;
		deg[b]++;

		g[a].push_back(b);
		g[b].push_back(a);
	}


	for(long long i = 0; i < n; i++){
		if(deg[i] > 2){
			cout << -1 << endl; return 0;
		}
	}

	for(long long i = 0; i < n; i++){
		if(deg[i] == 1 or deg[i] == 0){
			dfs(i); break;
		}
	}


	vector <long long> v = {0, 1, 2}, pokraska = {0, 1, 2};

	long long record = INF;

	do{
		long long sum = 0;
		for(long long i = 0; i < n; i++){
			sum += c[order[i]][v[i % 3]];
		}


		if(sum < record){
			record = sum;
			pokraska = v;
		}
	}while(next_permutation(v.begin(), v.end()));


	vector <long long> ans(n);

	cout << record << endl;
	for(long long i = 0; i < n; i++){
		ans[order[i]] = pokraska[i % 3];
	}


	for(long long e : ans){
		cout << e + 1 << " ";
	}
	cout << endl;

	return 0;
}
