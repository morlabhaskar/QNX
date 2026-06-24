#include <iostream>
#include <sys/neutrino.h>
#include <unistd.h>

int main()
{
    int chid = ChannelCreate(0);

    char msg[100];

    while (true)
    {
        int rcvid = MsgReceive(
            chid,
            msg,
            sizeof(msg),
            NULL);

        std::cout << "Received : "
                  << msg << std::endl;

        char reply[] = "ACK";

        MsgReply(
            rcvid,
            EOK,
            reply,
            sizeof(reply));
    }

    ChannelDestroy(chid);

    return 0;
}