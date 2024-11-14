#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ";");
         tok && *tok;
         tok = strtok(NULL, ";\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

int main()
{
    FILE* stream = fopen("slowka.csv", "r");
    if (stream == NULL) {
        perror("Nie mo¿na otworzyæ pliku");
        return 1;
    }

    char line[186];
    const char* slowka[186];
    const char* answers[186];
    int i = 0;
    while (fgets(line, sizeof(line), stream))
    {
        char* tmp = strdup(line);


        char* field1 = strdup(getfield(tmp, 1));
        char* tmp2 = strdup(line);
        char* field2 = strdup(getfield(tmp2, 2));

        slowka[i] = field1;
        answers[i] = field2;

        free(tmp);
        free(tmp2);
        i++;
    }
    fclose(stream);

    while(1)
    {
        srand(time(NULL));
        int i = rand() % 186;
        printf("%s\n", slowka[i]);
        system("pause");
        printf("%s\n", answers[i]);
        system("pause");
        system("cls");
    }

    return 0;
}
