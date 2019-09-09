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

void printGivenLevel(nodo* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
       cout << root->info;
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

// STAMPA L'ALBERO LIVELLO PER LIVELLO
void printLevelOrder(nodo* root) {
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
    {
        printGivenLevel(root, i);
        cout << endl;
    }
}
void stampaPrefissa(nodo*n) {
    if(n) {
        cout<<n->info<<"(";
        stampaPrefissa(n->left);
        cout<<",";
        stampaPrefissa(n->right);
        cout<<")";
    }
    else 
        cout<<"_";
}


// DA IMPLEMENTARE
// PRE=(albero(root) ben formato e non vuoto)
int cercaFoglia(nodo* root, int key, nodo* &t) {
    if(root->info == key) {
        t = root;
        //cout<<"yep"<<endl;
        return 0;
    }
    if(!root->left&&!root->right) //caso base 1
        return -1;
    if(!root->left)
        return cercaFoglia(root->right, key, t);
    if(!root->right)
        return cercaFoglia(root->left, key, t);
    int a = cercaFoglia(root->left,key, t);
    int b = cercaFoglia(root->right, key, t);
    if(a>b)
        return b+1;
    else return a+1;
}
// POST=(se c'è una foglia con info=x, allora restituisce col return la profondità minima di tale foglia e assegna a t il puntatore ad essa, altrimenti restituisce -1)

// Driver program to test above function
int main() {
    int a[100], n, key;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    cin >> key;
    //cout<<"key: "<<key<<endl;
    
    nodo* root = NULL;
    root = buildTree(a, 0, n);
    //stampaPrefissa(root);
    //printLevelOrder(root); // decommentare per vedere la stampa dell'albero livello-per-livello
    nodo* tmp = root;
    int r = cercaFoglia(root, key, tmp);
    cout << "start" << endl;
    if(r==-1)
        cout<<"Foglia non trovata"<<endl;
    else 
        cout<<"La foglia si trova ad altezza "<<r<<endl;
    
    int altezza = cercaFoglia(root, key, tmp); // CHIAMATA ALLA FUNZIONE RICORSIVA DA IMPLEMENTARE
    // IMPLEMENTARE LA LOGICA COME DA SPECIFICHE
    cout << "end" << endl;
}
