#include <stdio.h>
#include <stdbool.h>

// Function to compute total weight
double computeTotalWeight(double droneWeight, double payloadWeight) {
    return droneWeight + payloadWeight;
}

// Function to estimate battery drain
double estimateDrain(double distanceKm, double totalWeight, double windSpeed) {
    double baseDrain = distanceKm * 2.2;
    double weightPenalty = totalWeight * 0.8;
    double windPenalty = windSpeed * 1.5;
    return baseDrain + weightPenalty + windPenalty;
}

// Pointer function: applies a 5% safety buffer to remaining battery
void applySafetyBuffer(double* remainingBattery) {
    *remainingBattery = *remainingBattery - 5.0;
}

// Function to determine and print mission status
void determineStatus(char model, double totalWeight, double windSpeed, double remainingBattery) {
    double modelLimit;
    if (model == 'A') modelLimit = 6.0;
    else if (model == 'B') modelLimit = 8.5;
    else modelLimit = 11.0;

    if (totalWeight > modelLimit) {
        printf("Status: MISSION FAIL (Overweight)\n");
    } else if (windSpeed > 12) {
        printf("Status: MISSION FAIL (Unsafe Wind)\n");
    } else if (remainingBattery < 20) {
        printf("Status: MISSION FAIL (Low Battery)\n");
    } else {
        printf("Status: MISSION PASS\n");
    }
}

// Function to print the mission report
void printReport(char model, double totalWeight, double estimatedDrain,
                 double remainingBattery, int checkpoints, double windSpeed) {
    double modelLimit;
    if (model == 'A') modelLimit = 6.0;
    else if (model == 'B') modelLimit = 8.5;
    else modelLimit = 11.0;

    printf("\n--- DRONE MISSION REPORT ---\n");
    printf("Model: %c\n", model);
    printf("Total Weight: %.2f kg\n", totalWeight);

    if (totalWeight <= modelLimit && windSpeed <= 12) {
        double avgDrain = (double)estimatedDrain / checkpoints;
        printf("Estimated Drain: %.2f %%\n", estimatedDrain);
        printf("Remaining Battery: %.2f %%\n", remainingBattery);
        printf("Average Drain per Checkpoint: %.2f %%\n", avgDrain);
    }

    determineStatus(model, totalWeight, windSpeed, remainingBattery);
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("--- DRONE MISSION CONSOLE ---\n");
        printf("1. Run Mission Simulation\n");
        printf("2. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 2) {
            printf("Goodbye!\n");
            break;
        }

        if (choice != 1) {
            printf("Invalid choice. Try again.\n\n");
            continue;
        }

        // Collect inputs
        char model;
        double payloadWeight, droneWeight, distanceKm, windSpeed, batteryPercent;
        int checkpoints;

        printf("Drone model (A, B, or C): ");
        scanf(" %c", &model);
        printf("Payload weight (kg): ");
        scanf("%lf", &payloadWeight);
        printf("Drone weight (kg): ");
        scanf("%lf", &droneWeight);
        printf("Flight distance (km): ");
        scanf("%lf", &distanceKm);
        printf("Wind speed (m/s): ");
        scanf("%lf", &windSpeed);
        printf("Battery percentage (0-100): ");
        scanf("%lf", &batteryPercent);
        printf("Number of checkpoints: ");
        scanf("%d", &checkpoints);

        // Validate checkpoints
        if (checkpoints <= 0) {
            printf("Checkpoints must be greater than 0.\n\n");
            continue;
        }

        // Calculations
        double totalWeight = computeTotalWeight(droneWeight, payloadWeight);
        double estimatedDrain = estimateDrain(distanceKm, totalWeight, windSpeed);
        double remainingBattery = batteryPercent - estimatedDrain;

        // Apply safety buffer via pointer
        applySafetyBuffer(&remainingBattery);

        // Print report
        printReport(model, totalWeight, estimatedDrain, remainingBattery, checkpoints, windSpeed);
    }

    return 0;
}