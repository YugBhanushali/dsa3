#include<stdio.h>
#include "/Users/yugbhanushali03/Desktop/DataStructures/projects/dsa3/dsa03_02.h"
#include <string.h>


typedef struct hostel
{
    char name[50];
    char rollNo[100];
    int noOfRoomsAllocated;
    int nofOfroomsLeft;
    char nameOfStudent[30][50];
    char rollNoOfStudent[30][100];
    int roomNo[30];
    char statusOfRoom[30][100];
}h;
h h1;
int main(){
        h1.noOfRoomsAllocated=0;
        h1.nofOfroomsLeft=30;

        int j=0;
        for (int i = 101; i <111 ; i++)
        {
            h1.roomNo[j]=i;
            strcpy(h1.statusOfRoom[j],"Not Alloted");
            strcpy(h1.nameOfStudent[j],"Not Alloted");
            j++;
        }
        for (int i = 201; i <211 ; i++)
        {
            h1.roomNo[j]=i;
            strcpy(h1.statusOfRoom[j],"Not Alloted");
            strcpy(h1.nameOfStudent[j],"Not Alloted");
            j++;
        }
        for (int i = 301; i <311 ; i++)
        {
            h1.roomNo[j]=i;
            strcpy(h1.statusOfRoom[j],"Not Alloted");
            strcpy(h1.nameOfStudent[j],"Not Alloted");
            j++;
        }  

              
        int counter1=0;
        while(1){
            int new1;
            printf("---------------------------------------------------------\n");
            printf("| 1. For allotment of room                              |\n");
            printf("---------------------------------------------------------\n");
            printf("| 2. For checking status of your allotment              |\n");
            printf("---------------------------------------------------------\n");
            printf("| 3. For checking the availabale rooms in hostel        |\n");
            printf("---------------------------------------------------------\n");
            printf("| 4. For Exiting the program                            |\n");
            printf("---------------------------------------------------------\n");
            printf("Enter the number to execute the program : ");
            scanf("%i",&new1);

            if(new1 == 1){
                printf("Enter your name: ");
                scanf("%s",h1.name);
                printf("Enter your roll number: ");
                scanf("%s",h1.rollNo);
                

                int counter3=0;
                int temp2;
                for (int i = 0; i < 30; i++)
                {
                    if(strcmp(h1.name,h1.nameOfStudent[i])==0 && strcmp(h1.rollNo,h1.rollNoOfStudent[i])==0){
                        counter3=1;
                        temp2=i;
                        break;
                    }
                }

                if(counter3==1){
                    printf("\n----------------------------------------------------------------------\n");
                    printf("Congratualtion %s\n",h1.name);
                    printf("You have been alloted the room already and your room number is %d\n",h1.roomNo[temp2]);
                    printf("----------------------------------------------------------------------\n");
                }
                else{
                    int d = checker(h1.name,h1.rollNo);
                    if(d == 1){
                        strcpy(h1.nameOfStudent[counter1],h1.name);
                        strcpy(h1.rollNoOfStudent[counter1],h1.rollNo);
                        printf("\n-----------------------------------------------------------\n");
                        printf("Congratualtion %s you have been alloted room no %d in A-Block\n",h1.nameOfStudent[counter1],h1.roomNo[counter1]);
                        printf("-------------------------------------------------------------\n\n");
                        strcpy(h1.statusOfRoom[counter1],"Allocated");
                        counter1++;
                    }
                    else{
                        printf("\n--------------------------------------------------------------------------------\n");
                        printf("Sorry, As your name is not present in the hostel list we cannot allot you the room\n");
                        printf("Sorry for the inconviniance\n");
                        printf("----------------------------------------------------------------------------------\n\n");
                }
                }
            }
            else if(new1==2){
                printf("Enter your name: ");
                scanf("%s",h1.name);
                printf("Enter your roll number: ");
                scanf("%s",h1.rollNo);
                int counter2=0;
                int temp1;
                for (int i = 0; i < 30; i++)
                {
                    if(strcmp(h1.name,h1.nameOfStudent[i])==0 && strcmp(h1.rollNo,h1.rollNoOfStudent[i])==0){
                        counter2=1;
                        temp1=i;
                        break;
                    }
                }

                if(counter2==1){
                    printf("\n------------------------------------------------------\n");
                    printf("Congratualtion %s\n",h1.name);
                    printf("You have been alloted the room and your room number is %d\n",h1.roomNo[temp1]);
                    printf("--------------------------------------------------------\n\n");
                }
                else{
                    printf("\n-------------------------------------------------------------------------------------------------\n");
                    printf("Sorry %s, you haven't been alloted any room yet\n",h1.name);
                    printf("To get allotment of room apply your name and roll no in allotmnet section or check your name and id\n");
                    printf("-------------------------------------------------------------------------------------------------\n\n");
                }
            }
            else if(new1==3){
                printf("\nCurrent status of Hostel rooms\n");
                printf("A-Block\n");
                printf("\n#################################################################################\n\n");
                for (int i = 0; i < 10; i++)
                {
                    printf("#    %-5d--> %-15s %-5d--> %-15s %-5d--> %-15s #\n",h1.roomNo[i],h1.statusOfRoom[i],h1.roomNo[i+10],h1.statusOfRoom[i+10],h1.roomNo[i+20],h1.statusOfRoom[i+20]);
                    printf("---------------------------------------------------------------------------------\n");
                }
                printf("\n#################################################################################\n\n");

            }
            else if(new1 == 4){
                break;
            }

            FILE *file1;

            file1=fopen("HostelAlloctaion.txt","w+");
            fprintf(file1,"\nCurrent status of Hostel rooms\n");
            fprintf(file1,"A-Block\n");
            fprintf(file1,"\n#################################################################################\n\n");
            for (int i = 0; i < 10; i++)
            {
                fprintf(file1,"*    %-5d--> %-15s %-5d--> %-15s %-5d--> %-15s *\n",h1.roomNo[i],h1.nameOfStudent[i],h1.roomNo[i+10],h1.nameOfStudent[i+10],h1.roomNo[i+20],h1.nameOfStudent[i+20]);
                fprintf(file1,"---------------------------------------------------------------------------------\n");
            }
            fprintf(file1,"\n#################################################################################\n");
           
            fclose(file1);
        }
}