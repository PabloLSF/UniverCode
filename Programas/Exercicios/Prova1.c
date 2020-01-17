#include <stdio.h>
#include <string.h>
void main()
{

    int aux,i,j;
    char string [256];
    while(fgets(string,255,stdin))
    {
        i=0;
        while(string[i]!='\0')
        {

            if(string[i]!=' ')
            {
                aux=i;
                while(string[i] != ' ' && string[i] != '\0'&& string[i] != '\n')
                {
                    i++;
                }
            }

            if (string[aux]=='a'|| string[aux]=='e'||string[aux]=='i'|| string[aux]=='o'||string[aux]=='u'||string[aux]=='A'||string[aux]=='E'||string[aux]=='I'|| string[aux]=='O'||string[aux]=='U')
            {

                for(j=aux+1; j<i-1; j++)
                {
                    printf("%c",string[j]);
                }
                printf("%cay",string[aux]);
            }
            else
            {
                for(j=aux; j<i; j++)
                {
                    printf("%c",string[j]);
                }

                printf("ay");
            }
            if(string[i]!='\0')
            {
                printf("%c",string[i]);
                i++;
            }

        }

    }
    return 0;
}
