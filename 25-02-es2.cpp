#include <iostream>

using namespace std;

int main()
{
    //PRE=(cin contiene n (0<n<=100) seguito da n interi)
    int n=0, a=0, array[n];
    cin>>n;

    while(n>a) {
        cin>>array[a];
        a++;
    }
    int i = 0; //contatore ciclo grande
    int z = 0; //contatore ciclo piccolo 
    int buffer= 0;
    int segnalino = 0; // segno fino a dove i valori dell'array sono "originali"
    bool ok = true;
    while(i<n) {
        if(array[i] == *(array+i+1)) {
            z = i+1;
            while(z<n && ok) { // dovrebbe andare bene cosi la condizone
                buffer = array[z];
                array[z] = *(array+z+1);
                *(array+z+1) = buffer;
                z++;
                int a = n-1;
                if(z==a) ok = false;
            }
        }
        i++;
    }
    cout<<endl;
    for(int i = 0; i<n;i++) {
        cout <<array[i]<<endl;
    }
    cout<<"start"<<endl;
    cout<<"end"<<endl;
    return 0;
}  