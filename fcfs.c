#include<stdio.h>
#define max 30
int main() {
    int n, bt[max], wt[max], tat[max],i, j, temp[max];
    float avgtat=0, avgwt=0;
	printf("Enter the number of processes: ");
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        printf("Process %d - Burst time: ", i+1);
        scanf("%d", &bt[i]);
    }
	wt[0] = 0;
	for(i=1;i<n;i++) {
		wt[i] = 0;
		for(j=0;j<i;j++) {
			wt[i] += bt[j];
		}
	}
	printf("----------------------------------------------------------------------");
	printf("\nProcess\t\tBurst Time\tTurn around time\tWaiting Time\n");
	printf("----------------------------------------------------------------------");
	for(i=0;i<n;i++) {
		tat[i] = bt[i] + wt[i];
		avgwt += wt[i];
		avgtat += tat[i];
		printf("\nP%d\t\t%d\t\t%d\t\t\t%d", i+1, bt[i], tat[i], wt[i]);
	}
	printf("\n----------------------------------------------------------------------");
	avgwt = avgwt/(float)n;
	avgtat = avgtat/(float)n;
	printf("\n\nAverage Turn around Time: %.2f\n", avgtat);
	printf("\nAverage Waiting Time: %.2f\n", avgwt);
    return 0;
}
