#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int mod = 1e9 + 7;
LL pos = 1;
const int N = 100010;
LL dp[N];

void prepare()
{
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for(int i = 4; i < N; i++) dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
}
int main()
{
    string msg;
    cin >> msg;
    prepare();
    for(int i = 0; i < msg.length(); i++)
    {
        if(msg[i] == 'w' || msg[i] == 'm')
        {
            cout << 0 << endl;
            return 0;
        }
        if(msg[i] == 'u' || msg[i] == 'n')
        {
            int j = i;
            while(msg[i] == msg[j]) j++;
            j--;
            pos = (pos % mod) * (dp[j - i + 1] % mod) % mod;
            i = j;
        }
    }
    cout << pos << endl;
    return 0;
}