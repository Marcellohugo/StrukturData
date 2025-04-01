#include <stdio.h>
#include <string.h>

int main() {
    char sentence[1000];
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = '\0';
    char* token = strtok(sentence, " ");
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }

    return 0;
}
