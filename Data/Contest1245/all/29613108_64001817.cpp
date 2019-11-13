#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN = 5e4 + 5;

bool color[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while(T--)
    {
        int a, b;
        cin >> a >> b;

        if(a==1 || b==1) cout << "Finite" << '\n';
        else
        {
            if(__gcd(a, b)==1) cout << "Finite" << '\n';
            else cout << "Infinite" << '\n';
        }
    }
}
