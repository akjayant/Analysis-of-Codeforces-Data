    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    #define mp make_pair
    #define ff first
    #define ss second
    typedef long long ll;
    class Matrix
    {
      
       public:
          int size=0;
          int m[200][200];
          Matrix(int n)
          {
             size = n;
            
             for(int i = 0; i<n ; i++)
                for(int j = 0; j<n ; j++)
                   m[i][j]=0;
          }
          int n = size;
          void printer()
          {
             for(int i = 0; i<size ; i++)
                {
                   for(int j = 0; j<size ; j++)
                   cout<<m[i][j]<<' ';
                   cout<<endl;
                }
          }
       Matrix mul(Matrix A, Matrix B)
       {
          Matrix ans(A.size);
          for(int i = 0; i<size ; i++)
          {
             for(int j = 0; j<size ; j++)
             {
                for(int k = 0; k<size ; k++)
                { 
                   ans.m[i][j] = max(A.m[i][k]+B.m[(k+1)%size][j],ans.m[i][j]);
                }
             }
          }
          return ans;
       }
    Matrix power(Matrix A,int k)
    {
         // cout<<"called : k : "<<k<<endl;
          Matrix ans(A.size);
          
          if(k == 1)
             ans = A;
          else if(k == 0)
          {
             for(int i = 0; i<size ; i++)
                for(int j =0 ; j<size; j++)
                   ans.m[i][j]=0;
          }
          else
          {
             ans = A.power(A,k/2);
             ans = ans.mul(ans,ans);
             if(k%2 == 1)
                ans=ans.mul(ans,A);
          }
          return ans;
    }
  };
    

    int  main()
    {
       // ios_base::sync_with_stdio(false);
       // cin.tie(NULL);
        
       // int a,b;
       // cin>>a>>b;
       // int dp[100]={};
       // for(int i = 0; i<100 ; i++)
       // {
       //    if(i == 0)
       //      dp[i]=0;
       //    else if(i-a>=0 && dp[i-a]==0)
       //      dp[i]=0;
       //    else if(i-b>=0 && dp[i-b]==0)
       //      dp[i]=0;
       //    else
       //      dp[i] = 1;

       //    //cout<<" "<<i<<" : "<<dp[i]<<endl;
       //    cout<<dp[i]<<" ";
       //  }

       int t;
       cin>>t;
       while(t--)
       {
          int a,b;
          cin>>a>>b;

          if(__gcd(a,b) == 1)
            cout<<"Finite\n";
          else
            cout<<"Infinite\n";
       }
       return 0;
      
      
    }