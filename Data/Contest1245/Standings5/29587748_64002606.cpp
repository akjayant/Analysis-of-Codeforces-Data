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
                const int mox=3e5+9;
                main()
                {
                     ios
                     int t;
                     cin>>t;
                     for(int ii=0 ; ii<t ; ii++)
                     {
                         int a,b;
                         cin>>a>>b;
                         bool u=0;
                         for(int j=2 ; j<=min(a,b) ; j++)
                         {
                             if(a%j==0&&b%j==0)
                             {
                                 u=1;
                                 break;
                             }
                         }
                         if(u==1)
                         {
                             cout<<"Infinite"<<'\n';
                         }
                         else
                            cout<<"Finite"<<'\n';
                     }

                }
