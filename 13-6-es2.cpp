#include<iostream>
using namespace std;

struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};

nodo* crea(int dim)
{
 if(dim)
  {
    int x;
    cin>>x;
    return new nodo(x,crea(dim-1));
  }
 return 0;
}


void leggi(int dim, int*P)
{
  if(dim)
   {
    cin>>*P;
    leggi(dim-1,P+1);
   }

}
void stampa(nodo *L){
    if(!L){
        cout<<endl;
        return;
    }
    cout<<L->info<<" ";
    stampa(L->next);
}
//PRE=
bool check(nodo*n, int *P, int dimP, nodo *&p) {
    if(!n)
        return false;
    if(n->info == *P) {
        if(dimP==1) {//caso base 
            if(n->next) {
                p = n->next;
                n->next = 0;
            }
            else 
                p = 0;
            return true;
        }
        else {
            if(check(n->next,P+1,dimP-1, p)) {
                stampa(p);
                return true;
            }
            else 
                return false;        
        }

    }
    else 
        return false;
    

}

//PRE=(L(n) è una lista corretta, P ha dimP elementi, chiamiamo vL(n)=L(n))
// si ritorna il resto della lista
nodo* match(nodo* &n, int*P, int dimP) {
    nodo *p = 0;
    if(!n)
        return 0;
    if(check(n,P, dimP, p)) {
        cout<<"n"<<endl;
        stampa(n);
        nodo *tmp = n;
        n = p;
        return tmp;
    }
    else return match(n->next,P,dimP);
}
//POST=(in L(n) c’è un match di P, allora la funzione restituisce col return match(vL(n),P[0..dimP-1]) e
//L(n)=resto_mach(vL(n),P[0..dimP-1], se invece non c’è il match allora la funzione restituisce 0 e L(n)=vL(n))
main()
{
  int dim, dimP, P[20];
  cout<<"start"<<endl;
  cin>>dim;
  nodo* L1=crea(dim);
  cin>>dimP;
  leggi(dimP, P);
  nodo* L2= match(L1,P, dimP);//da fare
  stampa(L2); //da fare
  stampa(L1);
  cout<<"end"<<endl;
}