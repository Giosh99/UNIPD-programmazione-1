    #include <iostream>

    using namespace std;

    int main() {
        int A[3][4][5];
        for(int i = 0; i<3;i++) {   
            for(int a = 0; a<4;a++) {
                for(int z = 0; z<5;z++) {
                    cin>>A[i][a][z];
                }
            }
        }

        char taglio;//tipo di fetta (V o H)
        cin>>taglio; 
        int n;// riga/colonna richiesta
        cin>>n; 
        int *p = A[0][0];
        cout<<"start"<<endl;
        if(taglio=='H') {
            for(int i = 0; i<3;i++) { //R(0<=i<=3)&&(eseguo i volte il ciclo innestato)
                for(int j=0;j<5;j++) { // R(0<=i<=5)&&(stampo j valori secondo la riga n e lo strato i)
                    cout<<*(p+n*5+j+5*4*i)<<" ";
                }
                cout<<endl;
            }
        }
        else if(taglio=='V') {
            for(int i = 0; i<3;i++) {
                for(int j=0;j<4; j++){
                    cout<<*(p+n+j*5+i*5*4)<<" ";
                }
                cout<<endl;
            }
        }
        cout<<"end";

    }