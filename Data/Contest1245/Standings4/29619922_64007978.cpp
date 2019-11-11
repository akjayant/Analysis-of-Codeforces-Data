#include <bits/stdc++.h>
#define ENDL '\n'
#define F first
#define S second
#define PB push_back
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define FLOOR(a,b) (a-a%b) / b
#define CEIL(a,b) (a%b==0) ? a/b : FLOOR(a,b) + 1
#define NEXT(a) next_permutation(ALL(a))
#define T = 100000
#define N = 1000000000000000000
#define RANDOM(a) (rand()%a) + 1
#define TEST_CASES 20

using namespace std;

typedef long long int lli;
typedef long double ld;
typedef unsigned long long int ulli;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    lli t,n,r,p,sc;
    cin>>t;
    string s;
    map<string,int> alice;
    map<string,int> bob;
    while(t--)
    {
        cin>>n;
        cin>>r>>p>>sc;
        cin>>s;
        string ans="";
        lli wins=0;
        for(char c : s)
        {
            if(c=='R')
            {
                if(p>0)
                {
                    ++wins;
                    --p;
                    ans+="P";
                }
                else
                    ans+="X";
            }
            if(c=='P')
            {
                if(sc>0)
                {
                    ++wins;
                    --sc;
                    ans+="S";
                }
                else
                    ans+="X";
            }
            if(c=='S')
            {
                if(r>0)
                {
                    ++wins;
                    --r;
                    ans+="R";
                }
                else
                    ans+="X";
            }
        }
        n = CEIL(n,2);
        if(wins>=n)
        {
            cout<<"YES"<<ENDL;
            for(char &c : ans)
            {
                if(c=='X')
                {
                    if(p){ c = 'P';--p;continue;}
                    if(r){ c = 'R';--r;continue;}
                    if(sc){ c = 'S';--sc;continue;}
                }
            }
            cout<<ans<<ENDL;
        }
        else
        {
            cout<<"NO"<<ENDL;
        }
    }
    return 0;
}
