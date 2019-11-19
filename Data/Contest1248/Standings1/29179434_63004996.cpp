#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <array>
#include <memory.h>
#include <memory>

using namespace std;

#define MODP 1000000007


int main()
{
	int n;
	cin >> n;

	string s;
	cin >> s;
	vector<int> co(n+1);

	int md = 0;
	int ind = 0;
	for(int i = 0; i<n; i++)
	{
		if(s[i] == '(')
			co[i+1] = co[i] + 1;
		else
			co[i+1] = co[i];
		if(co[i+1] - (1+i-co[i+1]) < md)
		{
			md = co[i+1] - (1+i-co[i+1]);
			ind = i+1;
		}
	}

	if(co[n] != n/2)
	{
		cout << 0 << endl;
		cout << "1 1" << endl;
		return 0;
	}

	co[0] = 0;
	int so = 0;
	int so1 = 0;
	int ne = 0;
	int nd = 0;
	int nem = 1;
	int i1 = 0,i2 = 0;
	int cnt0 = 0;
	for(int i = 0; i<n; i++)
	{
		if(s[(i+ind)%n] == '(')
			co[i+1] = co[i] + 1;
		else
			co[i+1] = co[i];
		if(co[i+1] - (1+i-co[i+1]) == 0)
			cnt0++;
	}
	for(int i = 0; i<n; i++)
	{
		if(co[i+1] - (1+i-co[i+1]) == 0)
		{
			if(ne > nem + cnt0 - 1)
			{
				nem = ne - cnt0 + 1;
				i1 = so;
				i2 = i;
			}
			so = i+1;
			ne = 0;
		}
		if(co[i+1] - (1+i-co[i+1]) == 1)
		{
			if(nd+1 > nem)
			{
				nem = nd+1;
				i1 = so1;
				i2 = i;
			}
			ne++;
			nd = 0;
			so1 = i+1;
		}
		if(co[i+1] - (1+i-co[i+1]) == 2)
		{
			nd++;
		}
	}

	if(nem == 0)
	{
		cout << cnt0 << endl;
		cout << (i1+ind)%n+1 << " " << (i2+ind)%n+1 << endl;
	}

	cout << cnt0 + nem - 1 << endl;
	cout << (i1+ind)%n+1 << " " << (i2+ind)%n+1 << endl;
	return 0;
}