#include <stdio.h>
#include <stdlib.h>

int main()
{

    static count = 1;
    count++;
    printf("%d\n", count);
    main();

    return 0;
}
