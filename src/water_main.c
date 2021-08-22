#include "water.h"

void calcwaterquant( struct member *p, int );

void water()
{
	struct member ptr1[100];
	int r = 0, x = 0, mbid;
	
	while(x!=3)
	{
		int choice;
		printf("     Water Tracker     \n");
		printf(" -------------------------------------------------------------------\n");
		printf("               1- To Estimate recomended water intake:           \n");
		printf("               2- Check your record:          \n");
		printf("               3- Exit:          \n");
		printf(" ------------------------------------------------------------------ \n");	
		printf("  Enter your choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				if(r>=0)
				{
					newmember(ptr1,r);
					calcwaterquant(ptr1,r);
					displaymemberdetails(ptr1,r);
					r = r+1;
				}
				break;
		  	case 2:
		  		printf("Enter ID:\n");
				scanf("%d",&mbid);
				displaymemberdetails(ptr1,mbid);
		  		break;
		  	case 3:
		  		x=3;
		  		break;
		  	default:
		  		printf("Incorrect Entry\n");
		  		break;
		  }
	}

}
