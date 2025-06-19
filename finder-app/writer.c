#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <sys/stat.h>
#include <errno.h>


int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Error: Two arguments required: <file path> <write string>\n");
        return 1;
    }

    char *writefile = argv[1];
    char *writestr = argv[2];

    // Write the string to the file (overwrite if exists)
    FILE *fp = fopen(writefile, "w");
    if (!fp) {
        fprintf(stderr, "Error: Could not write to file '%s'\n", writefile);
        return 1;
    }
    if (fputs(writestr, fp) == EOF) {
        fprintf(stderr, "Error: Could not write to file '%s'\n", writefile);
        fclose(fp);
        return 1;
    }
    fclose(fp);
    return 0;
}