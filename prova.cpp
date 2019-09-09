#include <iostream>

using namespace std;

void f(int *p) {
    *p = *p+1;
    cout<<*p<<endl;
}

int main() {
    {

        int x = 5;
        int *p = &x;
        f(p);
        cout<<x<<endl;
        /*
        int a = 4;
        {
            char x = 't';
            int c = 8;
            cout<<"sono x interna: "<<x<<endl;
            cout<<"stampo a dal blocco interno: "<<a<<endl;
        }
        cout<<"sono x esterna: "<<x<<endl;*/
    }
}