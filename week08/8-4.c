#include"ch8.h"

static void func1(void);
static void func2(void);

static jmp_buf g_stack_env;

int main()
{
    if(setjmp(g_stack_env)==0)
    {
        printf("Normal flow!\n");
        func1();
        printf("Normal flow back from func!\n");
    }
    else
    {
        printf("Back From long jump!\n");
    }
    return 0;
}

static void func1(void)
{
    printf("Enter func1!\n");
    func2();
    printf("Leave func1!\n");
}

static void func2(void)
{
    printf("Enter func2!\n");
    longjmp(g_stack_env,1);
    printf("Leave func2!\n");
}
