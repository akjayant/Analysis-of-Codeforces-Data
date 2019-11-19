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
                const int mox=1e5+9;
                main()
                {
                  int t;
                  cin>>t;
                  for(int ii=0 ; ii<t ; ii++)
                  {
                      int n,m;
                      cin>>n;
                      int x=0,y=0;
                      for(int i=0 ; i<n ; i++)
                      {
                          int a;
                          cin>>a;
                          if(a%2==0)
                            x+=1;
                          else
                            y+=1;
                      }
                         int x1=0,y1=0;
                         cin>>m;
                      for(int i=0 ; i<m ; i++)
                      {
                          int a;
                          cin>>a;
                          if(a%2==0)
                            x1+=1;
                          else
                            y1+=1;
                      }
                      int ans=(x*x1)+(y1*y);
                      cout<<ans<<'\n';

                  }
                }
