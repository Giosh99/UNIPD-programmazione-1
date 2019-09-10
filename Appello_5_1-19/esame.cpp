#include<iostream>
using namespace std;

struct nodo{int info; nodo* next; nodo(int a =0, nodo* b=0){info=a; next=b;}};
struct nodoL{nodo* info; nodoL* next; nodoL(nodo* a =0, nodoL* b=0){info=a; next=b;}};


nodo* clone(nodo*L)
{
  if(L)
    return new nodo(L->info,clone(L->next));
  return 0;
}

void stampaL(nodo*L)
{
  if(L)
    {cout<<L->info<<' '; stampaL(L->next);}
  else
    cout<<endl;

}
void stampaLL(nodoL*LL,int n)
{
  if(LL)
    {cout<<"fetta "<<n<<") "; stampaL(LL->info); stampaLL(LL->next,n+1);}
}

nodo* faiL(int n)
{
  if(n>0)
    return new nodo(n, faiL(n-1));
  return 0;

}
//INIZIO

//PRE=(lista(L) corretta, dimA >=0 e A contiene dimA interi  non negativi
nodoL* affettaric(nodo*&L, int*A, int dimA){
}
//POST L ha dentro i nodi che rimanenti
void push_end(nodoL *&L, nodoL *n) {
    nodoL*p = L;
    if(!L)
        L=n;
    else
    {
        while(p->next){
            p = p->next;
        }
        p->next = n;
    }
}
void push_end(nodo *&L, nodo *n){
    nodo*p = L;
    if(!L)
        L=n;
    else
    {
        while(p->next){
            p = p->next;
        }
        p->next = n;
    }
}
nodo* ultimo(nodo*n){
    if(!n)
        return 0;
    while(n->next)
        ultimo(n->next);
    return n;
}
nodoL* affettaiter(nodo*&L, int*A, int dimA){

    nodo *p = 0; // lista nodi per creare un nodoL
    nodoL*i = 0;// lista di nodiL da ritornare
    while(L&&dimA>0) {
        p = 0;
        cout<<"ini<io"<<*A<<endl;
        while (*A>0&&L)
        {
            if(!p) {
                nodo* tmp = L;
                L=L->next;
                tmp->next = 0;
                p = tmp;
                stampaL(L);
                *A = *A-1;
               // cout<<*A<<endl;
            }
            else
            {
                nodo* tmp = L;
                L=L->next;
                tmp->next = 0;
                push_end(p,tmp);
                stampaL(L);
                *A = *A-1;
               // cout<<*A<<endl;
            }
        }
        if(p&&!(*A)>0) {
            stampaL(p);
            push_end(i,new nodoL(p)); // comprende il caso in cui i=0
            stampaL(i->info);
        }
        else if(!p||*A==0) {
            cout<<"caso non esista p"<< *A<<endl;
            push_end(i, new nodoL(0,0));
        }
        if(*A>0){
            cout<<"non vi erano abbaztanza elementi"<<endl;
            L = p;
            return i;
        }
        else {
            A++;
            dimA = dimA-1;
        }
    }
    return i;
}   
//FINE
int main()
{
  cout<<"start"<<endl;
  nodo* L=faiL(10);
  nodo*L0=clone(L);
  int n, A[10];
  cin >> n;
  for(int i=0; i<n; i++)
    cin >> A[i];
  /*nodoL*K=affettaric(L,A,n);
  cout<<"Lric=";
  stampaL(L);
  cout<<"LLric:"<<endl;
  stampaLL(K,1);
  cout<<endl;*/
 nodoL* K=affettaiter(L0,A,n);
  cout<<"Liter=";
  stampaL(L0);
  cout<<"LLiter:"<<endl;
  stampaLL(K,1);
  cout<<"end"<<endl;
}