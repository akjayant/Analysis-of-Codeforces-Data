#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define PB push_back
#define P push
#define mem(x,y) memset(x,y,sizeof(x))
map<LL,LL>mp;
vector<LL>vc;
int main()
{

    LL i,j,k,s,d,r,m,n,mn=10000000000,mx=0;
    cin>>n>>k;

    for(i=1; i<=n; i++)
    {
        cin>>r;
        if(!mp[r])
            vc.PB(r);
        mp[r]++;
    }
    sort(vc.begin(),vc.end());
    m=vc.size();
    i=0;
    j=m-1;
    mn=vc[i];
    mx=vc[j];
    while(k && i<j)
    {
        //cout<<mx<<" "<<mn<<endl;
        if(mp[vc[i]]<=mp[vc[j]])
        {
            LL req=vc[i+1]-vc[i];
            req*=mp[vc[i]];

            if(k<req)
            {
                d=k/mp[vc[i]];
                mn+=d;
                break;
            }

            else
            {
                mn=vc[i+1];
                i++;
                k-=req;
                mp[vc[i]]+=mp[vc[i-1]];
            }
        }
        else
        {
            LL req=vc[j]-vc[j-1];
            req*=mp[vc[j]];

            if(k<req)
            {
                d=k/mp[vc[j]];
                mx-=d;
                break;
            }

            else
            {
                mx=vc[j-1];
                j--;
                k-=req;
                 mp[vc[j]]+=mp[vc[j+1]];
            }
        }

    }

    cout<<mx-mn<<endl;

}

