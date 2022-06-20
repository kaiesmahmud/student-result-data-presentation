
#include<stdio.h>
#include<string.h>
char SubjectsNameArr[][15]={"CSE-113","CSE-114","Math-101","Physics-201","English-201"};// Declaring Subjects Name in Char type Array
//>>>>>>>>>-------Data Structure of Students ------<<<<<<<<
struct data
{
    char name[20] ;
    const char *cgpa;
    long int id;
    float result ,avg;
    int ranking;
    struct subject
    {
        char subName[15];
        float q1, q2, q3, bstQ, mid, fin, attndnc, prsnttn,total;
    }subjects[5];
};
//>>>>>>>>>---- Valid Value Checking Function -----<<<<<<<<
int valCheck(int mn,int mx)
{
    int val;
    scanf("%d",&val);
    if(val>=mn && val <=mx){
        return val;
    }
    else{
        printf("\n Enter Valid number between %d to %d : ",mn,mx);
        return valCheck(mn,mx);
    }
};
//>>>>>>>>>>---- CGPA Count Function -----<<<<<<<<<<<
const char* countCgpa(int mark){
    if(mark >= 80){
        return "A+" ;
    }else if(mark>= 75 && mark <= 79){
        return  "A";
    }else if(mark>= 70 && mark <= 74){
        return  "A-";
    }else if(mark>= 65 && mark <= 69){
        return  "B+";
    }else if(mark>= 60 && mark <= 64){
        return "B";
    }else if(mark>= 55 && mark <= 59){
        return "B-";
    }else if(mark>= 50 && mark <= 54){
        return  "C+";
    }else if(mark>= 45 && mark <= 49){
        return  "C";
    }else if(mark>= 40 && mark <= 44){
        return  "D";
    }else if(mark < 40){
        return  "F";
    }
    return 0;
}
//<<<<<<<<<<<---------------------------Main function Starts Here--------------------------------->>>>>>>>
int main()
{
    int n, i, j, proceed;

    printf("\n Number of Students:");//taking number of students
    scanf("%d",&n);

    float ranking[n]; //array of results of students  for ranking
    int rankingId[n]; //array of id's of students  for ranking
    struct data students[n];//Creating the Structure of n numbers  student data

    i=0;
    while(i<n)
    {
        printf("\n<<<---------------Student No : %d--------------->>>\n",i+1);
        printf("\n Enter Student Name:");
        scanf("%s",&students[i].name);
        printf("\n Enter ID :");
        scanf("%ld",&students[i].id);
        students[i].result = 0 ;//initial value of result is = 0

        j=0;
        while(j<5)// this loop will go for 5 subjects
        {
            strcpy(students[i].subjects[j].subName , SubjectsNameArr[j]);
            printf("\n----Enter %s subject Marks-----\n", students[i].subjects[j].subName );

            printf("\n\t Enter First Quiz mark:");
            students[i].subjects[j].q1 = valCheck(0,10);
            printf("\n\t Enter Second Quiz mark:");
            students[i].subjects[j].q2 = valCheck(0,10);
            printf("\n\t Enter Third Quiz mark:");
            students[i].subjects[j].q3 = valCheck(0,10);
            //comparing  for bestQuiz from 3 quiz marks
            ( students[i].subjects[j].q1 > students[i].subjects[j].q2 && students[i].subjects[j].q1 > students[i].subjects[j].q3 )?
                students[i].subjects[j].bstQ = students[i].subjects[j].q1
               : ( students[i].subjects[j].q2 > students[i].subjects[j].q3 ?
                    students[i].subjects[j].bstQ = students[i].subjects[j].q2
                   : students[i].subjects[j].bstQ = students[i].subjects[j].q3);

            printf("\n\t Enter Mid Term mark:");
            students[i].subjects[j].mid = valCheck(0,30);
            printf("\n\t Enter Final  mark:");
            students[i].subjects[j].fin = valCheck(0,40);
            printf("\n\t Enter Attendance mark:");
            students[i].subjects[j].attndnc = valCheck(0,10);
            printf("\n\t Enter Presentation mark:");
            students[i].subjects[j].prsnttn = valCheck(0,10);
            //Counting total marks of a subject = bestQ + mid + final + attendence + presentation (marks)
            students[i].subjects[j].total = students[i].subjects[j].bstQ
                                            + students[i].subjects[j].mid
                                            + students[i].subjects[j].fin
                                            + students[i].subjects[j].attndnc
                                            + students[i].subjects[j].prsnttn ;

            students[i].result += students[i].subjects[j].total;//Counting full result of all subjects

            j++;
        }
        students[i].avg = students[i].result/5 ;
        students[i].cgpa = countCgpa(students[i].avg);//Calculating CGPA from avg mark
        i++;
    }
    // sorting start

    i=0;
    while(i<n)
    {
        rankingId[i] = students[i].id;  //rankingId gets id
        ranking[i] = students[i].avg;   //ranking gets avg mark value
        i++;
    }

    i=0;
    while(i<n)
    {
        for(j=i+1; j<n ; j++)
        {
            float temp;
            int tempid;
            if(ranking[i] < ranking[j]){
                //for avg result ranking
                temp = ranking[i];
                ranking[i]= ranking[j];
                ranking[j] = temp;

                tempid = rankingId[i];
                rankingId[i]= rankingId[j];
                rankingId[j] = tempid;

            }
        }
        i++;
    }

    //printing results start here
    printf("\n--------------------------------------------------\n");
    printf("\n--------------------------------------------------------------\n");
    printf("\n----------Proceed to show results ?(1/0)----------------------\n");
    printf("\n--------------------------------------------------\n");
    scanf("%d",&proceed);
    if(proceed){
        i=0;
        while(i<n)
        {
            j=0;
            while(j<n)
            {
                if(rankingId[i] == students[j].id)
                {
                    printf("\n\n<<<<-------------Ranking %d ----------->>>>\n",i+1);
                    printf("\n Name:%s   ID: %ld    Result:%.2f   CGPA: %s  \n\n" ,
                                students[j].name,
                                students[j].id,
                                students[j].result,
                                students[j].cgpa);
                }
                j++;
            }


            i++;
        }
        printf("\n---------Thank You, Have a Nice Day---------\n");
    }else{

        printf("\n---------Thank You, Have a Nice Day---------\n");
    }

    return 0;
}
