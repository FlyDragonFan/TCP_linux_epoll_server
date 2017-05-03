#ifndef TCP_CIENT_H_
#define TCP_CIENT_H_

#include <deque>
#include <sys/socket.h>
#include <pthread.h>


class TCPClient
{
public:
    TCPClient();
    ~TCPClient();
    int start(const char* ip, const unsigned short port);
    void stop();

protected:
    //ֻ�ܴ�recv_deque������
    //ֻ����send_dequeѹ����
    //�û����ж��������������recv_dequeȡ�����պõ����ݣ���Ҫ���͵����ݷ���send_deque
    //�û�ֻʹ������������Բ��ù�������ϸ��
    virtual void work(std::deque<char>& send_deque, std::deque<char>& recv_deque);

private:
    static void* thread_func(void*);
    int connect_to_server(const char* ip, const unsigned short port);
    int connect_retry(const int socket, const struct sockaddr* addr, const socklen_t alen, const int connect_cnt);
    int read_from_server();
    int write_to_server();


private:
    unsigned int m_port;
    char m_server_ip[16];
    bool m_run_flag;
    int m_socket;
    pthread_t m_thread_id;
    bool m_write_event;
    std::deque<char> m_recv_queque;
    std::deque<char> m_send_queque;
};

#endif
