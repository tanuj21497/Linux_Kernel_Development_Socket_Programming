#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
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
#define PATH_SOCK "unix_socket"
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
    struct sockaddr_un serv_addr, cli_addr;
    int s =socket(AF_UNIX, SOCK_STREAM, 0);
    if(s==-1){
        perror("socket error");
    }
    serv_addr.sun_family = AF_UNIX;
    strcpy(serv_addr.sun_path, PATH_SOCK);
    unlink(serv_addr.sun_path);
    int b= bind(s, (struct sockaddr *)&serv_addr, strlen(serv_addr.sun_path)+ sizeof(serv_addr.sun_family));
    if(b!=0){
        perror(":bind");
        exit(0);
    }

    int l =listen(s, 1);
    if(l==-1){
        exit(0);
    }
    int s2;
    socklen_t t = sizeof(cli_addr);
    while(1){
        s2 = accept(s, (struct sockaddr *)&cli_addr, &t);
        if(s2!=-1){
            break;
        }
        if(s2==-1){

        }


    }
    // listen(sockfd, 5);
    // int clilen = sizeof(cli_addr);
    // int newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    // if(newsockfd<0){
    //     perror("accept");

    // }
    node **arr1 = (node **)malloc(sizeof(node*)*50); 
    // ar->str_a = (char*)malloc(sizeof(char)*20);
    // strcpy(ar->str_a ,"");

int count =0;
    clock_gettime(CLOCK_REALTIME, &start);
    while(1)
    {
        if(count>49){
            break;
        }

        bzero(buffer, 255);
    node *ar1 = (node *)malloc(sizeof(node));
    node *ar2 = (node *)malloc(sizeof(node));
    node *ar3 = (node *)malloc(sizeof(node));
    node *ar4 = (node *)malloc(sizeof(node));
    node *ar5 = (node *)malloc(sizeof(node));
        // char *arr = (char*)malloc(sizeof(char)*20);
        // strcpy()
        // char mp[50]="";

        // strcpy(mp, ar->str_a);
        // int n = read(newsockfd, ar1, sizeof(node));
        // n = read(newsockfd, ar2, sizeof(node));
        // n = read(newsockfd, ar3, sizeof(node));
        // n = read(newsockfd, ar4, sizeof(node));
        // n = read(newsockfd, ar5, sizeof(node));
        int n = recv(s2, ar1, sizeof(node),0);
        n = recv(s2, ar2, sizeof(node),0);
        n = recv(s2, ar3, sizeof(node),0);
        n = recv(s2, ar4, sizeof(node),0);
        n = recv(s2, ar5, sizeof(node),0);
        printf("%d %s\n", ar1->id, ar1->str_a);
        printf("%d %s\n", ar2->id, ar2->str_a);
        printf("%d %s\n", ar3->id, ar3->str_a);
        printf("%d %s\n", ar4->id, ar4->str_a);
        printf("%d %s\n", ar5->id, ar5->str_a);
        // int *max =NULL;
        int b[1]= {0};
        b[0] = max_fxn(ar1->id,ar2->id,ar3->id,ar4->id,ar5->id);
        int j = send(s2, b, sizeof(b[0]), 0);
        count+=5;
        // break;
        // arr = (char*)malloc(sizeof(char)*20);

        // n = read(newsockfd, arr1[1], sizeof(arr1[1]));
        // // arr = (char*)malloc(sizeof(char)*20);

        // n = read(newsockfd, arr1[2], sizeof(arr1[2]));
        // // arr = (char*)malloc(sizeof(char)*20);

        // n = read(newsockfd, arr1[3], sizeof(arr1[3]));
        // // arr = (char*)malloc(sizeof(char)*20);

        // n = read(newsockfd, arr1[4], sizeof(arr1[4]));

        if(n<0){
            perror("read");
        }
        // printf("Client: %s", buffer);
        bzero(buffer, 255);
        // fgets(buffer, 255, stdin);


        if(j<0){
            perror("write");
        }


        if(strncmp("Bye", buffer, 3)==0){
            break;
        }

    }
    clock_gettime(CLOCK_REALTIME, &stop);

    printf("%lf",stop.tv_sec - start.tv_sec +(stop.tv_nsec - start.tv_nsec)/10e9 );

    close(s2);
    // close(sockfd);

    return 0;

}
