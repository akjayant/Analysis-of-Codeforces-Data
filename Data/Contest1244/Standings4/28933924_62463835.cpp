#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;
typedef long long ll;
inline int f(int a, int b)
{
	if(a%b==0)
	    return a/b;
	return a/b+1;
}

int main()
{
    int a,b,c,d,k,t;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> c >> d >> k;
        if(f(a,c)+f(b,d)<=k)
            cout << f(a,c) << " " << f(b,d) << endl;
        else
            cout << -1 << endl;
	}   
	return 0;
}
