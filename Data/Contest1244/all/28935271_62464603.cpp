// ConsoleApplication11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
#define var auto
#define ll long long;

int upperd(int a, int b)
{
	if (a%b == 0)
		return a / b;
	else
		return a / b + 1;
}
void solve()
{
	int a, b, c, d, k;
	cin >> a >> b >> c >> d >> k;
	int x = upperd(a, c);
	int y = upperd(b, d);
	if (x + y <= k)
	{
		cout << x << " " << y<<endl;
	}
	else
		cout << -1 << endl;
}
int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		solve();
}