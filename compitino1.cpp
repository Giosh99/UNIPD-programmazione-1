#include<iostream>
using namespace std;

int S(int i, int lim2, int lim3) {
    return (i/lim3)*(lim2*lim3)+i%lim3;
}
int match(int *F, int*P, int n_ele_fetta, int nP, int lim2, int lim3) {
    int d = 0;
    int buffer;
    int count=0;
    int c=0;
    int d2=0;
    for(int i = 0; i<n_ele_fetta&&c<nP; i++) { //R(0<=i<=n_ele_fetta && 0<=c<nP)&&(eseguito i volte il ciclo innestato)
                                               //&&(d è lo spostamento sulla h-fetta)&&(count è il numero di elementi matchati su F)
        d = S(i,lim2,lim3);
        if(P[c] == *(F+d)) { 
            count++;
            c++;
            for(int a = 0; a<(n_ele_fetta-i-1); a++) {
                d = S(i+a,lim2,lim3);
                d2 = S(i+a+1,lim2,lim3);
                buffer = *(F+d);
                *(F+d) = *(F+d2);
                *(F+d2) = buffer;
            }
            i--;
        }
    }
    return count;
}
void stampa_fetta() {

}

main()
{
  int X[400], P[20], n_ele, nP, lim1, lim2,lim3;
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
  int hf;
  cin >> hf; // fetta da trattare
  int lung; // lunghezza della H-fetta hf
  lung = nsp*lim3;
  if(hf<rpus) //posso pigliare 
  {
      lung +=lim3;
  }
  else if(hf==rpus)
        lung += ur;
  int b = match(X+hf*lim3,P,lung,nP,lim2,lim3);
  int *p = X;
  p = p+hf*lim3;
  if(b==nP) 
    cout<<"pattern consumato tutto"<<endl;
    else {
        cout<<"pattern rimasto ";
        for(int i = b; i<nP;i++)
            cout<<P[i];
        cout<<endl;
    }
  //stampa quello che resta di P e la H-fetta risultante

  // o  cout<<"pattern rimasto: "<<endl;
    
 // o    cout<<"pattern consumato tutto"<<endl;
    cout<<"la H-fetta "<<hf<<" e' diventata:"<<endl;
       for(int z = 0; z<(lung-b);z++) {
            int d = S(z,lim2,lim3);
            cout<<*(p+d)<<" ";
        }   
  cout<<"end"<<endl;
}