#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t main()
{
    int t=1;
    cin>>t;
    while(t--){
      int N;
      cin>>N;
      string A,B;cin>>A>>B;
      int op = 0;
      string ans = "Yes";
      vector<pair<int,int>>temp;
      for(int i = 0;i<N;i++){
          if(A[i]==B[i])
          {
              continue;
          }
          else
          {
              //Search in i+1 to N for A[i]
              int index = -1;
              for(int j = i+1;j<N;j++){
                  if(A[j]==A[i]&&A[j]!=B[j])
                  {
                      //Swap now
                      if(index!=-1)
                      {
                      if(B[i]==B[j])
                      {
                          index = j;
                      }
                      }
                      else
                      {
                          index = j;
                      }
                  }
              }
              if(index==-1)
              {
                  for(int j = i+1;j<N;j++){
                      if(A[j]!=B[j]&&A[i]==B[j])
                      {
                          char ch = A[j];
                          A[j] = B[j];
                          B[j] = ch;
                          op++;
                          index = j;
                          temp.push_back({j,j});
                          break;
                      }
                  }
              }
              if(index!=-1)
              {
                  temp.push_back({index,i});
                      char ch = B[i];
                      B[i] = A[index];
                      A[index] = ch;
                      op++;
              }
              else
              {
                  ans = "No";
                  break;
              }
          }
      }
          cout<<ans<<endl;
         
          if(ans=="Yes")
          {
               cout<<op<<endl;
              for(auto x:temp)
              {
                  cout<<x.first+1<<" "<<x.second+1<<endl;
              }
          }
    }
}