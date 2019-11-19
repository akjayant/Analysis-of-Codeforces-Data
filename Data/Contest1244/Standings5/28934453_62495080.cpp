#include<bits/stdc++.h>
using namespace std;
long long a[131072],n,k;
deque< pair<long long,long long> >d;
int main()
{
    cin>>n>>k;
    pair<long long,long long>p,p1;
    long long i,j;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    p.first=a[0];
    p.second=1;
    for(i=1;i<n;i++)
    {
        if(a[i]==p.first)
        {
            p.second++;
        }
        else
        {
            d.push_back(p);
            p.first=a[i];
            p.second=1;
        }
    }
    d.push_back(p);
    while(1)
    {
        if(d.size()==1||k==0)break;
        if(d.front().second<d.back().second)
        {
            //cout<<"line35\n";
            p=d.front();
            d.pop_front();
            p1=d.front();
            if(k>=p.second*(p1.first-p.first))
            {
                k-=(p.second*(p1.first-p.first));
                d.front().second+=p.second;
            }
            else
            {
                p.first+=(k/p.second);
                d.push_front(p);
                break;
            }
            //cout<<k<<endl;
        }
        else
        {
            //cout<<"line54\n";
            p=d.back();
            d.pop_back();
            p1=d.back();
            if(k>=p.second*(p.first-p1.first))
            {
                k-=(p.second*(p.first-p1.first));
                d.back().second+=p.second;
            }
            else
            {
                p.first-=(k/p.second);
                d.push_back(p);
                break;
            }
            //cout<<k<<endl;
        }
    }
    cout<<d.back().first-d.front().first<<endl;
    return 0;
}
