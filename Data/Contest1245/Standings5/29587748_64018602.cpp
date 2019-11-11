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
                const int mox=1e2+9;
                char ca[mox];
                bool visit[mox];
                main()
                {
                     ios
                     int t;
                     cin>>t;
                     for(int ii=0 ; ii<t ; ii++)
                     {
                         int n;
                         cin>>n;
                         int a,b,c;
                         cin>>a>>b>>c;
                         string s;
                         cin>>s;
                         int a2=0,b2=0,c2=0;
                         for(int i=0 ; i<n ;i++)
                         {
                             if(s[i]=='R')
                               a2+=1;
                               if(s[i]=='S')
                                c2+=1;
                               if(s[i]=='P')
                                b2+=1;
                         }
                         int x=(min(a,c2)+min(c,b2)+min(b,a2));

                         if(x<((n+1)/2))
                         {
                             cout<<"NO"<<'\n';
                         }
                         else
                         {
                             cout<<"YES"<<'\n';
                             for(int i=0 ; i<n ; i++)
                             {
                                 if(a>0&&s[i]=='S')
                                 {
                                     a-=1;
                                     ca[i]='R';
                                     visit[i]=1;
                                 }
                                   if(s[i]=='R'&&b>0)
                                    {
                                        b-=1;
                                        ca[i]='P';
                                               visit[i]=1;
                                    }
                               if(s[i]=='P'&&c>0)
                                {
                                    c-=1;
                                    ca[i]='S';
                                           visit[i]=1;
                                }

                             }
                             for(int i=0 ; i<n ; i++)
                             {
                                 if(visit[i]==0)
                                 {
                                       if(a>0)
                                 {
                                     a-=1;
                                     ca[i]='R';

                                 }
                                   else if(b>0)
                                    {
                                        b-=1;
                                        ca[i]='P';

                                    }
                                else
                                {
                                    c-=1;
                                    ca[i]='S';

                                }

                                 }
                             }
                             for(int i=0 ; i<n ;i++)
                             {
                                 cout<<ca[i];
                                 visit[i]=0;
                             }
                             cout<<'\n';

                         }

                     }

                }
