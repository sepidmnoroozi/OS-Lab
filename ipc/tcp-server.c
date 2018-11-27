/*
 * In The Name of God
 * =======================================
 * [] File Name : tcp-server.c
 *
 * [] Creation Date : 06-11-2018
 *
 * [] Created By : Parham Alvani <parham.alvani@gmail.com>
 * =======================================
 */
/*
 * Copyright (c)  2018 Parham Alvani.
 */

// Server side C/C++ program to demonstrate Socket programming

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
  int new_socket, valread;
  int opt = 1;
  char buffer[1024] = {0};
  char *hello = "Hello from server";

  // creates socket file descriptor
  int server_fd;
  server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd == 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  struct sockaddr_in address;
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT); // host to network -- coverts the ending of the given integer
  const int addrlen = sizeof(addrlen);

  // binding
  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  // listening
  if (listen(server_fd, 3) < 0) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
    perror("accept");
    exit(EXIT_FAILURE);
  }
  valread = read( new_socket , buffer, 1024);
  printf("%s\n",buffer );
  send(new_socket , hello , strlen(hello) , 0 );
  printf("Hello message sent\n");
  return 0;
}