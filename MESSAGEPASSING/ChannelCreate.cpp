/*
Creates a channel on the server.
A channel acts like a mailbox where clients can send messages.
Without a channel, the server cannot receive messages.

#include <sys/neutrino.h>
int chid = ChannelCreate(0);
Success : Channel ID (chid)
Failure : -1
*/
