#include<stdio.h>
#include<unistd.h>



int main()
{
    int uid = getuid();

    if(uid == 0)
    {
        printf("I am root \n");
    }
    else
    {
        printf("I am not root my uid is: %d \n",uid);
    }

    return 0;
    
}
