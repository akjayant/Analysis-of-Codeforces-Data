#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int ttttttttttttttttttttttttttttttttttttttt=0;
int fhihuhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh=12;
int jjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj=13;
string a ,b ;
vector<int>q;
void solv(){
        int t ;
    cin >> t ;
    while(t--)
    {
        q.clear();
        int n ;int hhhhhhhhhhhhhhsss=12;
        cin >> n ;int jjjjjjjjjjjjjjjjjj=12;
        cin >> a>>b;
        for(int i = 0 ; i < a.size() ; i++)
        {
            if(a[i]!=b[i])
            {
                q.push_back(a[i]-'a');
                q.push_back(b[i]-'a');
            }
        }
        int hioooooooooooo=15;
        if(q.size()==0)
        {
            cout << "Yes"<<endl;
            continue;
        }
        if(q.size()!=4)
        {
            cout << "No" <<endl;
        }
        else
        {
int yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy=10;
            if(q[0]==q[2]&&q[1]==q[3])
            {
                cout << "Yes" <<endl;
            }
            else//gerhguigiu
                cout << "No" <<endl;
        }
    }
}
int main()
{
    int ttttttttttttttttttttttttttttttttttttttttttttttttttt=00;
    solv();
}
/*    int t ;
    cin >> t ;
    while(t--)
    {
        q.clear();
        int n ;
        cin >> n ;
        cin >> a>>b;
        for(int i = 0 ; i < a.size() ; i++)
        {
            if(a[i]!=b[i])
            {
                q.push_back(a[i]-'a');
                q.push_back(b[i]-'a');
            }
        }
        if(q.size()==0)
        {
            cout << "Yes"<<endl;
            continue;
        }
        if(q.size()!=4)
        {
            cout << "No" <<endl;
        }
        else
        {
           // cout << "Dsa" <<endl;
            //sort(q.begin() , q.end());
            if(q[0]==q[2]&&q[1]==q[3])
            {
                cout << "Yes" <<endl;
            }
            else
                cout << "No" <<endl;
        }
    }
    */
