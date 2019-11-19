#include <bits/stdc++.h>

using namespace std;

#define int long long

const int DIM = 2007;

int c[DIM];
int k[DIM];

struct muchie
{
	int x, y, cost;
};

vector <int> t;
pair <int, int> v[DIM];

struct cmp
{
	bool operator() (muchie a, muchie b)
	{
		return a.cost > b.cost;
	}
};

bool cmp2(int x, int y)
{
	return c[x] < c[y];
}

priority_queue <muchie, vector <muchie>, cmp> pq;

bitset <DIM> vis;

int n;

int get(int a, int b)
{
	int dist = abs(v[a].first - v[b].first) + abs(v[a].second - v[b].second);
	
	dist *= (k[a] + k[b]);
	
	return dist;
}

void baga(int nod)
{
	vis[nod] = true;
	
	for(int i = 1; i <= n; i++)
		if(vis[i] == false)
			pq.push(muchie{nod, i, get(nod, i)});
}

main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> v[i].first >> v[i].second;
		
		t.push_back(i);
	}
	
	for(int i = 1; i <= n; i++)
		cin >> c[i];
	
	for(int i = 1; i <= n; i++)
		cin >> k[i];
	
	sort(t.begin(), t.end(), cmp2);
	
	int start = t[0];
	int pos = 1;
	
	baga(start);
	
	int res = c[start];
	
	vector <int> statie;
	vector <pair <int, int> >  fir;

	statie.push_back(start);

	while(pos < n)
	{
		while(pos < n && vis[t[pos]] == true)
			pos++;
		
		if(pos >= n)
			break;
		
		int nod1;
		int nod2;
		int cost;
		
		if(!pq.empty())
		{
			nod1 = pq.top().x;
			nod2 = pq.top().y;
			cost = pq.top().cost;
			
			if(vis[nod2] == true)
			{
				pq.pop();
				continue;
			}
		}
		
		if(pq.empty() == true || cost > c[t[pos]])
		{
			int nod = t[pos];
			
			baga(nod);
			
			res += c[nod];
			statie.push_back(nod);
			
			pos++;
		}
		else
		{
			res += cost;
			
			baga(nod2);
			
			fir.push_back({nod1, nod2});
		}
	}
	
	cout << res << '\n';
	
	cout << statie.size() << '\n';
	
	for(auto i : statie)
		cout << i << ' ';
	
	cout << '\n';
	
	cout << fir.size() << '\n';
	
	for(auto i : fir)
		cout << i.first << ' ' << i.second << '\n';
}