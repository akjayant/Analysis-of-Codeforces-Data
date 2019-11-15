#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
#define pi pair<int,int>
#define pc pair<char,int>
#define pii pair<int,pi>
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
vector <pi> v;
int main()
{
    go;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        bool yes=1;
        bool now=0;
        string s,t,A,B;
        cin>>n>>s>>t;
        A=s;
        B=t;
        for(int i=0; i<n; i++)
        {
            now=0;
            if(A[i]==B[i])
                continue;
            for(int j=i+1; j<n; j++)
            {
                if(A[j]==A[i])
                {
                    swap(A[j],B[i]);
                    v.pb({j+1,i+1});
                    now=1;
                    break;
                }
                else if(B[j]==B[i])
                {
                    swap(B[j],A[i]);
                    v.pb({i+1,j+1});
                    now=1;
                    break;
                }
            }
            if(!now)
            {
                swap(A[i],B[i]);
                v.pb({i+1,i+1});
                for(int j=i+1; j<n; j++)
                {
                    if(A[j]==A[i])
                    {
                        swap(A[j],B[i]);
                        v.pb({j+1,i+1});
                        now=1;
                        break;
                    }
                    else if(B[j]==B[i])
                    {
                        swap(B[j],A[i]);
                        v.pb({i+1,j+1});
                        now=1;
                        break;
                    }
                }
                if(!now)
                    yes=0;
            }
        }
        if(!yes||v.size()>2*n)
            cout<<"No\n";
        else
        {
            cout<<"Yes\n";
            cout<<v.size()<<endl;
            for(auto xx : v)
                cout<<xx.F<<" "<<xx.S<<endl;
        }
        v.clear();
    }
    return 0;
}
