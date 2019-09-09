    #include<iostream>
    using namespace std;
    struct nodoA{int info; nodoA* left,*right; nodoA(int a=0, nodoA*b=0,nodoA*c=0){info=a; left=b; right=c;}};
    struct nodo{nodoA* info; nodo* next; nodo(nodoA* a=0, nodo*b=0){info=a; next=b;}};

    void stampa_l(nodoA *r)
    {
    if(r)
        {
        cout<<r->info<<'(';
        stampa_l(r->left);
        cout<<',';
        stampa_l(r->right);
        cout<<')';
        }
    else
        cout<< '_';
    }
    int conta_n(nodoA*r)
    {
    if(!r) return 0;
        else
        return conta_n(r->left)+conta_n(r->right)+1;
    }

    nodoA* insert(nodoA*r, int y)
    {
    if(!r) return new nodoA(y);
    
    if(conta_n(r->left)<=conta_n(r->right))
        r->left=insert(r->left,y);
    else   
        r->right=insert(r->right,y); 
    return r;
    }

    nodoA* buildtree(nodoA*r, int dim)
    {
    if(dim)
    {
        int z;
        cin>>z;
        nodoA*x=insert(r,z);
        return buildtree(x,dim-1);
    }
    return r;
    }


    void riempi(int*P,int m)
    {
    if(m)
        {
        cin>>*P;
        riempi(P+1,m-1);
        }
    }

    void stampaL(nodo*a)
    {
    if(a)
        {
        cout<<a->info->info<<' ';
        stampaL(a->next);      
        }
    else
        cout<<endl;
    }
    nodoA* check(nodoA *A, int P) {
        if(!A)
            return NULL;
        if(A->info == P) {
            return A;
        }
        else if(A) {
            nodoA *p = check(A->left, P);
            if(p)
                return p;
            else 
                return check(A->right,P);
        }
        else return NULL;
    }
    //PRE=(albero(r) ben formato, P ha dimP elementi con dimP>0)
    nodo* match(nodoA* r, int* P, int dimP) {

        nodoA*a = check(r, *P);
        if(a) {
            if(dimP == 1) 
                return new nodo(a);
            else {
                nodo *n = match(r,P+1,dimP-1);
                if(!n)
                    return NULL;
                nodo *n2 = new nodo(a,n);
                return n2;
            }

        }
        else {
            return NULL;
        }
    }
    //POST=(se esiste su un cammino di albero(r) un match di P, allora,
    //restituisce una lista concatenata con dimP nodi ciascuno dei quali punta
    //ad un nodo di albero(r) che partecipa al match trovato)&&(altrimenti
    //restituisce 0)

    main()
    {
    int  n,m;
    cout<<"start"<<endl;
    cin>> n;
    nodoA*R=buildtree(0,n);
    stampa_l(R);
    cout<<endl;
    int P[50];
    cin>> m;
    riempi(P,m);
    nodo*a=match(R,P,m);
    if(a)
        stampaL(a);
        else
        cout<<"no match found"<<endl;
    cout<<"end"<<endl;
    }