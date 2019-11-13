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

char ar[1000];


vector<int> one;
vector<int> two;
vector<int> th;

int main()
{
    idfc;
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int a;
        int b,c;
        cin>>a>>b>>c;
        char e;
        int i;
        for(i=1;i<=n;i++)
        {
            ar[i]='0';
            cin>>e;
            if(e=='R')one.pb(i);
            else if(e=='P')two.pb(i);
            else th.pb(i);
        }
        int mid=ceil((n*1.0)/2);
        int ans=0;
        for(int ii:th)
        {
            if(a<=0)break;
            ar[ii]='R';
            a--;
            ans++;
        }
        for(int ii:one)
        {
            if(b<=0)break;
            ar[ii]='P'; b--;
            ans++;
        }
        for(int ii:two)
        {
            if(c<=0)break;
            ar[ii]='S';c--;
            ans++;
        }
        if(ans>=mid)
        {
            cout<<"YES\n";
            for(i=1;i<=n;i++)
            {
                if(ar[i]=='0')
                {
                    if(a)
                    {
                        cout<<"R";
                        a--;
                    }
                    else if(b)
                    {
                        cout<<"P";
                        b--;
                    }
                    else{
                        cout<<"S";c--;
                    }
                }
                else cout<<ar[i];
            }
            cout<<"\n";
        }
        else cout<<"NO\n";
        one.clear(); two.clear(); th.clear();
    }

    return 0;
}