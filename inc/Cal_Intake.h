#ifndef __Cal_Intake_H__
    
    #define __Cal_Intake_H__
    
    
    int printBrkfstList(brkfst*);
    int printLunchList(lunch*);
    int printSnacksList(snack*);
    int printDinnerList(dinner*);

    int mealchoice(int,brkfst*,lunch*,snack*,dinner*);
    int brkfst_priority(int,brkfst*,lunch*,snack*,dinner*);
    int lunch_priority(int,brkfst*,lunch*,snack*,dinner*);
    int dinner_priority(int,brkfst*,lunch*,snack*,dinner*);
    int dietPlan(brkfst*,lunch*,snack*,dinner*);


#endif   