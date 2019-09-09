#include<iostream>
using namespace std;

struct nodo{
    int info; 
    nodo* left,*right; 
    nodo(int a=0, nodo* b=0, nodo*c=0){
        info=a; left=b; right=c;
    }
};

int conta(nodo *n) {
    if(!n)
        return -1;
    int a = conta(n->left)+1;
    int b = conta(n->right)+1;
    return a+b;
}
void stampa(nodo *n) {
    if(n) {
        cout<<n->info<<"(";
        stampa(n->left);
        cout<<",";
        stampa(n->right);
        cout<<")";
    }
    else {
        cout<<"_";
    }
}
//PRE=(n è ben formato e i definito)
void InsertNode(nodo *&n, int i ) {
    if(!n) { // caso base
        n = new nodo(i);
        return;
    }
    if(conta(n->left)+1 > conta(n->right)+1) //caso ricorsivo 1
        InsertNode(n->right,i);
    else 
        InsertNode(n->left,i); //caso ricorsivo 2
}
//POST=(albero(n) è un albero ben formato e non vuoto)
/*
- caso base: !n => creo un nodo con info=i => POST
- caso ricorsivo1: conta(n->left)>conta(n->right) => dato che a sinistra c'è una concentrazione maggiore di nodi procedo verso destra per mantenere
    l'albero bilanciato, pre_ric è verificata in quanto se r->right fosse NULL ci saremmo fermati alla codizione inziale (caso base), allora per 
    ipotesi induttiva post_ric è verificato, allora n è ben definito => POST
-caso ricorsivo2: conta(n->left)<=conta(n->right) => dato che a destra c'è una concentrazione maggiore di nodi procedo verso sinistra per mantere 
    l'albero bilanciato, pre_ric è verificata in quanto se r->left fosse NULL ci saremmo fermati alla codizione inziale (caso base), allora per 
    ipotesi induttiva post_ric è verificato, allora n è ben definito => POST
*/

//PRE=(albero(R) ben formato e dim valori da leggere)
void buildtree(nodo*& R, int dim) {
    if(dim != 0) {
        int i;
        cin>>i;
        InsertNode(R,i);
        buildtree(R, dim-1);
    }
}
int main() {
//nodo *root = new nodo(1, new nodo(2, new nodo(3), new nodo(4)), new nodo(3));
nodo *root = 0;
int a;
cin>>a;
buildtree(root,a);
stampa(root);
//cout<<conta(root)<<endl;
}