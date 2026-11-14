#include <stdio.h>

static int calls;
static int read_status(void) { return ++calls; }

static int process(int expected = 5)
{
    defer printf("scope exit; read_status calls=%d\n", calls);

    if (0 < read_status() <= expected) {
        int status = calls;
        if (status == 0 || != expected)
            return status;
    }
    return -1;
}

int main(void)
{
    int result = process();
    printf("result=%d, calls=%d\n", result, calls);
    return result == 1 && calls == 1 ? 0 : 1;
}
