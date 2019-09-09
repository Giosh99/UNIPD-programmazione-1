#include<iostream>
using namespace std;
struct nodo {int info,num; nodo* left,*right; nodo(int a=0,int b=1, nodo*c=0, nodo*d=0){info=a; num=b; left=c; right=d;} };

void stampa_lin(nodo*r)
{
  if(r)
    {
      cout <<'['<<r->info<<','<<r->num<<']'<<'(';
      stampa_lin(r->left);
      cout<<',';
      stampa_lin(r->right);
      cout<<')';
    }
  else
  cout<<'_';
}
//PRE=(albero(r) è un albero binario benformato e BST in cui il campo num di ciascun
//nodo è corretto, Vr=albero(r), x è un qualsiasi intero)
void build_BST(nodo*&r, int x){   
    bool trovato = false;
    nodo*p = r;
   // cout<<"yep"<<endl;
    if(!p) {
        r = new nodo(x);
        p = r;
       // cout<<"primo valore "<<p->info<<endl;
        return;
    }
    while(!trovato) { //R=(!trovato=true => non ho trovato ancora il posto esatto in cui posizionare il nodo)
                    //&&(!trovato=false=> ho trovato il posto corretto rispetto al BST e ho inserito il nodo)&&(p punta ai nodi di albero(r))
        if(p->info>x) {
            p->num++;
            if(!p->left) {
                p->left = new nodo(x);
                trovato = true;
            }
            else 
                p = p->left;
        }
        else if(p->info<=x) {
            p->num++;
            if(!p->right) {
                p->right = new nodo(x);
                trovato = true;
            }
                
            else 
                p = p->right;
        }   
    }
    return;
}
//POST=(albero(r) è ben formato, BST e con i campi num corretti ed è ottenuto da Vr
//aggiungendo il nodo con info=x come foglia)
/*
CORRETTEZZA
1) PRE=>R, trovato = false=> !trovato=true => cerco il posto corretto per il nuovo nodo secondo la politica BST, p punta alla radice
2) R&&cond => R=> !trovato=true => scorro albero(r) e p punta al nodo corrente
3) R&&!(cond) => !trovato=false => ho inserito il nuovo nodo in albero(r), p punta al nodo padre
*/
main()
{
  cout<<"start"<<endl;
  int n;
  nodo*R=0;
  cin >>n;
    while (n !=-1)
      {
      build_BST(R,n);
      cin>>n;
      }
  stampa_lin(R);
  cout<<endl;
  cout<<"end"<<endl;
}
