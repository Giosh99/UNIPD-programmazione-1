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
};

struct nodoG
{
    nodo *N;
    nodoG *next;
    nodoG(nodo *a = 0, nodoG *b = 0)
    {
        N = a;
        next = b;
    }
};

struct match
{
    int ip, //inizio della sottosequenza di P[0..dimP-1] che viene matchata
        im, //indice di T[0..dimT-1] nel quale inizia il match
        fm; //indice di T[0..dimT-1] nel quale finisce il match
    match(int a = 0, int b = 0, int c = 0)
    {
        ip = a;
        im = b;
        fm = c;
    }
};

//PRE_costruisciLista=(l_match è una lista corretta, i è un intero 0<=i<=dimT-1)
void costruisciLista(nodo *l_match, int i)
{
    nodo *aux = l_match; //lista ausiliare per spostarmi all'ultimo nodo (lista) di l_match
    while (aux->next)
        aux = aux->next;
    aux->next = new nodo(i);

} //POST_costruisciLista=(aggiunge un nodo con campo info=i alla fine della lista del match di P su T[0..dimT-1])

//PRE_cercaMatch=(T è un array di dimT>0 elementi, P è definito)&&(tutti i valori di P[0..dimP-1] sono presenti su T[0..dimT-1])
nodo *cercaMatch(int *T, int dimT, int *P)
{
    nodo *n = 0;
    for (int i = 0; i < dimT; i++)
    {
        if (*P == T[i])
        {
            if (!n)
                n = new nodo(i);
            else
                costruisciLista(n, i);
        }
    }
    return n;
} //POST_cercaMatch=(ritorna la lista del match di P su T[0..dimT-1])

//PRE_costruisciListaG=(l_match è una lista corretta, l_match è una lista corretta non vuota)
void costruisciListaG(nodoG *l_match, nodo *l_match_aux)
{
    nodoG *aux = l_match; //lista ausiliare per spostarmi all'ultimo nodo (lista) di l_match
    while (aux->next)
        aux = aux->next;
    aux->next = new nodoG(l_match_aux);
} //POST_costruisciListaG=(aggiunge la lista del match di P su T[0..dimT-1] sulla lista del match di P[0..dimP-1] su T[0..dimT-1])

//PRE_M=(T è un array di dimT interi, P un array di dimP interi, dimT e dimP>=0)
nodoG *M(int *T, int dimT, int *P, int dimP)
{
    nodoG *nG = 0;
    nodo *lista = 0;
    for (int i = 0; i < dimP; i++)
    { //R=(0<=i<=dimP)&&(scorso i elementi di P)&&(nG contiene le lista_i dei match dei singoli elementi di P[0..dimP-1] su T[0..dimT-1] )
        lista = cercaMatch(T, dimT, P + i);
        if (lista)
        {
            if (!nG)
            {
                nG = new nodoG(lista);
            }
            else
                costruisciListaG(nG, lista);
        }
    }
    return nG;
} //POST_M=(M restituisce una lista di dimP liste tale che la lista L_i (i in [0..dimP-1]) contiene gli indici di tutte le occorrenze di P[i] in T, da sinistra a destra)
/*
PROVA DI CORRETTEZZA:
PRE=> R: i = 0, ho scorso 0 elementi di P, nG e' vuota perche' contiene le lista_i dei match degli elementi di P[0..-1] su T[0..-1]
R&&cond =>  R: i<=dimP, ho scorso i elementi di P, nG contiene n<=i  Liste_i di elementi matchati dei singoli elementi di P[0..i-1] su T[0..i-1]
            ed aggiungiamo in fondo a nG la lista_i degli elementi matchati di P[i] su T[0..dimT-1]
R&&!cond => POST: Se i=dimP allora l_match è la lista composta dalle liste dei match dei singoli elementi di P[0..dimP-1] su T[0..dimT-1] → vale POST
*/

//PRE_lung=(MT è una struttura con campi (interi) 0<=ip<=dimP-1, 0<=im<=dimT-1, 0<=fm<=dimT-1)
int lung(match MT)
{

    int lunghezza = MT.fm - MT.im + 1;
    //fm : indice di T nel quale finisce il match
    //im : indice di T nel quale inizia il match
    //1 : bisogna sommare 1 in quanto non abbiamo considerato l'elemento di inizio match
    return lunghezza;

} //POST_lung=(ritorna la lunghezza del match)
//PRE=(L e' l'inizio del match da cui bisogna partire per contare)
int contaLung(int *L, int *P)
{
    int i = 0;
    //stampa(L);
    bool continua = true;
    while (L && P && continua)
    {
        if (*L != *P)
        {
            continua = false;
        }
        else
        {
            i++;
            P++;
            L++;
        }
    }
    return i;
}
int 
//POST=(ritorna il numero di elementi matchati di L[0..] )
//PRE_cercaSequenza=(G è una lista corretta non vuota, pos è un intero >=0)
int cercaSequenza(nodoG *G, int pos)
{

} //POST_cercaSequenza=(la funzione ritorna la massima lunghezza della sequenza che fa match a partire dalla lista di liste G)

//PRE_FM1_ric=(G sia una lista corretta di liste tutte corrette e contenenti valori interi non negativi e crescenti, e sia L una lista corretta e possibilmente vuota di interi non negativi e i>=0)
match FM1_ric(nodoG *G, nodo *L, int i)
{

} //POST_FM1_ric=(la funzione restituisce il valore [i, x, y] che corrisponde a MAX_S_(G,L) . Se L è vuota, allora FM1_ric restituisce [0,0,-1] a indicare l'assenza di match)

/* PROVA DI CORRETTEZZA: PRE_FM1_ric < FM1_ric() > POST_FM1_ric

  Caso base: !L
---------------
Dato PRE_FM1_ric se L è una lista vuota allora non ci può essere alcun match: per ipotesi facciamo partire il match dall'indice 0 e lo facciamo finire all'indice -1, quindi ritorna [i,0,-1], infatti la lunghezza del match è -1+0+1=0 → vale POST_FM1_ric

  Caso ricorsivo: 
-----------------
Dato PRE_FM1_ric se L è una lista corretta non vuota allora invoco la chiamata ricorsiva FM1_ric(G,L->next,i), con G lista corretta di liste corrette, L lista corretta possibilmente vuota e i intero >=0: la funzione restituirà il valore [i,x,y], cioè il match di lunghezza massima a partire dall'indice nel nodo L; al ritorno confronterà la lunghezza del massimo match tra il nodo L ed il successivo e ritornerà il match di lunghezza massima nella lista delle liste G a partire dalla lista L → valgono PRE_FM1_ric e POST_FM1_ric 
*/

//PRE_FM=(IG è una lista corretta di liste corrette e tutte contenenti interi non negativi e crescenti. IG ha lunghezza dimP>=0)
match FM(nodoG *IG, int dimP)
{

} //POST=(restituisce un valore match [a,b,c] tale che se k=c-b, allora P[a..a+k]  è uguale a T[b..c] e tale che tra tutti i match di sotto-sequenze di P in T, k+1 è la lunghezza massima, inoltre, se ci fossero vari match con la stessa lunghezza, FM restituisce quello con  minimo a e a partità di a, con minimo b. In caso IG fosse vuota, oppure, tutte le liste appese a IG fossero vuote, FM restituisce [0,0,-1] a indicare l'assenza di match.)

void stampa(nodo *y)
{
    while (y)
    {
        cout << y->info << ' ';
        y = y->next;
    }
}

void stampaG(nodoG *x)
{
    while (x)
    {
        stampa(x->N);
        x = x->next;
        cout << endl;
    }
}

main()
{
    int T[200], P[40], dimP, dimT;
    cin >> dimT >> dimP;
    //cout<<dimT<<' '<<dimP<<' '<<endl;
    for (int i = 0; i < dimT; i++)
        cin >> T[i];
    for (int i = 0; i < dimP; i++)
        cin >> P[i];
    nodoG *X = M(T, dimT, P, dimP); // M da fare
    stampaG(X);
    cout<<contaLung(T+X->next->N->info, P+1)<<endl;
    /*  try
    {
        ifstream INP("input");
        ofstream OUT("output");
        if (!INP)
            throw(0);
        if (!OUT)
            throw(1);
        int T[200], P[40], dimP, dimT;
        INP >> dimT >> dimP;
        //cout<<dimT<<' '<<dimP<<' '<<endl;
        for (int i = 0; i < dimT; i++)
            INP >> T[i];
        for (int i = 0; i < dimP; i++)
            INP >> P[i];
        nodoG *X = M(T, dimT, P, dimP); // M da fare
        stampaG(X, OUT);                // data
        match y = FM(X, dimP);          //data
        OUT << endl
            << y.ip << ' ' << y.im << ' ' << y.fm << endl;
    }
    catch (int x)
    {
        switch (x)
        {
        case 0:
            cout << "problemi con input" << endl;
            break;
        case 1:
            cout << "problemi con output" << endl;
            break;
        }
    }*/
}