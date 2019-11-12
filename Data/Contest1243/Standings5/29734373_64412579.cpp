#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int q;
    cin>>q;
    while(q--)
    {
        long long j,k,n,i,sum=0,count=0,ans=0,d,e,m;
        cin>>n;
         string s,t;
         char c,c2;
         vector<pair<long long, long long>>v;
         cin>>s>>t;
        int h[26]={0};
         for(i=0;i<n;i++)
         {
             h[s[i]-'a']++; h[t[i]-'a']++;
         }
         for(i=0;i<26;i++)
         {
             if(h[i]%2==1)
             sum=1;
         }
         if(sum==1)
         {
             cout<<"NO"<<"\n";
         }
         else
         {   cout<<"YES"<<"\n"; 
         int mov=0;
             for(i=0;i<n-1;i++)
             {
                 if(s[i]!=t[i])
                 {
                     for(j=i+1;j<n;j++)
                     {
                         if(s[i]==s[j])
                         {
                             mov++;
                             v.push_back(make_pair(j+1,i+1));
                             c=t[i];
                             t[i]=s[j];
                             s[j]=c; break;
                         }
                       
                     }
                      if(s[i]!=t[i])
                      {
                           for(j=i+1;j<n;j++)
                         {
                         if(s[i]==t[j])
                         {
                             mov+=2;
                             v.push_back(make_pair(i+2,j+1));
                             c=t[i]; c2=s[i+1];
                             t[i]=s[i];
                             s[i+1]=c; t[j]=c2;
                              v.push_back(make_pair(i+2,i+1));
                             break;
                         }
                       
                          }
                         
                      }
                 }
                 
             }
             cout<<mov<<"\n";
             for(i=0;i<v.size();i++)
             cout<<v[i].first<<" "<<v[i].second<<"\n";
         }
        v.clear();
    }
     
    
	return 0;
}