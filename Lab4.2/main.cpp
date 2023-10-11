#include <iostream>
using namespace std;

int main() {
    long n; /*Вводим значение n, очевидно, что нельзя поделить число на сумму 1 или двух равных, но при этом различных порций*/
    cin >> n;
    if(n<=2){
        cout << "NO" << endl;
    }
    else{
        int a[n];
        long p = 0, m = 0, cp = n/2 + n%2, cm = n/2, petya[cp], masha[cm];
        for(int i = 0; i < n; i++){
            a[i] = i + 1;
            if (i < cp){
                petya[i] = 0;
            }
            if (i < cm){
                masha[i] = 0;
            }
        }
        
        for(int i = 0; i < n; i++){
            if (i%2==0){
                int j = 0;
                while(petya[j] != 0){
                    j++;
                }
                petya[j] = a[i];
                p += a[i];
            }
            else{
                int j = 0;
                while(masha[j] != 0){
                    j++;
                }
                masha[j] = a[i];
                m += a[i];
            }
        }
        if (n%2==1){
            for(int i = 0; i < cp; i++){
                petya[i] += 2;
                p += 2;
            }
            masha[cm - 1] += p - m;
            m += p - m;
        }
        else{
            petya[cp - 1] += cm;
            p += cm;
        }
                        /*выводим ответ*/
        cout << "YES" << "\n\n";
        cout << cp << endl;
        for(int i = 0; i < cp; i++){
            if(i < cp - 1){
                cout << petya[i] << ", ";
            }
            else{
                cout << petya[i] << endl;
            }
        }
        
        cout << endl << cm << endl;
        for(int i = 0; i < cm; i++){
            if(i < cm - 1){
                cout << masha[i] << ", ";
            }
            else{
                cout << masha[i] << endl;
            }
        }
    }
    return 0;
}
