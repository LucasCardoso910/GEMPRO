#include <stdio.h>

#define KMPERLITER 12
 
int main() {
    float hours, speed, liters;
    
    scanf("%f", &hours);
    scanf("%f", &speed);

    liters = (hours * speed) / KMPERLITER;
    
    printf("%.3f\n", liters);
 
    return 0;
}