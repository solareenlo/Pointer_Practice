// argcとargvの例
#include <stdio.h>

int main(int argc, char** argv) {
    int i;

    for(i = 0; i < argc; i++)
        printf("arg %d は %s です.\n", i, argv[i]);
    printf("\n");

    for(i = 0; i < argc; i++) {
        printf("arg %d は %s です.\n", i, *argv);
        argv++;
    }

    return 0;
}
