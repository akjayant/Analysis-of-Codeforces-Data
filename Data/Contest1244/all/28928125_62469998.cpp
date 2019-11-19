#include<bits/stdc++.h>
#define ll long long
#define S second
#define F first

using namespace std;

const int N = 1e6+5;

char s[2000];

int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d\n%s", &n, s);
        bool chk = 0, ind1 = -1, ind2 = -1;
        int mx = n;
        for(int i = 0 ; i < n; i++)
        {
            if(s[i] & 1) mx = max(mx, max(i+1, n- i) * 2);
        }
        printf("%d\n", mx);
    }
}
