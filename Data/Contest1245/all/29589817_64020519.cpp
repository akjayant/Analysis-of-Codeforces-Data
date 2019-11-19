#include<bits/stdc++.h>
#define pb           push_back
#define pii          pair<int,int>
#define vi           vector<int>
#define vpii         vector<pair<int,int>>
#define gph          map<int, vector<int>>
#define mp           make_pair
#define FOR(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD0(i, n) for (int i = (int)n; i >= 0; i--)
#define FORD1(i, n) for (int i = (int)n; i >= 1; i--)
#define FORS(i, n) for(; i < (int)(n); i++)
#define debug(X) { cout << #X << " = " << (X) << endl; }
#define printArr(A,n) { cout << #A << " = "; FOR(i,n) cout << A[i] << ' '; cout << endl; }
using namespace std;
#define int long long int

#define mod (int)1e9 + 7
vector<int> lenCost, cost;
vector<pii> cities;
int ans =0;
vector<pii> edges;
vector<int> pS;
int n;
int dis(int i , int j){
    return abs(cities[i].first - cities[j].first) + abs(cities[i].second - cities[j].second);
}
void dij(){
	priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    FOR(i, n){
        pq.push(mp(cost[i], i));
    }
    vector<bool> visited(cities.size());
    vector<int> parent(cities.size());
    vector<int> minCost(cities.size());
    FOR(i, n)parent[i] = -1;
    FOR(i, n)minCost[i] = cost[i];
	while(!pq.empty()){
		pair<int, int> cur = pq.top();
        int cit = cur.second;
		pq.pop();
		if(visited[cur.second])continue;
		visited[cur.second] = true;
        ans += cur.first;
        if(parent[cur.second] != -1){
            edges.pb(mp(cur.second, parent[cur.second]));
        }else pS.pb(cur.second);
	   FOR(i, n){	
            int temp  = (lenCost[i] + lenCost[cur.second])*(dis(i, cur.second));
			if(!visited[i] && minCost[i] > temp){
                minCost[i] = temp;
                parent[i] = cur.second;
                pq.push(mp(temp, i));
			}
		}
	}
}


signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    cin >> n;
    cities.resize(n);
    cost.resize(n);
    lenCost.resize(n);
    FOR(i, n)cin >> cities[i].first >> cities[i].second;
    FOR(i, n)cin >> cost[i];
    FOR(i, n)cin >> lenCost[i];

    dij();
    cout << ans <<endl;
    cout << pS.size() <<endl;
    for(int x: pS)cout << x + 1 << " ";
    cout <<endl;
    cout << edges.size() << endl;
    for(auto x: edges){
        cout << x.first + 1 << " " << x.second + 1 << endl;

    }
}


