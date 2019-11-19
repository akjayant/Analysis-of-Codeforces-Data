                // in the name of allah
                // never give up :))))
                #include <bits/stdc++.h>
                #define mp make_pair
                #define f1 first
                #define f2 second
                #define pb push_back
                #define pii pair<int ,int>
                #define int long long
                #define ios  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
                using namespace std;
                const int mox=2e3+9;
                int d[mox];
                set <pii> s;
                int xa[mox];
                int ya[mox];
                int ka[mox];
                int dad[mox];
                bool visit[mox];
                main()
                {
                     ios
                   int n;
                   cin>>n;
                   for(int i=0 ; i<n ;i++)
                   {
                       cin>>xa[i]>>ya[i];

                   }
                   for(int i=0 ; i<n ; i++)
                   {
                       int c;
                       cin>>c;
                       s.insert(mp(c,i));
                       d[i]=c;
                       dad[i]=-1;

                   }
                   for(int i=0 ; i<n ; i++)
                   {
                       cin>>ka[i];
                   }
                   int ans=0;
                   while(s.empty()==0)
                   {
                       int x=s.begin()->f2;
                       ans+=s.begin()->f1;
                       s.erase(s.begin());
                       visit[x]=1;
                       for(int i=0 ; i<n ; i++)
                       {
                           if(d[i]>((abs(xa[i]-xa[x])+abs(ya[i]-ya[x]))*(ka[i]+ka[x]))&&visit[i]==0)
                           {
                               s.erase(mp(d[i],i));
                               d[i]=((abs(xa[i]-xa[x])+abs(ya[i]-ya[x]))*(ka[i]+ka[x]));
                               s.insert(mp(d[i],i));
                               dad[i]=x;
                           }
                       }
                   }
                   cout<<ans<<'\n';
                   int v=0;
                   for(int i=0 ; i<n ; i++)
                   {
                       if(dad[i]==-1)
                        v+=1;

                   }
                   cout<<v<<'\n';
                    for(int i=0 ; i<n ; i++)
                   {
                       if(dad[i]==-1)
                         cout<<i+1<<" ";

                   }
                   cout<<'\n';
                   cout<<n-v<<'\n';
                   for(int i=0 ; i<n ; i++)
                   {
                       if(dad[i]!=-1)
                       {
                           cout<<i+1<<" "<<dad[i]+1<<'\n';
                       }
                   }
                }
