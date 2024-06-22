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
#include <time.h>


struct node{
    int id;
    char str_a[50];
};
typedef struct node node;
int main(int argc, char *argv[]){
    char buffer[255];
    struct timespec start, stop;

    char *arr;
    char str[27] = "abcdefghijklmnopqrstuvwxyz";


    node **arr1 = (node **)malloc(sizeof(node*)*100); 
    for (size_t i = 0; i < 50; i++)
    {
        node *st = malloc(sizeof(node));
        st->id=i;
        arr = (char*)malloc(sizeof(char)*20);

        for (int j = 0; j < 6; j++)
        {
            
            int r = rand()%25;
            arr[j] = str[r];
            
        }
        strcpy(st->str_a,arr);

        arr1[i] = st;
        

        /* code */
    }

    
    // int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    // struct hostent *server = gethostbyname(argv[1]);
    // struct sockaddr_in serv_addr;
    // bzero((char *) &serv_addr, sizeof(serv_addr));
    // serv_addr.sin_family = AF_INET;
    // bcopy((char*)server->h_addr, (char*)&serv_addr.sin_addr.s_addr, server->h_length);
    // serv_addr.sin_port = htons(atoi(argv[2]));
    // if(connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr))<0){
    //     perror("connection failure");
    // }
    int fd = mkfifo("newf",0666);
    if(fd==-1 && (errno!=EEXIST)){

        perror("mknod");
        exit(0);
    }

    // while(1){

    // }


    clock_gettime(CLOCK_REALTIME, &start);
    int count =0;
    while(1){
        fd = open("newf", O_WRONLY);
        bzero(buffer, 255);
        if(count>49){
            break;
        }
        int j = write(fd, arr1[count++], sizeof(node));
                if(count>49){
            break;
        }
        j = write(fd, arr1[count++], sizeof(node));
                if(count>49){
            break;
        }
        j = write(fd, arr1[count++], sizeof(node));
                if(count>49){
            break;
        }
        j = write(fd, arr1[count++], sizeof(node));
                if(count>49){
            break;
        }
        j = write(fd, arr1[count++], sizeof(node));
                if(count>49){
            break;
        }



        if(j<0){
            perror("write");
        }
        close(fd);
        bzero(buffer, 255);
        // sleep(3);
        int b[1] = {0};
        // int *max =NULL;
        fd = open("newf", O_RDONLY);


        int n = read(fd, b, sizeof(b[0]));
        printf("\n%d", b[0]);
        count = b[0]+1;
        // break;
        if(n<0){
            perror("read");
        }
        // printf("SERVER: %s", buffer);
        if(strncmp("Bye", buffer, 3)==0){
            break;
        }
        close(fd);



    }

    close(fd);
    clock_gettime(CLOCK_REALTIME, &stop);
    printf("\n%ld", stop.tv_sec- start.tv_sec );
    return 0;
}
