#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(void) {
	struct sockaddr_in dirServidor;
	dirServidor.sin_family = AF_INET;
	dirServidor.sin_addr.s_addr = inet_addr("127.0.0.1");
	dirServidor.sin_port = htons(8080);

	int cliente = socket(AF_INET, SOCK_STREAM, 0);
	if (connect(cliente, (void*) &dirServidor, sizeof(dirServidor)) != 0) {
		perror("No se pudo conectar");
		return 1;
	}

	while (1) {
		char mensaje[1000];
		scanf("%s", mensaje);

		send(cliente, mensaje, strlen(mensaje), 0);
	}

	return 0;
}
