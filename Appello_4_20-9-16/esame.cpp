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
struct FIFOX
{
    nodo *primo, *ultimo;
    int valp, valu, nele;
    FIFOX(nodo *a = 0, int b = 0, int c = 0, int d = 0)
    {
        primo = a;
        ultimo = a;
        valp = b;
        valu = c;
        nele = d;
    }
};

ostream &operator<<(ostream &OUT, FIFOX &a)
{
    OUT << '[' << "nele=" << a.nele << " valp=" << a.valp << " valu=" << a.valu << ']' << endl;
    int x = 0;
    nodo *z = a.primo;
    while (x < a.nele)
    {
        OUT << z->info << ' ';
        z = z->next;
        x++;
    }
    OUT << endl;
    return OUT;
}
void stampa(nodo *n)
{
    if (!n)
        return;
    else
    {
        cout << n->info << " ";
        stampa(n->next);
    }
}
FIFOX push_iter(FIFOX x, nodo *n)
{
    if (x.primo == 0)
    { // caso iniziale
        x.primo = n;
        x.ultimo = n;
        x.valp = n->info;
        x.valu = n->info;
        x.nele = 1;
        return x;
    }
    if (x.primo->info > n->info)
    {
        n->next = x.primo;
        x.primo = n;
        x.valp = n->info;
        x.nele++;
        return x;
    }
    bool trovato = false;
    nodo *p = x.primo;
    while (!trovato)
    {
        // cout <<"primo elemento" x.primo->info << endl;
        if (!p->next)
        {
            // caso 1 elemento e p->info<n->info
            x.ultimo->next = n;
            x.ultimo = n;
            x.nele++;
            x.valp = x.primo->info;
            x.valu = x.ultimo->info;
            p = p->next;
            trovato = true;
            stampa(x.primo);
        }
        else
        {
            if (p->next->info > n->info)
            {
                n->next = p->next;
                p->next = n;
                x.nele = x.nele+1;
                trovato = true;
            }
            else  p = p->next;
        }
    }
    return x;
}

main()
{
    int dim1, dim2, x;

    cin >> dim1 >> dim2;
    FIFOX a;
    while (dim1)
    {

        cin >> x;
        a = push_iter(a, new nodo(x));
        dim1--;
        cout << "dim1 " << dim1 << endl;
    }
    cout << a.primo->info << endl;
    cout << a.ultimo->info << endl;
    stampa(a.primo);
    //  cout << a;

    /*   while (dim2)
    {
        cin >> x;
        a = deleteX(a, x);
        dim2--;
    }*/
    //stampa(a.primo);

    cout << "end" << endl;
}