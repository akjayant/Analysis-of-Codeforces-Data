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
                int na[mox];
                main()
                {   ios
                  int n;
                  cin>>n;
                  for(int i=0 ; i<n ; i++)
                  {
                     cin>>na[i];
                  }
                  sort(na,na+n);
                  int x=(n/2);
                  if(n%2==1)
                    x+=1;
                    int a=0,b=0;
                    for(int i=n-1 ; i>=n-x ; i--)
                    {
                        a+=na[i];
                    }
                    for(int i=n-1-x ; i>=0 ; i--)
                    {
                        b+=na[i];
                    }
                    cout<<((a*a)+(b*b));

                }
