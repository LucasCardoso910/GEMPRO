#include <iostream>
 
using namespace std;
 
int main() {
    int n;
    int *answers;
    
    cin >> n;
    answers = (int*) malloc(sizeof(int) * n);
    
    for (int i = 0; i < n; i++) {
        int days = 0;
        float supply;
        
        cin >> supply;
        
        while (supply > 1.0) {
            supply = supply / 2;
            days++;
        }

        answers[i] = days;
    }

    for (int i = 0; i < n; i++) {
        cout << answers[i] << " dias" << endl;
    }
 
    return 0;
}