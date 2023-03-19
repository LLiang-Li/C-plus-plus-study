#include<stdio.h>
#include<stdlib.h>

int cmp(char s1, char s2)
{
    if (s1 > s2)
        return 1;
    else
        return 0;
}


int main()
{
    char name[1025];
    while (gets(name)) {
        int len = 0;
        
        while (name[len] != '\0' || name[len] == '\n')
            len++;


        for (int i = 0; i < len; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                //puts(name);
                if ((int)(name[i]) > (int)(name[j]))
                {
                    char temp = name[i];
                    //printf("%c",temp);
                    name[i] = name[j];
                    name[j] = temp;

                }
            }
        }
        for (int i = 0; i < len; i++)
        {
            if ((int)(name[i]) == 10)
                continue;
            printf("%c", name[i]);
        }

    }

}