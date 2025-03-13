#include<stdio.h>
struct profit
{
	int job,dead,pro;
};
int main()
{
	struct profit p[5];
	printf("ENTER THE jobs : ");
	for(int i=0;i<5;i++)
	{
		scanf("%d",&p[i].job);
	}
	printf("ENTER THE deadlines : ");
	for(int i=0;i<5;i++)
	{
		scanf("%d",&p[i].dead);
	}
	printf("ENTER THE profit : ");
	for(int i=0;i<5;i++)
	{
		scanf("%d",&p[i].pro);
	}
	int j;
	struct profit swap;
	for(int i=0;i<4;i++)
	{
		for(j=0;j<5-i-1;j++)
		{
			if(p[j].pro<p[j+1].pro)
			{
				swap=p[j];
				p[j]=p[j+1];
				p[j+1]=swap;
			}
		}
	}
	printf("RESULT: \n");
	for(int i=0;i<5;i++)
	{
		printf("%d",p[i].job);
		printf("\n%d",p[i].dead);
		printf("\n%d",p[i].pro);
		printf("\n\n");
	}
    int seq[3]={-1,-1,-1};
    for(int i=0;i<5;i++)
    {
    	j=p[i].dead-1;
    	while(j>=0)
    	{
    		if(seq[j]==-1)
    		{
    			seq[j]=i;
    			break;
			}
			j=j-1;
		}
	}
    printf("SCHEDULED JOBS: \n");
    for (int i = 0; i < 3; i++) 
	{
        if (seq[i] != -1) 
		{
            printf("Slot %d: Job %d\n", i + 1, p[seq[i]].job);
        } 
		else 
		{
            printf("Slot %d: Empty\n", i + 1);
        }
    }
	return 0;
}
