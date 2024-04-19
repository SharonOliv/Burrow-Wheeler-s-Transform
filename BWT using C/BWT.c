#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* burrowsWheelerTransform(const char*text) 
{
    int length=strlen(text);
    char** rotations=(char**)malloc(length*sizeof(char*));
    char* transformedText=(char*)malloc((length + 1)*sizeof(char));

    //Generating all cyclic rotations of the text
    int i,j;
    for(i=0;i<length;++i)
	{
        rotations[i]=(char*)malloc((length+1)*sizeof(char));
        strcpy(rotations[i],text+i);
        strncat(rotations[i],text,i);
    }

    //Sort the rotations lexicographically
    for(i=0;i<length-1;++i)
	{
        for(j=i+1;j<length;++j)
		{
            if(strcmp(rotations[i],rotations[j])>0)
			{
                char* temp=rotations[i];
                rotations[i]=rotations[j];
                rotations[j]=temp;
            }
        }
    }

    //Extracting the last characters of each rotation
    for(i=0;i<length;++i)
	{
        transformedText[i]=rotations[i][length-1];
    }
    transformedText[length] = '\0';

    //Free memory
    for (i=0;i<length;++i)
	{
        free(rotations[i]);
    }
    free(rotations);
    return transformedText;
}

int main() 
{
    int choice;
    printf("Choose input option:\n");
    printf("1. Enter text manually\n");
    printf("2. Input text from file\n");
    scanf("%d", &choice);
    char text[1000];
    if(choice==1) 
	{
        printf("Enter the text: ");
        scanf(" %[^\n]s ",text);
    }
	else if(choice==2)
	{
        char filename[100];
        printf("Enter the filename containing the text: ");
        scanf("%s",filename);
        FILE*file=fopen(filename,"r");
        if(file==NULL) 
		{
            fprintf(stderr,"Error: Unable to open file.\n");
            return 1;
        }
        fscanf(file," %[^\n]s ",text);
        fclose(file);
    }
	else
	{
        fprintf(stderr,"Invalid choice.\n");
        return 1;
    }
    char* bwt=burrowsWheelerTransform(text);
    printf("Burrows-Wheeler Transform: %s\n",bwt);
    free(bwt);
    return 0;
}

