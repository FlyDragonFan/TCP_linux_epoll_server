#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "log.h"
#include "MyTCPServer.h"
//https://github.com/lihaitao8233/TCP_linux_epoll_server.git  //ת���뱣���˵�ַ
//linux epollģ�ͱ�д�ĸ߲���TCP�������ˣ�������Ӧ�Ĳ��Կͻ��˴��룬������������ͻ��˽��е���
//https://github.com/lihaitao8233/TCPServer_windows_iocp,�����windows����ɶ˿�IOCPģ�ͱ�д�ĸ߲���TCP�������ˣ�
//linux �� windows�Ľӿ���ȫһ����


int main(int argc, char *argv[])
{
    open_log_file("/home/lht/server", "server", 0);// ����ʵ��ָ����־Ŀ¼
    set_log_level(LOG_ERROR_LEVEL | LOG_NORMAL_LEVEL | LOG_DEBUG_LEVEL);

    MyTCPServer tcp_sever;
    tcp_sever.start(NULL, 5150, 30);//���ݸ��غͻ������õ����̳߳��߳���Ŀ
    //getchar();//��̨���лᱻֹͣ
    pause();
    tcp_sever.stop();


    close_log_file();//�ر���־�ļ�
    return 0;
}