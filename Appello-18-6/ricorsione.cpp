#include<iostream>
using namespace std;

struct nodo{int info; nodo* next;nodo(int a=0, nodo* b=0){info=a; next=b;}};

nodo* faiLista()
{
  int x;
  cin>> x;
  if(x==-1) return 0;
  return new nodo(x, faiLista());
}
void stampaL(nodo*L)
 {
   if(L)
     {
       cout<<L->info<<' ';
       stampaL(L->next);
     }
   cout<<endl;

 }
 nodo* findNode(nodo*n, int x) {
    if(!n)
        return 0;
    if(n->info == x)
        return n;
    else return findNode(n->next,x);
 }
 nodo* Fine(nodo*n) {
    if(!n->next)
        return n;
    if(!n)
        return 0;
    else 
        return Fine(n->next);
 }
 nodo* prendiNodo(nodo*inizio,nodo*fine,int x, nodo*&L) {
    if(inizio) {
        if(inizio->info!=x) {
            fine->next = inizio;
            fine = inizio;
            inizio = inizio->next;
            fine->next = 0;
            stampaL(inizio);
            return prendiNodo(inizio, fine,x, L);
        }
        else if(inizio->info == x) {
            nodo*tmp = inizio;
          //  cout<<fine->info<<endl;
            inizio = inizio->next;
            fine->next = tmp->next;
            //cout<<fine->info<<endl;
            tmp->next = 0;
            //stampaL(inizio);
            L = inizio;
            return tmp;
        }
    }
 }
 //POST=(restituisce il nodo con info=x)
//PRE=(Lista(L) bel formata, A ha nA elementi, vL=L)
nodo* patt_match(nodo*&L, int*A, int nA){
    nodo*inizio = L;
    nodo*fine = Fine(L);
    nodo*n = prendiNodo(inizio, fine, *A, L);
    cout<<n->info<<endl;
    if(!n->next)cout<<"ok"<<endl;
    fine->next = 0;
    if(nA==1)
        return n;
    else 
        Fine(n)->next =  patt_match(L,A+1,nA-1);
    return n;
}
//POST=(L è la lista che consiste dei nodi di vL che matchano con A e col return restituisce la lista degli altri
//nodi di vL)
main()
{
  cout<<"start"<<endl;
  nodo*K=faiLista();
  int nA;
  cin >>nA;
  int * A= new int[nA];
  for(int i=0; i<nA; i++)
    cin >>A[i];
    cout<<"inizio K "<<K->info<<endl;
    stampaL(K);
  nodo* X=patt_match(K,A,nA);
  cout<<"lista del match:"<<endl;
  stampaL(K);
  cout<<"lista rimasta:"<<endl;
   stampaL(X);  
   cout<<"end"<<endl;
}
