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


struct node{
    int id;
    char str_a[50];
};
typedef struct node node;
int main(int argc, char *argv[]){
    char buffer[255];

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
    // printf("%s", arr1[49]->str_a);
    int shm_id; key_t key; node *shm_ptr, *s;
    key =ftok("file_use", 'b');
    node n, m;
    n.id =3;
    m.id =4;
    strcpy(n.str_a, "tanuj");
    strcpy(m.str_a, "nuj");
    shm_id = shmget(key, sizeof(node), IPC_CREAT | 0666);
    shm_ptr = (node *)shmat(shm_id, NULL,0);
    s= shm_ptr;
    int count =0;

    while(count<=50){
        int s_count = count;
        if(count!=0){
            strcpy(shm_ptr->str_a, "*");
        }


        s->id = arr1[s_count]->id;
        strcpy(s->str_a, arr1[s_count]->str_a);
        s++;
        s_count++;

        if(s_count>49){
            break;
        }

        s->id = arr1[s_count]->id;
        strcpy(s->str_a, arr1[s_count]->str_a);
        s++;
        s_count++;

        if(s_count>49){
            break;
        }
        s->id = arr1[s_count]->id;
        strcpy(s->str_a, arr1[s_count]->str_a);
        s++;
        s_count++;

        if(s_count>49){
            break;
        }

        s->id = arr1[s_count]->id;
        strcpy(s->str_a, arr1[s_count]->str_a);
        s++;
        s_count++;

        if(s_count>49){
            break;
        }
        s->id = arr1[s_count]->id;
        strcpy(s->str_a, arr1[s_count]->str_a);
        s_count=0;
                if(s_count>49){
            break;
        }
        if(count!=0){
            strcpy(shm_ptr->str_a, "#");
        }
        while (strcmp(shm_ptr->str_a, ">")!=0)
        {
            sleep(0.0000001);
        }
        // sleep(6);
                if(s_count>49){
            break;
        }

        printf("%d\n", shm_ptr->id);
        count = shm_ptr->id;
        if(count>=49){
            break;
        }
        count++;
        s++;
        if(s_count>49){
            break;
        }
        bzero(shm_ptr, sizeof(node));
        strcpy(shm_ptr->str_a, "*");
        shm_ptr->id =-1;


        // s++;
        
    

    

        
    }
    // sleep(10);
        shmdt(shm_ptr);
        shmctl(shm_id, IPC_RMID, NULL);
    

    



    // int count =0;
    // while(1){
    //     fd = open("newf", O_WRONLY);
    //     bzero(buffer, 255);
    //     if(count>49){
    //         break;
    //     }
    //     int j = write(fd, arr1[count++], sizeof(node));
    //             if(count>49){
    //         break;
    //     }
    //     j = write(fd, arr1[count++], sizeof(node));
    //             if(count>49){
    //         break;
    //     }
    //     j = write(fd, arr1[count++], sizeof(node));
    //             if(count>49){
    //         break;
    //     }
    //     j = write(fd, arr1[count++], sizeof(node));
    //             if(count>49){
    //         break;
    //     }
    //     j = write(fd, arr1[count++], sizeof(node));
    //             if(count>49){
    //         break;
    //     }



    //     if(j<0){
    //         perror("write");
    //     }
    //     close(fd);
    //     bzero(buffer, 255);
    //     // sleep(3);
    //     int b[1] = {0};
    //     // int *max =NULL;
    //     fd = open("newf", O_RDONLY);


    //     int n = read(fd, b, sizeof(b[0]));
    //     printf("\n%d", b[0]);
    //     count = b[0]+1;
    //     // break;
    //     if(n<0){
    //         perror("read");
    //     }
    //     // printf("SERVER: %s", buffer);
    //     if(strncmp("Bye", buffer, 3)==0){
    //         break;
    //     }
    //     close(fd);



    // }
    // close(fd);
    return 0;
}