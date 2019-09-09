#include <iostream>

using namespace std;

int main() {
    int A1[10][5];
    int A2[10][5];
    bool B[10][10];
    int *pA1 = A1[0];
    int buffer;
    bool yeo = false;
    for(int j = 0; j<5; j++) { //R(0<=j<=5)&&(ho effettuao il ciclo innestato j volte)
        for(int i = 0; i<10; i++, pA1++) {//R(0<=j<=10)&&(ho inserito i valori per colonna in A2 )&&(ho inserito i valori per riga in A1)
            cin>>buffer;
            A2[i][j] = buffer;
            *pA1 = buffer;
        }
    } 

    cout <<endl<<endl;
    // stampo A1
    for(int i = 0; i<10; i++) {
        for(int j = 0; j<5; j++) {
            cout<<A1[i][j]<<" ";
        }
        cout<<endl;
    }
// stampo A2
    cout<<endl<<endl;
        for(int i = 0; i<10; i++) {
        for(int j = 0; j<5; j++) {
            cout<<A2[i][j]<<" ";
        }
        cout<<endl;
    }
    int *pA2 = A2[0];
    int b = 0;
    for(int i = 0; i<10; i++) {//R(0<=i<=10)&&(effettuo i volte il ciclo innestato)
        for(int j = 0; j<10; j++) {//R(0<=j<=10)&&(ho effettuato j volte il ciclo innestato)
            yeo = true;
            for(int z = 0; z<5;z++) { //R(0<=z<=5)&&(effettuo z volte il ciclo innestato)
                for(int f = 0; f<5&& yeo==true; f++) { //R(0<=f<=5)&&(yeo==true se la riga i di A2 non ha elementi in comune con la riga j di A2)&&(yeo==false se la
                                                        //riga i di A2 e j di A2 hanno un elemento in comune)
                    if(A2[i][z]==A2[j][f])
                        yeo = false;
                }
            }
            B[i][j] = yeo;
        }
    }
    
}