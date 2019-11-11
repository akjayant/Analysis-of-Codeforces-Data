#include <iostream>
using namespace std;
int f[200000];
int test,u,v;
void xuli(int x,int y){
    for (int i = 1; i <= y; i++)
		{
			int k = (x*i) % y;
			if (f[k] != v)
				u++;
			f[k] = v;
		}
		if (u != y) cout << "Infinite" << endl;
		else cout << "Finite" << endl;
}
int main()
{
    cin>>test;
	while (test--)
	{
		u = 0;
		v++;
		int x, y;
		cin >> x >> y;
		xuli(x,y);
	}
}

