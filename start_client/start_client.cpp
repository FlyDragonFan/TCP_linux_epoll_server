#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//usage: start_client �ͻ��˳���·�� ��������

int main(int argc, char *argv[])
{
    char path[512];
    strcpy(path, argv[1]);
    strcat(path, "&");

    for (int i = 0; i < atoi(argv[2]); i++)
    {
        system(path);
        //ÿ��1������1������֤1���ͻ��˵���һ����־�ļ�����ȻҲ���Լ����ͻ���ͬһ����־�ļ�
        usleep(1000 * 1001);
        printf("%d start\n", i);
    }

	return 0;
}
