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
    int clientEntry;
    struct sockaddr_in address;
    FILE *file = fopen("clientLog.txt", "a");
    time_t t;
    struct tm *tm;
    char timeControl[100];
    char *tmp;
    char sendLine[100] = "Puerto en uso. . . . . \n22000\n";

    clientEntry = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&address, sizeof(address));

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htons(INADDR_ANY);
    address.sin_port = htons(22000); 

    bind(clientEntry, (struct sockaddr *)&address, sizeof(address));

    listen(clientEntry, 10);
    messagesList = accept(clientEntry, (struct address*) NULL, NULL);

    printf(". . . . . CHAT INICIADO . . . . . ");
    fputs("\n\n . . . .  CHAT INICIADO . . . . . \n\n", file);


}