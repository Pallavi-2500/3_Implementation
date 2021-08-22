#ifndef __WATER_H__
	#define __WATER_H__
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	#include <math.h>

	struct member
	{
		int usr_id;
		char name[30];
		int age;
		int gender;
		int unit;
		float w;
		float h;
		int time[2];
		float total_w;
		float bmi;
		int bmr;
	};


	void water();
	void newmember(struct member*,int);
	void calcwaterquant( struct member *, int );
	void displaymemberdetails( struct member*, int );

#endif