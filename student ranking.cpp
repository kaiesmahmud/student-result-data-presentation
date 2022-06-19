
#include<stdio.h>
#include<string.h>
#include<math.h>
char SubjectsNameArr[][15]={"CSE-113","CSE-114","Math-101","Physics-201","English-201"};// Declaring Char type Array

struct data
{
    char name[20];
    long int id;
    float result,cgpa ,avg;
    int ranking;
    struct subject
    {
        char subName[15];
        float q1, q2, q3, bstQ, mid, fin, attndnc, prsnttn,total;
    }subjects[4];
};
int valCheck(int mn,int mx)
{
    int val;
    scanf("%d",&val);
    if(val>=mn && val <=mx){
        return val;
    }
    else{
        printf("\nEnter Valid number between %d to %d : ",mn,mx);
        valCheck(mn,mx);
    }
}
int countCgpa(int gpa){ //gpa function
    if(gpa >= 90){
        return gpa ;
    }
    return 0;
}

int main()
{
    int n, i, j,rank = 1 ;
    printf("\n Number of Students:");
    scanf("%d",&n);

    struct data students[n-1];
    i=0;
    while(i<n)
    {
        printf("\n<<<---------------%d--------------->>>\n",i+1);
        printf("Enter Name:");
        scanf("%s",&students[i].name);
        printf("\nEnter ID :");
        scanf("%ld",&students[i].id);
        students[i].result = 0 ;
        j=0;
        while(j<5)
        {
            strcpy(students[i].subjects[j].subName , SubjectsNameArr[j]);
            printf("\n--Enter %s subject Marks--\n", students[i].subjects[j].subName );

            printf("\n Enter First Quiz mark:");
            students[i].subjects[j].q1 = valCheck(0,10);
            printf("\n Enter Second Quiz mark:");
            students[i].subjects[j].q2 = valCheck(0,10);
            printf("\n Enter Third Quiz mark:");
            students[i].subjects[j].q3 = valCheck(0,10);
            ( students[i].subjects[j].q1 > students[i].subjects[j].q2 && students[i].subjects[j].q1 > students[i].subjects[j].q3 )?
                students[i].subjects[j].bstQ = students[i].subjects[j].q1
               : ( students[i].subjects[j].q2 > students[i].subjects[j].q3 ?
                    students[i].subjects[j].bstQ = students[i].subjects[j].q2
                   : students[i].subjects[j].bstQ = students[i].subjects[j].q3);
            printf("\n Enter Mid Term mark:");
            students[i].subjects[j].mid = valCheck(0,30);
            printf("\n Enter Final  mark:");
            students[i].subjects[j].fin = valCheck(0,40);
            printf("\n Enter Attendance mark:");
            students[i].subjects[j].attndnc = valCheck(0,10);
            printf("\n Enter Presentation mark:");
            students[i].subjects[j].prsnttn = valCheck(0,10);
            students[i].subjects[j].total = students[i].subjects[j].bstQ
                                            + students[i].subjects[j].mid
                                            + students[i].subjects[j].fin
                                            + students[i].subjects[j].attndnc
                                            + students[i].subjects[j].prsnttn ;
            students[i].result += students[i].subjects[j].total;

            j++;
        }
        students[i].avg = students[i].result / 5 ;
        students[i].cgpa = countCgpa(students[i].avg);

        i++;
    }
    i=1;
    while(i<n)
    {
       //i will be back

        i++;
    }

    return 0;
}
