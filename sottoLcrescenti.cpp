#include <iostream>
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
};
struct doppioN
{
    nodo *inizio, *fine;
    int lung;
    doppioN(nodo *a = 0, nodo *b = 0, int c = 0)
    {
        inizio = a;
        fine = b;
        lung = c;
    }
};

nodo *build(int n)
{
    if (n > 0)
    {
        int x;
        cin >> x;
        return new nodo(x, build(n - 1));
    }
    else
        return 0;
}
void stampa_DN(doppioN A)
{
    cout << "valore DN:" << A.inizio->info << ' ' << A.fine->info << " lung=" << A.lung << endl;
}
void stampaL(nodo *L)
{
    if (L)
    {
        cout << L->info << ' ';
        stampaL(L->next);
    }
    else
        cout << endl;
}
nodo *clone(nodo *L)
{
    if (L)
        return new nodo(L->info, clone(L->next));
    else
        return 0;
}
nodo *fine(nodo *n)
{
    if (!n)
        return 0;
    if (!n->next)
        return n;
    else
        fine(n->next);
}
void push_end(doppioN &L, nodo *n)
{
    if (!L.inizio)
    {
        L.inizio = L.fine = n;
        L.lung = 1;
    }
    else
    {
        L.fine->next = n;
        L.fine = L.fine->next;
        L.lung = L.lung + 1;
    }
    cout << "hola" << endl;
}
doppioN Fiter(nodo *L)
{
    doppioN A = 0;
    while (L)
    {
        int lung = 1;
        nodo *temp = L;
        while (temp->next && temp->info <= temp->next->info)
        {
            temp = temp->next;
            lung++;
        }
        if (!A.inizio)
        {
            A = doppioN(L, temp, lung);
        }
        else if (A.lung < lung)
        {
            A.inizio = L;
            A.fine = temp;
            A.lung = lung;
        }
        else
        {
            L = temp->next;
        }
    }
    return A;
}
//POST=(restituisce il valore doppioN che rappresenta la sotto lista crescente di lunghezza massima di L)
main()
{
    int n;
    cin >> n;
    cout << "start" << endl;
    nodo *L = build(n);
    stampaL(L);

    nodo *L1 = clone(L);
    doppioN A = Fiter(L); //da fare
                          //   doppioN B = Frec(L1); //da fare
    stampa_DN(A);
    // stampa_DN(B);
    // nodo *K = Giter(L, A);  //da fare
    //  nodo *K1 = Grec(L1, B); //da fare
    //  stampaL(K);
    ///  stampaL(L);
    //  stampaL(K1);
    //  stampaL(L1);
    cout << "end" << endl;
}