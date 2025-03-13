#include<stdio.h>
int n;
int profit[100];
int weight[100];
int w;
float avg[100];
float total_profit;
float fractional_knapsack()
{
	int curr_weight=w;
	for(int i=0;i<n;i++)
	{
		avg[i]=(float)profit[i]/weight[i];
	}
	for(int i=0;i<n;i++) 
	{
        for(int j=i+1;j<n;j++) 
		{
            if(avg[i]<avg[j]) 
			{
                float temp=avg[i];
                avg[i]=avg[j];
                avg[j]=temp;
                int temp2=profit[i];
                profit[i]=profit[j];
                profit[j]=temp2;
                temp2=weight[i];
                weight[i]=weight[j];
                weight[j]=temp2;
            }
        }
    }
	total_profit=0.0;
	while(curr_weight>0)
	{
		for(int i=0;i<n;i++)
		{
			if(weight[i]<=curr_weight)
			{
				curr_weight=curr_weight-weight[i];
				total_profit=total_profit+profit[i];
			}
			else
			{
				total_profit=total_profit+curr_weight*avg[i];
				curr_weight=0;
				break;
			}
		}
	}
	return total_profit;
}
int main() 
{
    printf("Enter number of items: ");
    scanf("%d",&n);
    printf("Enter profits and weights:\n");
    for(int i=0;i<n;i++) 
	{
        scanf("%d %d",&profit[i],&weight[i]);
    }
    printf("Enter knapsack capacity: ");
    scanf("%d",&w);
    float max_profit=fractional_knapsack();
    printf("Maximum Profit: %.2f\n",max_profit);
    return 0;
}
