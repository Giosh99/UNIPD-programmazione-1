#include<iostream>
using namespace std;
 
int F(int i, int lim2, int lim3){
    return ((i/lim3)*(lim2*lim3)+i%lim3);
}
 //PRE=(T punta all’inizio di una H-fetta in X tale che a partire dal suo elemento inizio abbia almeno nP elementi, P, nP, lim2 e lim3, sono definiti ed hanno il senso usuale)
bool match(int *T, int inizio, int *P, int nP, int lim2, int lim3){
    bool trovato=true;
    int d;
    for(int i=0; i<nP && trovato; i++){ //R=(0=<i<=nP)&&(ho confrontato a coppie di valori)&&(trovato true => scorro gli elementi della H-Fetta da T[0+inizio... nP+inizio e P[0... nP])&&(d e' il numero di posti di cui spostarsi su T)&&(trovato falso => non ho trovato pattern matching)
        d=F(inizio+i, lim2, lim3);
        if(*(P+i)!=*(T +d))
            trovato=false;
    }
    return trovato;
}
//POST=(restituisce true sse nella H-fetta che inizia in T, gli elementi, inizio, inizio+1,..inizio+nP-1 sono identici a P[0..nP-1])
/*CORRETTEZZA
 *1) PRE=> R a=0 => ho confrontato 0 coppie di valori
 *             trovato = true => sto cercando il pattern-matching
 *2) R&& cond => R i<=nP controllo a coppie di valori e se trovato
 *                 trovato true => continuo la ricerca del [attern mathcing
 *3) R&& !cond => POST, se R&&(i=nP) => ho scorso P[0... nP-1] e ho trovato il pattern-matching
 *                      se R&&(trovato= false) => controllando i coppie non ho trovato il pattern-matching    
 * */ 

 
int main(){
    int X[400], P[20], n_ele, nP, lim1, lim2, lim3;
    cin >> n_ele;
    for(int i=0; i<n_ele; i++)
        cin >> X[i];
    cin >> lim1 >> lim2 >> lim3;
    if(lim1*lim2*lim3 < n_ele)
        n_ele=lim1*lim2*lim3;
    cin >> nP;
    for(int i=0; i<nP; i++)
        cin >> P[i];
    int nsp= n_ele/(lim2*lim3), eus= n_ele%(lim2*lim3), rpus= eus/lim3, ur= eus%lim3;
    //nsp = numeroStratiPieni
    //eus = elementi ultimo strato
    //rpus = riga piena ultimo strato 
    //ur = colonneNonPiene
    cout<<"start"<<endl;
    bool trovato= false;
    int eHfetta, inizio, fetta; // eHFetta sono gli elementi che ci sono nella fetta 
    for(fetta=0; fetta<lim2 && !trovato; fetta++)//R=(0=<fetta<=lim2)&&(trovato true)&&(scorro H-Fette )&&(eHfetta e' il numero di elementi di una H-Fetta)&&
    {
        eHfetta=nsp*lim3; // e' il numero di elementi della hfetta
        if(fetta<rpus){ // se la riga e minore
            eHfetta+=lim3;
        }
        else if(fetta==rpus){
            eHfetta+=ur;
        }
        for(inizio=0; inizio<eHfetta && !trovato; inizio++){
            trovato=match(&X[fetta*lim3], inizio, &P[0], nP, lim2, lim3);
        }
    }
   
    if(!trovato)
        cout<< "nessun match trovato"<<endl;
    else
        cout << "match trovato a partire dalla posizione "<<--inizio << " della H-fetta "<<--fetta<<endl;
  cout<<"end"<<endl;
  return 0;
}