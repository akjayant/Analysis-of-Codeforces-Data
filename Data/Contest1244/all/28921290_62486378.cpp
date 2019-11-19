//RAB RAKHA

/* Code till every compiler has crashed */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

/*-----------------------------------------------------------------
                            Templates
----------------------------------------------------------------*/
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define in1(n) cin >> n;
#define in2(a,b) cin >> a >> b;
#define in3(a,b,c) cin >> a >> b >> c;
#define out1(n) cout << n << "\n";
#define out2(a,b) cout << a << " " << b << "\n";
#define out3(a,b,c) cout << a << " " << b << " " << c << "\n";
#define inputarr(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define printarr(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";
#define initarr(a,n,x) for(int i=0;i<n;i++) a[i]=x;
#define veci vector<int>
#define seti set<int>
#define mapi map<int,int>
const int MOD=1e9+7;
/*-----------------------------------------------------------------
                            Templates
----------------------------------------------------------------*/
ll gcd(ll a, ll b)
{
    if (a == 0)
       return b;
    if (b == 0)
       return a;

    if (a == b)
        return a;

    if (a > b)
        return gcd(a%b, b);
    return gcd(a, b%a);
}
void swap(ll &a, ll &b)
{
     b = a + b;
     a = b - a;
     b = b - a;
}
/*
if()
cout << "YES\n";
else
cout << "NO\n";
*/
int main()
{
    FASTIO
    int t=1;
    while(t--)
    {
        ll n,m,ans=0;
        ll i,j;
        in1(n);
        ll c1[n],c2[n],c3[n];
        inputarr(c1,n);
        inputarr(c2,n);
        inputarr(c3,n);
        vector <ll> v[n];
        ll x,y;
        for(i=0;i<n-1;i++)
        {
            in2(x,y);v[x-1].push_back(y-1);v[y-1].push_back(x-1);
        }
        for(i=0;i<n;i++)
        {
            if(v[i].size()>2)
            {
                cout << "-1\n";
                return 0;
            }
        }
        for(i=0;i<n;i++)
        {
            if(v[i].size()==2)
            break;
        }
        ll beginwiththisindex=i;
        ll count=0;
        ll c[n];initarr(c,n,0);count=3;
        c[beginwiththisindex]=1;
        c[v[beginwiththisindex][0]]=2;
        c[v[beginwiththisindex][1]]=3;
        ll curr=v[beginwiththisindex][0];
        while(count<n)
        {
            if(v[curr].size()==1)
            break;
            if(c[v[curr][0]]==0&&c[v[curr][1]]>0)
            {
                c[v[curr][0]]=6-c[curr]-c[v[curr][1]];
                count++;
                curr=v[curr][0];
            }
            else if(c[v[curr][1]]==0&&c[v[curr][0]]>0)
            {
                c[v[curr][1]]=6-c[curr]-c[v[curr][0]];
                count++;
                curr=v[curr][1];
            }
        }
        curr=v[beginwiththisindex][1];
        while(count<n)
        {
            if(v[curr].size()==1)
            break;
            if(c[v[curr][0]]==0&&c[v[curr][1]]>0)
            {
                c[v[curr][0]]=6-c[curr]-c[v[curr][1]];
                count++;
                curr=v[curr][0];
            }
            else if(c[v[curr][1]]==0&&c[v[curr][0]]>0)
            {
                c[v[curr][1]]=6-c[curr]-c[v[curr][0]];
                count++;
                curr=v[curr][1];
            }
        }
        ll cost1=0;
        for(i=0;i<n;i++)
        {
            if(c[i]==1)
            cost1+=c1[i];
            else if(c[i]==2)
            cost1+=c2[i];
            else
            cost1+=c3[i];
        }
        ll c11[n];
        for(i=0;i<n;i++)
        c11[i]=c[i];
        
        initarr(c,n,0);count=3;
        c[beginwiththisindex]=1;
        c[v[beginwiththisindex][0]]=3;
        c[v[beginwiththisindex][1]]=2;
        curr=v[beginwiththisindex][0];
        while(count<n)
        {
            if(v[curr].size()==1)
            break;
            if(c[v[curr][0]]==0&&c[v[curr][1]]>0)
            {
                c[v[curr][0]]=6-c[curr]-c[v[curr][1]];
                count++;
                curr=v[curr][0];
            }
            else if(c[v[curr][1]]==0&&c[v[curr][0]]>0)
            {
                c[v[curr][1]]=6-c[curr]-c[v[curr][0]];
                count++;
                curr=v[curr][1];
            }
        }
        curr=v[beginwiththisindex][1];
        while(count<n)
        {
            if(v[curr].size()==1)
            break;
            if(c[v[curr][0]]==0&&c[v[curr][1]]>0)
            {
                c[v[curr][0]]=6-c[curr]-c[v[curr][1]];
                count++;
                curr=v[curr][0];
            }
            else if(c[v[curr][1]]==0&&c[v[curr][0]]>0)
            {
                c[v[curr][1]]=6-c[curr]-c[v[curr][0]];
                count++;
                curr=v[curr][1];
            }
        }
        ll cost2=0;
        for(i=0;i<n;i++)
        {
            if(c[i]==1)
            cost2+=c1[i];
            else if(c[i]==2)
            cost2+=c2[i];
            else
            cost2+=c3[i];
        }
        ll c21[n];
        for(i=0;i<n;i++)
        c21[i]=c[i];
        
        
        initarr(c,n,0);count=3;
        c[beginwiththisindex]=2;
        c[v[beginwiththisindex][0]]=1;
        c[v[beginwiththisindex][1]]=3;
        curr=v[beginwiththisindex][0];
        while(count<n)
        {
            if(v[curr].size()==1)
            break;
            if(c[v[curr][0]]==0&&c[v[curr][1]]>0)
            {
                c[v[curr][0]]=6-c[curr]-c[v[curr][1]];
                count++;
                curr=v[curr][0];
            }
            else if(c[v[curr][1]]==0&&c[v[curr][0]]>0)
            {
                c[v[curr][1]]=6-c[curr]-c[v[curr][0]];
                count++;
                curr=v[curr][1];
            }
        }
        curr=v[beginwiththisindex][1];
        while(count<n)
        {
            if(v[curr].size()==1)
            break;
            if(c[v[curr][0]]==0&&c[v[curr][1]]>0)
            {
                c[v[curr][0]]=6-c[curr]-c[v[curr][1]];
                count++;
                curr=v[curr][0];
            }
            else if(c[v[curr][1]]==0&&c[v[curr][0]]>0)
            {
                c[v[curr][1]]=6-c[curr]-c[v[curr][0]];
                count++;
                curr=v[curr][1];
            }
        }
        ll cost3=0;
        for(i=0;i<n;i++)
        {
            if(c[i]==1)
            cost3+=c1[i];
            else if(c[i]==2)
            cost3+=c2[i];
            else
            cost3+=c3[i];
        }
        ll c31[n];
        for(i=0;i<n;i++)
        c31[i]=c[i];
        
        
        
        
        initarr(c,n,0);count=3;
        c[beginwiththisindex]=2;
        c[v[beginwiththisindex][0]]=3;
        c[v[beginwiththisindex][1]]=1;
        curr=v[beginwiththisindex][0];
        while(count<n)
        {
            if(v[curr].size()==1)
            break;
            if(c[v[curr][0]]==0&&c[v[curr][1]]>0)
            {
                c[v[curr][0]]=6-c[curr]-c[v[curr][1]];
                count++;
                curr=v[curr][0];
            }
            else if(c[v[curr][1]]==0&&c[v[curr][0]]>0)
            {
                c[v[curr][1]]=6-c[curr]-c[v[curr][0]];
                count++;
                curr=v[curr][1];
            }
        }
        curr=v[beginwiththisindex][1];
        while(count<n)
        {
            if(v[curr].size()==1)
            break;
            if(c[v[curr][0]]==0&&c[v[curr][1]]>0)
            {
                c[v[curr][0]]=6-c[curr]-c[v[curr][1]];
                count++;
                curr=v[curr][0];
            }
            else if(c[v[curr][1]]==0&&c[v[curr][0]]>0)
            {
                c[v[curr][1]]=6-c[curr]-c[v[curr][0]];
                count++;
                curr=v[curr][1];
            }
        }
        ll cost4=0;
        for(i=0;i<n;i++)
        {
            if(c[i]==1)
            cost4+=c1[i];
            else if(c[i]==2)
            cost4+=c2[i];
            else
            cost4+=c3[i];
        }
        ll c4[n];
        for(i=0;i<n;i++)
        c4[i]=c[i];
        
        
        
        
        initarr(c,n,0);count=3;
        c[beginwiththisindex]=3;
        c[v[beginwiththisindex][0]]=2;
        c[v[beginwiththisindex][1]]=1;
        curr=v[beginwiththisindex][0];
        while(count<n)
        {
            if(v[curr].size()==1)
            break;
            if(c[v[curr][0]]==0&&c[v[curr][1]]>0)
            {
                c[v[curr][0]]=6-c[curr]-c[v[curr][1]];
                count++;
                curr=v[curr][0];
            }
            else if(c[v[curr][1]]==0&&c[v[curr][0]]>0)
            {
                c[v[curr][1]]=6-c[curr]-c[v[curr][0]];
                count++;
                curr=v[curr][1];
            }
        }
        curr=v[beginwiththisindex][1];
        while(count<n)
        {
            if(v[curr].size()==1)
            break;
            if(c[v[curr][0]]==0&&c[v[curr][1]]>0)
            {
                c[v[curr][0]]=6-c[curr]-c[v[curr][1]];
                count++;
                curr=v[curr][0];
            }
            else if(c[v[curr][1]]==0&&c[v[curr][0]]>0)
            {
                c[v[curr][1]]=6-c[curr]-c[v[curr][0]];
                count++;
                curr=v[curr][1];
            }
        }
        ll cost5=0;
        for(i=0;i<n;i++)
        {
            if(c[i]==1)
            cost5+=c1[i];
            else if(c[i]==2)
            cost5+=c2[i];
            else
            cost5+=c3[i];
        }
        ll c5[n];
        for(i=0;i<n;i++)
        c5[i]=c[i];
        
        
        
        
        
        initarr(c,n,0);count=3;
        c[beginwiththisindex]=3;
        c[v[beginwiththisindex][0]]=1;
        c[v[beginwiththisindex][1]]=2;
        
        curr=v[beginwiththisindex][0];
        while(count<n)
        {
            if(v[curr].size()==1)
            break;
            if(c[v[curr][0]]==0&&c[v[curr][1]]>0)
            {
                c[v[curr][0]]=6-c[curr]-c[v[curr][1]];
                count++;
                curr=v[curr][0];
            }
            else if(c[v[curr][1]]==0&&c[v[curr][0]]>0)
            {
                c[v[curr][1]]=6-c[curr]-c[v[curr][0]];
                count++;
                curr=v[curr][1];
            }
        }
        curr=v[beginwiththisindex][1];
        while(count<n)
        {
            if(v[curr].size()==1)
            break;
            if(c[v[curr][0]]==0&&c[v[curr][1]]>0)
            {
                c[v[curr][0]]=6-c[curr]-c[v[curr][1]];
                count++;
                curr=v[curr][0];
            }
            else if(c[v[curr][1]]==0&&c[v[curr][0]]>0)
            {
                c[v[curr][1]]=6-c[curr]-c[v[curr][0]];
                count++;
                curr=v[curr][1];
            }
        }
        ll cost6=0;
        for(i=0;i<n;i++)
        {
            if(c[i]==1)
            cost6+=c1[i];
            else if(c[i]==2)
            cost6+=c2[i];
            else
            cost6+=c3[i];
        }
        ll c6[n];
        for(i=0;i<n;i++)
        c6[i]=c[i];
        
        ll costs[]={cost1,cost2,cost3,cost4,cost5,cost6};
        sort(costs,costs+6);
        ll mincost=costs[0];
        out1(mincost);
        if(cost1==mincost)
        {
            printarr(c11,n);
            return 0;
        }
        if(cost2==mincost)
        {
            printarr(c21,n);
            return 0;
        }
        if(cost3==mincost)
        {
            printarr(c31,n);
            return 0;
        }
        if(cost4==mincost)
        {
            printarr(c4,n);
            return 0;
        }
        if(cost5==mincost)
        {
            printarr(c5,n);
            return 0;
        }
        if(cost6==mincost)
        {
            printarr(c6,n);
            return 0;
        }
    }
}