#include<bits/stdc++.h> 
using namespace std;
int mod=1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,k;
    cin>>k;
    while(k>0)
    {
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        vector<pair<int,int>> xchange;
        int found=0,ans=0;
        for(i=0;i<n;i++)
        {
            if(s[i]!=t[i])
            {
                found=0;
                for(j=0;j<n;j++)
                {
                    if(s[i]==t[j] && t[j]!=s[j])
                    {
                        xchange.push_back(make_pair(j,j));
                        xchange.push_back(make_pair(j,i));
                        char temp=s[j];
                        s[j]=t[j];
                        t[j]=temp;
                        temp=t[i];
                        t[i]=s[j];
                        s[j]=temp;

                        found=1;
                        break;
                    }
                }
                if(found==0)
                {
                    for(j=i+1;j<n;j++)
                    {
                        if(s[j]==s[i] && s[j]!=t[j])
                        {
                            xchange.push_back(make_pair(j,i));
                            char temp=s[j];
                            s[j]=t[i];
                            t[i]=temp;
                            found=1;
                        }
                    }
                }
                if(found==0)
                {
                    ans=1;
                    break;
                }
            }
            
        }
        if(ans==1)
            cout<<"No"<<endl;
        else
        {
            cout<<"Yes"<<endl;

            cout<<xchange.size()<<endl;
            for(i=0;i<xchange.size();i++)
                cout<<xchange[i].first+1<<" "<<xchange[i].second+1<<endl;
        }
        
        k--;
    }
}