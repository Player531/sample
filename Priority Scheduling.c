#include<stdio.h>
#define max 30
int main() {
    int n, bt[max], wt[max], tat[max], p[max], pr[max], i, j, pos, temp;
    float avgtat=0, avgwt=0;
	printf("Enter the number of processes: ");
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        printf("Process %d - Burst time: ", i+1);
        scanf("%d", &bt[i]);
        printf("Process %d - Priority: ", i+1);
        scanf("%d", &pr[i]);
        p[i] = i+1;
        printf("\n");
    }
    for(i=0;i<n;i++) {
    	pos = i;
    	for(j=i+1;j<n;j++) {
    		if(pr[j] < pr[pos]) {
    			pos = j;
			}
		}
		temp = pr[i];
		pr[i] = pr[pos];
		pr[pos] = temp;
		temp = bt[i];
		bt[i] = bt[pos];
		bt[pos] = temp;
		temp = p[i];
		p[i] = p[pos];
		p[pos] = temp;
	}
	wt[0] = 0;
	for(i=1;i<n;i++) {
		wt[i] = 0;
		for(j=0;j<i;j++) {
			wt[i] += bt[j];
		}
	}
	printf("+------------------------------------------------------------------------------------+");
	printf("\n|Process\t|Priority\t|Burst Time\t|Turn around time\t|Waiting Time|\n");
	printf("+------------------------------------------------------------------------------------+");
	for(i=0;i<n;i++) {
		tat[i] = bt[i] + wt[i];
		avgwt += wt[i];
		avgtat += tat[i];
		printf("\n|P%d\t\t|%d\t\t|%d\t\t|%d\t\t\t|%d\t\t|", p[i], pr[i], bt[i], tat[i], wt[i]);
	}
	printf("\n+------------------------------------------------------------------------------------+");
	avgwt = avgwt/(float)n;
	avgtat = avgtat/(float)n;
	printf("\n\nAverage Turn around Time: %.2f\n", avgtat);
	printf("\nAverage Waiting Time: %.2f\n", avgwt);
    return 0;
}
