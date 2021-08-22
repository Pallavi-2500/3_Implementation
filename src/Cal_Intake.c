#include "dietPlan.h"
#include "Cal_Intake.h"
#include<stdio.h>
#include<stdlib.h>
int brkfst_limit=0,lunch_limit=0,snack_limit =0,dinner_limit =0;








int mealchoice(int bmr,brkfst *b_head,lunch *l_head,snack *s_head,dinner *d_head)
{
    int choice;
       
    printf("________________________Choose your Meal plan_______________________\n");
    printf("1. Fiesty Breakfast, Light lunch, Healthy dinner\n2.Healthy breakfast, Fiesty lunch, Light dinner\n3. Light Breakfast, Healthy lunch, Fiesty dinner\n");
    fscanf(stdin,"%d",&choice);
        if(choice==1){
            return brkfst_priority(bmr,b_head,l_head,s_head,d_head);
            }
        else if (choice ==2){
            return lunch_priority(bmr,b_head,l_head,s_head,d_head);
        }
        else if (choice ==3){
            return dinner_priority(bmr,b_head,l_head,s_head,d_head);
        }
        else
        {
            printf("Choose a valid choice");
            return 0;
        }

}
int brkfst_priority(int bmr,brkfst *b_head,lunch *l_head,snack *s_head,dinner *d_head)
{
    brkfst_limit = (40/100.0)*bmr;
    lunch_limit = (20 / 100.0)*bmr;
    snack_limit = (10/100.0)*bmr;
    dinner_limit = (30/100.0)*bmr;
    return dietPlan(b_head,l_head,s_head,d_head); 
}
int lunch_priority(int bmr,brkfst *b_head,lunch *l_head,snack *s_head,dinner *d_head)
{
    brkfst_limit = (30/100.0)*bmr;
    lunch_limit = (40/100.0)*bmr;
    snack_limit = (10/100.0)*bmr;
    dinner_limit = (20/100.0)*bmr;
    return dietPlan(b_head,l_head,s_head,d_head); 
}
int dinner_priority(int bmr,brkfst *b_head,lunch *l_head,snack *s_head,dinner *d_head)
{
    brkfst_limit = (20/100.0)*bmr;
    lunch_limit = (30/100.0)*bmr;
    snack_limit = (10/100.0)*bmr;
    dinner_limit = (40/100.0)*bmr; 
    return dietPlan(b_head,l_head,s_head,d_head);
}


int dietPlan(brkfst *b_head,lunch *l_head,snack *s_head,dinner *d_head){
    printBrkfstList(b_head);
    printDinnerList(d_head);
    printSnacksList(s_head);
    printLunchList(l_head);

}

int printBrkfstList(brkfst *head){
    if(head ==NULL){
        return -1;
    }
    
      brkfst* temp = head;

      printf("\n");
      while(temp!=NULL){

            //printf("%-49s\t%d\n",temp->name,temp->cal);
            if (temp->cal<brkfst_limit)
            {
                printf("%-49s\t%d\n",temp->name,temp->cal);
            }
            temp = temp->next;
      }
      return 1;
}
int printLunchList(lunch *head){
    if(head ==NULL){
        return -1;
    }
    
    lunch* temp = head;

    printf("\n");
    while(temp!=NULL){
            
            //printf("%-49s\t%d\n",temp->name,temp->cal);
            if (temp->cal<lunch_limit)
            {
                printf("%-49s\t%d\n",temp->name,temp->cal);
            }
            temp = temp->next;
    }
    return 1;
}
int printSnacksList(snack *head){
    if(head ==NULL){
        return -1;
    }
    
    snack* temp = head;

    printf("\n");
    while(temp!=NULL){
            
            //printf("%-49s\t%d\n",temp->name,temp->cal);
            if (temp->cal<snack_limit)
            {
                printf("%-49s\t%d\n",temp->name,temp->cal);
            }
            temp = temp->next;
    }
    return 1;
}
int printDinnerList(dinner *head){
    if(head ==NULL){
        return -1;
    }
    
    dinner* temp = head;

    printf("\n");
    while(temp!=NULL){
            
            //printf("%-49s\t%d\n",temp->name,temp->cal);
            if (temp->cal<dinner_limit)
            {
                printf("%-49s\t%d\n",temp->name,temp->cal);
            }
            temp = temp->next;
    }
    return 1;
}
