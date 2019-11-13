#include <bits/stdc++.h>
using namespace std;

int main() {
   
    int q;
    cin>>q;
    while(q--)
    {
        long long j,k,n,i,sum=0,count=0,ans=0,c,d,e,m;
        cin>>n;
         string s,t;
         vector<char>v;
         cin>>s>>t;
  
         for(i=0;i<n;i++)
         {
             if(s[i]!=t[i])
             {       count++;
                 v.push_back(s[i]);
                 v.push_back(t[i]);
             }
            
         }
          if(count>2)
          cout<<"NO"<<endl;
           else if(count==2)
           {
               if(v[0]==v[2] && v[1]==v[3])
               cout<<"YES"<<endl;
               else
               cout<<"NO"<<endl;
           }
           else cout<<"NO"<<endl;
        v.clear();
    }
     
    
	return 0;
}