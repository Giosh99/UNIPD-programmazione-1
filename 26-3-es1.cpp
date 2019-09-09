#include <iostream>

using namespace std;
//PRE TV: p punta al primo elemento di una V-fetta, gli altri parametri sono ben definiti
int& TV(int*p, int lim1,int lim2, int lim3, int f, int n) { //f e' l'indice e n e' l'elemento
    return *(p+f+n*lim3);

}
//POST TV: restituito il riferimento alla cella n della V-fetta
int main() {
    int X[100];
    int lim1, lim2, lim3,buffer;
    bool yep= true;
    int i,j,k,z;
    //inserimento valori
    for(int i = 0; i<100; i++) {
        cin>>*(X+i);
    }
        cin>>lim1>>lim2>>lim3;
    while(i!=-1) {//R(i!=-1 allora leggo j,k,z)&&(v1 è alias dell'elemento j della V-fetta i)&&(v2 è alias dell'elemento z della V-fetta k)
                    //&& (i==-1 => non vi sono altre quadruple  )
        cin>>i;
        if(i!=-1) {
            cin>>j;
            cin>>k;
            cin>>z;
            int &v1 = TV(X,lim1,lim2,lim3,i,j);
            int &v2 = TV(X,lim1,lim2,lim3,k,z);
            buffer = v1;
            v1 = v2;
            v2 = buffer;
        }
    }
    cout<<"start"<<endl;
    for(int a = 0; a<lim1; a++) {
        for(int f = 0; f<lim2; f++) {
            for(int g = 0; g<lim3;g++) {
                cout<<*(X+a*lim2*lim3+f*lim3+g)<<" ";
            }
            cout<<endl;
        }
    }
    cout<<"end";
}