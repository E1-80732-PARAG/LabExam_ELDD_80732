// import.h
#ifndef __IMPORT_H_
#define __IMPORT_H_

extern int k_size, k_len, k_avail;

void kfifo_push(char *ch);
char* kfifo_pop(void);



#endif
