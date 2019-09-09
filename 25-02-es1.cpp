#include <iostream>

using namespace std;

bool control(int c, int lung, int *p) {
    for(int i = 0; i<lung; i++) {
        if(c == p[i])
            return true;
    }
    return false;
}

int main()
{
	int N = 0; //numero di biglietti da controllare
    int i=0; // contatore per inserimento
    int z = 0; //contatore per controllo codici duplicati
    int a = 0; // buffer percodice preso da cin
    bool found = false; //condizione di uscita del ciclo più interno 
    int v = 0; // per inserimento dei codici in booleanArray
	cin >> N;
    int array[N];
    int booleanArray[N];
	while(i<N){
        cin>>a;
        while(z<i&&!found){ //in modo da controllare solo i valori effettivamente riempiti 
            if(array[z]==a) {
                if(!control(a,v,booleanArray)) {
                    booleanArray[v] = a;
                    found = true;
                    v++;
                }
            }
            z++;
        }
        z = 0;
        found = false;
        array[i] = a;
        i++;
    }
    cout <<"start"<<endl;
    //ora stampo i valori duplicati in "ordine"
    if(v==0) 
        cout<<"Tutto regolare"<<endl;
    else {
        for(int i = 0; i<v; i++){
            cout<<booleanArray[i]<<endl;
        }
    }
    cout<<"end"<<endl;
}  