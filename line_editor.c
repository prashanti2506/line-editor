#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LEN 256

typedef struct {
    char lines[MAX_LINES][MAX_LEN];
    int count;
} Document;

void show_help(void) {
    printf("\nCommands:\n");
    printf("  i <line> <text>  Insert text at a line number\n");
    printf("  d <line>         Delete a line\n");
    printf("  p                Print the document\n");
    printf("  q                Quit\n");
    printf("  h                Show help\n\n");
}

void print_document(const Document *doc) {
    if (doc->count == 0) {
        printf("[Document is empty]\n");
        return;
    }

    for (int i = 0; i < doc->count; i++) {
        printf("%d: %s\n", i + 1, doc->lines[i]);
    }
}

void insert_line(Document *doc, int line_no, const char *text) {
    if (doc->count >= MAX_LINES) {
        printf("Error: document is full.\n");
        return;
    }

    if (line_no < 1 || line_no > doc->count + 1) {
        printf("Error: invalid line number. Use 1 to %d.\n", doc->count + 1);
        return;
    }

    for (int i = doc->count; i >= line_no; i--) {
        strcpy(doc->lines[i], doc->lines[i - 1]);
    }

    strncpy(doc->lines[line_no - 1], text, MAX_LEN - 1);
    doc->lines[line_no - 1][MAX_LEN - 1] = '\0';
    doc->count++;
    printf("Line inserted.\n");
}

void delete_line(Document *doc, int line_no) {
    if (line_no < 1 || line_no > doc->count) {
        printf("Error: invalid line number.\n");
        return;
    }

    for (int i = line_no - 1; i < doc->count - 1; i++) {
        strcpy(doc->lines[i], doc->lines[i + 1]);
    }

    doc->count--;
    printf("Line deleted.\n");
}

int main(void) {
    Document doc = { .count = 0 };
    char input[512];

    printf("=== C Line Editor ===\n");
    printf("Type 'h' for help.\n");

    while (1) {
        printf("editor> ");

        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "q") == 0) {
            printf("Goodbye!\n");
            break;
        } else if (strcmp(input, "p") == 0) {
            print_document(&doc);
        } else if (strcmp(input, "h") == 0) {
            show_help();
        } else if (input[0] == 'i' && input[1] == ' ') {
            int line_no;
            char text[MAX_LEN];

            if (sscanf(input + 2, "%d %[^"]", &line_no, text) == 2) {
                insert_line(&doc, line_no, text);
            } else {
                printf("Usage: i <line> <text>\n");
            }
        } else if (input[0] == 'd' && input[1] == ' ') {
            int line_no;

            if (sscanf(input + 2, "%d", &line_no) == 1) {
                delete_line(&doc, line_no);
            } else {
                printf("Usage: d <line>\n");
            }
        } else if (input[0] != '\0') {
            printf("Error: unknown command. Type 'h' for help.\n");
        }
    }

    return 0;
}
