#include<stdio.h>
int mat[10][6];
void findWaitingTime(int processes[], int n, int bt[],
                                   int wt[], int at[])
{
    int service_time[n];
    service_time[0] = at[0];
    wt[0] = 0;
 
    // calculating waiting time
    for (int i = 1; i < n ; i++)
    {
        // Add burst time of previous processes
        service_time[i] = service_time[i-1] + bt[i-1];
 
        // Find waiting time for current process =
        // sum - at[i]
        wt[i] = service_time[i] - at[i];
 
        // If waiting time for a process is in negative
        // that means it is already in the ready queue
        // before CPU becomes idle so its waiting time is 0
        if (wt[i] < 0)
            wt[i] = 0;
    }
}
 
// Function to calculate turn around time
void findTurnAroundTime(int processes[], int n, int bt[],
                                      int wt[], int tat[])
{
    // Calculating turnaround time by adding bt[i] + wt[i]
    for (int i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}
 
// Function to calculate average waiting and turn-around
// times.
void findavgTime(int processes[], int n, int bt[], int at[])
{
    int wt[n], tat[n];
 
    // Function to find waiting time of all processes
    findWaitingTime(processes, n, bt, wt, at);
 
    // Function to find turn around time for all processes
    findTurnAroundTime(processes, n, bt, wt, tat);
 
    // Display processes along with all details
    printf( "Processes  Burst Time  Arrival Time  Waiting Time  Turn-Around Time  Completion Time \n");
    int total_wt = 0, total_tat = 0;
    for (int i = 0 ; i < n ; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        int compl_time = tat[i] + at[i];
     printf( " %d \t\t %d \t\t %d \t\t %d \t\t  %d \n",i,bt[i],at[i],wt[i],compl_time);
    }
 
    printf ("Average waiting time = %f",(float)total_wt / (float)n);
    printf("\nAverage turn around time = %f",(float)total_tat / (float)n);
}

//sjf
int mat[10][6];
  
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
  
void arrangeArrival(int num, int mat[][6])
{
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (mat[j][1] > mat[j + 1][1]) {
                for (int k = 0; k < 5; k++) {
                    //swap(mat[j][k], mat[j + 1][k]);
                     int temp = mat[j][k];
                 mat[j][k]=mat[j+1][k];
                  mat[j+1][k]=temp;
                }
            }
        }
    }
}
  
void completionTime(int num, int mat[][6])
{
    int temp, val;
    mat[0][3] = mat[0][1] + mat[0][2];
    mat[0][5] = mat[0][3] - mat[0][1];
    mat[0][4] = mat[0][5] - mat[0][2];
  
    for (int i = 1; i < num; i++) {
        temp = mat[i - 1][3];
        int low = mat[i][2];
        for (int j = i; j < num; j++) {
            if (temp >= mat[j][1] && low >= mat[j][2]) {
                low = mat[j][2];
                val = j;
            }
        }
        mat[val][3] = temp + mat[val][2];
        mat[val][5] = mat[val][3] - mat[val][1];
        mat[val][4] = mat[val][5] - mat[val][2];
        for (int k = 0; k < 6; k++) {
            int temp = mat[val][k];
            mat[val][k]=mat[i][k];
            mat[i][k]=temp;
           // swap(mat[val][k], mat[i][k]);
        }
    }
}


int main()
{
    int n;
	
	float wtavg, tatavg;
	printf("Enter the number of processes:");
	scanf("%d",&n);
    int p[n],bt[n], su[n], wt[n],ct[n],i, k, temp,at[n];
	for(i=0;i<n;i++)
	{
		p[i] = i;
		printf("Enter the Burst Time of Process%d:", i);
		scanf("%d",&bt[i]);
		printf("System/User Process (0/1) ? ");
		scanf("%d", &su[i]);
		printf("Arrival time");
		scanf("%d", &at[i]);
	}
	for(i=0;i<n;i++)
		for(k=i+1;k<n;k++)
			if(su[i] > su[k])
			{
			temp=p[i];
			p[i]=p[k];
			p[k]=temp;
			temp=at[i];
			at[i]=at[k];
			at[k]=temp;
			temp=bt[i];
			bt[i]=bt[k];
			bt[k]=temp;
			temp=su[i];
			su[i]=su[k];
			su[k]=temp;
			}
    
	wtavg = wt[0] = 0;
    int sy=0,us=0;
   for(i=0;i<n;i++)
   {
      if(su[i]==1)
      us++;
      else sy++;
   }

 int sp[sy],sbt[sy],sat[sy];
int j=0;
 for(i=0;i<sy;i++)
 { 
    mat[j][0]=p[i];
    mat[j][1]=at[i];
    mat[j][2]=bt[i];
 }
  
  arrangeArrival(sy, mat);
    completionTime(sy, mat);
 printf("Process ID \tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < sy; i++) {
        printf("%d\t\t %d \t\t%d\t\t %d \t\t %d\n",mat[i][0],mat[i][1],mat[i][2],mat[i][4],mat[i][5]);
    }
	
 int usp[us],ubt[us],uat[us];
j=0;
 for(i=sy;i<n;i++)
 { 
     usp[j]=p[i];
     ubt[j]=bt[i];
     uat[j]=at[i];
 }
findavgTime(usp, us, ubt, uat);
	return 0;
}
