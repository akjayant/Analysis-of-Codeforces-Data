#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

signed main()
{
    int nbQueries;
    cin >> nbQueries;
    
    for (int idQuery = 0; idQuery < nbQueries; ++ idQuery)
    {
        int nbParties;cin>>nbParties;
        
        int nbA, nbB, nbC, a, b, c;
        cin >> nbA >> nbB >> nbC;
        a = nbA; b = nbB; c = nbC;
        
        int nb = 0;
        string res = "";
        
        for (int iPartie = 0; iPartie < nbParties; ++iPartie)
        {
            char coup;
            cin >> coup;
            res += coup;
            
            if (coup == 'R')
            {
                if (nbB > 0)
                {
                    nbB--;
                    nb++;
                }
            }
            else if (coup == 'P')
            {
                if (nbC > 0)
                {
                    nbC--;
                    nb++;
                }
            }
            else
            {
                if (nbA > 0)
                {
                    nbA --;
                    nb++;
                }
            }
            
        }
        
        //cout << nb << endl;
        
        if (nb >= ceil((double)nbParties/2))
        {
            cout << "YES\n";
            for (int iPartie = 0; iPartie < nbParties; ++iPartie)
            {
                if (res[iPartie] == 'R')
                {
                    if (b > 0)
                    {
                        b--;
                        cout << "P";
                    }
                    else
                    {
                        if (nbC > 0)
                        {
                            cout << "S";
                        
                            nbC--;
                        }
                            else{
                            cout << "R";nbB--;}
                    }
                }
                else if (res[iPartie] == 'P')
                {
                    if (c > 0)
                    {
                        c--;
                        cout << "S";
                    }
                    else
                    {
                        if (nbA > 0){
                            cout << "R";nbA--;}
                        else{
                            cout << "P";nbC--;}
                    }
                }
                else
                {
                    if (a > 0)
                    {
                        --a;
                        cout << "R";
                    }
                    else
                    {
                        if (nbB > 0){
                            cout << "P";
                            nbB--;}
                        else{
                            cout << "S";
                            nbA--;}
                    }
                }
            }
            cout << endl;
        }
        else
            cout << "NO\n";
    }
    return 0;
}