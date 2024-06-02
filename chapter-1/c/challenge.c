#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libstringlist.c"


void print_strings(string_list *list)
{
    char *str = NULL;
    int i = 0;

    printf("  printing strings\n");

    for (i = 0; i < list->list_length; i++)
    {
        str = list_get(list, i);
        printf("    %d: %s\n", i, str);
    }

    printf("  done priting strings.\n\n");
}

int main(int argc, char *argv[])
{    
    string_list *list = NULL;
    char *str = NULL;
    int retval = 0;
    int c = 0;

    list = malloc(sizeof(string_list));
    memset(list, 0, sizeof(string_list));

    str = malloc(64);
    strcpy(str, "Hello world!");
    printf("calling list_insert() with \"%s\" @ at index 0\n", str);
    retval = list_insert(list, str, 0);
    printf("retval: %d\n", retval);
    print_strings(list);

    str = malloc(64);
    strcpy(str, "second string!");
    printf("calling list_push() with \"%s\"\n", str);
    retval = list_push(list, str);
    printf("retval: %d\n", retval);
    print_strings(list);

    str = malloc(64);
    strcpy(str, "third string.");
    printf("calling list_push() with \"%s\"\n", str);
    retval = list_push(list, str);
    printf("retval: %d\n", retval);
    print_strings(list);

    str = malloc(64);
    strcpy(str, "fourth? string");
    printf("calling list_insert() with \"%s\" @ at index 1\n", str);
    retval = list_insert(list, str, 1);
    printf("retval: %d\n", retval);
    print_strings(list);

    str = malloc(64);
    strcpy(str, "abcd");
    printf("calling list_push() with \"%s\"\n", str);
    retval = list_push(list, str);
    printf("retval: %d\n", retval);
    print_strings(list);;

    str = malloc(64);
    strcpy(str, "abcde");
    printf("calling list_push() with \"%s\"\n", str);
    retval = list_push(list, str);
    printf("retval: %d\n", retval);
    print_strings(list);;

    str = malloc(64);
    strcpy(str, "second string!");
    retval = list_search(list, str);
    printf("search for \"%s\" -- count is: %d\n", str, retval);
    free(str);
    str = NULL;

    printf("calling list_get() with index 3\n");
    str = list_get(list, 3);
    printf("string at list[3]: %s\n", str);

    printf("calling list_remove() with index 0\n");
    str = list_remove(list, 0);
    printf("string removed from list at list[0]:\n  %s\n", str);
    print_strings(list);
    free(str);
    str = NULL;

    str = malloc(64);
    strcpy(str, "impostor string? is now here");
    printf("calling list_insert() with \"%s\" @ at index 0\n", str);
    retval = list_insert(list, str, 0);
    printf("retval: %d\n", retval);
    print_strings(list);

    printf("now deleting the list\n");
    while(list->list_length)
    {
        str = list_pop(list);
        free(str);
        str = NULL;
    }
    print_strings(list);

    free(list);
    list = NULL;

    return 0;
}