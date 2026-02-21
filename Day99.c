// Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.
// Sort cars by position in descending order and calculate time to reach target.
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pos;
    int speed;
} Car;

int cmp(const void *a, const void *b) {
    return ((Car*)b)->pos - ((Car*)a)->pos;
}

int main() {
    int n, target;
    scanf("%d %d", &n, &target);

    Car cars[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &cars[i].pos);
    }

    for(int i = 0; i < n; i++) {
        scanf("%d", &cars[i].speed);
    }

    qsort(cars, n, sizeof(Car), cmp);

    int fleets = 0;
    double time = 0;

    for(int i = 0; i < n; i++) {
        double t = (double)(target - cars[i].pos) / cars[i].speed;
        if(t > time) {
            fleets++;
            time = t;
        }
    }

    printf("%d", fleets);

    return 0;
}