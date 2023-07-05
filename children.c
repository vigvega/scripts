#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>

int leer_proceso(char* fname);

int main(void){
	struct dirent *dt;
    DIR *dire;
 
    dire=opendir("/proc");
    
    while((dt=readdir(dire)) != NULL){ // recorro el directorio
        if(isdigit(dt->d_name[0])){
            leer_proceso(dt->d_name);
        }
    }
    
    return 0;
}

int leer_proceso(char* fname){
    char filename[20];
   
    sprintf(filename, "/proc/%s/stat", fname);
    
    FILE *f = fopen(filename, "r"); // abro el fichero
    if (f == NULL)
        exit(-1);

    // TODA LA INFO DE CADA PROCESO
    char state, name[32];
    int pid, ppid, threads;

    // VARIABLES PARA LA INFO QUE NO NECESITO
    int otra_info_i;
    unsigned long otra_info_l;
    unsigned long long otra_info_ll;
    long otra_info;
   
    fscanf(f, "%d %s %c %d %d %d %d %d %lu %lu %lu %lu %lu %Lu %Lu %Lu %Lu %ld %ld %d",
                 &pid, name, &state, &ppid, &otra_info_i, &otra_info_i, &otra_info_i,
                  &otra_info_i, &otra_info_l, &otra_info_l,
                  &otra_info_l, &otra_info_l, &otra_info_l,
                    &otra_info_ll, &otra_info_ll, &otra_info_ll, &otra_info_ll,
                     &otra_info, &otra_info, &threads);
   
    fclose(f); // cierro fichero

    printf (" PID: %d\n COMMAND: %s\n #CHILDREN: %d\n #THREADS: %d\n", pid, name, ppid, threads);
    printf("-------------------\n");
}