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

nodo* trova(nodo* r ,int n)
{
    
     
    if (r)
    {
        nodo* t;
        t= r-> left;
        if (n!= 0)
        {
            //cout << r-> info<< " " << n <<  endl;
           
            if (!t)
            {
                if (n==1)
                {
                    return r;
                }
                n--;
                return  trova (r-> right, n);
                
            }
            else
            {
                
                if (t-> num + 1 == n)
                    return r;
                else if  (t-> num < n)
                {
                n= n- t-> num-1;
                return  trova (r-> right, n);
                }
                
                else
                {
                return trova ( r-> left, n);
                n--;
                }
            
            }
            
        }
        else 
        return r;
        
    }
    else
    return 0;
    
}
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