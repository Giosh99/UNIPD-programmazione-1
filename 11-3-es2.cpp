    #include <iostream>

    using namespace std;

    int main() {
        int X[2][4][5];
        int n;
        cin>>n;
        bool ok = true; // mi dirà se dovrò andare avanti nell'inserimento di valori
        bool procedi = true; // mi dirà se mi trovo o meno nell'ultima riga durante la stampa
        int c = 0; // contatore che mi serve per settare ok false in caso
        int c2 = 0; //conttor per stampa
        int *p = X[0][0];
        for(int i = 0; i<4&&ok;i++) {
            for(int a = 0; a<10&&ok; a++, c++) {
                if(a>=5)
                    cin>>*(p+4*5+(a-5)+i*4);
                else 
                    cin>>*(p+i*4+a);
                if(c == n)
                    ok = false;
            }
        }
                        //n = 8
        int nrighe = n/5; //1
        int resto = n%5; //3
        int restoPrimoStrato = 0;
        int righePrimoStrato = nrighe/2; //1
        if(resto!=0){
            nrighe++; //2
            restoPrimoStrato = nrighe%2; //0
            if(restoPrimoStrato!=0)
                restoPrimoStrato = resto;
        }
        righePrimoStrato = nrighe/2; //1
        if(restoPrimoStrato!=0) //si
            righePrimoStrato++;// 2
        
        bool si = true;
        //provo a stampare primo strato
        for(int i = 0; i<righePrimoStrato;i++) { 
            for(int a = 0; a<5&&si; a++) {
                if(restoPrimoStrato!=0) {
                    if(i==righePrimoStrato-1)
                        resto--;
                    if(resto == 0)
                        si = false;
                }
                cout<<X[0][i][a]<<" ";
            }
            cout<<endl;
        }



/*        for(int i = 0; i<2;i++){
            for(int a = 0; a<nrighe&&procedi; a++, c2++) {
                for(int z = 0; z<5&&procedi;z++) {
                    if(a>=nrighe&&resto==0)
                        procedi=false;
                    else 
                        cout<<*(p+a*5+z+i*4*5)<<" ";
                }
                if(resto==0&&a>=nrighe)
                    procedi=false;
                cout<<endl;
            }
        }*/
    }