using namespace std;
#include<iostream>
struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};
struct nodoP{nodo* P; nodoP* next; nodoP(nodo* a=0, nodoP* b=0){P=a; next=b;}};

nodo* leggi() {
    nodo *n = new nodo();
    int c;
    cin>>c;
    if(c == -1)
        return NULL;
    else {
        n->info = c;
        n->next = leggi();
    }
    return n;
}

void stampa(nodo*n) {
    if(!n)
        return;
    else  {
        cout<<n->info<<" ";
        stampa(n->next);
    }
}
//PRE=(Lista(L) è ben formata, x è definito)
nodoP* aux(nodo*L, int x) {
    nodoP *n = new nodoP();
    if(!L) //caso base: una volta scorsa la lista L ho finito i controlli
        return NULL;
    if(L->info == x) { //caso ricorsivo1: trovo un elemento di L con campo info=x => aggiunfo a L(n) il nodo con tale campo info e continuo a scorrere L(L)
        n->P = L;
        n->next = aux(L->next, x);
    }
    else 
        n = aux(L->next,x); //caso ricorsivo2: L->info corrente != x => continuo a scorrere la lista
    return n;
}
//POST=(restituisce una lista di nodoP lunga come il n. di nodi di Lista(L) con x=info e i
/*
CORRETTEZZA
- caso base: !L => ho scorso la L(L)
- caso ricorsivo1: L->info==x => trovo un elemento di L con campo info=x => aggiunfo a L(n) il nodo con tale campo info e continuo a scorrere L(L)
- caso ricorsivo2: L->info != x => Pre_ric verificata in quanto L->next è ben formata, per ipotesi induttiva vale post_ric
*/
//scui nodi puntano a questi nodi di L nell’ordine in cui i nodi sono in L)
nodoP* ultimo(nodoP*n) {
    if(n->next)
        n = ultimo(n->next);
    else
        return n;
}
//PRE=(L(L) ben formata e cin contiene -1)
nodoP* F(nodo *L) {
    int i;
    cin>>i;
    nodoP *p = new nodoP();
    if(i==-1)
        return NULL;
    p = F(L);
    if(!p) {
        p = aux(L,i);
        return p;
    }
    else {
        nodoP *p2 = new nodoP();
        p2 = aux(L,i);
        if(p2) {
            ultimo(p2)->next = p;
            return p2;
        }
        else return p; 
    }
}
void stampa(nodoP * F) { 
      cout <<F->P->info<<" ";
      if(F->next == NULL) 
        return;
     stampa(F->next);
}
main()
{
  cout<<"start"<<endl;
  nodo*L=leggi();
  nodoP*y=F(L);
  if(y)
    stampa(y);
  cout<<"end"<<endl;

}





