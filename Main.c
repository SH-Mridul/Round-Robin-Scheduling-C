#include<stdio.h>

void main()
{
		//get total process from user
		printf("Enter total process:");
		int process; //total process
		scanf("%d",&process);

		int burstTime[process]; //burst time
		int ta[process];// turn around times
		int wt[process];// waiting times
		int TQ; //time quantities

		printf("Enter Time Quantum:");
		scanf("%d",&TQ);


		//get bust time from user
		int totalTA = 0;
		float wtAv = 0;
		for(int i = 0;i<process;i++)
		{
			printf("Enter burst time for process %d:",i+1);
			scanf("%d",&burstTime[i]);
			totalTA += burstTime[i];
			ta[i] = totalTA-0;
			wt[i] = totalTA-burstTime[i];
			wtAv+= wt[i];
		}


		float taT = 0;
        for(int i = 0;i<process;i++)
        {
        	taT += ta[i];
        }


        printf("\n");
		printf("---------------------------\n");
		printf("P.Id\tB.T\tT.A\tW.T\n");
		printf("---------------------------\n");
		for(int i = 0; i<process;i++)
		{
			printf("%d\t %d\t %d\t %d\n",(i+1),burstTime[i],ta[i],wt[i]);
		}

		printf("---------------------------\n");
		printf("   Avarage process time\n");
		printf("---------------------------\n");

		printf("Avrg.T.A.T:%d\n",taT/process);
		printf("Avrg.W.T:%d\n",wtAv/process);
		printf("---------------------------\n");



       int flag = 1;

       int processList[100];
       int TqList[100];

       int totalTime = 0;
       int processTQindex = 0;

       while(flag)
       {
    	   for(int i = 0; i<process; i++)
    	   {
    		   if(burstTime[i] == 0 || burstTime[i]< 0)
    			   continue;
    		   int counter = 0;
    		   while(counter<TQ)
    		   {
    			   if(burstTime[i] == 0|| burstTime[i]<0)
    				   break;

    			   counter++;
    			   burstTime[i] = burstTime[i] - 1;
        		   totalTime += 1;

    		   }

    		   processList[processTQindex] = i+1;
    		   TqList[processTQindex] = totalTime;
               processTQindex++;
    	   }

    	   flag =  checkEmpty(burstTime);
       }

       printf("------------------------------------------------------------------------\n");
       for(int i = 0; i<processTQindex;i++)
       {
    	   printf("| P%d |",processList[i]);
       }
       printf("\n------------------------------------------------------------------------\n");
       printf("%d",0);

       for(int i = 0; i<processTQindex; i++)
       {
    	  printf("    %d",TqList[i]);
       }

       getch();
   }

    int checkEmpty(int arr[]){
        int count = 0;

		for(int i = 0;i<4;i++)
		{
			if(arr[i] == 0 || arr[i]<0)
				count++;
		}

		if(count == 4)
			return 0;

		return 1;
	}
