#include<iostream>
#include<cstring>
#include<algorithm>
#define mod 1000000007
using namespace std;

int n, qz[501];
string s;
void c()
{
    for(int i = 0; i < s.size(); i ++)
    {
        if(s[i] == '(')
            qz[i + 1] = qz[i] + 1;
        else
            qz[i + 1] = qz[i] - 1;
     }
}
int ans = 0, a1, a2;
int ci()
{
    int mini = 9999, an = 0;
    for(int i = 1; i <= n; i ++)
        mini = min(mini, qz[i] );
    for(int i = 1; i <= n; i ++)
        if(mini == qz[i] )
            an ++;
    if(mini > 0)
        return 0;
    return an;
}
int main()
{
    cin >> n;
    cin >> s;
    c(); int y = ci();
    if(qz[n] != 0)
    {
        cout << 0 << endl << 1 << ' ' << 1 << endl;
        return 0;
    }
    if(ans < y){ans = y; a1 = 1, a2 = 1;}
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j ++)
        {
            swap(s[i], s[j]);c();
            int y = ci();
            if(ans < y){ans = y; a1 = i, a2 = j;}
            swap(s[j], s[i] );
        }
    cout << ans << endl << a1 + 1 << " " << a2 + 1 << endl;
}