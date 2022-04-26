#include<stdio.h>



int main()
{
    int n,i;
	
	float wtavg, tatavg;
	printf("Enter the number of processes:");
	scanf("%d",&n);
    int p[n],bt[n], su[n], wt[n],ct[n], k, temp,at[n];
	for(i=0;i<n;i++)
	{
		p[i] = i+1;
		printf("Enter the Burst Time of Process%d:", i);
		scanf("%d",&bt[i]);
		printf("System/User Process (0/1) ? ");
		scanf("%d", &su[i]);
		printf("Arrival time");
		scanf("%d", &at[i]);
}
int maxAt=0;
for(i=0;i<n;i++)	
if(maxAt<at[i])
maxAt=at[i];
int loop =maxAt;
int rq[n],pr=0,rbt[n],rat[n],st=0,rsu[n];
int twt=0;
for(i=0;i<maxAt;i++)
{
   for(int j=0;j<n;j++)
 {
   if(i==at[j])
   {
   rq[pr]=p[j];
rbt[pr]=bt[j];
rat[pr]=at[j];
rsu[pr]=su[j];
   pr++;
   }
 }
 int cq[n],cr=0,cbt[n],cat[n],j=0,cnt=0,csu[n],cct[n],cwt[n];
  for(i=0;i<pr;i++)
{
 cq[j]=rq[i];
cbt[j]=rbt[i];
cat[j]=rat[i];
csu[j]=rsu[i];
j++;
cnt++;
}
st=pr;

///
for(i=0;i<cnt;i++)
		for(k=i+1;k<cnt;k++)
			if(csu[i] > csu[k])
			{
			temp=cq[i];
			cq[i]=cq[k];
			cq[k]=temp;
			temp=cbt[i];
			cbt[i]=cbt[k];
			cbt[k]=temp;
			temp=csu[i];
			csu[i]=csu[k];
			csu[k]=temp;
			}
///
 int sy=0,us=0;
   for(i=0;i<cnt;i++)
   {
      if(su[i]==1)
      us++;
      else sy++;
   }
int stwt=0,scpt=0;

     for(i=0;i<sy;i++)
		for(k=i+1;k<sy;k++)
			if(cbt[i] > cbt[k])
			{
			temp=cq[i];
			cq[i]=cq[k];
			cq[k]=temp;
			temp=cbt[i];
			cbt[i]=cbt[k];
			cbt[k]=temp;
			temp=csu[i];
			csu[i]=csu[k];
			csu[k]=temp;
			}
     for(i=sy;i<cnt;i++)
		for(k=i+1;k<cnt;k++)
			if(cq[i] > cq[k])
			{
			temp=cq[i];
			cq[i]=cq[k];
			cq[k]=temp;
			temp=cbt[i];
			cbt[i]=cbt[k];
			cbt[k]=temp;
			temp=csu[i];
			csu[i]=csu[k];
			csu[k]=temp;
			}
    for(i=0;i<cnt;i++)
    {
        cwt[i]= twt;
        cct[i] = twt+cbt[i];
        twt += cbt[i];   
    }
	printf("\nPROCESS\t\t SYSTEM/USER PROCESS \tBURST TIME\tWAITING TIME\tCOMPLETION TIME");
	for(i=0;i<cnt;i++)
		printf("\n%d \t\t %d \t\t\t %d \t\t %d \t\t %d ",p[i],su[i],bt[i],wt[i],ct[i]);
	// printf("\nAverage Waiting Time is --- %f",wtavg/n);
	// printf("\nAverage Turnaround Time is --- %f",tatavg/n);
}


return 0;
}
