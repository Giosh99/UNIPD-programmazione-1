#include<iostream>
using namespace std;
#include<fstream>
struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}}; // nodo di lista 
struct FIFO{nodo* primo, *ultimo;FIFO(nodo*a=0, nodo*b=0){primo=a; ultimo=b;}};
struct nodot{int info; nodot* left, *right; nodot(int a=0, nodot* b=0, nodot* c=0){info=a; left=b; right=c;}};//nodo di albero
FIFO push_end(FIFO a, nodo*b)
{
  if(!a.primo)
  {a.primo=a.ultimo=b;}
  else
   {a.ultimo->next=b; a.ultimo=b;}
  return a;
}

void stampa_L(nodo*L)
{
 if (L)
  {cout<<L->info<<' '; stampa_L(L->next);}
 else
   cout<<endl;

}
nodo* costruisci(int dim)
{
 if(dim)
   {int x; cin>>x; return new nodo(x,costruisci(dim-1));}
 return 0;
}
 nodo* clone(nodo*a)
 {
  if(a)
  {return new nodo(a->info, clone(a->next));}
  return 0;
 }

 FIFO  push_begin(FIFO x, nodo* b){
    if(x.primo==0 && x.ultimo==0){
        x.primo=b;
        x.ultimo=b;
    }else{
        b->next=x.primo;
        x.primo=b;
    }
    return x;
 }
nodo* presente(nodo* n, int y){
    if(n==0){
        return 0;
    }else{
        if(n->info==y){
            return n;
        }else{
           return presente(n->next, y); 
        }
    }
}
 
bool presente_iter(nodo* n, int y){
    bool b=false;
    while(n!=0 && !b){
        if(n->info==y){
            b=true;
        }
    }
    return b;
}
 
//PRE=(L(Q) è una lista corretta e vL(Q)=L(Q))
FIFO tieni_ultimo_ric(nodo*&Q){
    FIFO r;
    //caso base la lista e' vuota
    if(Q==0){//CB1
        return FIFO();//la lista dei nodi ripetuti su una lista vuota e' anche essa vuota
    }else{
        //caso ricorsivo
        r=tieni_ultimo_ric(Q->next);
        nodo *p=presente(Q->next, Q->info);//CR1
        if(p!=0){//allora q e' un duplicato
            nodo *a=Q;
            Q=Q->next;
            a->next=0;
            r=push_begin(r,a);
            
        }
        //r=push_end(r,0);
       return r;
    }
}
//PRE=(n e L(f) sono ben formate)
bool check(nodo* f, int y){ //n [ il nodo che devo controllare
if(!f)
  return false;
  if(f->info==y)
      return true;
  else return check(f->next,y);
}
//POST=(ritorna true<=>c'e' un elemento in f con campo info=n)
FIFO tieni_ultimo_iter(nodo *&Q)
{
  FIFO f = FIFO();
  nodo*p = Q;
  FIFO x;
  while (p)
  {
    if (check(p->next, p->info))
    {
    //  cout<<p->info<<endl;
      
      nodo *tmp = p;
      p = p->next;
      tmp->next = 0;
      f = push_end(f,tmp);
    }
    else {
      x = push_end(x,p);
    //  cout<<x.primo->info<<endl;
    p = p->next;
    }
  }
  Q = x.primo;
  return f;
}
//stesse PRE e POST dell'esercizio (2).

//fine
int main()
{
  
   int dim;
   
   cin>>dim;
   nodo*C=costruisci(dim);
   nodo* D=clone(C);
   cout<<"Lista costruita"<<endl;
   stampa_L(C);
   FIFO a =tieni_ultimo_ric(C);
   cout<<"soluzione ricorsiva"<<endl<<"nodi tolti:"<<endl;
   
   stampa_L(a.primo);
   cout<<"lista rimanente:"<<endl;
   stampa_L(C);
   FIFO b=tieni_ultimo_iter(D);
   cout<<"soluzione iterativa"<<endl<<"nodi tolti:"<<endl;
   stampa_L(b.primo);
   cout<<"lista rimanente:"<<endl;
   stampa_L(D);
   cout<<"end";
}