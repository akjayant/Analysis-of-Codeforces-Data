#include <bits/stdc++.h>

#define pb push_back
#define ll long long
#define ull unsigned long long
#define stop return cout << -1 << endl, false;

using namespace std;

int niz[262146];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin>>t;

    while(t--)
    {
        int n, razl=0;
        cin>>n;
        char a[10001], b[10001];
        int i1=-1, i2=-1;
        for(int i=0;i!=n;i++) cin>>a[i];
        for(int i=0;i!=n;i++)
        {
            cin>>b[i];
            if(b[i]!=a[i])
            {
                razl++;
                if(i1==-1)i1 = i;
                else i2=i;
            }
        }

        if(razl != 2) cout<<"No"<<endl;
        else
        {
            if(a[i1]==a[i2] && b[i1]==b[i2]) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }



    return 0;
}
