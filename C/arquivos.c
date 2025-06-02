#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50
#define MAX_GENERO 30
#define MAX_FAVORITOS 10

typedef struct {
    int id;
    char nome[MAX_NOME];
    char genero[MAX_GENERO];
    int duracao;
} Video;

typedef struct {
    int id;
    char nome[MAX_NOME];
    int favoritos[MAX_FAVORITOS];
    int qtdFavoritos;
} Usuario;

void cadastrarVideo() {
    FILE *fp = fopen("videos.dat", "ab");
    if (fp == NULL) return;

    Video v;
    printf("ID do video: ");
    scanf("%d", &v.id);
    getchar();
    printf("Nome do video: ");
    fgets(v.nome, MAX_NOME, stdin);
    v.nome[strcspn(v.nome, "\n")] = 0;
    printf("Genero: ");
    fgets(v.genero, MAX_GENERO, stdin);
    v.genero[strcspn(v.genero, "\n")] = 0;
    printf("Duracao (minutos): ");
    scanf("%d", &v.duracao);

    fwrite(&v, sizeof(Video), 1, fp);
    fclose(fp);
    printf("Video cadastrado com sucesso.\n");
}

void listarVideos() {
    FILE *fp = fopen("videos.dat", "rb");
    if (fp == NULL) {
        printf("Nenhum video cadastrado.\n");
        return;
    }

    Video v;
    printf("\n=== Lista de Videos ===\n");
    while (fread(&v, sizeof(Video), 1, fp) == 1) {
        printf("ID: %d | Nome: %s | Genero: %s | Duracao: %d min\n", v.id, v.nome, v.genero, v.duracao);
    }
    fclose(fp);
}

char* buscarNomeVideo(int id) {
    static char nome[MAX_NOME];
    FILE *fp = fopen("videos.dat", "rb");
    if (fp == NULL) {
        strcpy(nome, "Nao encontrado");
        return nome;
    }

    Video v;
    while (fread(&v, sizeof(Video), 1, fp) == 1) {
        if (v.id == id) {
            strcpy(nome, v.nome);
            fclose(fp);
            return nome;
        }
    }
    fclose(fp);
    strcpy(nome, "Nao encontrado");
    return nome;
}

void removerVideo() {
    int id;
    printf("ID do video a remover: ");
    scanf("%d", &id);

    FILE *fp = fopen("videos.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    if (fp == NULL || temp == NULL) return;

    Video v;
    int encontrado = 0;
    while (fread(&v, sizeof(Video), 1, fp) == 1) {
        if (v.id != id) {
            fwrite(&v, sizeof(Video), 1, temp);
        } else {
            encontrado = 1;
        }
    }

    fclose(fp);
    fclose(temp);
    remove("videos.dat");
    rename("temp.dat", "videos.dat");

    if (encontrado)
        printf("Video removido com sucesso.\n");
    else
        printf("Video nao encontrado.\n");
}

void cadastrarUsuario() {
    FILE *fp = fopen("usuarios.dat", "ab");
    if (fp == NULL) return;

    Usuario u;
    printf("ID do usuario: ");
    scanf("%d", &u.id);
    getchar();
    printf("Nome do usuario: ");
    fgets(u.nome, MAX_NOME, stdin);
    u.nome[strcspn(u.nome, "\n")] = 0;
    u.qtdFavoritos = 0;

    char opcao;
    do {
        if (u.qtdFavoritos >= MAX_FAVORITOS) break;
        printf("ID do video favorito: ");
        scanf("%d", &u.favoritos[u.qtdFavoritos]);
        u.qtdFavoritos++;

        printf("Adicionar mais um favorito? (s/n): ");
        getchar();
        opcao = getchar();
    } while (opcao == 's' || opcao == 'S');

    fwrite(&u, sizeof(Usuario), 1, fp);
    fclose(fp);
    printf("Usuario cadastrado com sucesso.\n");
}

void listarUsuarios() {
    FILE *fp = fopen("usuarios.dat", "rb");
    if (fp == NULL) {
        printf("Nenhum usuario cadastrado.\n");
        return;
    }

    Usuario u;
    printf("\n=== Lista de Usuarios ===\n");
    while (fread(&u, sizeof(Usuario), 1, fp) == 1) {
        printf("ID: %d | Nome: %s | Favoritos: ", u.id, u.nome);
        for (int i = 0; i < u.qtdFavoritos; i++) {
            printf("%s", buscarNomeVideo(u.favoritos[i]));
            if (i < u.qtdFavoritos - 1) printf(", ");
        }
        printf("\n");
    }
    fclose(fp);
}

void removerUsuario() {
    int id;
    printf("ID do usuario a remover: ");
    scanf("%d", &id);

    FILE *fp = fopen("usuarios.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    if (fp == NULL || temp == NULL) return;

    Usuario u;
    int encontrado = 0;
    while (fread(&u, sizeof(Usuario), 1, fp) == 1) {
        if (u.id != id) {
            fwrite(&u, sizeof(Usuario), 1, temp);
        } else {
            encontrado = 1;
        }
    }

    fclose(fp);
    fclose(temp);
    remove("usuarios.dat");
    rename("temp.dat", "usuarios.dat");

    if (encontrado)
        printf("Usuario removido com sucesso.\n");
    else
        printf("Usuario nao encontrado.\n");
}

void menu() {
    int opcao;
    do {
        printf("\n===== MENU =====\n");
        printf("1. Cadastrar Video\n");
        printf("2. Listar Videos\n");
        printf("3. Remover Video\n");
        printf("4. Cadastrar Usuario\n");
        printf("5. Listar Usuarios\n");
        printf("6. Remover Usuario\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: cadastrarVideo(); break;
            case 2: listarVideos(); break;
            case 3: removerVideo(); break;
            case 4: cadastrarUsuario(); break;
            case 5: listarUsuarios(); break;
            case 6: removerUsuario(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida.\n");
        }
    } while (opcao != 0);
}

int main() {
    menu();
    return 0;
}
