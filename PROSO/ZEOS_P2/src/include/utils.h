
#ifndef UTILS_H
#define UTILS_H

void copy_data(void *start, void *dest, int size);
int copy_from_user(void *start, void *dest, int size);
int copy_to_user(void *start, void *dest, int size);
void itoa(int num, char *buffer);
int strlen (const char * str);
int strcmp(const char * s1, const char * s2);

int intmax(int a, int b);
int intmin(int a, int b);
void itohex(unsigned int num, char *buffer);

#define LIST_TO_TASK(list) ((struct task_struct*)list)
#define LIST_TO_UNION(list) ((union task_union*)list)
#define TASK_TO_UNION(a) ((union task_union*)a)

#endif
