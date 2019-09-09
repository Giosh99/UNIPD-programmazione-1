#include<iostream>
using namespace std;
struct nodo {
    int chiave;
    nodo *next;
    nodo(int c='\0', nodo* n=NULL) {
        chiave = c;
        next= n;
    }
};

struct coda {
    nodo *inizio;
    nodo *fine;
    coda(nodo* i=NULL,nodo *f=NULL ){
        inizio = i;
        fine = f;
    }
};

void push(int c, coda &Q) {
    if(!Q.inizio) {
        Q.inizio = new nodo(c);
        Q.fine = Q.inizio;
    }
    else {
        Q.fine->next = new nodo(c);
        //Q.fine = Q.fine->next;
    }
}
int pop(coda &Q){
    if(!Q.inizio) {
        cout<<"vuota ";
        return '\0';
    }
    else {
        cout<<Q.inizio->chiave<<' ';
        nodo *n = Q.inizio->next;
        int c = Q.inizio->chiave;
         if(!Q.inizio->next)
            Q.fine  = NULL;
        delete(Q.inizio);
        Q.inizio = n;
        return c;
    }
}
bool e_vuota(coda Q) {
    if(!Q.inizio)
        return true;
}

void trasla(coda &Q,int k) {
    for(int i = 0; i<k-1; i++) {
        nodo * n = Q.inizio;
        Q.inizio = Q.inizio->next;
        n->next = NULL;
        nodo *n2 = Q.fine;
        Q.fine = n;
        n2->next = n;
    }
}

void stampa(nodo* &n) {
    if(n) {
        cout<<n->chiave<<" ";
        stampa(n->next);
    }
    else {
        cout<<"fine"<<endl;
    }
}

void riempiLista(int n, coda &Q) {
    for(int i = 0; i<n; i++) {
        push(i,Q);
    }
}

// IMPLEMENTARE I METODI DELLA LIBRERIA `coda`

int main() 
{
    coda Q;
    int k,n;
    int c;
    cout << "start" << endl;
    cin>>n;
    cin>>k; 
    riempiLista(n,Q);
    //stampa(Q.inizio);
    while(Q.inizio->next) {
        trasla(Q,k);
        pop(Q);
        cout<<"eliminata"<<endl;
    }
    cout<<Q.inizio->chiave<<" "<<"sopravvive"<<endl;
    cout << "end" << endl;
}