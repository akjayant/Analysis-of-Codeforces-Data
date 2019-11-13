#include<bits/stdc++.h>
typedef long long ll;

#define pb push_back
#define mp make_pair
#define mem(x) memset(x,0,sizeof(x))
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        int g = __gcd(a,b);
        if(g==1)
            cout<<"Finite\n";
        else
            cout<<"Infinite\n";
    }
    return 0;
    
}