#include<bits/stdc++.h>

using namespace std;

#define sp << " " <<
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define int long long
#define double long double
#define INF 1e18
#define PI 3.14159265359

int power(int p,int y)
{
    int res=1;
    p=p%mod;
    while(y>0)
    {
        if(y&1)
            res=(res*p)%mod;
        y=y>>1;
        p=(p*p)%mod;
    }
    return res;
}

/*
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int dice()
{
    uniform_int_distribution<int> uid(0,1);//specify l and r.
    return uid(rng) ;
}

int read()
{
       int cc = getc(stdin);
       for (;cc < '0' || cc > '9';)  cc = getc(stdin);
       int dp = 0;
       for (;cc >= '0' && cc <= '9';)
       {
          dp = dp * 10 + cc - '0';
          cc = getc(stdin);
       }
      return dp;
}

inline void print(int n)
{
  if (n == 0)
  {
    putchar('0');
    putchar('\n');
  }
  else if (n == -1)
  {
    putchar('-');
    putchar('1');
    putchar('\n');
  }
  else
  {
    char buf[20];
    buf[19] = '\n';
    int i = 18;
    while (n)
    {
      buf[i--] = n % 10 + '0';
      n /= 10;
    }
    while (buf[i] != '\n')
      putchar(buf[++i]);
  }
}

int n;

vector<vector<int>> mat_mul(vector<vector<int>> a,vector<vector<int>> b)
{
	vector<vector<int>> t(n,vector<int>(n,0));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				t[i][j]+=((a[i][k]*b[k][j])%mod);
				t[i][j]%=mod;
			}
		}
	}
	return t;
}

vector<vector<int>> pow_mat(vector<vector<int>> mat_a,int p)
{
	if(p==1)
        return mat_a;
	vector<vector<int>> temp=pow_mat(mat_a,p/2);
	vector<vector<int>> res=mat_mul(temp,temp);
	if(p&1)
        res=mat_mul(res,mat_a);
	return res;
}
*/

vector<int> parent, r;

void make_set(int v) {
    parent[v] = v;
    r[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (r[a] < r[b])
            swap(a, b);
        parent[b] = a;
        if (r[a] == r[b])
            r[a]++;
    }
}

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

vector<Edge> edges;

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,h;
    cin >> n;
    h=n;
    pair<int,int> a[n+1];
    for(int i=1;i<n+1;i++)
        cin >> a[i].first >> a[i].second;
    int b[n+1],c[n+1];
    for(int i=1;i<n+1;i++)
    {
        cin >> b[i];
        Edge dp;
        dp.u=0;
        dp.v=i;
        dp.weight=b[i];
        edges.pb(dp);
    }
    for(int i=1;i<n+1;i++)
        cin >> c[i];
    for(int i=1;i<n+1;i++)
    {
        for(int j=i+1;j<n+1;j++)
        {
            Edge dp;
            dp.u=i;
            dp.v=j;
            dp.weight=(c[i]+c[j])*(abs(a[i].first-a[j].first)+abs(a[i].second-a[j].second));
            edges.pb(dp);
        }
    }
    int cost = 0;
    vector<pair<int,int>> result;
    n+=13;
    parent.resize(n);
    r.resize(n);
    for (int i = 0; i < n; i++)
        make_set(i);

    sort(edges.begin(), edges.end());
    for (Edge e : edges) {
        if (find_set(e.u) != find_set(e.v)) {
            cost += e.weight;
            result.push_back(mp(e.u,e.v));
            union_sets(e.u, e.v);
        }
    }
    n=result.size();
    int k=0;
    for(int i=0;i<n;i++)
    {
        if(result[i].first>result[i].second)
            swap(result[i].first,result[i].second);
        if(result[i].first==0)
            k++;
    }
    cout << cost << endl;
    cout << k << endl;
    for(int i=0;i<n;i++)
        if(result[i].first==0)
            cout << result[i].second << " ";
    cout << endl;
    cout << h-k << endl;
    for(int i=0;i<n;i++)
    {
        if(result[i].first!=0)
        {
            cout << result[i].first sp result[i].second << endl;
        }
    }
    return 0;
}
