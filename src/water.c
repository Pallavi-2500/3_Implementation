#include "water.h"
#include<string.h>

void newmember(struct member *p, int n )
{
	int ch_u, ch_wk;
	float weight;
	int hr,min;
	char tmr_wk[10];
	(p+n)->usr_id = n;
	printf("Enter your Name:");
	scanf("%s",(p + n)->name);
	printf("Select a unit of your preference:\n");
	printf("   1. SI units(kgs)    ");
	printf("   2. Imperial(Pounds)    ");
	scanf("%d",&ch_u);
	if(ch_u == 1)
	{
		(p + n)->unit = 1;
		printf("Enter your weight in Kgs:");
		scanf("%f",&weight);
		(p+n)->w = weight;
	}
	else
	{
		(p +n)->unit =2;
		printf("Enter your weight in Pounds:");
		scanf("%f",&weight);
		(p+n)->w = weight;
		//printf("%f, Weight",(p+n)->w);
	}
	printf("Do you workout? :\n");
	printf("   1. Yes    \n");
	printf("   2. No    \n");
	printf(" Enter your choice: ");
	scanf("%d",&ch_wk);
	if(ch_wk == 1)
	{
		printf("Enter workout duration in \"hh:mm\" format: ");
		scanf("%2d:%2d",&hr,&min);
		(p+n)->time[0] = hr;
		(p+n)->time[1] = min;
	}
	else
	{
		(p+n)->time[0] = 0;
		(p+n)->time[1] = 0;
	}
		
}

void calcwaterquant( struct member *p, int n )
{	
	int hr=0, min=0, t=0;
	float wt, q, total_w=0; 
	//printf("Calculate Water!!!!!\n");
	if((p+n)->unit == 1)
	{
		wt = (p+n)->w * 2.2046;
		//printf("Weight kg %f \n", wt);
		q = wt * (2/3.0);
		hr = (p+n)->time[0];
		min = (p+n)->time[1];
		t = (hr*60) + min;
		(p+n)->total_w = (q + ((t/30)*12)) * 0.0295735;
	}
	else
	{
		wt = (p+n)->w;
		//printf("WEIGHT %f\n",wt);
		q = wt * (2/3.0);
		//printf("Water: %f\n",q);
		hr = (p+n)->time[0];
		min = (p+n)->time[1];
		//sscanf((p+n)->time, "%d:%d", &hr,&min);
		t = (hr*60) + min;
		(p+n)->total_w = (q + ((t/30)*12));
	}	
}

void displaymemberdetails( struct member *p, int n)
{
	printf("-------------------------------------------------\n");
	printf("Member ID: %d\n",(p+n)->usr_id);
	printf("Member Name: %s\n",(p+n)->name);
	if((p+n)->unit == 1)
	{
		printf("Units used: SI units\n");
	}
	else if((p+n)->unit == 2)
	{
		printf("Units used: Imperial units\n");
	}
	printf("Weight: %f\n",(p+n)->w);
	printf("Workout duration: %d:%d\n",(p+n)->time[0],(p+n)->time[1]);
	printf("Recomended Water-intake: %f\n",(p+n)->total_w);
}
