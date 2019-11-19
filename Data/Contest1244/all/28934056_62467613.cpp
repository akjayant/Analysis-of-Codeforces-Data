#include <bits/stdc++.h>
#define ll long long
#define pet pair<int,int>
#define one first
#define two second
using namespace std;

void solvetest()
{
	int n;
    string s;
    cin >> n >> s;

    int first=n-1;

    while(first>=0 && s[first]=='0')
    first--;

    if(first==-1)
    {
        cout << n << endl;
        return;
    }

    int last=0;

    while(last<=n && s[last]=='0')
    last++;

    if(first+1>n-last)
    cout << 2*(first+1) << endl;

    else 
    cout << 2*(n-last) << endl;
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