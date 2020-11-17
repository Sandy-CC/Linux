#include "ch09.h"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   

int main()
{
	if(execle("./test","./test","hello","world\n",NULL,NULL/*env_init*/)==-1)
    {
        perror("execve!\n");
        exit(EXIT_FAILURE);
    }
    puts("Never get here!\n");
    exit(EXIT_SUCCESS);
}
