#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <numero_de_processos>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int n = atoi(argv[1]);
    
    for (int i = 0; i < n; i++) {
        pid_t pid = fork();
        
        if (pid < 0) {
            fprintf(stderr, "Erro ao criar o processo filho\n");
            return EXIT_FAILURE;
        } else if (pid == 0) {  // Processo filho
            execl("./hello_world", "hello_world", NULL);
            perror("exec");
            return EXIT_FAILURE;
        }
    }

    // Espera todos os processos filhos terminarem
    for (int i = 0; i < n; i++) {
        wait(NULL);
    }

    return EXIT_SUCCESS;
}
