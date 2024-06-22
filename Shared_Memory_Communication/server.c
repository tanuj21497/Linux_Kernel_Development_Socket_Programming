#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>
int max_fxn(int a, int b, int c, int d, int e){
    if(a>=b && a>=c && a>=d &&a>=e){
        return a;

    }
    if(b>=a && b>=c && b>=d &&b>=e){
        return b;

    }
    if(c>=a && c>=b && c>=d &&c>=e){
        return c;

    }
    if(d>=a && d>=b && d>=d &&d>=e){
        return d;

    }
    else{
        return e;
    }
    return e;
}
struct node{
    int id;
    char str_a[50];
};
typedef struct node node;

int main(int argc, char const *argv[])
{

    node **arr1 = (node **)malloc(sizeof(node*)*50); 
    struct timespec start, stop;


    // printf("waiting for writers...\n");
    int shm_id; key_t key; node *shm_ptr, *s;
    key =ftok("file_use", 'b');
    
    shm_id = shmget(key, sizeof(node),0666);
    shm_ptr = (node *)shmat(shm_id, NULL,0);
    // node *a = malloc(sizeof(node));
    // strcpy(a->str_a,"*");
    s= shm_ptr;
    char ar1[30];
    int a=0, b=0,c=0,d=0,e=0;
    int s_count=0;
    
    clock_gettime(CLOCK_REALTIME, &start);

    while(s_count<=49){
        while(strcmp(shm_ptr->str_a, "#")!=0 && s_count!=0){

            sleep(0.0000001);
        }
    printf("%d %s\n", s->id, s->str_a);
    a= s->id;
        // while(strcmp(shm_ptr->str_a, "#")!=0 && s_count==0){

        //     sleep(0.01);
        // }

    s++;
    // s_count++;
    printf("%d %s\n",s->id, s->str_a);
    b= s->id;

    s++;
    // s_count++;

    printf("%d %s\n", s->id, s->str_a);
    c= s->id;

    s++;
    // s_count++;

    printf("%d %s\n", s->id, s->str_a);
    d= s->id;

    s++;    
    // s_count++;

    printf("%d %s\n", s->id, s->str_a);
    e= s->id;

    // s++;
    // s_count++;
    s++;
    bzero(shm_ptr, sizeof(node));
    shm_ptr->id = max_fxn(a,b,c,d,e);
    s_count = shm_ptr->id;
    s_count++;
    printf("%d\n", shm_ptr->id);
    strcpy(shm_ptr->str_a, ">");
    
    }
    // sleep(3);
    clock_gettime(CLOCK_REALTIME, &stop);
    printf("%lf",stop.tv_sec - start.tv_sec +(stop.tv_nsec-start.tv_nsec)/10e9);

    shmdt(shm_ptr);
    
    return 0;

}
