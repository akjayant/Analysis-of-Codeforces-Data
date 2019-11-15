#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi 2*acos(0.0)
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define gap ' '
#define mod 1000000007
#define INF 1000000000


int main()
{
    int t;

    cin>>t;

    while(t--)
    {
        int n;

        cin>>n;

        int ara[n+5];

        for(int i=0;i<n;i++)
        {
            cin>>ara[i];
        }

        sort(ara,ara+n);

        int baki=n;

        for(int i=0;i<n;i++)
        {
            if(ara[i]>=baki)
            {
                cout<<baki<<endl;
                break;
            }

            baki--;
        }

    }
}
