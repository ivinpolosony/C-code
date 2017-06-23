#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

void *say_hello(void *arg)
{
    std::cout << "Hello  "<< *((int *)arg) <<std::endl;

    long sum = 1000;
    return (void *) sum;

}
int main(int argc, char *argv[])
{
    pthread_t threads[2];
    void  *ret_code;



    int arg = 124;
    int arg2 = 125;

    if (pthread_create(&threads[0], NULL, say_hello, &arg) != 0) {
        perror("pthread_create() error");
        exit(1);
    }


    //   long sum = *((long *)ret_code);


    if (pthread_create(&threads[1], NULL, say_hello, &arg2) != 0) {
        perror("pthread_create() error");
        exit(1);
    }


    if (pthread_join(threads[0], &ret_code) != 0) {
        perror("pthread_create() error");
        exit(3);
    }

    long sum = (long) ret_code;
    printf("thread exited with '%d'\n", ret_code);

    if (pthread_join(threads[1], &ret_code) != 0) {
        perror("pthread_create() error");
        exit(3);
    }

    sum += (long)ret_code;
    std::cout << sum  << "\n";
    printf("thread exited with '%d'\n", ret_code);

    //ret_code = pthread_create(&threads[0], NULL, say_hello, "NULL");
    return 0;
}
