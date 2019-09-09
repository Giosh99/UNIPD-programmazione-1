#include<iostream>
using namespace std;
struct nodo {
    char chiave;
    nodo *next;
    nodo(char c='\0', nodo* n=NULL) {
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

//che aggiunge un nuovo elemento con chiave == c alla fine della coda Q;
void push(char c, coda &Q) {
    if(!Q.inizio) { // allora la coda è vuota
        Q.fine = new nodo(c,0);
        Q.inizio = Q.fine;
    }
    else {
        Q.fine->next = new nodo(c,0);
        Q.fine = Q.fine->next;
    }
}
// che estrae l’elemento all’inizio della coda Q, lo rimuove dalla coda e ne ritorna la chiave;
char pop(coda &Q) {
    if(!Q.inizio) 
        return '\0';
    else {
        char c = Q.inizio->chiave;
        Q.inizio = Q.inizio->next;
        return c;
    }
}
//che ritorna true se e solo se la coda Q `e vuota.
bool e_vuota(coda Q) {
    if(!Q.inizio)
        return true;
}
int main() {
    char c;
    coda Q = coda();
    cout<<"start"<<endl;
    while(c!='.') {
        cin>>c;
        if(c!='.') {
            if(c=='*') {
                char v = pop(Q);
                if(v!='\0')
                    cout<<v<<endl;
                else 
                    cout<<"vuota"<<endl;
            }
            else {
                push(c,Q);
            }
        }    
    }
    cout<<"end";
}