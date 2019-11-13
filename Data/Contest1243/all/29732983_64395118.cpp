#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<pair<ll,ll> >ans;
vector<pair<pair<char,ll>,pair<char,ll> > >vec;
int main()
{
    ll a,b,c,d,e,i,j,k,l,n,m,x,y,t,p;
    string st,st2;
    scanf("%lld",&t);
    for(p=1;p<=t;p++)
    {
        scanf("%lld",&n);
        cin>>st>>st2;
        ans.clear();
        vec.clear();
        char ch,ch2;
        x=0;
        c=0;
        for(i=0;i<n;i++)
        {
            if(st[i]!=st2[i])
            {
                vec.push_back(make_pair(make_pair(st[i],i+1),make_pair(st2[i],i+1)));
            }
        }
        c=0;
        l=vec.size();
        for(i=0;i<l;i++)
        {
            if(vec[i].first.first!=vec[i].second.first)
            {
                b=-1;
                for(j=i+1;j<l;j++)
                {
                    if(vec[j].first.first==vec[j].second.first)continue;
                    if(vec[j].second.first==vec[i].first.first)
                    {
                        b=j;
                        break;
                    }
                }
                if(b!=-1)
                {
                ans.push_back({vec[b].first.second,vec[b].second.second});
                ans.push_back({vec[b].first.second,vec[i].second.second});
                swap(vec[b].first.first,vec[b].second.first);
                swap(vec[b].first.first,vec[i].second.first);
                }
                else
                {
                b=-1;
                for(j=i+1;j<l;j++)
                {
                    if(vec[j].first.first==vec[j].second.first)continue;
                    if(vec[j].first.first==vec[i].first.first)
                    {
                        b=j;
                        break;
                    }
                }
                if(b==-1)
                {
                    c=1;
                    break;
                }
                ans.push_back({vec[b].first.second,vec[i].second.second});
                swap(vec[b].first.first,vec[i].second.first);
                }
            }
        }
        if(c==0 && ans.size()<=(2*n))
        {
            printf("Yes\n");
            l=ans.size();
            printf("%lld\n",l);
            for(i=0;i<l;i++)
            {
                printf("%lld %lld\n",ans[i].first,ans[i].second);
            }
        }
        else
        {
            printf("No\n");
        }
    }
}
