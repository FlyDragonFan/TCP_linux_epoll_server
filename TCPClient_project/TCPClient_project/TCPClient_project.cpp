#include <stdio.h>
#include <unistd.h>
#include "MyTCPClient.h"
#include "log.h"
//https://github.com/lihaitao8233/TCP_linux_epoll_server.git  //ת���뱣���˵�ַ
//linux epollģ�ͱ�д�ĸ߲���TCP�������ˣ�������Ӧ�Ĳ��Կͻ��˴��룬������������ͻ��˽��е���
//https://github.com/lihaitao8233/TCPServer_windows_iocp,�����windows����ɶ˿�IOCPģ�ͱ�д�ĸ߲���TCP�������ˣ�
//linux �� windows�Ľӿ���ȫһ����

int  main()
{
    open_log_file("/home/lht/server", "client", 1);  //����־�ļ�������1��
    set_log_level(LOG_ERROR_LEVEL | LOG_NORMAL_LEVEL | LOG_DEBUG_LEVEL);


    MyTCPClient my_tcp_client;
    my_tcp_client.start("192.168.96.139", 5150);
    //getchar();//��̨���г���ᱻֹͣ
    pause();
    my_tcp_client.stop();



    close_log_file();//�ر���־�ļ�
    return 0;
}



