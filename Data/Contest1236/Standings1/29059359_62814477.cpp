#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define mod 1000000007
#define int long long
#define ll long long
#define EPS 0.00000000000001
#define ld long double
#define inf 1000000
#define N 100001

int n,m,k;
int total = 0;
vector<int> mr[N];
vector<int> ml[N];
vector<int> mu[N];
vector<int> md[N];
int rb,lb,ub,db;

void print_ans()
{
	if(total == 0)
		cout << "Yes";
	else
		cout << "No";
	exit(0);
}
pair<int,int> move_right(int x,int y)
{
	vector<int>::iterator it = lower_bound(mr[x].begin(),mr[x].end(),y);
	if(it == mr[x].end() or *it > rb)
		return {x,rb};
	else
		return {x,*it - 1};
}
pair<int,int> move_left(int x,int y)
{
	vector<int>::iterator it = lower_bound(ml[x].begin(),ml[x].end(),y);
	if(it == ml[x].begin() or ml[x].size() == 0)
		return {x,lb};
	else
	{
		it--;
		if(*it < lb)
			return {x,lb};
		else
			return {x,*it + 1};
	}
}
pair<int,int> move_down(int x,int y)
{
	vector<int>::iterator it = lower_bound(md[y].begin(),md[y].end(),x);
	if(it == md[y].end() or *it > db)
		return {db,y};
	else
		return {*it - 1,y};
}
pair<int,int> move_up(int x,int y)
{
	vector<int>::iterator it = lower_bound(mu[y].begin(),mu[y].end(),x);
	if(it == mu[y].begin() or mu[y].size() == 0)
		return {ub,y};
	else
	{
		it--;
		if(*it < ub)
			return {ub,y};
		else
			return {*it + 1,y};
	}
}

int32_t main()
{
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("int.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif

  	cin >> n >> m >> k;
  	if(k == 0)
  	{
  		cout << "Yes";
  		return 0;
  	}
  	vector<pair<int,int>> v(k);
  	map<pair<int,int>,int> ex;
  	for(int i = 0;i < k;i++)
  	{

  		cin >> v[i].first >> v[i].second;
  		mu[v[i].second].push_back(v[i].first);
  		md[v[i].second].push_back(v[i].first);
  		mr[v[i].first].push_back(v[i].second);
  		ml[v[i].first].push_back(v[i].second);
  		ex[{v[i].first,v[i].second}] = 1;
  	}
  	for(int i = 1;i <= m;i++)
  	{
  		sort(mu[i].begin(),mu[i].end());
  		sort(md[i].begin(),md[i].end());
  	}
  	for(int i = 1;i <= n;i++)
  	{
  		sort(mr[i].begin(),mr[i].end());
  		sort(ml[i].begin(),ml[i].end());
  	}

  	rb = m;
  	lb = 1;
  	ub = 2;
  	db = n;
  	total = n*m - k;
  	int curx = 1;
  	int cury = 1;
  	while(1)
  	{
  		pair<int,int> pos = move_right(curx,cury);
  		total -= (pos.second - cury + 1);
  		curx = pos.first;
  		cury = pos.second;
  		rb = min(rb,cury - 1);
  		curx++;
  		// cerr << curx << " " << cury << " " << total << endl;

  		if(curx > db or ex[{curx,cury}])
  			print_ans();
  		pos = move_down(curx,cury);
  		total -= (pos.first - curx + 1);
  		curx = pos.first;
  		cury = pos.second;
  		db = min(db,curx - 1);
  		cury--;
  		if(cury < lb or ex[{curx,cury}])
  			print_ans();
  		// cerr << curx << " " << cury << " " << total << endl;

  		pos = move_left(curx,cury);
  		total -= (cury - pos.second + 1);
  		curx = pos.first;
  		cury = pos.second;
  		lb = max(lb,cury + 1);
  		curx--;
  		// cerr << curx << " " << cury << " " << total << endl;
  		if(curx < ub or ex[{curx,cury}])
  			print_ans();
  		

  		pos = move_up(curx,cury);
  		total -= (curx - pos.first + 1);
  		curx = pos.first;
  		cury = pos.second;
  		ub = max(ub,curx + 1);
  		cury++;
  		// cerr << curx << " " << cury << " " << total << endl;
  		if(cury > rb or ex[{curx,cury}])
  			print_ans();

  	}

  
  	

    return 0;
}
 
 