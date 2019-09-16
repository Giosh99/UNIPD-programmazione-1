#include <iostream>
#include <fstream>
using namespace std;

struct nodo
{
    int info;
    nodo *left, *right;
    nodo(int a = 0, nodo *b = 0, nodo *c = 0)
    {
        info = a;
        left = b;
        right = c;
    }
};
struct ni
{
    nodo *info;
    ni *next;
    ni(nodo *a = 0, ni *b = 0)
    {
        info = a;
        next = b;
    }
};

struct dni
{
    ni *primo, *ultimo;
    dni(ni *a = 0)
    {
        primo = a;
        ultimo = a;
    }
};

dni pend_ni(dni x, ni *a)
{
    if (!x.primo)
    {
        x.primo = x.ultimo = a;
        return x;
    }
    else
    {
        x.ultimo->next = a;
        x.ultimo = a;
        return x;
    }
}

dni pop_ni(dni x)
{
    if (x.primo)
    {
        ni *w = x.primo;
        x.primo = x.primo->next;
        delete w;
        if (!x.primo)
            x.ultimo = 0;
    }
    return x;
}
void svuota(dni x)
{
    while (x.primo)
    {
        ni *w = x.primo;
        x.primo = x.primo->next;
        delete w;
    }
}

//funzioni di stampa
void stampa_alb(nodo *x)
{
    if (x)
    {
        cout << x->info;
        cout << '(';
        stampa_alb(x->left);
        cout << ',';
        stampa_alb(x->right);
        cout << ')';
    }
    else
        cout << '_';
}

void stampa_dni(dni x)
{
    while (x.primo)
    {
        cout << x.primo->info->info << ' ';
        x = pop_ni(x);
    }
}

dni creastrato(int &n, dni X0, int *x, nodo *r)
{
    //nodo *r = 0;
    while (n > 0 && x)
    {
        if (!r)
        {
            X0 = pend_ni(X0, new ni(r = new nodo(*x)));
            n--;
            x++;
        }
        else
        {
            r = X0.primo->info;
            //cout<<r->info<<endl;
            // if(!r->left){
            X0 = pop_ni(X0);
            X0 = pend_ni(X0, new ni(r->left = new nodo(*x)));
            n--;
            x++;
            //}
            if (n > 0)
            {
                X0 = pend_ni(X0, new ni(r->right = new nodo(*x)));
                n--;
                x++;

            }
        }
    }
    return X0;
}
dni creastrato2(int &n, dni X0, ifstream &IN)
{
    dni nuovo;
    while (n > 0 && X0.primo)
    {
        n--;
        int a;
        IN >> a;
        nodo *no = new nodo(a);
        ni *mNi = new ni(no);
        nuovo = pend_ni(nuovo, mNi);

        if (X0.primo->info->left == 0)
        {
            X0.primo->info->left = no;
        }
        else
        {
            X0.primo->info->right = no;
            X0 = pop_ni(X0);
        }
    }
    return nuovo;
}
int main()
{
    int x;
    int c = 0;
    cin >> x;
    int a[100];
    for (int i = 0; i < x; i++)
    {
        //     cout<<"bah"<<endl;
        *(a + i) = i;
    }
    int *pointer = a;
    //cout<<"ok"<<endl;
    nodo *r = new nodo(*pointer);
    dni X0 = pend_ni(X0, new ni(r = new nodo(*pointer)));
    x--;
    pointer++;
    dni X1 = creastrato2(x, X0, pointer, r);
    stampa_dni(X1);
    stampa_alb(r);
}
//PRE=(primo valore su "input" e' n>0 ed e' seguito da n valori interi)
/*main()
{
    ifstream IN("input");
    ofstream cout("ouput");
    int n, y;
    IN >> n >> y;
    nodo *root = new nodo(y);
    dni X0;
    X0 = pend_ni(X0, new ni(root));
    n = n - 1;
    while (n)
    {
        X0 = creastrato(n, X0, IN); //da fare
    }
    svuota(X0);
    stampa_alb(root, cout);
    cout << endl;
    X0 = unfold(root); //da fare
    stampa_dni(X0, cout);
    cout << endl
        << "fine coutput" << endl;
}*/

/*
        if(!r) { // "caso base"
            r = new nodo(X0.primo->info->info);
            //X0 = pop_ni(X0.primo);
        } 
        else { //"r esiste allora devo fare pop di X0 per campo info e poi aggiungere i figli( se esistono )"
            r->info = X0.primo->info->info;
          //  X0 = pop_ni(X0.primo);
        }
        r->left = new nodo(*x);
        X0 = pend_ni(X0, new ni(r->left));
        x++;
        if(x){
            r->right = new nodo(*x);
            X0 = pend_ni(new ni(r->right));
        }*/