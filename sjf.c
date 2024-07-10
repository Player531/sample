#include<stdio.h>
#define max 30
int main() {
	void display(int a[], int n) {
		int i;
		for(i=0;i<n;i++) {
			printf("%d ", a[i]);
		}
	}
	int bt[max], p[max], wt[max], tat[max];
	int i, j, n, total = 0, pos, temp;
	float avgtat=0, avgwt=0;
	printf("Enter the number of Processes: ");
	scanf("%d", &n);
	printf("\nEnter the Burst time:\n");
	for(i=0;i<n;i++) {
		printf("Process - %d: ",i + 1);
		scanf("%d", &bt[i]);
		p[i] = i + 1;
	}
	//Sorting the burst times
	for(i=0;i<n;i++) {
		pos = i;
		for(j=i+1;j<n;j++) {
			if(bt[j] < bt[pos]) {
				pos = j;
			}
		}
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
		total += wt[i];
	}
	avgwt = (float)total/(float)n;
	total = 0;
	printf("+-----------------------------------------------------------------------+");
	printf("\n|Process\t|Burst Time\t|Turn around time\t|Waiting Time\t|\n");
	printf("+-----------------------------------------------------------------------+");
	for(i=0;i<n;i++) {
		tat[i] = bt[i] + wt[i];
		avgtat += tat[i];
		printf("\n|P%d\t\t|%d\t\t|%d\t\t\t|%d\t\t|", p[i], bt[i], tat[i], wt[i]);
	}
	printf("\n+-----------------------------------------------------------------------+");
	avgtat = (float)avgtat/(float)n;
	printf("\n\nAverage Turn around Time: %.2f\n", avgtat);
	printf("\nAverage Waiting Time: %.2f\n", avgwt);
	return 0;
}
