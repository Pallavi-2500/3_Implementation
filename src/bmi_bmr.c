/*
This program is a Body Mass Index (BMI) and Basal Metabolic Rate (BMR) .
---------------------------------------------------------------------------
									BMI
---------------------------------------------------------------------------
The formula used to calculate the BMI is BMI = weight  / (height^2)).
BMI Categories:
	- Underweight = <18.5.
	- Normal Weight = 18.5-24.9.
	- Overweight = 25-29.9.
	
---------------------------------------------------------------------------
									BMR
---------------------------------------------------------------------------
The formula used to calculate BMR is:
	- Men (Weight(kg) and Height(cm)) --> BMR = (10*weight) + (6.25 * height) - (5*age) + 5 
	- Women (Weight(kg) and Height(cm)) --> BMR = (10*weight) + (6.25*height) - (5*age) - 161
	
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>
double calcBMI();
const char* bmiResult(double bmi);
double bmrResult(int gender, double weight, double height, double age);
double calcBMR();


double calcBMI() {
	//Formula --> BMI = weigh * (703 / (height^2)).
	
	//Variables
	double weight;
	double height;
	double bmi;
	char word[20];
	
	printf("___________________________BMI Calculation_________________________________ ");
	printf("\nEnter your weight (Kg): ");
	scanf("%lf",&weight);

	printf ("\nEnter your height (cm): ");
	scanf("%lf",&height);

	//Calculations
	bmi = (weight /(height*height))*10000;

	//Print
	printf( "\n Your Body Mass Index (BMI) is:%lf \n",bmi);
	//*word=bmiResult(bmi);
	
	//printf("According to your Body Mass Index (BMI) you're %s\n",*word);
	printf("According to your Body Mass Index (BMI) you're %s\n",bmiResult(bmi));
	return bmi;
}
const char* bmiResult(double bmi) {
	char word[20];

	if (bmi < 18.5) {
		//strcpy(word,"underweight");
		return "underweight";
	}
	else if (bmi >= 18.5 && bmi <= 24.9) {
	    //strcpy(word,"normal weight");
	    return "normal weighted";
	}
	else if (bmi >= 25 && bmi <= 29.9) {
	    //strcpy(word,"overweight");
	    return "overweight";
	}
	else if (bmi >= 30) {
	    //strcpy(word,"obese");
	    return "obese";
	}
	//return word;
}

//BMR Calculator
double bmrResult(int gender, double weight, double height, double age) {
	//Calculations
	double bmr;
	bmr = 0;

	if (gender == 1) {
		bmr = (10*weight) + (6.25*height) - (5*age) - 161;
	}
	else if (gender == 2) {
		bmr = (10*weight) + (6.25 * height) - (5*age) + 5;
	}
	return bmr;
}
double calcBMR() {
	
	//Variables
	int gender;
	double weight;
	double height;
	double age;

	printf("___________________________BMR Calculation_________________________________ ");
	printf("Select gender: \n");
	printf("1. Female\n");
	printf("2. Male\n");
	printf("Enter your choice: ");
	//gets(gender);
	scanf("%d",&gender);
	//transform (gender.begin(), gender.end(), gender.begin(), [](unsigned char c) {return toupper (c); }); //toupper

	printf("\n\nEnter your weight (kg): ");
	scanf("%lf",&weight);

	printf("\n\nEnter your height (cm): ");
	scanf("%lf",&height);
	
	printf( "\n\nEnter your age (years): ");
	scanf("%lf",&age);

	//Print
	double bmr = bmrResult(gender, weight, height, age);
	printf( "You have a Basal Metabolic Rate (BMR) of:%0.2f ",bmr);
	printf(" calories per day.\n");
	return bmr;
}



