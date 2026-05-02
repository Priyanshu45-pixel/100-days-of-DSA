#include <stdio.h>
#include <stdlib.h>

// Structure for car
typedef struct {
    int position;
    int speed;
} Car;

// Sort cars by position (descending)
int compare(const void *a, const void *b) {
    return ((Car *)b)->position - ((Car *)a)->position;
}

int carFleet(int target, int position[], int speed[], int n) {
    Car cars[n];

    // Combine position and speed
    for (int i = 0; i < n; i++) {
        cars[i].position = position[i];
        cars[i].speed = speed[i];
    }

    // Step 1: Sort by position descending
    qsort(cars, n, sizeof(Car), compare);

    int fleets = 0;
    float maxTime = 0.0;

    // Step 2: Traverse
    for (int i = 0; i < n; i++) {
        float time = (float)(target - cars[i].position) / cars[i].speed;

        if (time > maxTime) {
            fleets++;          // new fleet
            maxTime = time;    // update slowest time ahead
        }
    }

    return fleets;
}

// Driver code
int main() {
    int n, target;

    printf("Enter target distance: ");
    scanf("%d", &target);

    printf("Enter number of cars: ");
    scanf("%d", &n);

    int position[n], speed[n];

    printf("Enter positions:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &position[i]);

    printf("Enter speeds:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &speed[i]);

    int result = carFleet(target, position, speed, n);

    printf("Number of car fleets: %d\n", result);

    return 0;
}