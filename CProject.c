#include <stdio.h>
#include <string.h> // string library to use functions like strcpy strcmp etc..
#include <stdlib.h>
/*declaring variables in the  GLOBAL area so any changes occur  in the variable can happen anywhere, so no need to use pointers */
int ids[1000];
char names[1000][50];
double scores[1000];
int count;  // counter for how many student there are
/* functions prototype*/
void read_data();
void save_data();
void display_data();
void sort_by_id();
void sort_by_name();
void sort_score();
void searchbyid();
void searchbyname();
int main()
{
    read_data();
    printf("1) Sort and display data according to student ID\n");
    printf("2) Sort and display data according to student name\n");
    printf("3) Sort and display data according to student score\n");
    printf("4) find student score according to student ID\n");
    printf("5) find student score according to student name\n");
    printf("6) Exit the program\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    while(choice != 6)
    {
        if (choice== 1)
        {
            printf("-----------------------------------------------\n");
            sort_by_id();
            display_data();
            save_data();
        }
        else if(choice== 2)
        {
            printf("-----------------------------------------------\n");
            sort_by_name();
            display_data();
            save_data();
        }
        else if(choice== 3)
        {
            printf("-----------------------------------------------\n");
            sort_score();
            display_data();
            save_data();
        }
        else if(choice== 4)
        {
            printf("-----------------------------------------------\n");
            searchbyid();
        }
        else if(choice== 5)
        {
            printf("-----------------------------------------------\n");
            searchbyname();
        }

        printf("1) Sort and display data according to student ID\n");
        printf("2) Sort and display data according to student name\n");
        printf("3) Sort and display data according to student score\n");
        printf("4) find student score according to student ID\n");
        printf("5) find student score according to student name\n");
        printf("6) Exit the program\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
    }
    if(choice==6)
        {
            printf("\n\nThank you for using this program, have a good day :)\n");
        }
    return 0;
}
void read_data()
{
    char fname[50];
    FILE *fp_r;
    double marks[5];//an array of the 5 marks for the student, for example : marks[0] is the mark of Assignment marks[1] is midterm mark etc..
    char dollar;
    printf("Enter the file name you want to import the data from (with the extension):");
    scanf("%s", fname);
    fp_r = fopen(fname, "r");
    count = 0;
    fscanf(fp_r, "%d$", &ids[count]); // to read data from file till it reaches the $ sign
    while(!feof(fp_r)) // to keep reading while there's data left in the input file
    {
        fscanf(fp_r, "%[^$]s)", names[count]); // after we read ids, we read the names till we reach the $ sign (this method  I asked Dr.Abdullah about it and searched a lot to find it)
        for(int i = 0; i < 5; i++) // to read the 5 marks:Assignment, mid ,...
        {
            fscanf(fp_r, "%c", &dollar);// to skip the dollar sign and save it in variable called dollar
            fscanf(fp_r, "%lf", &marks[i]);
        }
        scores[count] = marks[0] * 0.15 + marks[1] * 0.15 +marks[2] * 0.25 + marks[3] * 0.10 + marks[4] * 0.35; // calculating final mark for each student
        count++;
        fscanf(fp_r, "%d$", &ids[count]);// pumping the loop
    }
    fclose(fp_r);
}
void save_data()
{
    char file_name[50];
    FILE *fout;// output file poiter
    char yes_no;
    printf("would you like to save the data?  press:(y/n):\n");
    scanf(" %c",&yes_no);
    if(yes_no == 'y' || yes_no == 'Y')
    {
        printf("enter file name you want to save the data in please (with the extension) : ");
        scanf(" %s",file_name);
        fout = fopen(file_name, "w");// to write in the file you want to save the data in
        fprintf(fout, "ID:\tNAME:\t\t\t\tSCORE:\n");
        for( int i = 0; i < count; i++)
        {
            fprintf(fout, "%d\t%s\t\t\t\t%.2lf\n", ids[i], names[i],scores[i]);
        }
        fclose(fout);
    }
}
void display_data()
{
    printf("ID:\t  NAME:\t\t\t\t  SCORE:\n");
    for(int i = 0; i < count; i++)
    {
        printf("%d\t\t  %s\t\t\t\t  %.2lf\n", ids[i], names[i], scores[i]);
    }
    printf("\n");
}
void sort_by_id()
{
    char temp[50];
    int tempi;
    double tempf;
    for(int i = 0; i < count; i++)
    {
        for(int j = i + 1; j < count; j++)
        {
            if(ids[i] > ids[j])
            {
                strcpy(temp,names[i]);
                strcpy(names[i],names[j]);
                strcpy(names[j],temp);
                tempf=scores[i];
                scores[i]=scores[j];
                scores[j]=tempf;
                tempi=ids[i];
                ids[i]=ids[j];
                ids[j]=tempi;
            }
        }
    }
}
void sort_by_name()
{
    char temp[50];
    int tempi;
    double tempf;
    for(int i = 0; i < count; i++)
    {
        for(int j = i + 1; j < count; j++)
        {
            if(strcmp(names[i], names[j]) > 0)
            {

                strcpy(temp,names[i]);
                strcpy(names[i],names[j]);
                strcpy(names[j],temp);
                tempf=scores[i];
                scores[i]=scores[j];
                scores[j]=tempf;
                tempi=ids[i];
                ids[i]=ids[j];
                ids[j]=tempi;
            }
        }
    }
}
void sort_score()
{
    char temp[50];
    int tempi;
    double tempf;
    for(int i = 0; i < count ; i++)
    {
        for(int j = i + 1; j < count; j++)
        {
            if(scores[i] < scores[j])
            {
                strcpy(temp,names[i]);
                strcpy(names[i],names[j]);
                strcpy(names[j],temp);
                tempf=scores[i];
                scores[i]=scores[j];
                scores[j]=tempf;
                tempi=ids[i];
                ids[i]=ids[j];
                ids[j]=tempi;
            }
        }
    }
}
void searchbyid()
{
    int id;
    printf("enter student id you're looking for: ");
    scanf("%d", &id);
    for(int i = 0; i < count; i++)
    {
        if(id == ids[i])
        {
            printf("the score is %.2lf\n", scores[i]);
            break;
        }
    }
}
void searchbyname()
{
    char stu_name[50];
    printf("enter student name you're looking for: ");
    scanf("\n%[^\n]s",stu_name);// to read the name
    for(int i = 0; i < count; i++)
    {
        if(strcmp(stu_name,names[i]) == 0)
        {
            printf("the score is %.2lf\n", scores[i]);
            break;
        }
    }
}
/*  Done by: Faris Abufahra
    ID:1200546
    SEC: 14l
*/

