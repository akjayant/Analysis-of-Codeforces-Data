// ConsoleApplication11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include<string>
#include <algorithm>
#include <vector>


using namespace std;
#define var auto
#define ll long long
#define endl '\n'

int upperd(int a, int b)
{
	if (a%b == 0)
		return a / b;
	else
		return a / b + 1;
}
ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a%b);
}

vector<vector<int>> graph;
vector<vector<ll>> weights;
vector<int> colors;
vector<int>result;
ll dfs(int cur, int from, int colorIdx)
{
	ll res = weights[colors[colorIdx]][cur];
	colorIdx++;
	colorIdx %= 3;
	for (auto a : graph[cur])
		if (a != from)
			res += dfs(a, cur, colorIdx);
	return res;
}

int startVert;
ll test(vector<int> curColors)
{
	colors = curColors;
	return dfs(startVert, -1, 0);
}

void doColor(int cur, int from, int colorIdx)
{
	result[cur] = colors[colorIdx];
	colorIdx++;
	colorIdx %= 3;
	for (auto a : graph[cur])
		if (a != from)
			doColor(a, cur, colorIdx);
}

void solve()
{
	/*
	ll n, p, w, d;
	cin >> n >> p >> d >> w;
	var md = p % w;
	int dCnt = 0;
	ll curd = 0;
	while (curd%w != md)
	{
		dCnt++;
		curd = (curd + d) % w;
	}
	n -= dCnt;
	p -= dCnt * d;
	if (n < 0 || p < 0)
	{
		cout << -1;
		return;
	}
	var c = w / gcd(d,w);
	var x = (p / (c*d))*c;
	dCnt += x;
	n -= x;
	p = p % (c*d);
	var wCnt = p / w;
	n -= wCnt;
	if (n < 0)
	{
		cout << -1;
	}
	else
	{
		cout << dCnt << " " << wCnt << " " << n;
	}*/
	int n;
	cin >> n;
	graph = vector<vector<int>>(n);
	weights = vector<vector<ll>>(3, vector<ll>(n));
	result = vector<int>(n);
	vector<int> steps = vector<int>(n,0);
	for(int i = 0; i < 3; ++i)
		for (int j = 0; j < n; ++j)
		{
			ll x;
			cin >> x;
			weights[i][j] = x;
		}
	for (int i = 0; i < n - 1; ++i)
	{
		int x, y;
		cin >> x >> y;
		--x;
		--y;
		graph[x].push_back(y);
		graph[y].push_back(x);
		steps[x]++;
		steps[y]++;
	}

	int oneCnt = 0;
	for (int i = 0 ; i < n ; ++i)
	{
		if (steps[i]== 1)
		{
			oneCnt++;
			startVert = i;
		}
		if (steps[i] > 2)
		{
			cout << -1;
			return;
		}
	}
	if (oneCnt > 2)
	{
		cout << -1;
		return;
	}

	ll curRes = 100000000000000000;

	vector<int> bestAnswer;

	vector<int> curAnswer = { 0, 1, 2 };
	var tres = test(curAnswer);
	if (tres < curRes)
	{
		curRes = tres;
		bestAnswer = curAnswer;
	}

	curAnswer = { 0, 2, 1 };
	tres = test(curAnswer);
	if (tres < curRes)
	{
		curRes = tres;
		bestAnswer = curAnswer;
	}

	curAnswer = { 1, 0, 2 };
	tres = test(curAnswer);
	if (tres < curRes)
	{
		curRes = tres;
		bestAnswer = curAnswer;
	}

	curAnswer = { 1, 2, 0 };
	tres = test(curAnswer);
	if (tres < curRes)
	{
		curRes = tres;
		bestAnswer = curAnswer;
	}

	curAnswer = { 2, 1, 0 };
	tres = test(curAnswer);
	if (tres < curRes)
	{
		curRes = tres;
		bestAnswer = curAnswer;
	}

	curAnswer = { 2, 0, 1 };
	tres = test(curAnswer);
	if (tres < curRes)
	{
		curRes = tres;
		bestAnswer = curAnswer;
	}
	colors = bestAnswer;
	doColor(startVert, -1, 0);
	cout << curRes << endl;
	for (auto a : result)
	{
		cout << a + 1 << " ";
	}
	cout << endl;
}
int main()
{
	int t=1;
	//cin >> t;
	for (int i = 0; i < t; ++i)
		solve();
}