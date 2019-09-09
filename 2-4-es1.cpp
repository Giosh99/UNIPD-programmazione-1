#include <iostream>

using namespace std;
//PRE: P è un pattern che termina con ’\0’, S è una sequenza di char che termina con ’\0’
bool match(char *P, char *s) { // P stringa e s pattern
    int i = 0;
    bool continua = true;
    while(*(s+i)!='\0'&&continua) { //R(scorro s[0..'\0'])&&(s+i=='\0'=> ho eseguito i volte il ciclo e non ho trovato match)&&
                                    //(continua=true => s[0..i]==P[0..i])&&(continua=false non ho trovato un match )
        if(*(P+i)=='\0')
            continua = false;
        else if(*(P+i) != *(s+i)) {
            if(*(s+i)!='?')
                continua = false;
        }
        else   
            continua = true;
        i++;
    }
    return continua;
}
//POST: la funzione ritorna true se e solo se P occorre in S a partire dalla posizione 0
int main() {
    char S[100];
    cin.getline(S,100);
    int  a=0, count=0, n_righe;
    char P[100][100];
    char *l = P[0];
    cin >> n_righe;
    cin.ignore();       // ignora il carattere "a capo" dopo la lettura del numero di righe 
    for(int i = 0; i < n_righe; i++) {
        cin.getline(P[i],256);
    }
    bool found = false;
    cout<<"start"<<endl;
    for(int i = 0; i<n_righe; i++) {
        l = P[i];
        while(*(l+a)!='\0') {
            if(match(l+a, S)) 
            {
                cout<<"riga: "<<i<<" colonna: "<<a<<endl; 
                found = true;
            }
            a++;
            count++;
        }
        a = 0;
    }
    if(!found)
        cout<<"Pattern non trovato"<<endl;
    cout<<"end";
}