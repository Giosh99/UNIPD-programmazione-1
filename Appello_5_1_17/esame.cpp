#include<iostream>
using namespace std;
//-------------------strutture dati------osservare costruttore di FIFOX-----------------------
struct nodo {
int info;
nodo *next; 
nodo(int a=0, nodo*b=0){info=a; next=b;}
};

struct FIFOX {
nodo *primo, *ultimo;
int val_p, val_u, n_ele;
FIFOX(nodo*a=0,nodo*b=0, int c=0, int d=0, int e=0) 
 {
  
      primo=a;
      ultimo=b;
      val_p=c;
      val_u=d;
      n_ele=e;
  }
};

struct nodo_x{
FIFOX* fix;
nodo_x *next;
nodo_x(FIFOX *a=0,nodo_x*b=0){
    fix=a;next=b;
}
};
//-------------------------------------funzioni date----------------------------
//trova ultimo nodo di lista non vuota
nodo* ult(nodo*n){if(!n->next) return n; return ult(n->next);}
//calcola lungheza di lista
int length(nodo*n){if(!n) return 0; return 1 + length(n->next);}

nodo* build(int n)//costruisce lista di n nodi
{
  if(n>0)
   {
     int x;
     cin >> x;
     return new nodo(x, build(n-1));
   }
 return 0;

}

nodo_x* fai()//costruisce la lista nodo_x su cui far girare partiziona
{
  
       nodo_x*m1=new nodo_x;
       int n;
       cin >> n;
       nodo*x1=build(n);
       m1->fix=new FIFOX(x1,ult(x1), x1->info, ult(x1)->info, n);
       return m1;
}
  

void stampaL(nodo* L)
{
  if(L)
   {cout<<L->info<<' '; stampaL(L->next);}
  else
    cout<<endl;
}
 void stampaT(nodo_x* x,int n)
 {
   if(x)
    {
      cout<<"nodo_x n."<<n<<" primo="<<x->fix->val_p<<" ultimo="<<x->fix->val_u<<':'<<"lista=";
      stampaL(x->fix->primo);
      stampaT(x->next,n+1);
    }
 }
nodo* cloneL(nodo*a)//fa copia di lista di tipo nodo
{
  if(a)
    return new nodo(a->info, cloneL(a->next));
  return 0;
}
nodo_x* clone(nodo_x* a)//fa copia di lista di tipo nodo_x
{
  FIFOX *b= a->fix;
  nodo*c=cloneL(b->primo);
  nodo_x* d=new nodo_x;
  d->fix=new FIFOX(c,ult(c),b->val_p, b->val_u,b->n_ele);
  return d;
}
//INIZIO
void partiziona_it(nodo_x * N, int k){
    nodo *n= N->fix->primo;
    nodo *first = N->fix->primo;
    int count = N->fix->n_ele/k;
    int resto = N->fix->n_ele%k;
    int c = k;
    //cout<<count<<endl;
    while(count>0||resto>0) {
        if(N->fix->n_ele<k)
            return;
        while(c>1) {
            n = n->next;
            c--;
        }
        c = k;
        if(n->next) {
            nodo *tmp = n->next;
            nodo_x *x = new nodo_x(new FIFOX(tmp,N->fix->ultimo),0);
            n->next = 0;
            N->next = x;
            int ele = N->fix->n_ele-k;
            cout<<"ele "<<ele<<endl;
            N = N->next;
            N->fix->n_ele = ele;
            n = N->fix->primo;
            if(count==0)
                resto--;
            else
                count--;
            first = n;
        }
        else return;
    }
}


void partiziona_ric(nodo_x * N, int k){
}
//FINE
int main()
{
 cout<<"start"<<endl;
 nodo_x* T1=fai(), *T2=clone(T1);
 int k;
 cin >> k;
 stampaT(T1,0);
 partiziona_it(T1,k);
 stampaT(T1,0);
//partiziona_ric(T2,k);
 //stampaT(T2,0);
 cout<<"end"<<endl;
}