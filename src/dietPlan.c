#include "dietPlan.h"
#include "Cal_Intake.h"
#include<stdio.h>
#include<stdlib.h>

brkfst* makeBrkfstList(char *path,brkfst *head){
    
    FILE *fp = fopen(path,"r");

    if(fp == NULL){
        printf("NULL");
        return NULL;
    }
    brkfst *newnode,*temp; 
    
    while(!(feof(fp))){
        
        newnode = (brkfst*)malloc(sizeof(brkfst));
        newnode->cal = 0;
        
        fscanf(fp,"%49[^,],%d\n",newnode->name,&newnode->cal);
        newnode->next = NULL;
        
        if(head==NULL){
            head = newnode;
        }
        else{
            temp = head;
                while(temp->next!=NULL)
                        temp = temp->next;
            temp->next = newnode;   
        }
    }
    fclose(fp) ;
return head;
}
lunch* makeLunchList(char *path,lunch *head){
    
    FILE *fp = fopen(path,"r");

    if(fp == NULL){
        printf("NULL");
        return NULL;
    }
    lunch *newnode,*temp; 
    
    while(!(feof(fp))){
        
        newnode = (lunch*)malloc(sizeof(lunch));
        newnode->cal = 0;
        
        fscanf(fp,"%49[^,],%d\n",newnode->name,&newnode->cal);
        newnode->next = NULL;
        
        if(head==NULL){
            head = newnode;
        }
        else{
            temp = head;
                while(temp->next!=NULL)
                        temp = temp->next;
            temp->next = newnode;   
        }
    } 
    fclose(fp) ;
return head;
}
snack* makeSnacksList(char *path,snack *head){
    
    FILE *fp = fopen(path,"r");

    if(fp == NULL){
        printf("NULL");
        return NULL;
    }
    snack *newnode,*temp; 
    
    while(!(feof(fp))){
        
        newnode = (snack*)malloc(sizeof(snack));
        newnode->cal = 0;
        
        fscanf(fp,"%49[^,],%d\n",newnode->name,&newnode->cal);
        newnode->next = NULL;
        
        if(head==NULL){
            head = newnode;
        }
        else{
            temp = head;
                while(temp->next!=NULL)
                        temp = temp->next;
            temp->next = newnode;   
        }
    }
    fclose(fp) ;
return head;
}
dinner* makeDinnerList(char *path,dinner *head){
    
    FILE *fp = fopen(path,"r");

    if(fp == NULL){
        printf("NULL");
        return NULL;
    }
    dinner *newnode,*temp; 
    
    while(!(feof(fp))){
        
        newnode = (dinner*)malloc(sizeof(dinner));
        newnode->cal = 0;
        
        fscanf(fp,"%49[^,],%d\n",newnode->name,&newnode->cal);
        newnode->next = NULL;
        
        if(head==NULL){
            head = newnode;
        }
        else{
            temp = head;
                while(temp->next!=NULL)
                        temp = temp->next;
            temp->next = newnode;   
        }
    }
    fclose(fp) ;
return head;
}
