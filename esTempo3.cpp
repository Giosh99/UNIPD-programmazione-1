// cc'è stato un piccolo problema di comprensione del testo, il check viene fatto senza la divisione degli strati
#include <iostream>

using namespace std;

bool match(int *A, int *p, int np, int col,int lim3, int start) {
    bool ok = true;
    for(int i = 0; i<np&&ok;i++) {
        cout<<"confronto "<<*(A+col+lim3*i+start*lim3)<<"con: "<<*(p+i)<<endl;
        if(*(A+col+lim3*i+start*lim3) != *(p+i)) {
            ok = false;
            cout<<"nope"<<endl;
        }
    }
    return ok;
}
//POST=(restituisce true sse x[0..nP-1]==P[0..nP-1])
int main() {
    int X[100];
    int p[100]; // array pattern
    bool found = false; // per dire che ho definitivamente trovato il match
    int nele;
    cin>>nele;
    for(int i = 0; i<nele; i++) {
        cin>>*(X+i);
    }
    int lim1, lim2, lim3;
    cin>>lim1>>lim2>>lim3;
    int np; //elementi di p
    cin>>np;
    for(int i = 0; i<np; i++) {
        cin>>*(p+i);
    }

    int righe = nele/lim3;
    int resto = nele%lim3;
    int fetta =0;
    int elemento=0;
    if(resto!=0)
        righe++;
    for(int i = 0; i<lim3&&!found; i++, fetta++){ //R(0<=i<=lim3)&&(!found=true allora non ho trovato match)&&(fetta mi indica la V-fetta che sto controllando)
                                                    //&&(resto indica se ci sono righe non completamente piene)
        elemento = 0;
        for(int a = 0; a+np-1<righe&&!found;a++, elemento++) {//R(0<=a+np-1<=righe)&&(elemento indica l'elemento di partenza da cui avrò il match)
            if(match(X,p,np,i,lim3, a))
                found = true;
        }
        if(resto!=0){
            resto--;
            if(resto == 0) 
                righe--;
        }
    }
    cout<<"start"<<endl;
    if(found == true) {
        cout<<"La V-fetta "<<fetta-1<<" contiene un match che inizia nell'elemento "<<elemento-1<<endl;
    }
    else 
        cout<<"Nessun match trovato"<<endl;

cout<<"end";
    return 0;
}