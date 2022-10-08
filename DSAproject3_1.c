#include<stdio.h>
#include "/Users/yugbhanushali03/Desktop/DataStructures/projects/dsa3/dsa03_02.h"
#include <string.h>

// Here we declare the structure we use typedef function to give short name of strcuture
typedef struct hostel
{
    char name[50];
    char rollNo[100];
    int noOfRoomsAllocated;  //rear
    int nofOfroomsLeft;
    char nameOfStudent[30][50]; //size of queue
    char rollNoOfStudent[30][100];
    int roomNo[30];//size of queue
    char statusOfRoom[30][100];
}h;
h h1;
// In this hostel allocation enqueue function is we allot the room one by one only we take the input in one time then one by one we allot the room
// Display function is we display the how many rooms are alloted or not

int main(){
        // Initially we declare the number of room allocated is 0 and remaining rooms is 30 
        // So we know how many rooms are available or how many are full
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

        printf("\t\t-----------------Hostel Allocation System-----------------\n\n");      
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

                int new3=0;
                printf("How many number of rooms do you want:");
                scanf("%d",&new3);
                printf("Enter your name and roll no\n");
                printf("e.g-\nYug 35\n");
                char tempName[new3][50];
                char tempRoll[new3][100];

                for(int k=0;k<new3;k++){
                    scanf("%s",tempName[k]);
                    scanf("%s",tempRoll[k]);
                }
                // We take name and id to check the student name is listed in the list if yes then allot the room

                for (int k = 0; k < new3; k++)
                {
                   
                int counter3=0;
                int temp2;
                for (int i = 0; i < 30; i++)
                {
                    if(strcmp(tempName[k],h1.nameOfStudent[i])==0 && strcmp(tempRoll[k],h1.rollNoOfStudent[i])==0){
                        counter3=1;
                        temp2=i;
                        break;
                    }
                }

                if(counter3==1){
                    printf("\n------------------------------------------------------------------------\n");
                    printf("Congratualtion %s\n",tempName[k]);
                    printf("You have been alloted the room already and your room number is %d\n",h1.roomNo[temp2]);
                    printf("------------------------------------------------------------------------\n");
                }
                else{
                    int d = checker(tempName[k],tempRoll[k]); // this function in header file and it work for checking the name and id of student 
                    if(d == 1){
                        strcpy(h1.nameOfStudent[counter1],tempName[k]);
                        strcpy(h1.rollNoOfStudent[counter1],tempRoll[k]);
                        printf("\n----------------------------------------------------------------------\n");
                        printf("Congratualtion %s you have been alloted room no %d in A-Block\n",h1.nameOfStudent[counter1],h1.roomNo[counter1]);
                        printf("----------------------------------------------------------------------\n\n");
                        strcpy(h1.statusOfRoom[counter1],"Allocated");
                        counter1++;
                    }
                    else{
                        printf("\n----------------------------------------------------------------------------------\n");
                        printf("Sorry, As your name is not present in the hostel list we cannot allot you the room\n");
                        printf("Sorry for the inconviniance\n");
                        printf("----------------------------------------------------------------------------------\n\n");
                }
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
            // This show which room is allocated in hostel and which is not alloted
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
            // here we create the file of extension .txt and save the data of room status so we know after terminting the program
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