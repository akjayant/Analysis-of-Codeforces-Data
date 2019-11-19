#include <bits/stdc++.h>
#define ll long long
#define pet pair<int,int>
#define one first
#define two second
using namespace std;

void solvetest()
{
	int a,b,c,d,k;
    cin >> a >> b >> c >> d >> k;

    int a1=(a-1)/c+1;
    int b1=(b-1)/d+1;

    if(a1+b1<=k)
    cout << a1 << ' ' << b1 << endl;

    else cout << -1 << endl;
}

int main()
{
	int t=1;
	cin >> t;
	
	while(t--)
	{
		solvetest();
	}
}