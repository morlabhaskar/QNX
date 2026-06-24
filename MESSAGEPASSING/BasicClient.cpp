#include <iostream>
#include <sys/neutrino.h>

int main()
{
    int server_pid = 1234; // server PID
    int server_chid = 1;   // server Channel ID

    int coid = ConnectAttach(
        ND_LOCAL_NODE,
        server_pid,
        server_chid,
        _NTO_SIDE_CHANNEL,
        0);

    char msg[] = "Hello Server";
    char reply[100];

    MsgSend(
        coid,
        msg,
        sizeof(msg),
        reply,
        sizeof(reply));

    std::cout << "Reply : "
              << reply << std::endl;

    ConnectDetach(coid);

    return 0;
}