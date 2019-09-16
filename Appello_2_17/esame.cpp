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
struct nodoD
{
    int lascia, togli;
    nodoD *next;
    nodoD(int a = 0, int b = 0, nodoD *c = 0)
    {
        lascia = a;
        togli = b;
        next = c;
    }
};
struct doppioN
{
    nodo *La, *To;
    doppioN(nodo *a = 0, nodo *b = 0)
    {
        La = a;
        To = b;
    }
};

nodo *build(int n)
{
    if (n)
    {
        int x;
        cin >> x;
        return new nodo(x, build(n - 1));
    }
    return 0;
}
nodoD *buildD(int n)
{
    if (n)
    {
        int x, y;
        cin >> x >> y;
        return new nodoD(x, y, buildD(n - 1));
    }
    return 0;
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
void stampaD(nodoD *L)
{
    if (L)
    {
        cout << '[' << L->lascia << ',' << L->togli << ']' << ' ';
        stampaD(L->next);
    }
    else
        cout << endl;
}

nodo *conc(nodo *L1, nodo *L2)
{
    if (!L1)
        return L2;
    if (!L2)
        return L1;
    nodo *x = L1;
    while (x->next)
        x = x->next;
    x->next = L2;
    return L1;
}

nodo *clone(nodo *L)
{
    if (!L)
        return 0;
    return new nodo(L->info, clone(L->next));
}

nodo *push_end(nodo *L, nodo *n)
{
    if (!L)
    {
        L = n;
        return L;
    }
    nodo *t = L;
    bool ok = true;
    while (L && ok)
    {
        if (!L->next)
        {
            L->next = n;
            ok = false;
        }

        else
            L = L->next;
    }
    return t;
}
//PRE=(Lista(L) è corretta, n>=0, vL=L)
nodo *taglia(nodo *&L, int n)
{
    nodo *lista = 0;
    while (n > 0&&L)
    {
        nodo *tmp = L;
        L = L->next;
        tmp->next = 0;
        if (lista)
        {
            lista = push_end(lista, tmp);
        }
        else
        {
            lista = tmp;
        }
        n--;
    }
    return lista;
}
//POST=(la funzione restituiscecol returni primi n nodi di vL se ci sono e altrimenti restituisce quello che c’è, L diventaquelloche resta di vL una volta tolto il prefisso restituito col return)
//PRE=(Lista(L), Lista(D), Lista(lasciati) e Lista(tolti) sono corrette, vL=L,vlasciati=lasciati e vtolti=tolti)
void Fiter(nodo *L, nodoD *D, nodo *&lasciati, nodo *&tolti)
{
    bool ok = true;
    nodo *lasciati_parziale = 0;
    nodo *tolti_parziale = 0;
    while (D && ok)
    {
        //cout << "ok";
        lasciati_parziale = taglia(L, D->lascia);
         //stampaL(lasciati_parziale);
        if (!lasciati_parziale && D->lascia != 0)
            ok = false;
        else
        {
            //cout << "zizi" << endl;
            lasciati = push_end(lasciati, lasciati_parziale);
            //stampaL(lasciati);
            tolti_parziale = taglia(L, D->togli);
            if (!tolti_parziale && D->togli != 0)
                ok = false;
            else
            {
                tolti = push_end(tolti, tolti_parziale);
            }
        }
        D = D->next;
    }
    if (L)
        lasciati = push_end(lasciati, L);
}
//POST=(lasciati e tolti sono vlasciati e vtolti a cui sono state appese (alla fine) le liste ottenute dalla smembramento di vL come indicato dai nodi di D)
main()
{
    int dimL, dimD;
    cin >> dimL >> dimD;
    nodo *L = build(dimL);   //data
    nodoD *D = buildD(dimD); //data
    nodo *L1 = clone(L);     //data
    cout << "start" << endl;
    stampaL(L); //data
    stampaD(D); //data
    nodo *lasciati = 0, *tolti = 0;
    Fiter(L, D, lasciati, tolti); //da fare
    stampaL(lasciati);
    stampaL(tolti);
    /* doppioN y = Fric(L1, D); //da fare
    stampaL(y.La);
    stampaL(y.To);*/
    cout << "end" << endl;
}