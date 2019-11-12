#include<bits/stdc++.h> 
using namespace std;
int mod=1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,k,n;
    cin>>k;
    while(k>0)
    {
        cin>>n;
        string s,t;
        cin>>s>>t;
        int diff=0;
        vector<int> ind;
        for(i=0;i<n;i++)
        {
            if(s[i]!=t[i])
            {
                ind.push_back(i);
                diff+=1;
            }
            if(diff>2)
                break;
        }
        //cout<<ind[0]<<ind[1];
        if(diff==2)
        {
            if(s[ind[0]]==s[ind[1]] && t[ind[0]]==t[ind[1]])
                cout<<"Yes"<<endl;
            else
            {
                cout<<"No"<<endl;
            }
            
        }
        else
        {
            cout<<"No"<<endl;
        }
        

        k--;
    }
}