// ConsoleApplication11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
 
#include <iostream>
#include<string>
#include <algorithm>
 
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
	string str;
	cin >> str;
	int firstOne = -1;
	int lastOne = -1;
	for(int i = 0 ; i < n; ++i)
		if (str[i] == '1')
		{
			if (firstOne == -1)
				firstOne = i;
			lastOne = i;
		}
	if (firstOne == -1)
		cout << n << endl;
	else
	{
 
		int m = min(firstOne, n - 1 - lastOne);
		cout << 2 * n - 2 * m<<endl;
	}
}
int main()
{
	int t=1;
	cin >> t;
	for (int i = 0; i < t; ++i)
		solve();
}