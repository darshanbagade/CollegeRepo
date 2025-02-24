#include <stdio.h>
#include <limits.h>

void sjf_preemptive(int n, int arrival_time[], int burst_time[]) {
    int remaining_time[n], completion_time[n], turnaround_time[n], waiting_time[n];
    int time = 0, completed = 0, shortest = -1, min_burst = INT_MAX;
    int is_completed[n];
    
    for (int i = 0; i < n; i++) {
        remaining_time[i] = burst_time[i];
        is_completed[i] = 0;
    }
    
    while (completed != n) {
        shortest = -1;
        min_burst = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            if (arrival_time[i] <= time && is_completed[i] == 0 && remaining_time[i] < min_burst) {
                min_burst = remaining_time[i];
                shortest = i;
            }
        }
        
        if (shortest == -1) {
            time++;
            continue;
        }
        
        remaining_time[shortest]--;
        time++;
        
        if (remaining_time[shortest] == 0) {
            completion_time[shortest] = time;
            turnaround_time[shortest] = completion_time[shortest] - arrival_time[shortest];
            waiting_time[shortest] = turnaround_time[shortest] - burst_time[shortest];
            is_completed[shortest] = 1;
            completed++;
        }
    }
    
    float total_tat = 0, total_wt = 0;
    printf("\nPID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, arrival_time[i], burst_time[i], completion_time[i], turnaround_time[i], waiting_time[i]);
        total_tat += turnaround_time[i];
        total_wt += waiting_time[i];
    }
    
    printf("\nAverage Turnaround Time: %.2f", total_tat / n);
    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    int arrival_time[n], burst_time[n];
    
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
    }
    
    sjf_preemptive(n, arrival_time, burst_time);
    
    return 0;
}