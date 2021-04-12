#include <stdio.h>
#include <string.h>
char str2[100];
char substring[100];
char str3[100];
char str5[100];
int Position(char *str, int num, char *str1) //to get the position of the inputed word
{
    int flag;
    int i;
    int position; //to store the position of the inputed word
    for (i = 0; i < num; i++)
    {
        position = i; //store the position of the word
        flag = 1;     //to track the element of the second string
        for (int j = 0; j < strlen(str1); j++)
        {
            if (str[i + j] == str1[j])
            {
                flag++;
            }
            else
            {
                flag = 0;
                break;
            }
        }
        if (flag == 0)
        {
            continue;
        }
        else
        {
            return (position);
        }

        if (i == num)
        {
            return (-1);
        }
    }
}
char *substr(char *str, int index, int lenght) //to get the remaining string
{
    int m = 0;
    for (int i = index; i < lenght; i++)
    {
        substring[m] = str[i];
        m++;
    }
    substring[m] = '\0';

    return (substring);
}
char *insert(char *str, int index, char *str1) //to add two strings at a given place
{
    strcpy(str2, substr(str, 0, index));
    strcat(str2, str1);
    strcat(str2, substr(str, index + 1, strlen(str)));
    return (str2);
}
char *delete (char *str, char *str1) //to delete the particular word or string from inputed string
{
    int index = Position(str, strlen(str), str1);
    strcpy(str3, substr(str, 0, index));
    strcat(str3, substr(str, index + strlen(str1), strlen(str)));
    return (str3);
}
char *replace(char *str, char *strr, char *str1)//to replace the string with another string with a particular string 
{
    char str4[100];
    strcpy(str4, delete (str, strr));
    strcpy(str5, insert(str4, Position(str, strlen(str), strr), str1));
    return (str5);
}
int main()
{
    int num;      //to store the choice
    char S[100];  //to store the string
    char S1[100]; //to store the new characters or new string
    char S3[100]; //to store the word or charecters of the inputed string
    int startposition;
    int endposition;
    int index;
    printf("Enter the string on which you wanted to perform the given opretations\n");
    scanf("%[^\n]", &S);
    int lenght = strlen(S); //to know the lenght of the inputed string
    printf("Hey There, Welcome to the world of word Processing\n\n");
    printf("Choose what you wanted to do\n");
    printf("1.To get the lenght of the string\n");
    printf("2.To get the position of a word in an string\n");
    printf("3.To get the remaining string from given word\n");
    printf("4.To Copy the string into another string\n");
    printf("5.To insert the given string into the particular string inputed by you and at a given place\n");
    printf("6.To delete the particular word/charecters from the string\n");
    printf("7.To replace the given word/charecter by given word/charecters/string\n");
    printf("Enter your choice \n");
    scanf("%d", &num);
    if (num == 1)
    {
        printf("The size of the given string is %d", strlen(S));
    }
    else if (num == 2)
    {
        
        printf("Enter the word who's position is to be determined\n");
        // scanf("%s", &S1);
        // gets(S1);
        // fgets(S1,100,stdin);
         scanf("%[^\n]", &S1);
        printf("The Position of the given word in an string is %d", Position(S, lenght, S1));
    }
    else if (num == 3)
    {
        printf("Enter the starting position from which you wanted to see the string\n");
        scanf("%d", &startposition);
        printf("Enter the ending position from which you wanted to see the string\n");
        printf("NOTE: To lenght of the string is %d\n", lenght);
        scanf("%d", &endposition);
        printf("The string is\n %s", substr(S, startposition, endposition));
    }
    else if (num == 4)
    {
        printf("Enter the another string who you wanted to add in the end of the first string\n");
        scanf("%s", &S1);
        strcat(S, S1);
        printf("The string after adding both string is given by\n %s", S);
    }
    else if (num == 5)
    {
        printf("Enter the string\n");
        scanf("%s", &S1);
        printf("Enter the place where you wanted to insert the string\n");
        scanf("%d", &index);
        printf("The string is given by %s", insert(S, index, S1));
    }
    else if (num == 6)
    {
        printf("Enter the word or charecters who you wanted to delete from inputed string\n");
        scanf("%s", &S1);
        printf("The new string is given by %s", delete (S, S1));
    }
    else if (num == 7)
    {
        printf("Enter the word from the string for which you wanted to replace\n");
        scanf("%s", &S3);
        printf("Enter the string to replace at inputed position\n");
        scanf("%s", &S1);
        printf("The new string after replacing is given by %s", replace(S, S3, S1));
    }

    else
    {
        printf("You have entered invalide choice\n");
    }

    return 0;
}