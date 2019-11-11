#include <bits/stdc++.h>
#define DIM 100007
#define INF 1000000007
using namespace std;

long long n,d[DIM],res=1;
string s;
long long cnt[DIM];
int main()
{
    string s;
    cin>>s;
    d[0] = 1;
    d[1] = 1;
    for(int i = 2; i <= s.size(); ++i)
        {d[i] = d[i-1]+d[i-2];d[i]%=INF;}
    for(int i = 0; i < s.size(); ++i)
    {
        int j = i;
        if(s[i] == 'n')
        {
            while(s[j+1]=='n'&& j < s.size()-1) j++;
        }
        else if(s[i]=='u')
        {
            while(s[j+1]=='u' && j < s.size()-1) j++;
        }
        else if(s[i] == 'm' || s[i] == 'W') {res = 0;break;}
        else continue;
        int k = j-i+1;

        long long g = k;

        res*=d[g];
        res%=INF;
        i = j;

    }
    cout<<res;
    return 0;
}
