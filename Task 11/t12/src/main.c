#include "list.h"

int main(int argc, char *argv[]) {
    if (argc < 3 || argc > 5) {
        mx_printerr("usage: ./playlist [file] [command] [args]\n");
        exit(0);
    }

    if (mx_strcmp(argv[2], "add") == 0 && argc == 5) {
        int fd = open(argv[1], O_CREAT | O_RDWR | O_APPEND, S_IWUSR | S_IRUSR);
        char *temp = argv[3];
        if (fd < 0) {
            mx_printerr("ERROR\n");
            exit(0);
        }

        while(*temp) write(fd, temp++, 1);
        write(fd, " - ", 3);

        temp = argv[4];
        while(*temp) write(fd, temp++, 1);
        write(fd, "\n", 1);

        if (close(fd) < 0) {
            mx_printerr("ERROR\n");
            exit(0);            
        }

    }
    else if (mx_strcmp(argv[2], "print") == 0 && argc == 3) {
        int fd = open(argv[1], O_CREAT | O_RDWR | O_APPEND, S_IWUSR | S_IRUSR);
        if (fd < 0) {
            mx_printerr("ERROR\n");
            exit(0);
        }
        int max_count = 0, count = 1;
        char buffer;
      
        while (read(fd, &buffer, 1)) if (buffer == '\n') max_count++;

        if (close(fd) < 0) {
            mx_printerr("ERROR\n");
            exit(0);            
        }
        
        fd = open(argv[1], O_CREAT | O_RDWR | O_APPEND, S_IWUSR | S_IRUSR);
        if (fd < 0) {
            mx_printerr("ERROR\n");
            exit(0);
        }

        mx_printstr("0. ");        
        while (read(fd, &buffer, 1)) {
            if (buffer == '\n' && count < max_count) {
                mx_printchar('\n');
                mx_printint(count++);
                mx_printstr(". ");
                continue;
            }
            write(1, &buffer, 1);
        }
        if (close(fd) < 0) {
            mx_printerr("ERROR\n");
            exit(0);            
        }
    }
    
    else if (mx_strcmp(argv[2], "remove") == 0 && argc == 4) {
        int fd = open(argv[1], O_CREAT | O_RDWR | O_APPEND, S_IWUSR | S_IRUSR);
        if (fd < 0) {
            mx_printerr("ERROR\n");
            exit(0);
        }
        int index = mx_atoi(argv[3]);
        int max_count = 0, count_of_symbols = 0, count = 0;
        char buffer;
      
        while (read(fd, &buffer, 1)) {
            if (buffer == '\n') max_count++;
            if (index == max_count) continue;
            count_of_symbols++;
        }
        if (close(fd) < 0) {
            mx_printerr("ERROR\n");
            exit(0);            
        }
        if (index < 0 || index >= max_count) {
            mx_printerr("ERROR\n");
            exit(0);            
        }

        ;
        char *arr = (char*)malloc(count_of_symbols);
        
        fd = open(argv[1], O_CREAT | O_RDWR | O_APPEND, S_IWUSR | S_IRUSR);
        if (fd < 0) {
            mx_printerr("ERROR\n");
            exit(0);
        }
        int i = 0;
        while (read(fd, &buffer, 1)) {
            if (buffer == '\n') count++;
            if (index == count) continue;
            arr[i++] = buffer;
        }
        while (arr[i]) arr[i++] = '\0';
        if (close(fd) < 0) {
            mx_printerr("ERROR\n");
            exit(0);            
        }
        if (remove(argv[1]) < 0) {
            mx_printerr("ERROR\n");
            exit(0);                                
        }
      
        
        fd = open(argv[1], O_CREAT | O_RDWR | O_APPEND, S_IWUSR | S_IRUSR);
        if (index == 0) write(fd, arr + 1, mx_strlen(arr + 1));
        else write(fd, arr, mx_strlen(arr));
        if (close(fd) < 0) {
            mx_printerr("ERROR\n");
            exit(0);            
        }
        free(arr);
        arr = NULL;

    }   
    else if (mx_strcmp(argv[2], "sort") == 0 && argc == 4) {
        if (mx_strcmp(argv[3], "artist") == 0) {
            int fd = open(argv[1], O_CREAT | O_RDWR | O_APPEND, S_IWUSR | S_IRUSR);
            if (fd < 0) {
                mx_printerr("ERROR\n");
                exit(0);
            }
            int max_count = 0;
            char buffer;
        
            while (read(fd, &buffer, 1)) if (buffer == '\n') max_count++;

            if (close(fd) < 0) {
                mx_printerr("ERROR\n");
                exit(0);            
            }

            
            fd = open(argv[1], O_CREAT | O_RDWR | O_APPEND, S_IWUSR | S_IRUSR);
            if (fd < 0) {
                mx_printerr("ERROR\n");
                exit(0);
            }
            int *temp = (int*)malloc((max_count + 1) * 4);
            for (int i = 0; i < max_count; i++) {
                temp[i] = 1;
                while (read(fd, &buffer, 1)) {
                    if (buffer == '\n') break;
                    temp[i]++;
                }
            }
            temp[max_count] = '\n';
            if (close(fd) < 0) {
                mx_printerr("ERROR\n");
                exit(0);            
            }

            
            char **arr = (char**)malloc(max_count * 8);
            for (int i = 0; i < max_count; i++) 
                arr[i] = (char*)malloc(temp[i]);

            fd = open(argv[1], O_CREAT | O_RDWR | O_APPEND, S_IWUSR | S_IRUSR);
            if (fd < 0) {
                mx_printerr("ERROR\n");
                exit(0);
            }
            int j = 0;
            for (int i = 0; i < max_count; i++) {
                while (read(fd, &buffer, 1)) {
                    if (buffer == '\n') break;
                    arr[i][j++] = buffer;
                }
                j = 0;
            }

           
            if (close(fd) < 0) {
                mx_printerr("ERROR\n");
                exit(0);            
            }
            
            t_list *LList = NULL;
            t_list *tempList = LList;
            for (int i = 0; i < max_count; i++)
                mx_push_back(&LList, arr[i]);
            mx_sort_list(LList, cmp);

            if (remove(argv[1]) < 0) {
                mx_printerr("ERROR\n");
                exit(0);                                
            }
            tempList = LList; 
            

            fd = open(argv[1], O_CREAT | O_RDWR | O_APPEND, S_IWUSR | S_IRUSR);

            for (int i = 0; i < max_count; i++) {         
                write(fd, (char*)(tempList -> data), mx_strlen((char*)(tempList -> data)));
                buffer = '\n';
                write(fd, &buffer, 1);
                tempList = tempList -> next;
            }


            if (close(fd) < 0) {
                mx_printerr("ERROR\n");
                exit(0);            
            }

            
            mx_clear_list(&LList);
            for (int i = 0; i < max_count; i++) {
                free(arr[i]);
                arr[i] = NULL;
            }
            free(arr);
            arr = NULL;
            free(temp);
            temp = NULL;
        }
       
        else if (mx_strcmp(argv[3], "name") == 0) {

            int fd = open(argv[1], O_CREAT | O_RDWR | O_APPEND, S_IWUSR | S_IRUSR);
            if (fd < 0) {
                mx_printerr("ERROR\n");
                exit(0);
            }
            int max_count = 0;
            char buffer;
        
            while (read(fd, &buffer, 1)) if (buffer == '\n') max_count++;

            if (close(fd) < 0) {
                mx_printerr("ERROR\n");
                exit(0);            
            }

            
            fd = open(argv[1], O_CREAT | O_RDWR | O_APPEND, S_IWUSR | S_IRUSR);
            if (fd < 0) {
                mx_printerr("ERROR\n");
                exit(0);
            }
            int *temp = (int*)malloc(max_count * 4);
            int *start = (int*)malloc(max_count * 4);
            bool isT = true;
            for (int i = 0; i < max_count; i++) {
                isT = true;
                temp[i] = 1;
                start[i] = 2;
                while (read(fd, &buffer, 1)) {
                    if (buffer == '\n') break;
                    temp[i]++;
                    if (buffer != '-' && isT) start[i]++;
                    if (buffer == '-') isT = false;
                }
            }
            if (close(fd) < 0) {
                mx_printerr("ERROR\n");
                exit(0);            
            }

            
            char **arr = (char**)malloc(max_count * 8);
            for (int i = 0; i < max_count; i++) 
                arr[i] = (char*)malloc(temp[i]);

            fd = open(argv[1], O_CREAT | O_RDWR | O_APPEND, S_IWUSR | S_IRUSR);
            if (fd < 0) {
                mx_printerr("ERROR\n");
                exit(0);
            }
            int j = 0;
            for (int i = 0; i < max_count; i++) {
                while (read(fd, &buffer, 1)) {
                    if (buffer == '\n') break;
                    arr[i][j++] = buffer;
                }
                j = 0;
            }
         
            if (close(fd) < 0) {
                mx_printerr("ERROR\n");
                exit(0);            
            }
            

            for (int i = 0; i < max_count; i++) {
                for (int j = 0; j < max_count - 1; j++) {
                    if (mx_strcmp_new(&arr[j][start[j]], &arr[j + 1][start[j + 1]]) > 0 ) {
                        char *data = arr[j]; 
                        arr[j] = arr[j + 1]; 
                        arr[j + 1] = data;
                        int at = start[j];
                        start[j] = start[j + 1];
                        start[j + 1] = at;
                    }
                }
            }


            if (remove(argv[1]) < 0) {
                mx_printerr("ERROR\n");
                exit(0);                                
            }
             

            fd = open(argv[1], O_CREAT | O_RDWR | O_APPEND, S_IWUSR | S_IRUSR);


            for (int i = 0; i < max_count; i++) {         
                write(fd, arr[i], mx_strlen(arr[i]));
                buffer = '\n';
                write(fd, &buffer, 1);
            }


            if (close(fd) < 0) {
                mx_printerr("ERROR\n");
                exit(0);            
            }

            
            for (int i = 0; i < max_count; i++) {
                free(arr[i]);
                arr[i] = NULL;
            }
            free(arr);
            arr = NULL;
            free(temp);
            temp = NULL;            
        }
        else {
            mx_printerr("ERROR\n");
            exit(0);            
        }

    }
    else {
        mx_printerr("ERROR\n");
        exit(0);
    }

    return 0;
}
