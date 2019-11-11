#include<bits/stdc++.h>
using namespace std;
#define M 100005
#define MOD 1000000007

int fib[M];

int main()
{
    fib[0] = fib[1] = 1;
    for(int i = 2; i < M; i++) fib[i] = (fib[i-1]+fib[i-2])%MOD;

    string s;
    cin>>s;

    int ans = 1;

    int i = 0;
    while(i < s.size())
    {
        if(s[i] == 'm' || s[i] == 'w')
        {
            ans = 0;
            break;
        }

        if(s[i] != 'n' && s[i] != 'u') i++;
        else
        {
            int j = i;
            while(j < s.size() && s[j] == s[i]) j++;

            ans = (1LL*ans*fib[j-i])%MOD;
            i = j;
        }
    }

    cout<<ans<<endl;

    return 0;
}
