#include<bits/stdc++.h>
using namespace std;


int gcd(int x, int y)
{	
	int z = y;
	while(x%y!=0)
	{
		z = x%y;
		x = y;
		y = z;	
	}
	return z;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        if(gcd(a ,b) == 1) cout << "Finite" << endl;
        else cout << "Infinite" << endl;
    }
    return 0;
}