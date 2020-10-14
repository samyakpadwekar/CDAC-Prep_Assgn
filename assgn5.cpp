/*Input employee information from the user including his employee id,
name, address, salary, birth date and date of joining. 
Find the age of person when he joined company (in years) and his experience till date (in months). 
Also print the date when his probation period is over, 
assuming that probation period is of 90 days from date of joining.*/
#include<stdio.h>
#include<string.h>
#include<windows.h>

typedef struct employee
{
//employee id=id;emp birth date=bd;emp birth month=bm;emp birth year=by
//emp joining date=jd;emp joining month=jm;emp joining year=jy
    int id, bd, bm, by, jd, jm, jy;
    float salary;
    char name[20],address[40];
}Employee;
int md[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//month days

void details(Employee *e)
{
    printf("Enter details of the Employee : \n");
        printf("ID : ");
        scanf("%d",&e->id);
        printf("Name : ");
        scanf("%*c");
        scanf("%[^\n]s",e->name);
        printf("Salary : ");
        scanf("%f",&e->salary);
        printf("Address : ");
        scanf("%*c");
        scanf("%[^\n]s",e->address);
        printf("DOB in \"dd mm yyyy\" format(\"1 1 2000\"for 1 jan 2000): ");
        scanf("%d %d %d", &e->bd, &e->bm, &e->by);
        printf("Enter joining date in \"dd mm yyyy format\" (\"1 1 2000\"for 1 jan 2000): ");
        scanf("%d %d %d", &e->jd, &e->jm, &e->jy);
}

void Age(Employee *e)
    {
        int y;
        y = e->jy - e->by;
        printf("\nAge of Employee when he joined company (in years) : %d\n",y);
    }

void probation(Employee *e)
    {
        int days = 0, pdays = 0;
        int pd, pm, py;//probation date=pd;probation month=pm;probation year=py
        pd = e->jd;
        pm = e->jm;
        py = e->jy;
        while (days <= 90)
        {
            if (days == 0)
                days = md[pm - 1] - e->jd;
            else
            {
                pdays = days;
                days += md[pm - 1];
                if (days >= 90)
                {
                    pd = 90 - pdays;
                    break;
                }
            }

            if (pm == 12)
            {
                pm = 1;
                py++;
            }
            else
                pm++;
        }
        printf("Probation period will be completed on : %d/%d/%d\n",pd,pm,py);
    }

    void experience(Employee *e)
    {
        SYSTEMTIME time;
        GetSystemTime(&time);
        int cd, cm, cy; //current date=cd;current month=cm;current year=cy
        float exp;
        cd = time.wDay;
        cm = time.wMonth;
        cy = time.wYear;
        int d, m, y;
        y = cy - e->jy;
        if (cm < e->jm)
        {
            y--;
            m = 12 - (e->jm - cm);
        }
        else
            m = cm - e->jm;

        if (cd < e->jd)
        {
            m--;
            d = md[cm - 1] - (e->jd - cd);
        }
        else
            d = cd - e->jd;

        exp = (y * 12) + m + (float)d / md[cm - 1];
        printf("Employee experience till date (in months) : %.1f\n",exp);
    }

int main()
{
    Employee e1;
    details(&e1);
    Age(&e1);
    probation(&e1);
    experience(&e1);
    return 0;
}
