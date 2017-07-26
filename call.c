#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>

int main(int argc, char **argv) {
    void *handle;
    void (*sayhello)(void);
    char *error;

    handle = dlopen ("./libhello.so", RTLD_LAZY);
    if (!handle) {
        fputs (dlerror(), stderr);
        exit(1);
    }

    sayhello = dlsym(handle, "sayHello");
    if ((error = dlerror()) != NULL)  {
        fputs(error, stderr);
        exit(1);
    }
    (*sayhello)();
    dlclose(handle);
}
