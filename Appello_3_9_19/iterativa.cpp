#include <iostream>
using namespace std;

struct nodo
{
    int info;
    nodo *left, *right;
    nodo(int a = 0, nodo *b1 = 0, nodo *b2 = 0)
    {
        info = a;
        left = b1;
        right = b2;
    }
};
struct nodoEx
{
    nodo *info;
    int liv;
    nodoEx *next;
    nodoEx(nodo *a = 0, int b = 0, nodoEx *c = 0)
    {
        info = a;
        liv = b;
        next = c;
    }
};
struct coda
{
    nodoEx *inizio, *fine;
    coda(nodoEx *a = 0, nodoEx *b = 0)
    {
        inizio = a;
        fine = b;
    }
};
//PRE=(x è una coda che gestisce una lista di nodoEx ben formata e a punta ad un nodoEx)
coda push_end(coda x, nodoEx *a)
{
    a->next = 0;
    if (x.inizio)
    {
        x.fine->next = a;
        x.fine = a;
    }
    else
        x.inizio = x.fine = a;

    return x;
}
//POST=(restituisce la coda x che gestisce la lista originale con il nodoEx a aggiunto alla fine della lista)
//PRE=(C.inizio non è 0)
nodoEx *pop(coda &C)
{
    nodoEx *x = C.inizio;
    C.inizio = C.inizio->next;
    if (C.inizio == 0)
        C.fine = 0;
    return x;
}
//POST=(modifica C eliminando il suo primo nodoEx e restituendolo col return )

int contanodi(nodo *r)
{
    if (!r)
        return 0;
    return contanodi(r->left) + contanodi(r->right) + 1;
}
nodo *ins(nodo *R, int x)
{
    if (!R)
        return new nodo(x);
    else if (contanodi(R->left) <= contanodi(R->right))
    {
        R->left = ins(R->left, x);
        return R;
    }
    else
    {
        R->right = ins(R->right, x);
        return R;
    }
}

void stampaLista(nodoEx *e)
{
    if (!e)
    {
        cout << "fine dc" << endl;
        return;
    }
    else
    {
        cout << e->info->info << " ";
        stampaLista(e->next);
    }
}

void stampa_lin(nodo *r)
{
    if (r)
    {
        cout << '[' << r->info << ']' << '(';
        stampa_lin(r->left);
        cout << ',';
        stampa_lin(r->right);
        cout << ')';
    }
    else
        cout << '_';
}
//PRE=(albero(R) è un albero binario ben formato, x è definito, T contiene un numero di posizioni pari al
//doppio del numero dei nodi di albero(R) )
void perlar(nodo*R, int x, int*T, int& nt) {
    nodoEx n=new nodo();
    n.info=R;
    n.liv=0;
    coda *c = new coda();
    coda cc=push_end(*c,&n);
    int lvl_attuale=0, posizione=1, pos_nt=0;
    int elementi=1;
 
    for(nodoEx*temp=0;elementi>0;posizione++,elementi--){
        temp =pop(cc);
        if(temp->info->left){
 
            cc=push_end(cc,new nodoEx(temp->info->left,temp->liv+1,0));
            elementi++;
        }
        if(temp->info->right){
            cc=push_end(cc,new nodoEx(temp->info->right,temp->liv+1,0));
            elementi++;
        }
        if(temp->liv>lvl_attuale){
            lvl_attuale++;
            posizione=1;
        }
        if(temp->info->info==x){
            T[pos_nt]=lvl_attuale;
            T[pos_nt+1]=posizione;
            pos_nt=pos_nt+2;
            nt++;
        }
    }
 
 
}
//POST=(nt è è il numero di nodi con info=x in albero(R) e T contiene il livello e la posizione di ciascuno degli
//nt nodi nell’ordine del percorso in larghezza)
main()
{
    cout << "start" << endl;
    int n, num = 0, ntrova = 0;
    nodo *R = 0;
    cin >> n;
    while (n != -1)
    {
        R = ins(R, n);
        num++;
        cin >> n;
    }
    stampa_lin(R);
    cout << endl;

    int *T = new int[2 * num];
    cin >> n;
    perlar(R, n, T, ntrova);
    if (!ntrova)
        cout << "nessun nodo con info=" << n << endl;
    else
    {
        cout << n << " compare nei seguenti nodi:" << endl;
        for (int j = 0; j < ntrova; j++)
            cout << "Livello=" << T[2 * j] << " posizione=" << T[2 * j + 1] << endl;
    }
    cout << "end" << endl;
}