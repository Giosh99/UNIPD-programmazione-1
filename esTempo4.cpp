#include <iostream>

using namespace std;
int F(int i, int lim2, int lim3) {
    int strati = i/lim3;
    int offset = i%lim3;
    return strati*lim2*lim3+offset;
}
//POST=(restituisce la distanza tra l’inizio di una H-fetta e l’elemento i di quella fetta in X)

//PRE=(T punta all’inizio di una H-fetta in X tale che a partire dal suo elemento inizio abbia almeno nP
//elementi, P, nP, lim2 e lim3, sono definiti ed hanno il senso usuale)
bool match (int*T, int inizio, int*P, int nP,int lim2, int lim3) {
    // assumo di poter confrontare gli elementi che mi vengono proposti
    bool continua = true;
    for(int i = 0; i<nP&&continua;i++) { //R(0<=i<=nP && continua=true =>T[d...d+i]==P[0...i])&&(continua=false && i<nP => ho trovato un 
                                        //T[d]!=P[i]=> non posso avere match)&&(continua=true && i>=nP => ho scorso P[0..nP] e ho trovato match)
                                        //&&(d indica di quanto scorrere T per trovare il valore desiderato)
        int d = F(inizio+i, lim2,lim3);
        if(*(T+d)!=*(P+i)) {
            continua = false;
        }
    }
    return continua;
}
/*
PRE=>R: 
i=0=> 0<=0<=nP ok
continua=true ok
d=0 ok
R&&B:
caso: i<nP&&continua=> ho scorso T[d...d+i]==P[0..i] e non ho trovato valori diversi tra essi
R&&!B
caso:  i<nP&&!continua=> ho trovato un T[d]!=P[i] e non posso perciò avere match
caso:  i>=nP&&continua => ho scorso P e non ho trovato T[d]!=P[i]=> ho un match
*/
//POST=(restituisce true sse nella H-fetta che inizia in T, gli elementi, inizio, inizio+1,..inizio+nP-1 sono
//identici a P[0..nP-1])
main()
{
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
  cout<<"start"<<endl;
    cout<<"start"<<endl;
    bool trovato= false;
    int eHfetta, inizio, fetta;
    for(fetta=0; fetta<lim2 && !trovato; fetta++)
    {
        eHfetta=nsp*lim3;
        if(fetta<rpus){
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
  }