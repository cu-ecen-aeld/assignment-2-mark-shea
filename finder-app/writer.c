#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <sys/stat.h>
#include <errno.h>
#include "syslog.h"


int main(int argc, char *argv[]) {

    openlog("finder-app", 0, LOG_USER);

    if (argc != 3) {
        fprintf(stderr, "Error: Two arguments required: <file path> <write string>\n");
        syslog(LOG_ERR, "Error: Two arguments required: <file path> <write string>");
        return 1;
    }

    char *writefile = argv[1];
    char *writestr = argv[2];

    // Write the string to the file (overwrite if exists)
    FILE *fp = fopen(writefile, "w");
    if (!fp) {
        fprintf(stderr, "Error: Could not write to file '%s'\n", writefile);
        syslog(LOG_ERR, "Error: Could not write to file '%s': %s", writefile, strerror(errno));
        return 1;
    }
    if (fputs(writestr, fp) == EOF) {
        fprintf(stderr, "Error: Could not write to file '%s'\n", writefile);
        syslog(LOG_ERR, "Error: Could not write to file '%s': %s", writefile, strerror(errno));
        fclose(fp);
        return 1;
    }
    syslog(LOG_DEBUG, "Writing '%s' to file '%s'", writestr, writefile);
    fclose(fp);
    return 0;
}