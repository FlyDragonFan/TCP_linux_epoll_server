#ifndef TCP_SERVER_H_
#define TCP_SERVER_H_
#include <deque>
#include <map>
#include <pthread.h>

class TCPServer
{
public:
    typedef struct _SERVERTHREADPOOL
    {
        pthread_t thread_id;
        int fd[2];
        int epoll_fd;
    } SERVER_THREAD_POOL, *P_SERVER_THREAD_POOL;

    typedef struct _THREADARG
    {
        int thread_num; //0��ͷ
        void* p_this;
    } THREAD_ARG, *P_THREAD_ARG;

    typedef struct _CLIENTDEQUE
    {
        std::deque<char>  send_deque;
        std::deque<char>  recv_deque;
    } CLIENT_DEQUE;

    TCPServer();
    ~TCPServer();

    //���IP����NULL����ʾINADDR_ANY
    int start(const char* ip, const int port, int thread_cnt);
    int stop();

protected:
    //ֻ�ܴ�recv_deque������
    //ֻ����send_dequeѹ����
    //�û����ж��������������recv_dequeȡ�����պõ����ݣ���Ҫ���͵����ݷ���send_deque
    //�û�ֻʹ������������Բ��ù�������ϸ��
    virtual void work(std::deque<char>& send_deque, std::deque<char>& recv_deque);

private:
    int read_from_client(int fd, std::deque<char>& recv_deque);
    int write_to_client(int fd, std::deque<char>& send_deque);
    int create_thread_pool(int thread_cnt);
    int get_listen_socket(const char* ip, const int port, const int backlog); //SOMAXCONN
    static void* client_thread(void*);
    static void* accept_thread(void*);
    P_SERVER_THREAD_POOL m_thread_pool;
    int m_thread_cnt;
    bool m_run_flag;
    pthread_t m_accept_thread_id;
    int m_listen_socket;
    int m_epoll_fd;
};

#endif