#include <iostream>
#include <fstream>
using namespace std;
struct nodo
{
    int info;
    nodo *next;
    nodo(int a = 0, nodo *b = 0)
    {
        info = a;
        next = b;
    }
}; // nodo di lista
struct FIFO
{
    nodo *primo, *ultimo;
    FIFO(nodo *a = 0)
    {
        primo = a;
        ultimo = a;
    }
};

FIFO push_end(FIFO a, nodo *b)
{
    if (!a.primo)
    {
        a.primo = a.ultimo = b;
    }
    else
    {
        a.ultimo->next = b;
        a.ultimo = b;
    }
    return a;
}

struct nodoF
{
    FIFO fi;
    nodoF *next;
    nodoF(FIFO a = FIFO(), nodoF *b = 0)
    {
        fi = a;
        next = b;
    }
};

//funzioni ausiliarie

void stampa_L(nodo *L)
{
    if (L)
    {
        cout << L->info << ' ';
        stampa_L(L->next);
    }
    else
        cout << endl;
}
void stampa_F(nodoF *a)
{
    if (a)
    {
        stampa_L(a->fi.primo);
        cout << endl;
        stampa_F(a->next);
    }
    else
        cout << endl;
}

nodo *costruisci(int dim)
{
    if (dim)
    {
        int x;
        cin >> x;
        return new nodo(x, costruisci(dim - 1));
    }
    return 0;
}
nodo *pop(nodo *&L)
{
    if (!L)
        return 0;
    else
    {
        nodo *tmp = L;
        L = L->next;
        tmp->next = 0;
        return tmp;
    }
}
nodoF *inserisci(FIFO f, nodoF *L)
{
    nodoF *p = L;
    bool trovato = false;
    if (L)
    {
        if (L->fi.primo->info > f.primo->info)
        {
            nodoF *nodo = new nodoF(f, L);
            return nodo;
        }
        else
        {
            while (L && !trovato)
            {
                if (!L->next)
                {
                    //cout<<"ok";
                    L->next = new nodoF(f);
                    trovato = true;
                }
                if (L->next->fi.primo->info > f.primo->info)
                {
                    nodoF *in = new nodoF(f, L->next);
                    L->next = in;
                    trovato = true;
                }
                else
                    L = L->next;
            }
            cout<<"fatto"<<endl;
            return p;
        }
    }
}
//PRE=(Q è lista corretta di nodo)
nodoF *smembra(nodo *Q)
{
    nodo *n = 0;
    nodoF *Lista = new nodoF();
    while (Q)
    {
        n = pop(Q);
        stampa_L(Q);
        //fin qui ok
        FIFO f = FIFO(n);
        //cout<<f.primo->info<<endl;
        if (Q)
        {
            nodo *p = Q;
            stampa_L(p);
            cout<<p->info<<endl;
            while (true)
            {
                cout<<"so good ";
                if (p->info == f.primo->info)
                {
                    cout<<"ok";
                    f = push_end(f, p);
                }
                p = p->next;
            }
            cout<<"i";
            Lista = inserisci(p,Lista);
            Q = Q->next;
        }
        Lista = inserisci(n,Lista);
    }
    return Lista;
}
//POST=(restituisceuna lista concatenata di nodoF che contiene le sottoliste di Q come mostrato nell'esempio 2, cioè inordine di campo info crescenti)
main()
{
    int dim;

    cin >> dim;
    nodo *C = costruisci(dim);

    cout << "Lista costruita" << endl;
    stampa_L(C);
    nodoF *a = smembra(C);
    cout << "Liste uniformi:" << endl;
    stampa_F(a);

   /* nodo *b = LO(a);
    cout << "Lista ordinata" << endl;
    stampa_L(b);
    cout << "end";*/
}