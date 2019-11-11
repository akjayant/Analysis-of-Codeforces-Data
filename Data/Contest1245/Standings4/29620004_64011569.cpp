#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef long double ld;
#define pb push_back
#define mp make_pair

using namespace std;

ll get(ll a)
{
    if(a == 0)
        return 1;
    if(a == 1)
        return 2;
    return 0;    
}

int main()
{
   FAST/**/
   
   ll t;
   cin>>t;
   
   while(t--)
   {
       ll n;
       cin>>n;
       
       ll a,b,c;
       cin>>a>>b>>c;
       
       string s;
       cin>>s;
       
       pair<ll,ll> arr[3];
       arr[0].first = a, arr[0].second = 0;
       arr[1].first = c, arr[1].second = 2;
       arr[2].first = b, arr[2].second = 1;
       
       //sort(arr,arr+3);
       unordered_map<ll,ll> ma;
       string s1 = s;
       bool pos[n];
       memset(pos,0,sizeof(pos));
       ll cnt = 0;
       for(ll i=0;i<n;i++)
       {
           if(s[i] == 'R')
           {
               if(b>0)
                    b--, cnt++, pos[i] = 1, s1[i] = 'P';
           }
           else if(s[i] == 'P')
           {
               if(c>0)
                    c--, cnt++, pos[i] = 1, s1[i] = 'S';
           }
           else 
           {
               if(a>0)
                    a--, cnt++, pos[i] = 1, s1[i] = 'R';
           }
       }
       
       ll req = ceil((ld)n/2);
       if(cnt<req)
            cout<<"No"<<"\n";
       else
       {
           cout<<"Yes"<<"\n";
           for(ll i=0;i<n;i++)
           {
               if(!pos[i])
               {
                   if(a>0)
                        s1[i] = 'R',a--;
                   else if(b>0)
                        s1[i] = 'P',b--;
                   else s1[i] = 'S',c--;    
               }
           }
           cout<<s1<<"\n";
       }
       
       
   }
   
   return 0;
}