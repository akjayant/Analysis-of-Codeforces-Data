
// Created by RUPESH
// From https://blog.codingblocks.com/2019/setting-up-a-c-competitive-programming-environment

#include <bits/stdc++.h>


using namespace std;
using ll = long long;

#define pii pair<ll,ll>

ll n;
ll X[2000];
ll Y[2000];
ll C[2000];
ll K[2000];

ll Conn[2000][2000];
ll station;
ll connection;
ll answer[2000];
ll cost;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	priority_queue<pii , vector<pii>, greater<pii>> pq;
	for (ll i = 0; i < n; ++i)
	{
		cin >> X[i] >> Y[i];
	}
	for (ll i = 0; i < n; ++i)
	{
		cin >> C[i];
		pq.push(make_pair(C[i] , i));
	}
	for (ll i = 0; i < n; ++i)
	{
		cin >> K[i];
	}

	for (ll i = 0; i < n; ++i)
	{
		for (ll j = 0; j < n; ++j)
		{
			Conn[i][j] = (K[i] + K[j]) * (abs(X[i] - X[j]) + abs(Y[i] - Y[j]));
		}
	}
	// sort(v.begin(),v.end());

	station = 0;
	for (ll i = 0; i < n; ++i)
	{
		answer[i] = -2;
	}
	// station ++;
	pii tp;
	// tp = pq.top()
	// answer[tp.second] = -1;
	// cost += tp.first;

	while(!pq.empty()){
		tp = pq.top();
		pq.pop();
		if (answer[tp.second] == -2)
		{
		// cout << tp.first << " " << tp.second << endl;
			cost += tp.first;
			if(tp.first == C[tp.second]){
				station++;
				answer[tp.second] = -1;
			}
			else{
				connection++;
				for (int i = 0; i < n; ++i)
				{
					if((Conn[i][tp.second] == tp.first) && (answer[i] != -2) && ( i != tp.second)){
						answer[tp.second] = i;
						break;
					}
				}
			}
			for (int i = 0; i < n; ++i)
			{
				if(answer[i] == -2){
					pq.push(make_pair(Conn[i][tp.second] , i) );
				}
			}
		}
	}



	cout << cost << endl;
	cout << station << endl;
	for (int i = 0; i < n; ++i)
	{
		if(answer[i] == -1) cout << i+1 << " ";
	}
	cout << endl;
	cout << connection << endl;
	for (int i = 0; i < n; ++i)
	{
		if (answer[i] != -1)
		{
			cout << i+1 << " " << answer[i]+1 << endl; 
		}
	}


	return 0;
}