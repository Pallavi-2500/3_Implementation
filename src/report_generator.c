#include "Cal_Intake.h"
#include "water.h"
#include "dietPlan.h"


void report_builder(struct member *member,char *info)
    {
    // creating file pointer to work with files
        FILE *fptr;
        char fileName[30];
        // opening file in writing mode
        sprintf(fileName,"%s.txt",member->name);
         fptr = fopen  ("filename" ,"w");
        //fptr = fopen("%s.txt",member->name, "w");   
                    
    fputs("\t\t\t\t==================================================================\n",fptr);
    fputs(" \t\t\t\t                          REPORT CARD                            \n",fptr);
    fputs("\t\t\t\t==================================================================\n",fptr);

                fprintf(fptr," \t\t\t\tUser name        : %s \n", member->name);
                fprintf(fptr," \t\t\t\tUser id          : %d \n", member->usr_id);
                fprintf(fptr," \t\t\t\tAge              : %d \n", member->age);
                fprintf(fptr," \t\t\t\tGender           : %f \n", member->gender);
                fprintf(fptr,"\t\t\t\tHeight            : %f \n", member->h);
                fprintf(fptr,"\t\t\t\tWeight            : %f \n",member->w);
                
                int i;
                for(i=0;i<3;i++)
                {
                    fprintf(fptr,"\n");
                }
           
                fprintf("%s\n",info);
        

        fclose(fptr);
}