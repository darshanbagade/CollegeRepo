#include <stdio.h>

void sort_by_arrival(int n, int arrival_time[], int burst_time[], int process_id[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arrival_time[j] > arrival_time[j + 1]) {
                
                int temp = arrival_time[j];
                arrival_time[j] = arrival_time[j + 1];
                arrival_time[j + 1] = temp;
                
                
                temp = burst_time[j];
                burst_time[j] = burst_time[j + 1];
                burst_time[j + 1] = temp;
                
                
                temp = process_id[j];
                process_id[j] = process_id[j + 1];
                process_id[j + 1] = temp;
            }
        }
    }
}

void fcfs(int n, int arrival_time[], int burst_time[], int completion_time[], int waiting_time[], int turnaround_time[], int process_id[]) {
    sort_by_arrival(n, arrival_time, burst_time, process_id);
    int time = 0;
    for (int i = 0; i < n; i++) {
        if (time < arrival_time[i])
            time = arrival_time[i];
        
        completion_time[i] = time + burst_time[i];
        turnaround_time[i] = completion_time[i] - arrival_time[i];
        waiting_time[i] = turnaround_time[i] - burst_time[i];
        
        time = completion_time[i];
    }
}

void display(int n, int arrival_time[], int burst_time[], int completion_time[], int waiting_time[], int turnaround_time[], int process_id[]) {
    printf("\nPID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t\t %d \t\t %d \t\t %d \t\t %d \t\t %d\n", process_id[i], arrival_time[i], burst_time[i], completion_time[i], turnaround_time[i], waiting_time[i]);
    }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    int arrival_time[n], burst_time[n], completion_time[n], waiting_time[n], turnaround_time[n], process_id[n];
    
    for (int i = 0; i < n; i++) {
        process_id[i] = i + 1;
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
    }
    
    fcfs(n, arrival_time, burst_time, completion_time, waiting_time, turnaround_time, process_id);
    display(n, arrival_time, burst_time, completion_time, waiting_time, turnaround_time, process_id);
    
    return 0;
}