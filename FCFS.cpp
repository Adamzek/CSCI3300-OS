#include <iostream>
#include <iomanip>
using namespace std;

struct Process {
    int ccode;         // course code
    int duration;      // class duration
    int priority;      // priority
    int arrival_time;  // preferred start time
};

// Function to perform FCFS Scheduling
void FCFS(Process proc[], int n) {
    int waiting_time[n], turnaround_time[n];
    waiting_time[0] = 0;

    // Calculate waiting time
    for (int i = 1; i < n; i++) {
        waiting_time[i] = proc[i - 1].duration + waiting_time[i - 1];
    }

    // Calculate turnaround time
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = proc[i].duration + waiting_time[i];
    }

    // Output
    cout << "\nFCFS Scheduling Order:\n";
    int total_wt = 0, total_tt = 0;
    for (int i = 0; i < n; i++) {
        cout << "Course " << proc[i].ccode << " | Waiting Time: " << waiting_time[i]
             << " | Turnaround Time: " << turnaround_time[i] << endl;
        total_wt += waiting_time[i];
        total_tt += turnaround_time[i];
    }

    cout << "Average Waiting Time (FCFS): " << fixed << setprecision(2) << (float)total_wt / n << endl;
    cout << "Average Turnaround Time (FCFS): " << fixed << setprecision(2) << (float)total_tt / n << endl;
}
// Main Function
int main() {
    Process proc[] = {{2201, 3, 2, 1}, {3401, 2, 3, 2}, {1103, 1, 1, 3}};
    int n = sizeof(proc) / sizeof(proc[0]);

    // Make a copy of original array for separate use
    Process proc_copy[n];
    for (int i = 0; i < n; i++) {
        proc_copy[i] = proc[i];
    }

    FCFS(proc, n);

    return 0;
}
