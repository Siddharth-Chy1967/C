Drone Mission Simulation (C Program)
Overview

This program simulates a drone delivery mission by calculating battery usage, evaluating environmental conditions, and determining whether the mission succeeds or fails. It provides a detailed mission report based on user inputs such as drone model, payload, distance, wind speed, and battery level.

Features
Calculates total drone weight
Estimates battery drain based on distance, weight, and wind speed
Applies a safety buffer to remaining battery using pointers
Evaluates mission feasibility based on:
Weight limits per drone model
Wind conditions
Remaining battery
Generates a formatted mission report
Interactive console-based menu system
Drone Models and Constraints
Model	Maximum Weight (kg)
A	6.0
B	8.5
C	11.0
Mission Failure Conditions

A mission will fail if:

Total weight exceeds the model limit
Wind speed is greater than 12 m/s
Remaining battery is less than 20%
How It Works
1. Input সংগ্রহ

User provides:

Drone model (A, B, or C)
Payload weight (kg)
Drone weight (kg)
Flight distance (km)
Wind speed (m/s)
Battery percentage (%)
Number of checkpoints
2. Calculations
Total Weight = drone weight + payload weight
Estimated Drain =
(distance × 2.2) + (total weight × 0.8) + (wind speed × 1.5)
Remaining Battery = initial battery − estimated drain − 5% safety buffer
3. Output

The program prints:

Total weight
Estimated battery drain
Remaining battery
Average drain per checkpoint
Final mission status (PASS / FAIL with reason)
Compilation and Execution
Compile
gcc assignment3.c -o drone_sim
Run
./drone_sim
Example Output
--- DRONE MISSION REPORT ---
Model: B
Total Weight: 7.50 kg
Estimated Drain: 35.20 %
Remaining Battery: 59.80 %
Average Drain per Checkpoint: 7.04 %
Status: MISSION PASS
Code Structure
computeTotalWeight()
Calculates combined weight of drone and payload
estimateDrain()
Computes battery usage based on mission parameters
applySafetyBuffer()
Uses pointer to subtract 5% battery as a safety margin
determineStatus()
Checks mission constraints and prints result
printReport()
Displays formatted mission summary
main()
Handles user interaction and program flow
Notes
Input validation ensures checkpoints are greater than zero
Pointer usage demonstrates basic memory manipulation in C
Modular design improves readability and maintainability
