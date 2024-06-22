#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/un.h>

struct node{
    int id;
    char str_a[50];
};
typedef struct node node;

#define PATH_SOCK "unix_socket"
int main(void){
    char buffer[255];
    // struct socketaddr_un serv_addr;
    struct sockaddr_un client;

    // int s= socket(AF_UNIX, SOCK_STREAM, 0);
    // client.sun_family = AF_UNIX;
    // strcpy(client.sun_path, PATH_SOCK);
    // connect(s, (struct sockaddr *)&client ,strlen(client.sun_path) + sizeof(client.sun_family));

    // remote.
    // if(argc<3){
    //     perror("argc error");
    // }
    //    char *arr;
    // char **arr_str =(char**)malloc(sizeof(char*)*50);

    
    // char str[27] = "abcdefghijklmnopqrstuvwxyz";
    // char str2[51] = "123456789";
    // for (int i = 0; i < 20; i++)
    // {
    //     arr = (char*)malloc(sizeof(char)*20);
    //     char sp[10];
    //     sprintf(sp, "%d ", i);
    //     strcat(arr, sp);
    //     for (int j = 0; j < 6; j++)
    //     {

    //         int r = rand()%25;
    //         if(i>=9){
    //         arr[j+3] = str[r];}
    //         else if(i<9){
    //             arr[j+2] = str[r];
    //         }
    //     }
    //     // printf("%s\n", arr);
    //     arr_str[i] = arr;
        
    // }
    // for (int k = 0; k < 10; k++)
    // {
    //     printf(" %s\n", arr_str[k]);
    // }
    char *arr;
    // char **arr_str =(char**)malloc(sizeof(char*)*50);
    char str[27] = "abcdefghijklmnopqrstuvwxyz";
    // int r = rand()%25;


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
    // for (int k = 0; k < 10; k++)
    // {
    //     printf("%d %s\n", arr1[k]->id, arr1[k]->str_a);
    //     /* code */
    // }
    
    
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
       int s= socket(AF_UNIX, SOCK_STREAM, 0);
       if(s==-1){
        perror("socket");
        exit(0);
       }
    client.sun_family = AF_UNIX;
    strcpy(client.sun_path, PATH_SOCK);
    int g = connect(s, (struct sockaddr *)&client ,strlen(client.sun_path) + sizeof(client.sun_family));
    if(g!=0){
        printf("connection");
        exit(0);
    }

    int count =0;
    while(1){
        bzero(buffer, 255);

        // fgets(buffer, 255, stdin);
        // int j= write(sockfd, buffer, strlen(buffer));
        node *ar = (node *)malloc(sizeof(node));
        ar->id = 2;
        // strcpy(ar->str_a , "tanlochick");
        // printf("%s", ar->str_a);
        // int j = write(sockfd, ar, sizeof(node));
        if(count>49){
            break;
        }
        int j = send(s, arr1[count++], sizeof(node), 0);
                if(count>49){
            break;
        }
        j = send(s, arr1[count++], sizeof(node), 0);
                if(count>49){
            break;
        }
        j = send(s, arr1[count++], sizeof(node), 0);
                if(count>49){
            break;
        }
        j = send(s, arr1[count++], sizeof(node), 0);
                if(count>49){
            break;
        }
        j = send(s, arr1[count++], sizeof(node), 0);
                if(count>49){
            break;
        }

        if(j<0){
            perror("write");
        }
        bzero(buffer, 255);
        int b[1] = {0};
        // int *max =NULL;
        int n = recv(s, b, sizeof(b[0]), 0);
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



    }
    // close(s);
    return 0;
}