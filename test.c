#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "menu.h"

void quit(int argc, char *argv[]);
int add(int argc, char* argv[]);
int sub(int argc, char* argv[]);

void quit(int argc, char *argv[])
{
    exit(0);
}

int add(int argc, char* argv[])
{
    int i,r;
    if(argc !=3)
    {
        printf("warning: input 2 numbers\n");
        return 0;
    }
    r=atoi(argv[1])+atoi(argv[2]);
    printf("result is %d\n",r);
    return 0;
}

int sub(int argc, char* argv[])
{
    int i,r;
    if(argc !=3)
    {
        printf("warning: input 2 numbers\n");
        return 0;
    }
    r=atoi(argv[1])-atoi(argv[2]);
    printf("result is %d\n",r);
    return 0;
}
int argtest(int argc, char *argv[])
{
    const char *optString = "cnto";
    opterr = 0;
    int opt;
    while ((opt = getopt(argc, argv, optString)) != -1)
    {
        switch (opt)
        {
            case 'c':
                printf("this course is gaoruan.\n");
                break;            
            case 'n':
                printf("my name is daisy.\n");
                break;
            case 't':
                printf("today's weather is sunny\n",optarg);
                break;
            case 'o':
                printf("in this cmd, you have 4 option can use:\n");
                printf("-c\n");
                printf("-n\n");
                printf("-t\n");
                printf("-o\n");
                break;
            default:
                break;
        }
    }
    // reset global valuable optind
    optind = 0;
    return 0;
}

int main(int argc,char* argv[])
{
    MenuConfig("quit","quit from cmd",quit);
    MenuConfig("add","compute a+b", add);
    MenuConfig("sub","compute a-b", sub);
    MenuConfig("argtest","test arg option (-cnto)", argtest);
    ExecuteMenu();
}
