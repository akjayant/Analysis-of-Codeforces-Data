#include <bits/stdc++.h>

using namespace std;


#define int long long


void solve(){

	int n; cin >> n;

	vector <int> x(n), y(n), k(n), c(n);

	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
	}


	for(int i = 0; i < n; i++){
		cin >> c[i];
	}


	for(int i = 0; i < n; i++){
		cin >> k[i];
	}


	vector < vector <int> > g(n, vector <int> (n));


	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			g[i][j] = (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]));
			g[j][i] = g[i][j];
		}
	}

	vector < pair <int, pair <int ,int> > > edges; // вес - вершина 1 - вершина 2

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i != j){
				
					edges.emplace_back(g[i][j], make_pair(i, j));
				
			}
		}
	}


	int m = edges.size();
	

	int cost = 0;

	vector < pair <int, int> > res;

	sort (edges.begin(), edges.end());

	vector <int> tree_id(n), cheapest(n);

	for (int i = 0; i < n; ++i){
		cheapest[i] = c[i];
		tree_id[i] = i;
	}

	for (int i = 0; i < m; ++i)
	{
		int a = edges[i].second.first,  b = edges[i].second.second,  l = edges[i].first;

		if(l >= max(cheapest[a], cheapest[b])){
			continue;
		}

		if (tree_id[a] != tree_id[b])
		{

			int obwag = 1e18;
			for (int j = 0; j < n; ++j){
				if (tree_id[j] == tree_id[a] or tree_id[j] == tree_id[b]){
					obwag = min(obwag, c[j]);
				}
			}

			for (int j = 0; j < n; ++j){
				if (tree_id[j] == tree_id[a] or tree_id[j] == tree_id[b]){
					cheapest[j] = obwag;
				}
			}

			cost += l;
			res.push_back (make_pair(a, b));
			int old_id = tree_id[b],  new_id = tree_id[a];
			for (int j = 0; j < n; ++j){
				if (tree_id[j] == old_id){
					tree_id[j] = new_id;
				}
			}
		}
	}

	map <int, vector <int> > mapik;

	for(int i = 0; i < n; i++){
		mapik[tree_id[i]].push_back(i);
	}


	// for(int i = 0; i < n; i++){
	// 	for(int j = 0; j < n; j++){
	// 		cout << g[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	

	vector <int> ans1(mapik.size());

	int current = 0;
	for(auto &it : mapik){
		int record = 1e18;

		for(int j = 0; j < it.second.size(); j++){
			int t = it.second[j];
			if(record > c[t]){
				record = c[t];
				ans1[current] = t;
			}
		}

		cost += record;
		current++;
	}


	cout << cost << endl;

	cout << mapik.size() << endl;

	for(int i = 0; i < ans1.size(); i++){
		cout << ans1[i] + 1 << " ";
	}
	cout << endl;


	assert(n - mapik.size() == res.size());

	cout << res.size() << endl;

	for(int i = 0; i < res.size(); i++){
		cout << res[i].first + 1 << " " << res[i].second + 1 << endl;
	}


}


main(){


	int test = 1;

	while(test--){
		solve();
	}



	return 0;
}


