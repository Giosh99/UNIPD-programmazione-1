#include <iostream>
using namespace std;
struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};
void leggi(int dim, int*P)
{
    if(dim){
        cin>>*P;
        leggi(dim-1,P+1);
    }
}

nodo* crea(int dim)
{
    if(dim){
        int x;
        cin>>x;
        return new nodo(x,crea(dim-1));
    }
    return 0;
}

void stampa(nodo *L){
    if(!L){
        cout<<endl;
        return;
    }
    cout<<L->info<<" ";
    stampa(L->next);
}
//PRE: L(n) lista ben formata, P ha dimP elementi, dimP>0
bool check(nodo* n, int* P, int dimP, nodo* &resto){
    if(!n) return false;
    if(n->info==*P)
        if(dimP==1){
            resto=n->next;
            n->next=0;
            return true;
        }
        else{
            nodo* x=0;
            bool c=check(n->next, P+1, dimP-1,x);
            if(c){
                resto=x;
                return true;
            }
            else{
                resto=0;
                return false;
            }
        }
    else{
        resto=0;
        return false;
    }
}
//POST: (ritorna true sse è stato trovato un match in L(n) a partire da nodo(n)) && (ritorna per riferimento il resto della lista)
//PRE=(L(n)è una lista corretta, P ha dimP>0 elementi, chiamiamo vL(n)=L(n))
nodo* match(nodo* &n, int* P, int dimP){
    if(!n) return 0; // caso base 1
    nodo* x;
    if(check(n, P, dimP, x)){ //caso base 2
        nodo* tmp=n;
        n=x;
        return tmp;
    }
    else    //caso ricorsivo
        return match(n->next, P, dimP);
}
/*POST=(in L(n) c’è un match di P, allora la funzione restituisce col return match(vL(n),P[0..dimP-1]) e 
L(n)=resto_mach(vL(n),P[0..dimP-1], se invece non c’è il match allora la funzione restituisce 0 e L(n)=vL(n))
DIMOSTRAZIONE match:
- caso base 1: !n: L(n) è vuota, dunque non esiste match, ritorno 0 e non ritorno nulla con il riferimento, poichè non esiste resto => POST
    se esiste L(n), invoco check: la sua PRE condizione è verificata, in quanto le stesse assunzioni sono fatte dalla PRE di match, e questi elementi non vengono modificati
    Dunque, assumendo che check sia corretta, dopo l'invocazione vale la sua POST, perciò:
    - se ritorna true (caso base 1), allora è stato trovato un match a partire da nodo(n), l'ultimo nodo del match è stato scollegato dal resto della lista e x, passato per riferimento,
      punta alla lista composta dai nodi (se esistono) dopo il match. Dunque n punta alla lista del match, perciò lo ritorno. x, il resto, lo passo indietro per riferimento => POST
    - se false (caso ricorsivo), effettuo la chiamata ricorsiva su n->next. Qui la PRE_ric è verificata in quanto L(n), P, dimP non vengono modificati dall'inizio della funzione.
      Dunque, per ipotesi induttiva, vale la POST ric. Dunque L(n-next) sarà una sottolista senza match, ritorno il puntatore ritornato dalla chiamata ricorsiva, che sarà
      il puntatore alla lista match (se esiste), altrimenti 0 =>POST*/
int main(){
    int dim, dimP, P[20];
    cout<<"start"<<endl;
    cin>>dim;
    nodo* L1=crea(dim);
    cin>>dimP;
    leggi(dimP, P);
    nodo* L2=match(L1, P, dimP);
    stampa(L2);
    stampa(L1);
    cout<<"end"<<endl;
    return 0;
}