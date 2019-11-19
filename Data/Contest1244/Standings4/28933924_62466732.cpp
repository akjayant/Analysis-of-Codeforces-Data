#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 1005;
char str[MAXN];
int n;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
    	cin >> n;
        cin >> str+1;
		int lpos = 1<<30, rpos = 0;  
	    for(int i = 1; i<=n; i++)
	        if(str[i]=='1')
	            lpos = min(lpos,i), rpos = max(rpos,i);
	    if(!rpos)
	        cout << n << endl;
	    else
	        cout << 2*max(n-lpos+1,rpos) << endl;
	}
	return 0;
}
