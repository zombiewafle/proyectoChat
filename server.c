#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <unistd.h>

void main(void){
    char chat[1000];
    int socket_entry, messagesList;
    struct sockaddr_in address;
    FILE *file = fopen("serverLog.txt", "a");
    time_t t;
    struct tm *tm;
    char timeControl[100];
    char *tmp;
    char sendLine[100] = "Puerto en uso. . . . . \n22000\n";

    socket_entry = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&address, sizeof(address));

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htons(INADDR_ANY);
    address.sin_port = htons(22000); 

    bind(socket_entry, (struct sockaddr *)&address, sizeof(address));

    listen(socket_entry, 10);
    messagesList = accept(socket_entry, (struct address*) NULL, NULL);

    printf(". . . . . CHAT INICIADO . . . . . ");
    fputs("\n\n . . . .  CHAT INICIADO . . . . . \n\n", file);

    while(!strstr(chat, "Hasta la proxima . . . . ") && !strstr(sendLine, "Hasta la proxima . . . . ")){
        bzero(chat, 100);
        t = time(NULL);
        tm = localtime(&t);
        strftime(timeControl, 100, "\n otro usuario (%H:%M) -> ", tm);

        read(messagesList, chat, 100);
        tmp = strcat(timeControl, chat);
        printf("%s", tmp);

        fputs(tmp, file);

        if(!str(chat, "adios")){
            strftime(timeControl, 100, "\n yo (%H:%M) -> ", tm);
            printf("%s", timeControl);
            gets(sendLine);
            tmp = strcat(timeControl, sendLine);
            write(messagesList, sendLine, strlen(sendLine) + 1);
            fputs(tmp, file);
        }

    }

    printf("\n\n . . . . . CHAT TERMINADO . . . . .");
    fclose(file);
}