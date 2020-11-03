#include"myfun.c"

int main(){
    recorder *pt;
    pt=input();
    save(pt);
    free(pt);
    output();
	return 0;
}
