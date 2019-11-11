#include <bits/stdc++.h>
using namespace std;
#define idfc ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#define ll long long
#define pb push_back
#define mp make_pair
#define nt _int128
#define ld long double
long double PI =3.14159265358979323846;


const ll modo=1e8;
const ll inf=1e15;
const ll ms=(1e5) +5;

int main()
{
    idfc;
    int t;
    cin>>t;
    while (t--)
    {
        int a;
        int b;
        cin>>a>>b;
        int gc=__gcd(a,b);
        if(gc==1)
        {
            cout<<"Finite\n";
        }
        else cout<<"Infinite\n";
    }

    return 0;
}