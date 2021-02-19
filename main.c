#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

double Matrix [2][32] = { {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31}};

struct Person
{
    char name[40];
    double value;
};

void clearConsole()
{
    system("cls");
}

void accounting(struct Person p)
{
    clearConsole();
    fseek(stdin,0,SEEK_END);

    char inputa;
        printf("\n\nCreate a new User?\n\n");
        printf("y: yes\n");
        printf("n: no\n\n");
        printf("Input: ");
        inputa = getchar();

        if(inputa == 'y')
        {
            for(int i = 0; i < 32; i++)
            {
                Matrix[1][i] = 0;
            }
            clearConsole();
            printf("\n\nPlease enter your name \n\n");
            scanf("%s", p.name);
            printf("\n");

            printf("Please enter your start value \n\n");
            scanf("%lf", &p.value);
            printf("\n");
            Matrix[1][0] = p.value;

            printf("Name: %s\n", p.name);
            printf("Value: %.2lf \n\n", Matrix[1][0]);
            printf("Saved!");

            getchar();
            getchar();
        }
        if(inputa == 'n')
        {
            fseek(stdin,0,SEEK_END);
            return;
        }
        if(inputa != 'y' && inputa != 'n')
        {
            fseek(stdin,0,SEEK_END);
            clearConsole();
            printf("Invalid Input!!!");
            getchar();
        }
}

void managing(struct Person p)
{
    clearConsole();
    fseek(stdin,0,SEEK_END);

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    while(1)
    {
        clearConsole();
        fseek(stdin,0,SEEK_END);
        char inputm;
        printf("\n\nOptions\n\n");
        printf("1: Get Current Value\n");
        printf("2: Revenue\n");
        printf("3: Expenditure\n");
        printf("4: Quit\n\n\n");
        printf("Input: ");
        inputm = getchar();

        if(inputm == '1')
        {
            for(int i = 0; i < tm.tm_mday; i++)
            {
                Matrix[1][31] = Matrix [1][31] + Matrix[1][i];
                if(i == tm.tm_mday - 1)
                {
                    printf("\n\n%.2lf\n", Matrix[1][31]);
                    getchar();
                    getchar();
                    Matrix[1][31] = 0;

                }
            }
        }
        if(inputm == '2')
        {
            printf("\n");
            double betrag;
            int tag = tm.tm_mday;
            fseek(stdin,0,SEEK_END);
            printf("State the amount of revenue and the day\n\n");
            scanf("%lf,%d", &betrag, &tag);
            Matrix[1][tag-1] = Matrix[1][tag-1] + betrag;

            printf("\n\nAmount: %.2lf \n\n", betrag);
            printf("Amount today: %.2lf \n\n", Matrix[1][tag-1]);
            printf("Day: %02d.%02d.%d", tag, tm.tm_mon + 1, tm.tm_year + 1900);

            getchar();
            getchar();

        }
        if(inputm == '3')
        {
            printf("\n");
            double betrag;
            int tag = tm.tm_mday;
            fseek(stdin,0,SEEK_END);
            printf("State the amount of expenditure and the day\n\n");
            scanf("%lf,%d", &betrag, &tag);
            Matrix[1][tag-1] = Matrix[1][tag-1] - betrag;

            printf("\n\nAmount: -%.2lf \n\n", betrag);
            printf("Amount today: %.2lf \n\n", Matrix[1][tag-1]);
            printf("Day: %02d.%02d.%d", tag, tm.tm_mon + 1, tm.tm_year + 1900);

            getchar();
            getchar();

        }
        if(inputm == '4' || inputm == 'q')
        {
            fseek(stdin,0,SEEK_END);
            return;
        }
    }
}


void menu(struct Person p)
{
    clearConsole();
    while(1)
    {
        clearConsole();

        char inputmenu;
        printf("\n\nMENU\n\n");
        printf("1: Accounting\n");
        printf("2: Managing\n");
        printf("3: Quit\n\n\n");
        printf("Input: ");
        inputmenu = getchar();
        fseek(stdin,0,SEEK_END);
        if(inputmenu == '1')
        {
            accounting(p);
        }
        if(inputmenu == '2')
        {
            managing(p);
        }
        if(inputmenu == '3' || inputmenu == 'q')
        {
            char st;
            fseek(stdin,0,SEEK_END);
            printf("\n\nExit the program?\n\n");
            printf("y: yes\n");
            printf("n: no\n\n");
            printf("Input: ");
            st = getchar();

            if(st == 'y')
            {
                exit(0);
            }
            if(st == 'n')
            {
                fseek(stdin,0,SEEK_END);
            }
        if(st != 'y' && st != 'n')
            {
                fseek(stdin,0,SEEK_END);
                clearConsole();
                printf("Invalid Input!!!");
                getchar();
            }

        }
        if(inputmenu != '1' && inputmenu != '2' && inputmenu != '3' && inputmenu != 'q')
        {
            clearConsole();
            printf("\nInvalid Input!!!");
            fseek(stdin,0,SEEK_END);
            getchar();
        }
    }
}

int main()
{
    system("color 8F");

    struct Person person;

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    printf("\n%02d.%02d.%d \n\n\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    printf("Creator: Alexander Paul\n");
    printf("Version: 1.4.0\n");

    getchar();
    fseek(stdin,0,SEEK_END);
    menu(person);

    return 0;
}
