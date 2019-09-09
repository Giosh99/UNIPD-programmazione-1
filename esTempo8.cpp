#include<iostream>
using namespace std;
struct nodo{int info; nodo*next; nodo(int a=0, nodo*b=0){info=a; next=b;}};
// funzioni per input e output
nodo *buildL(int k)
{
  if(!k) return 0;
  else
    {
      int x;
      cin>>x;
      return new nodo(x,buildL(k-1));
    }
}
void leggiA(int*A,int k)
{
  for(int i=0; i<k; i++)
    cin>>A[i];
}
nodo* clone(nodo*L)
{
  if(!L) return 0;
  else
    return new nodo(L->info,clone(L->next));
}
void stampa(nodo*L)
{
  if(!L) cout<<endl;
  else
    {
      cout<<L->info<<' ';
      stampa(L->next);

    }
}
//PRE=(lista(L) ben formata, i definita)
nodo * individua(nodo *L, int i){
    if(!L)
        return NULL;
    else {
        if(i == 1)
            return L;
        else 
            return individua(L->next, i-1);
    }
}
//POST=(la funzione  individuare la porzione di L da “staccare” per poi aggiungerla in coda ad L1 o ad L2, o in caso non vi fosse ritorna NULL)
nodo * ultimo(nodo *L) {
    if(L)
        ultimo(L->next);
        else
        {
            return L;
        }
}
//PRE=()
nodo * connetti(nodo*&L, nodo *nL, nodo*porzione) {
    if(!nL) {
        nL = L;
        L = porzione->next;
        porzione->next = 0;
        return nL;
    }
    else {
        connetti(nL,ultimo(nL),porzione);
    }
}
//POST=()
//PRE=(lista(L), lista(L1), e lista(L2) sono ben formate, A contiene dimA elementi non negativi, con dimA pari>=0, vL=lista(L),vL1=lista(L1),vL2=lista(L2))
void Fric(nodo*L, int*A, int dimA, nodo*&L1, nodo*&L2) {
    if(!L || dimA==0)
        return;
    if(dimA%2!=0) {
        nodo*n = individua(L,*A);
        if(!L2)
            
    }
}
//POST=(i nodi di vL sono distribuiti correttamente su 2 liste X1 e X2 secondo i valori di A e L1=vL1@X1 e L2=vL2@X2)
main()
{
  cout<<"start"<<endl;
  int n, dimA;
  cin >> n ;//>> dimA;
  int*A=new int[dimA];
  nodo*L=buildL(n);
  stampa(L);
  //leggiA(A,dimA);
  
  nodo*L1=0,*L2=0;
 // Fric(L,A,dimA,L1,L2);
 nodo *p = individua(L,2);
 cout<<p->info<<endl;
 L1 = connetti(L,L1,p);
  stampa(L1);
  //stampa(L2);
  
  cout<<"end"<<endl;
}
