#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>

#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
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
    struct timespec start, stop;

    // struct sockaddr_in serv_addr, cli_addr;
    // int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    // if(sockfd<0){
    //     perror("sockfd");
    // }
    // bzero((char*) &serv_addr, sizeof(serv_addr));
    // int portno = atoi(argv[1]);
    // serv_addr.sin_addr.s_addr = INADDR_ANY;
    // serv_addr.sin_port = htons(portno);
    // serv_addr.sin_family= AF_INET;

    // if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr))<0){
    //     perror("bind");
    // }

    char buffer[255];

    // listen(sockfd, 5);
    // int clilen = sizeof(cli_addr);
    // int newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    // if(newsockfd<0){
    //     perror("accept");

    // }
    node **arr1 = (node **)malloc(sizeof(node*)*50); 
    // ar->str_a = (char*)malloc(sizeof(char)*20);
    // strcpy(ar->str_a ,"");

    // printf("waiting for writers...\n");
    int fd;
int count =0;
    clock_gettime(CLOCK_REALTIME, &start);

    while(1)
    {
    fd = open("newf", O_RDONLY);
        if(count>49){
            break;
        }

        bzero(buffer, 255);
    node *ar1 = (node *)malloc(sizeof(node));
    node *ar2 = (node *)malloc(sizeof(node));
    node *ar3 = (node *)malloc(sizeof(node));
    node *ar4 = (node *)malloc(sizeof(node));
    node *ar5 = (node *)malloc(sizeof(node));
        int n = read(fd, ar1, sizeof(node));
        n = read(fd, ar2, sizeof(node));
        n = read(fd, ar3, sizeof(node));
        n = read(fd, ar4, sizeof(node));
        n = read(fd, ar5, sizeof(node));
        printf("%d %s\n", ar1->id, ar1->str_a);
        printf("%d %s\n", ar2->id, ar2->str_a);
        printf("%d %s\n", ar3->id, ar3->str_a);
        printf("%d %s\n", ar4->id, ar4->str_a);
        printf("%d %s\n", ar5->id, ar5->str_a);
        // int *max =NULL;
        
        int b[1]= {0};
        b[0] = max_fxn(ar1->id,ar2->id,ar3->id,ar4->id,ar5->id);
        close(fd);
        count+=5;
        if(count>49){
            break;
        }
        fd = open("newf", O_WRONLY);
        
        int j = write(fd, b, sizeof(b[0]));
        // sleep(3);

        if(n<0){
            perror("read");
        }
        bzero(buffer, 255);


        if(j<0){
            perror("write");
        }
        close(fd);


        if(strncmp("Bye", buffer, 3)==0){
            break;
        }

    }
    clock_gettime(CLOCK_REALTIME, &stop);
    printf("\n%lf", stop.tv_sec- start.tv_sec +(stop.tv_nsec-start.tv_nsec)/10e9 );
    close(fd);
    // close(sockfd);

    return 0;

}
