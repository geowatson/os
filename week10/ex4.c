#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main() {
        struct dirent * dp;
        struct dirent * dt;

        char temp[100], full[100];
         struct stat * curr = malloc(sizeof(struct stat));

        getcwd(temp, sizeof(temp));
        strcat(temp, "/tmp/");
        DIR * dirp = opendir(temp);
        DIR * dirt;

        while ((dp = readdir(dirp)) != NULL) {
                strcpy(full, temp);
                strcat(full, dp->d_name);
                stat(full, curr);
                if (curr->st_nlink > 1 && strcmp(".", dp->d_name) & strcmp("..", dp->d_name)) {
                        dirt = opendir(temp);
                        int n = (int)curr->st_ino;

                        printf("%s <- ", dp->d_name);
                        while((dt = readdir(dirt)) != NULL) {
                                strcpy(full, temp);
                                strcat(full, dt->d_name);
                                stat(full, curr);
                                if ((int)curr->st_ino == n & strcmp(dt->d_name,dp->d_name) != 0) {
                                        printf("%s ", dt->d_name);
                                }
                        }

                        printf("(%d)\n", n);
                        closedir(dirt);
                }
        } 

        closedir(dirp);
}