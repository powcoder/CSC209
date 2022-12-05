https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>    /* Internet domain header */
#include <arpa/inet.h>     /* only needed on mac */

// change this value to customize the port per student (step 2)
#define PORT 54321
#define LEGO_PIECES 10
#define MAX_BUF 128
#define MAX_QUEUE 2

/* read and return a valid move from socket
 * a valid move is a text integer between 1 and 3 followed by a \r\n
 * 
 * Hint: read from the socket into a buffer, loop over the buffer
 *   until you find \r\n and then replace the \r with \0 to make a 
 *   string. Then use strtol to convert to an integer. If the result
 *   isn't in range, write a message to the socket and repeat. 
 */
int read_a_move(int socket) {
    // you must complete this function
    return 1;
}

/*
 * write msg to players with socket descriptors player1 and player2
 */
void write_to_players(char *msg, int player1, int player2) {
    // you must complete this function
}


int main() {
    // create socket
    int listen_soc = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_soc == -1) {
        perror("server: socket");
        exit(1);
    }

    // initialize server address    
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);  
    memset(&server.sin_zero, 0, 8);
    server.sin_addr.s_addr = INADDR_ANY;

    // This sets an option on the socket so that its port can be reused right
    // away. Since you are likely to run, stop, edit, compile and rerun your
    // server fairly quickly, this will mean you can reuse the same port.
    int on = 1;
    int status = setsockopt(listen_soc, SOL_SOCKET, SO_REUSEADDR, 
                            (const char *) &on, sizeof(on));
    if (status == -1) {
        perror("setsockopt -- REUSEADDR");
    }


    // bind socket to an address
    if (bind(listen_soc, (struct sockaddr *) &server, sizeof(struct sockaddr_in)) == -1) {
      perror("server: bind");
      close(listen_soc);
      exit(1);
    } 


    // Set up a queue in the kernel to hold pending connections.
    if (listen(listen_soc, MAX_QUEUE) < 0) {
        perror("listen");
        exit(1);
    }
   
    struct sockaddr_in client_addr;
    unsigned int client_len = sizeof(struct sockaddr_in);
    client_addr.sin_family = AF_INET;

    int client_socket = accept(listen_soc, (struct sockaddr *)&client_addr, &client_len);
    if (client_socket == -1) {
        perror("accept");
        return -1;
    } 

    // accept a second player  



    // demonstrating writing a message to player 1
    int item = LEGO_PIECES;
    char msg[MAX_BUF];
    sprintf(msg, "There are %d lego pieces left.\r\n", item);
    write(client_socket, msg, strlen(msg));


    // demonstrating reading up to MAX_BUF bytes from player 1
    char line[MAX_BUF];
    int num_chars = read(client_socket, line, MAX_BUF);
    line[num_chars] = '\0';

    // it may take more than one read to get all of the data that was written
    while(strstr(line, "\r\n") == NULL) {
        num_chars += read(client_socket, &line[num_chars], MAX_BUF-num_chars);
        line[num_chars] = '\0';
    }

    /* before we can use line in a printf statement, ensure it is a string */
    
    printf("I read %s.\n", line);

    return 0;
}


