/* 
Questão em: https://www.urionlinejudge.com.br/judge/en/problems/view/2340 
Acesso: 26/04/2021
Autor: Lucas Cardoso dos Santos
*/

/*

Testes:
# 1             # 2             # 3
- Input:        - Input:        - Input:
    2               5               4
    2 5             2   1           145 15
    3 4             4   5           2   4999
                    30  4           3   3211
                    20  6           135 20
                    2   154     

- Output:       - Output:       - Output:
    1               4               2

*/

#include <iostream>
#include <cmath>
 
using namespace std;
 
int main() {
    int n, tipo_melhor = 0;
    long double numero_melhor = 0;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        long double d, c, v;
        
        cin >> d >> c;
        v = c* log10(d);
        
        if (v > numero_melhor) {
            numero_melhor = v;
            tipo_melhor = i;
        }
    }
    
    cout << tipo_melhor << endl;
 
    return 0;
}