
/*Hey, What's up?*/

#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
vector<long long>v;
int main()
{
    fastio;
    long long a=0,b=0,c,d,e,f=0,l,g,m,n,k,i,j,t,p,q;
    cin>>t;
    string s,sa;
    while(t--)
    {
        cin>>n>>a>>b>>c>>s;
        sa="";
        f=0;
        for(i=0; i<n; i++)
        {
            f++;
            if(s[i]=='R'&&b)
            {
                sa.push_back('P');
                b--;
            }
            else if(s[i]=='P'&&c)
            {
                sa.push_back('S');
                c--;
            }
            else if(s[i]=='S'&&a)
            {
                sa.push_back('R');
                a--;
            }
            else
            {
                f--;
                sa.push_back('0');
            }
        }
        if(2*f>=n){
            cout<<"YES\n";
            for(i=0;i<n;i++){
                if(sa[i]=='0'){
                    if(a){
                        sa[i]='R';
                        a--;
                    }
                    else if(b){
                        sa[i]='P';
                        b--;
                    }
                    else if(c){
                        sa[i]='S';
                        c--;
                    }
                }
            }
            cout<<sa<<'\n';
        }
        else{
            cout<<"NO\n";
        }

    }
    return 0;
}
