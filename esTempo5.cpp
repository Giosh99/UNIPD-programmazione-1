
#include<iostream>
using namespace std;


void stampa(int*P,int m,int i){
    if(i==m)
        {cout<<endl; return;}
    cout<<'('<<i<<','<<P[i]<<')'<<' ';
    stampa(P,m,i+1);
}

//PRE_t=(N ha almeno m*m elementi definiti, 0<=i<m, j è definito e P ha m-j posizioni) 
/*
correttezza:
    caso base:
        j==m, cioè abbiamo finito di scorrere le righe, allora tutte le chiamate  a trova fino hanno trovato una cella per il pattern, e quindi ritorniamo true 
    caso j<m 
        verifica della PRE per tutti e tre i casi ricorsivi:
            --> N è sempre definito in quanto il suo valore non cambia mai in tutta la durata dell'esecuzione, idem per m
            --> 0<=i<m è sempre vero, in quanto in tutta ''trova'' non si cambia mai il valore di i, e nella prima chiamata di trova dentro
                partenza, vi è il controllo che i<m, e ocme valore iniziale di i si ha 0, quindi 0<=i<m sempre valido
            --> j è definito sempre in quanto la prima chiamata derivante da partenza ha come valore iniziale 0, e successivamente j può solo che essere aumentato,
                e nelle rispettivamente tre chiamate ricorsive a trova, il paramentro j sarà j+1
            --> P ha m-j posizioni, in quanto alla prima chiamata da partenza si passa P+1 e j=1, quindi P conterrà m-1 elementi, mentre nelle chiamate
                ricorsive, si passa sempre P+1 e j+1, quindi nel caso peggiore, quindi quando j==m, P conterrà 0 celle, infatti abbiamo trovato il pattern, quindi m coordinate
        verifica della POST per tutti e tre i casi ricorsivi:
            trovato vale false di default, sse una delle tre chiamate ritornerà true, esso potrà valere true e 
            se una delle chiamate ritorna true, l'unico modo è che si sia arrivati ad una chiamata in cui j==m, e che quindi si sia trovato un cammino.

            se restituisce true, allora P contiene le coordinate del cammino piu a sinistra, in quanto nella funzione i tre controlli vanno da sinistra a destra
            quindi da i-1 (se si piò), i, i+1 (se si può), e datu un caso che restituisce true, che quindi ci sia un cammino per quella via, allora non si guarda gli altri casi
            perchè per poter effettuare quelle succesive prove, si necessita che trovato==false, ma se una chiamata ricorsiva precedente ha restituito true, allora 
            trvato == true, e quindi non si effettueranno le chiamate successive, e quindi P conterrà le coordinate di quel cammino, cioè il cammino più a sinistra
            (infatti la j-esima chiamata di trova, può salvare solo su P+j se necessario la coordinata della colonna della riga j del possibile percorso)
                


*/
bool trova(bool* N, int m, int i, int j, int*P){
    bool trovato=false;
    if(j<m){
        if(i>0){
            if(*(N + j*m + i - 1)){
                //*P=i-1;
                trovato= trova(N, m, i-1 , j+1 , P+1); //caso ricorsivo (i>0 (se i==0 -> i-1= -1, quindi  andremo in segmentation fault, oppure a leggere la cella sbagliata dell'array) && j<m): se X[j][i-1]==true -> controlleremo se X[j+1][i-1 || i || i+1]==true (con opportuni controlli su i)
            }   
        }
        if(*(N + j*m + i) && !trovato){
            //*P=i;
            trovato = trova(N, m, i , j+1 , P+1); //caso ricorsivo (j<m): se X[j][i]==true -> controlleremo se X[j+1][i-1 || i || i+1]==true (con opportuni controlli su i)
        }
        if(i<m-1 && !trovato ){
            if(*(N + j*m + i + 1)){
                //*P=i+1;
                trovato =trova(N, m, i+1 , j+1 , P+1); //caso ricorsivo  (i<m-1 (se i==m-1 -> i+1=m, quindi andremo in segmentation fault, oppure a leggere la cella sbaglaita dell'array) && j<m): se X[j][i+1]==true -> controlleremo se X[j+1][i-1 || i || i+1]==true (con opportuni controlli su i)
            }
        }
    }
    if(j==m)return true; //caso base
    return trovato;
}
/*
    POST_t=(restituisce true sse in N vista come X[m][m] c’è un cammino dalla casella (i,j) alla riga m-1
    composto da sole caselle bianche) &&(se la risposta è true, in P [0..m-i-1] c’è il cammino più a sinistra con
    queste proprietà)                   
*/





//  PRE_p=(N ha m*m valori definiti, 0<=i<=m e P ha m elementi)
bool partenza(bool*N, int m, int i, int*P){
    bool trovato=false;
    if(i<m){
        if(*(N+i)){
            *P=i;
            trovato=trova(N, m, i, 1, P+1);
        }
        if(!trovato)trovato =partenza(N, m, i+1, P);
    }
    return trovato;
}
/*
    POST_p=(risponde true sse esiste un cammino di caselle bianche dalla prima all’ultima riga di N, vista come
    X[m][m], e che inizia in una casella tra i e m-1 della prima riga di X) &&(se risponde true allora P[0..m-1] è il
    ammino più a sinistra con queste proprietà)
*/



main(){
    int m;
    cin>>m;
    int*P=new int[m];
    bool*N =new bool[m*m];
    for(int i=0; i<m*m; i++)cin>>N[i];
    bool x=partenza(N,m,0,P);//da fare 
    cout<<"start"<<endl;
    if(x)
        { cout<<"esiste un cammino e quello più a sinistra è:"<<endl;
        stampa(P,m,0);
        
        }    
    else
        cout<<"il cammino non esiste"<<endl;
    cout<<"end"<<endl;
      
}

