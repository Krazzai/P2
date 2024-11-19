#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 100
#define MAX_FAVORITES 10

typedef struct {
    int id;
    char title[MAX_NAME];
    char genre[MAX_NAME];
} Video;

typedef struct {
    int id;
    char name[MAX_NAME];
    int favoriteVideos[MAX_FAVORITES];
    int favoriteCount;
} Usuario;


void menu();
void cadastrarVideo();
void cadastrarUsuario();
void listarVideos();
void listarUsuarios();
void atualizarVideo();
void atualizarUsuario();
void removerVideo();
void removerUsuario();


int main() {
    menu();
    return 0;
}

void menu() {
    int opcao;
    do {
        printf("\n=== Sistema de Streaming ===\n");
        printf("1. Cadastrar Video\n");
        printf("2. Cadastrar Usuario\n");
        printf("3. Listar Videos\n");
        printf("4. Listar Usuarios\n");
        printf("5. Atualizar Video\n");
        printf("6. Atualizar Usuario\n");
        printf("7. Remover Video\n");
        printf("8. Remover Usuario\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1: cadastrarVideo(); break;
            case 2: cadastrarUsuario(); break;
            case 3: listarVideos(); break;
            case 4: listarUsuarios(); break;
            case 5: atualizarVideo(); break;
            case 6: atualizarUsuario(); break;
            case 7: removerVideo(); break;
            case 8: removerUsuario(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}


void cadastrarVideo() {
    FILE *file = fopen("videos.dat", "ab");
    if (!file) {
        printf("Erro ao abrir o arquivo de videos.\n");
        return;
    }

    Video video;
    printf("Digite o ID do video: ");
    scanf("%d", &video.id);
    getchar();

    printf("Digite o titulo do video: ");
    fgets(video.title, MAX_NAME, stdin);
    video.title[strcspn(video.title, "\n")] = 0;

    printf("Digite o genero do video: ");
    fgets(video.genre, MAX_NAME, stdin);
    video.genre[strcspn(video.genre, "\n")] = 0;

    fwrite(&video, sizeof(Video), 1, file);
    fclose(file);
    printf("Video cadastrado com sucesso!\n");
}

void listarVideos() {
    FILE *file = fopen("videos.dat", "rb");
    if (!file) {
        printf("Erro ao abrir o arquivo de videos.\n");
        return;
    }

    Video video;
    printf("\n=== Lista de Videos ===\n");
    while (fread(&video, sizeof(Video), 1, file)) {
        printf("ID: %d | Titulo: %s | Genero: %s\n", video.id, video.title, video.genre);
    }
    fclose(file);
}


void cadastrarUsuario() {
    FILE *file = fopen("usuarios.dat", "ab");
    if (!file) {
        printf("Erro ao abrir o arquivo de usuarios.\n");
        return;
    }

    Usuario usuario;
    printf("Digite o ID do usuario: ");
    scanf("%d", &usuario.id);
    getchar();

    printf("Digite o nome do usuario: ");
    fgets(usuario.name, MAX_NAME, stdin);
    usuario.name[strcspn(usuario.name, "\n")] = 0;

    usuario.favoriteCount = 0;

    fwrite(&usuario, sizeof(Usuario), 1, file);
    fclose(file);
    printf("Usuario cadastrado com sucesso!\n");
}

void listarUsuarios() {
    FILE *file = fopen("usuarios.dat", "rb");
    if (!file) {
        printf("Erro ao abrir o arquivo de usuarios.\n");
        return;
    }

    Usuario usuario;
    printf("\n=== Lista de Usuarios ===\n");
    while (fread(&usuario, sizeof(Usuario), 1, file)) {
        printf("ID: %d | Nome: %s | Favoritos: %d videos\n", 
               usuario.id, usuario.name, usuario.favoriteCount);
    }
    fclose(file);
}


void atualizarVideo() {
    FILE *file = fopen("videos.dat", "rb+");
    if (!file) {
        printf("Erro ao abrir o arquivo de videos.\n");
        return;
    }

    int id;
    printf("Digite o ID do video a ser atualizado: ");
    scanf("%d", &id);
    getchar();

    Video video;
    int found = 0;
    while (fread(&video, sizeof(Video), 1, file)) {
        if (video.id == id) {
            found = 1;
            printf("Digite o novo titulo do video: ");
            fgets(video.title, MAX_NAME, stdin);
            video.title[strcspn(video.title, "\n")] = 0;

            printf("Digite o novo genero do video: ");
            fgets(video.genre, MAX_NAME, stdin);
            video.genre[strcspn(video.genre, "\n")] = 0;

            fseek(file, -sizeof(Video), SEEK_CUR);
            fwrite(&video, sizeof(Video), 1, file);
            break;
        }
    }

    fclose(file);
    if (found) {
        printf("Video atualizado com sucesso!\n");
    } else {
        printf("Video nao encontrado.\n");
    }
}

void atualizarUsuario() {
    FILE *file = fopen("usuarios.dat", "rb+");
    if (!file) {
        printf("Erro ao abrir o arquivo de usuarios.\n");
        return;
    }

    int id;
    printf("Digite o ID do usuario a ser atualizado: ");
    scanf("%d", &id);
    getchar();

    Usuario usuario;
    int found = 0;
    while (fread(&usuario, sizeof(Usuario), 1, file)) {
        if (usuario.id == id) {
            found = 1;
            printf("Digite o novo nome do usuario: ");
            fgets(usuario.name, MAX_NAME, stdin);
            usuario.name[strcspn(usuario.name, "\n")] = 0;

            fseek(file, -sizeof(Usuario), SEEK_CUR);
            fwrite(&usuario, sizeof(Usuario), 1, file);
            break;
        }
    }

    fclose(file);
    if (found) {
        printf("Usuario atualizado com sucesso!\n");
    } else {
        printf("Usuario nao encontrado.\n");
    }
}


void removerVideo() {
    FILE *file = fopen("videos.dat", "rb");
    if (!file) {
        printf("Erro ao abrir o arquivo de videos.\n");
        return;
    }

    FILE *temp = fopen("temp_videos.dat", "wb");
    if (!temp) {
        printf("Erro ao criar arquivo temporario.\n");
        fclose(file);
        return;
    }

    int id;
    printf("Digite o ID do video a ser removido: ");
    scanf("%d", &id);

    Video video;
    while (fread(&video, sizeof(Video), 1, file)) {
        if (video.id != id) {
            fwrite(&video, sizeof(Video), 1, temp);
        }
    }

    fclose(file);
    fclose(temp);

    remove("videos.dat");
    rename("temp_videos.dat", "videos.dat");
    printf("Video removido com sucesso!\n");
}

void removerUsuario() {
    FILE *file = fopen("usuarios.dat", "rb");
    if (!file) {
        printf("Erro ao abrir o arquivo de usuarios.\n");
        return;
    }

    FILE *temp = fopen("temp_usuarios.dat", "wb");
    if (!temp) {
        printf("Erro ao criar arquivo temporario.\n");
        fclose(file);
        return;
    }

    int id;
    printf("Digite o ID do usuario a ser removido: ");
    scanf("%d", &id);

    Usuario usuario;
    int found = 0;
    while (fread(&usuario, sizeof(Usuario), 1, file)) {
        if (usuario.id != id) {
            fwrite(&usuario, sizeof(Usuario), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp);

    if (found) {
        remove("usuarios.dat");
        rename("temp_usuarios.dat", "usuarios.dat");
        printf("Usuario removido com sucesso!\n");
    } else {
        printf("Usuario com ID %d nao encontrado.\n", id);
        remove("temp_usuarios.dat");
    }
}
