#include <iostream>

using namespace std;
int main() {
    int ele;
    cin>>ele;
    int lim1, lim2, lim3;
    int X[400];
    int *p = X;
    //inserisco elementi
    for(int i = 0; i<ele; i++) {
        cin>>*(p+i);
    }
     cin>>lim1>>lim2>>lim3;
    //cerco di vederli come lim1 lim2 lim3
    int righe = ele/lim3;
    int strati = ele/(lim2*lim3)+1;
    int resto = ele%lim3;
    int righeIntermedio = 0;
    if(resto!=0)
        righe++;
    bool ok = true;
    int count = 0;
    cout<<"start"<<endl;
    for(int i = 0; i<strati&&i<lim1; i++) {
        cout<<"strato"<<i<<endl;
        for(int a = 0; a<righe&&a<lim2;a++, count++) {
            cout<<"r"<<count<<":";
            for(int z = 0; z<lim3&&ok;z++)
            {
                if(a==righe-1) { // mi trovo nell'ultima riga
                    cout<<*(p+z+a*lim3+i*lim2*lim3)<<" ";
                    resto--;
                    if(resto==0)
                        ok = false;
                }
                else
                    cout<<*(p+z+a*lim3+i*lim2*lim3)<<" ";
            }
            cout<<endl;
        }
        count = 0;
        righe = righe-lim2;
        cout<<endl;
    }
cout<<"end";
}