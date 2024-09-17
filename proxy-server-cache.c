#include "proxy_parse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/wait.h>
#include <errno.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

#define MAX_CLIENTS 100;

struct chache_element
{
    char *data;
    int len;
    char *url;
    time_t lru_time_track;
    struct chache_element *next;
};

cache_element *find(char *url);
int add_cache_element(char *data, int size, char *url);
void remove_cache_element();

int port = 8080;
int proxy_socket;
pthread_t tid[MAX_CLIENTS];
sem_t semaphore;
pthread_mutex_t lock;


int main(int argc, char * argv[]) {

	int client_socketId, client_len; // client_socketId == to store the client socket id
	struct sockaddr_in server_addr, client_addr; // Address of client and server to be assigned

    sem_init(&seamaphore,0,MAX_CLIENTS); // Initializing seamaphore and lock
    pthread_mutex_init(&lock,NULL); // Initializing lock for cache}
}
