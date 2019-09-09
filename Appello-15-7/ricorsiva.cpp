#include<iostream>
using namespace std;
struct nodo {int info,num; nodo* left,*right; nodo(int a=0,int b=1, nodo*c=0, nodo*d=0){info=a; num=b; left=c; right=d;} };

void build_BST(nodo*&r, int x)
{
  if(!r)
    r=new nodo(x);
  else
    {
      nodo*q=r;
      bool continua=true;
      while (r && continua)
	{
	  r->num=r->num+1;
	  if(r->info >=x)
	    if(r->left)
	      r=r->left;
	      else
		{r->left=new nodo(x); continua=false;}
	    else
	      if(r->right)
		r=r->right;
	      else
		{r->right=new nodo(x); continua=false;}

	}

      r=q;

    }
}
void stampa_lin(nodo*r)
{
  if(r)
    {
      cout <<'['<<r->info<<','<<r->num<<']'<<'(';
      stampa_lin(r->left);
      cout<<',';
      stampa_lin(r->right);
      cout<<')';
    }
  else
  cout<<'_';
}
//PRE=(albero(r) è benformato, n>0)
nodo* trova(nodo*r,int n) {
    if(r) {
        nodo*p = 0;
        //cout<<"bah: "<<n<<endl;
        if(n==0)
            return r;
        if(r->left) {
            if(r->left->num>=n){
                p= trova(r->left,n-1);
                cout<<p<<endl;
            }
            else
            {
                n = n-(r->left->num);
            }
            
        }
        if(p==0 || !r->left) {
            //cout<<"ok"<<endl;
            if(r->right) {
                if(r->right->num>=n)
                    p= trova(r->right,n-1);
                else
                {
                    n = n-(r->right->num);
                }
                
            }
            else 
                return 0;
        }
        return p;
    }
    else return 0;
}
//POST=(se albero(r) contiene almeno n nodi, restituisce il puntatore al nodo numero
//n nell’ordinamento determinato dalla visita infissa, altrimenti restituisce 0)





main()
{
  cout<<"start"<<endl;
  int n;
  nodo*R=0;
  cin >>n;
    while (n !=-1)
      {
      build_BST(R,n);
      cin>>n;
      }
  stampa_lin(R);
  cout<<endl;
  cin >>n;
  while(n!=-1)
    {
      nodo*x=trova(R,n);
      if(x)
	cout<<"nodo n."<<n<<" info= "<<x->info<<endl;
      else
	cout<<"nodo n."<<n<<" non c'è"<<endl;
      cin>>n;
    }
  cout<<"end"<<endl;
}