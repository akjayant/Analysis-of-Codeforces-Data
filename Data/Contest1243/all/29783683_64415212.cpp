#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

set < ll > st;


 vector < ll > vec[100005];

 queue < ll > q,tmp;
 int ck[100005];

 int main()
 {
     ll n,m,i,j,k,a,b,c,x,y,z;
     cin>>n>>m;
     for(i=1;i<=n;i++)
     {
         vec[i].pb(0ll);
         vec[i].pb(n+1);
     }
     for(i=1;i<=m;i++)
     {
         scanf("%lld%lld",&a,&b);
         vec[a].pb(b);
         vec[b].pb(a);
     }
     for(i=1;i<=n;i++)
     {
         sort(vec[i].begin(),vec[i].end());
     }
     for(i=1;i<=n;i++)
     {
         st.insert(i);
     }
     set < ll > :: iterator it;
     ll ans=0;
     while(!st.empty())
     {
         it=st.begin();
         a=*it;
         q.push(a);
         if(a!=1ll)
            ans++;
         st.erase(it);
         //cout<<"a"<<a<<endl;
         while(!q.empty())
         {
             b=q.front();
             q.pop();
             if(ck[b])
                continue;
             ck[b]=1;
             //cout<<b<<endl;
             for(i=1;i<vec[b].size();i++)
             {
                 x=vec[b][i-1];
                 y=vec[b][i];
                 it=st.lower_bound(x);
                 while(!tmp.empty())
                    tmp.pop();
                 for(;it!=st.end();it++)
                 {
                     c=*it;
                     if(c>=y)
                        break;
                     if(c>x && x<y)
                     {
                         tmp.push(c);
                     }
                 }
                 while(!tmp.empty())
                 {
                     c=tmp.front();
                     q.push(c);
                     //cout<<b<< "  " <<x<< "  " <<y<< "  " <<c<<endl;
                     tmp.pop();
                     it=st.find(c);
                     if(it!=st.end())
                     {
                         st.erase(it);
                     }
                 }
             }
         }

     }
     cout<<ans<<endl;

 }
