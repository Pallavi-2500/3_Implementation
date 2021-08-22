#include<stdio.h>
#include<stdlib.h>
#include<bmi_bmr.h>
#include<dietPlan.h>
#include<Cal_Intake.h>
#include<water.h>
#include<workout.h>

int main(){


    double bmi = calcBMI();
	double bmr = calcBMR();
    printf("bmi = %d bmr = %d",bmi,bmr);
    printf("Enter your Choice \n1. Workout Plan\n2. Water Intake Plan\n3. Diet control Plan\n4. Complete Plan\n");
    
    char choice;
    fflush(stdin);
    scanf("%c",&choice);
    switch(choice){
        case 1:
            workout(bmi);
            break;
        case 2:
            water();
            break;
        case 3:
            calorie(bmr);
            break;
        case 4:
            workout(bmi);
            water();
            calorie(bmr);
            break;
    }

}