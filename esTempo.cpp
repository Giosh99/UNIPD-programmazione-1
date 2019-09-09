#include<iostream>
using namespace std;

struct nodo{
	int info;
	nodo* left;
	nodo* right;

	nodo(int x=0, nodo* l=0, nodo* r=0){
		info = x;
		left = l;
		right = r;
	}
};

// FUNZIONI AUSILIARIE FORNITE
nodo* buildTree(int arr[], int i, int n)  {

    if (i >= n) {
    	return NULL;
    }
    nodo* root = new nodo(arr[i]);
    // insert left child
    root->left = buildTree(arr, 2 * i + 1, n);
    // insert right child
    root->right = buildTree(arr, 2 * i + 2, n);

    return root;

}

int height(nodo* root) {
	if(!root) {
		return 0;
	}
	return 1 + max(height(root->left), height(root->right));
}

void stampa_l(nodo *r)
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
void sc(int*C)
{
  if(*C!=-1)
   {cout<<*C<<' '; sc(C+1);}
  else
    cout<<"fine cammino"<<endl;
}

int main() {
  int dim;
    cin >>dim;
    int* a= new int[dim];
    for (int i=0; i<dim; i++)
      cin >> a[i];
      
    nodo* root = NULL;
    root = buildTree(a, 0, dim);
    int h=height(root);
    int*C=new int[h];
   
    int k,y;  
    cin>>k>>y;    
    cout << "start" << endl;
    bool b=cerca_cam(root,k,y,C);
    cout<<endl;
   if(b)
    {cout<<"trovato  cammino="; sc(C);}
   else
    cout<<" nessun cammino con "<<k<<" valori="<<y<<endl;
   cout<<"end";
   cout << "end" << endl;
}
