#include <stdio.h>
#include <string.h>
#include <sys/errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

size_t  ft_strlen(char *s);
char    *ft_strcpy(char *dst, const char *src);
int     ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fd, const void *buf, size_t nbyte);
ssize_t ft_read(int fd, void *buf, size_t nbyte);
char    *ft_strdup(const char *s1);

int    main(void)
{
    char *str1 = "This is a string...\n";
    char *str2 = "Gaspacho\n";
    char *empty = "";
    char *ok = "qoigio;rqo;iqrinqr'inerqh'pinqhr'inqhr'pqerna\n";
    printf("\n\n-------------------TEST FT_STRLEN--------------------------\n\n");
    printf(" input: %s", str1);
    printf("  real: %lu\nlibasm: %lu\n", strlen(str1), ft_strlen(str1));
    printf("\n input: [empty string]\n");
    printf("  real: %lu\nlibasm: %lu\n", strlen(empty), ft_strlen(empty));
    printf("\n input: %s", ok);
    printf("  real: %lu\nlibasm: %lu\n", strlen(ok), ft_strlen(ok));
    printf("\n\n-------------------TEST FT_STRCPY--------------------------\n\n");
    char    empty1[50];
    char    empty2[50];
    printf("  real: %slibasm: %s\n", strcpy(empty1, str1), ft_strcpy(empty2, str1));
    printf("\n\n-------------------TEST FT_STRCMP--------------------------\n\n");
    printf("  real: %i\nlibasm: %i\n\n", strcmp(str1, str2), ft_strcmp(str1, str2));
    printf("  real: %i\nlibasm: %i\n\n", strcmp(empty, str1), ft_strcmp(empty, str1));
    printf("  real: %i\nlibasm: %i\n\n", strcmp(ok, str2), ft_strcmp(ok, str2));
    printf("\n\n-------------------TEST FT_WRITE--------------------------\n\n");
    FILE *test_file = fopen("test.txt", "w");
    fclose(test_file);
    int w_fd = open("test.txt", O_RDWR);
    printf("  real return: %zi\n", write(w_fd, str2, 9));
    printf("libasm return: %zi\n", ft_write(w_fd, str2, 9));
    printf("\n");
    printf("  Real Error: %zi, %s\n", write(-7, str2, 7), strerror(errno));
    printf("Libasm Error: %zi, %s\n", ft_write(-7, str2, 7), strerror(errno));
    printf("\n\n-------------------TEST FT_READ--------------------------\n\n");
    close(w_fd);
    char *buffer1 = calloc(500, sizeof(char));
    char *buffer2 = calloc (500, sizeof(char));
    int fd = open("test.txt", O_RDONLY);
    printf("  real return: %zi, %s\n", read(fd, buffer1, 5), buffer1);
    fd = open("test.txt", O_RDONLY);
    printf("libasm return: %zi, %s\n", ft_read(fd, buffer2, 5), buffer2);
    printf("\n");
    printf("  Real Error: %zi, %s\n", read(-7, buffer1, 7), strerror(errno));
    printf("Libasm Error: %zi, %s\n", ft_read(-7, buffer2, 7), strerror(errno));
    printf("\n\n-------------------TEST FT_STRDUP--------------------------\n\n");
    printf("  real: %slibasm: %s\n", strdup(str1), ft_strdup(str1));
    printf("  real: %s\nlibasm: %s\n\n", strdup(empty), ft_strdup(empty));
    printf("  real: %slibasm: %s", strdup(ok), ft_strdup(ok));
}
