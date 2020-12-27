#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/ip.h>
#include <netinet/if_ether.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

/**
 * A raw socket bypasses the normal TCP/IP processing and sends the packets to the specific user application.
 * Other sockets like stream sockets and datagram sockets receive data from the transport layer that contains no headers but only the payload.
 */
int main()
{
    FILE* rawSocketsLog = fopen("/home/bitate/TCP/rawSocketsLog", "w");

    int sock = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (sock == -1)
    {
        //socket creation failed, may be because of non-root privileges
        perror("Failed to create socket");
        exit(1);
    }

    // Allocate string buffer to hold raw socket
    uint8_t *buffer = (uint8_t*)malloc(65536);
    memset(buffer, 0, 65536);
    int rawSocketSize;
    
    for (int i = 0; i < 4; ++i)
    {
        rawSocketSize = recvfrom(sock, buffer, 65536, 0, NULL, NULL);
        if (rawSocketSize == -1)
        {
            printf("Failed to get raw socket\n");
            return 1;
        }
        
        // Save raw socket in hex string
        fprintf(rawSocketsLog, "Raw socket data in hexadecimal: \n\t");
        for(int i = 0; i < rawSocketSize; ++i)
        {
            // each column has 16 hexadecimal numbers.
            if(i != 0 && i%16==0)
                fprintf(rawSocketsLog, "\n\t");

            fprintf(rawSocketsLog, " %.2X ", buffer[i]);
        }

        // Save ethernet header info.
        struct ethhdr *ethernetHeader = (struct ethhdr *)(buffer);
        fprintf(rawSocketsLog, "\nEthernet Header Info:\n");
        fprintf(rawSocketsLog, "\t|-Source Address      : %.2X-%.2X-%.2X-%.2X-%.2X-%.2X\n", ethernetHeader->h_source[0], ethernetHeader->h_source[1], ethernetHeader->h_source[2], ethernetHeader->h_source[3], ethernetHeader->h_source[4], ethernetHeader->h_source[5]);
        fprintf(rawSocketsLog, "\t|-Destination Address : %.2X-%.2X-%.2X-%.2X-%.2X-%.2X\n", ethernetHeader->h_dest[0], ethernetHeader->h_dest[1], ethernetHeader->h_dest[2], ethernetHeader->h_dest[3], ethernetHeader->h_dest[4], ethernetHeader->h_dest[5]);
        fprintf(rawSocketsLog, "\t|-Protocol : %d\n", ethernetHeader->h_proto);

        // Save Ip header info.
        struct iphdr* ipHeader = (struct iphdr*)(buffer + sizeof(struct ethhdr));        
        fprintf(rawSocketsLog, "IP Header Info:\n");
        fprintf(rawSocketsLog, "\t|-IP ID: %.4X\n",                   ipHeader->id);
        fprintf(rawSocketsLog, "\t|-IP version: %.1X\n",             ipHeader->version);
        fprintf(rawSocketsLog, "\t|-IP source address: %.8X\n",      ipHeader->saddr);
        fprintf(rawSocketsLog, "\t|-IP destination address: %.8X\n", ipHeader->daddr);
        fprintf(rawSocketsLog, "\n\n\n");
    }

    return 0;
}