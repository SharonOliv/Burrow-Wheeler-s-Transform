#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct RotationIndex
{
    int index;
    char *rotation;
};

int compareSuffix(const void *a, const void *b) 
{
    struct RotationIndex *ra = (struct RotationIndex *)a;
    struct RotationIndex *rb = (struct RotationIndex *)b;
    return strcmp(ra->rotation, rb->rotation);
}

char *burrowsWheelerTransform(const char *text) 
{
    int n = strlen(text);
    struct RotationIndex *rotations = (struct RotationIndex *)malloc(n * sizeof(struct RotationIndex));

    // Generate indices of cyclic rotations
    int i;
    for (i = 0; i < n; ++i) 
	{
        rotations[i].index = i;
        rotations[i].rotation = (char *)malloc((n + 1) * sizeof(char));
        snprintf(rotations[i].rotation, n + 1, "%s%s", text + i, text);
    }

    // Sort the indices based on the corresponding cyclic rotations
    qsort(rotations, n, sizeof(struct RotationIndex), compareSuffix);

    // Extract the last characters of each rotation
    char *transformedText = (char *)malloc((n + 1) * sizeof(char));
    for (i = 0; i < n; ++i) 
	{
        transformedText[i] = rotations[i].rotation[n - 1];
    }
    transformedText[n] = '\0';

    // Free allocated memory
    for (i = 0; i < n; ++i) 
	{
        free(rotations[i].rotation);
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
    if (choice == 1) 
	{
        printf("Enter the text: ");
        scanf(" %[^\n]", text);
    } 
	else if (choice == 2) 
	{
        char filename[100];
        printf("Enter the filename containing the text: ");
        scanf("%s", filename);
        FILE *file = fopen(filename, "r");
        if (!file) 
		{
            fprintf(stderr, "Error: Unable to open file.\n");
            return 1;
        }
        char line[1000];
        while (fgets(line, sizeof(line), file)) 
		{
            strcat(text, line);
        }
        fclose(file);
    } 
	else 
	{
        fprintf(stderr, "Invalid choice.\n");
        return 1;
    }
    char *bwt = burrowsWheelerTransform(text);
    printf("Burrows-Wheeler Transform: %s\n", bwt);
    free(bwt);
    return 0;
}
