#include <iostream>

using namespace std;
//PRE=(n>0 e A[0..(n-1)*step] è definito)
int colonna(int* A, int n, int step) { // mi dice il bestValue della colonna 
    //n è l'indice della colonna
    //step è la "profondità" dove bisogna arrivare.
    int sum = 0;
    for(int i = 0; i<step;i++) { //R(0<=i<=step)(step è la profondità della colonna)(sum è la somma)
        sum = sum + *(A+i*8+n);
    }
    return sum;
}
//POST=(restituisce il bestValue di A[0]+A[step]+A[2*step]+A[3*step]+...+A[(n-1)*step])
int main() {
    int n_ele;
    cin>>n_ele;
    int X[10][5][8];
    int *p = X[0][0];
    for(int i = 0; i<n_ele; i++) {
        cin>>*(p+i);
    }
    int righe = n_ele/8;
    int resto = n_ele%8;
    int righeIntermedio =0;
    if(resto!=0)
        righeIntermedio = righe+1;
    int best = 0;
    int bestValue=-10, buffer=-10;
    for(int i=0; i<8; i++) {
        if(resto!=0) { // allora c'è una riga non piena della uale dobbiamo stampèare i valori "resto"
            buffer = colonna(p,i,righeIntermedio);
            if(buffer>=bestValue){ // mantengo quello con bestValue più alto  
                best = i;
                bestValue = buffer;
            }
            resto--;
        }
        else {
            buffer = colonna(p,i,righe);
            if(buffer>=bestValue){ // mantengo quello con bestValue più alto  
                best = i;
                bestValue = buffer;
            }
        }
    }

cout<<"start"<<endl;
    cout<<"V-fetta massima= "<<best<<" con somma= "<<bestValue<<endl;
cout<<"end";
}