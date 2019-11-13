#include <bits/stdc++.h>

using namespace std;
int t,n,flag=0;
char str1[100],str2[100];
vector<int> a[27],b[27];
int ansa[200],ansb[200],cnt;
int main()
{
    cin>>t;
    while(t--)
    {
        flag=0;
        cnt=0;
        fill(str1,str1+100,0);
        fill(str2,str2+100,0);
        fill(ansa,ansa+200,0);
        fill(ansb,ansb+200,0);
        for(int i=0;i<27;i++)
        {
            a[i].clear();
            b[i].clear();
        }
        cin>>n;
        scanf("%s",str1);
        scanf("%s",str2);
        for(int i=0;i<n;i++)
        {
            a[str1[i]-'a'].push_back(i);
            b[str2[i]-'a'].push_back(i);
        }
        for(int i=0;i<26;i++)
        {
            if((a[i].size()+b[i].size())%2)
            {
                cout<<"No"<<endl;
                flag=1;
                break;
            }
        }
        if(flag) continue;
        cout<<"Yes"<<endl;
        for(int i=0;i<n-1;i++)
        {
            if(str1[i]==str2[i]) continue;
            for(int j=i+1;j<n;j++)
            {
                if(str1[i]==str2[j])
                {
                    swap(str1[i+1],str2[j]);
                    swap(str1[i+1],str2[i]);
                    ansa[cnt]=i+1;
                    ansb[cnt]=j;
                    ansa[cnt+1]=i+1;
                    ansb[cnt+1]=i;
                    cnt+=2;
                    break;
                }
                else if(str1[i]==str1[j])
                {
                    swap(str1[j],str2[i]);
                    ansa[cnt]=j;
                    ansb[cnt]=i;
                    cnt++;
                    break;
                }
            }
        }
        cout<<cnt<<endl;
        for(int i=0;i<cnt;i++)
        {
            cout<<ansa[i]+1<<" "<<ansb[i]+1<<endl;
        }
    }
    return 0;
}
