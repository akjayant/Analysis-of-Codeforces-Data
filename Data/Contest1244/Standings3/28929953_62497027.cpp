
/*Hey, What's up?*/

#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
vector<long long>v,vc;
map<long long,long long>mp;
map<long long,long long>::iterator it,jt,kt,lt;
int main()
{
    fastio;
    long long a=0,b=0,aa,bb,c,d,e,f=0,l,g,m,n,k,i,j,t,p,q;
    cin>>n>>k;
    for(i=0; i<n; i++)
    {
        cin>>a;
        mp[a]++;
    }
    kt=mp.begin();
    while(kt!=mp.end()){
        v.push_back(kt->first);
        vc.push_back(kt->second);
        kt++;
    }
    p=0;
    q=v.size();
    q--;
    a=vc[0];aa=v[0];
    b=vc[q];bb=v[q];
    while(p!=q)
    {
        //cout<<p<<' '<<q<<'\n';
        c=min(a,b);
        if(c>k)
            break;
        if(a>=b)
        {
            d=bb-v[q-1];
            d*=b;
            d=min(d,k);
            d/=b;
            k-=d*b;
            if(bb-d==v[q-1]){
                q--;
                bb=v[q];
                b+=vc[q];
            }
            else bb-=d;

        }
        else
        {
            d=v[p+1]-aa;
            d*=a;
            d=min(d,k);
            d/=a;
            k-=d*a;
            if(aa+d==v[p+1]){
                p++;
                aa=v[p];
                a+=vc[p];
            }
            else aa+=d;
        }
    }
    //cout<<p<<' '<<q<<'\n';
    f=bb-aa;
    cout<<f<<'\n';
    return 0;
}
