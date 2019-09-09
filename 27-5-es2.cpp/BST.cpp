#include "BST.h"
 #include<iostream>
 using namespace std;
 // ricordo: stiamo lavorando con un albero BST
 nodo*& min(nodo*&n) {
     if(!n->left)
        return n;
    else return min(n->left);
 }
//PRE=(albero(n) ben formato e x definito)
nodo*& find(nodo*& n, int x) {
    if(!n){
        nodo *p = new nodo(0,0,0);
        return p;
    }
    if(n->info == x) {
        return n;
    }
    else if(n->info<x)
        return find(n->right,x);
        else 
        return find(n->left,x);
}
//POST=(albero(n) è il nodo con campo info=x oopure albero(n) è un nodo "vuoto")
/*
CORRETTEZZA:
- caso base2: n->info=x => ho trovato il nodo che cercavo e lo ritorno come alias => POST
- caso base1: !n=> non ho trovato il nodo con campo info=x, allora torno un nodo "vuoto"
- caso ricorsivo1: n->info<x => essendo un albero BST richiamo la funzione a destra, pre_ric è verificata in quanto n->right è ben formato, altrimenti 
saremmo rimasti al caso base, allora per ipotesi induttiva post_ric è verificato, allora n è "vuoto" (nel caso finisse in caso base1) oppure è il nodo con 
campo info=x (caso base2) => POST
- caso ricorsivo2: n->info>=x => essendo un albero BST richiamo la funzione a sinistra, pre_ric è verificata in quanto n->left è ben formato, altrimenti 
saremmo rimasti al caso base, allora per ipotesi induttiva post_ric è verificato, allora n è "vuoto" (nel caso finisse in caso base1) oppure è il nodo con 
campo info=x (caso base2) => POST
*/

void stampa_l(nodo *n) {
    if(n) {
        cout<<n->info<<"(";
        stampa_l(n->left);
        cout<<",";
        stampa_l(n->right);
        cout<<")";
    }
    else {
        cout<<"_";
    }
}


nodo* insert(nodo*r, int x){
        if(!r) return new nodo (x,0,0);
        if(x>r->info) r->right=insert(r->right,x);
        else r->left=insert(r->left,x);
        return r;
}
nodo* max(nodo*r){
    if (!r->right) return r;
    else max(r->right);
}
bool search(nodo*r, int x){
    if (!r) return false;
    if(r->info==x) return true;
    if(x>r->info)search(r->right,x);
    else search(r->left,x);
    return false;
}
int altezza (nodo*r) {
    if (!r) {
        return -1;
    } else {
        int a=altezza(r->left);
        int b=altezza(r->right);
        if (a>b) {
            return 1+a;
        } else {
            return 1+b;
        }
    }
}
 
int altMin (nodo*r) {
    if (!r) {
        return 0;
    } else {
        int a=altezza(r->left), b=altezza(r->right);
        if (a<b) {
            return 1+a;
        }
        if (b<a) {
            return 1+b;
        }
    }
}

int main() {
    cout<<"start"<<endl;
    //prepara un albero iniziale non triviale
    nodo* r=new nodo(15, new nodo(7), new nodo(19));
    r->left->right=new nodo (9, new nodo(8));
    r->right->right=new nodo(25, new nodo(22));
    bool stop=false;
    while(!stop) {
        int x;
        cin>>x;
        switch (x) {
            case 0:
                stop = true;
                break;
            case 1:
                stampa_l(r);
                cout<<endl;
                break;
            case 2:
                int y;
                cin>>y;
                insert(r, y);
                stampa_l(r);
                cout<<endl;
                break;
            case 3:
                int z;
                cin>>z;
                if (!search(r, z)) {
                    cout<<"valore "<<z<<" non presente"<<endl;
                } else {
                    cout<<"valore "<<z<<" presente"<<endl;
                }
                break;
            case 4:
                int q;
                cin>>q;
                switch (q) {
                    case 1:
                        cout<<max(r)->info<<endl;
                        break;
                    case 2:
                        cout<<min(r)->info<<endl;
                        break;
                }
                break;
            case 5:
                cout<<altezza(r)<<endl;
                break;
            case 6:
                cout<<altMin(r)<<endl;
                break;
            case 7:
                int a;
                cin>>a;
                elim(r,a);
                stampa_l(r);
                break;
        }
    }
    cout<<"end"<<endl;
}