/** @file reverse.h
 * 
 * @brief reverse.h hold all of the includes, defines, structure
 * definitions, and function declarations for use with reverse.c and reverse_funcs.c.
 * 
 * @par include with reverse.c and reverse_funcs.c
 * 
 */

#ifndef REVERSE_H
#define REVERSE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdint.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "../tls_crypto.h"

#pragma pack(1) /* set byte alignment */

#define FIXED_HEADER_SIZE 12

// /* structure definitions */
struct file_header
{
    u_int32_t file_type_id;
    u_int16_t major_version;
    u_int16_t minor_version;
    u_int32_t gmt_offset;
    u_int32_t accuracy_delta;
    u_int32_t max_length_of_capture;
    u_int32_t link_layer_type;
};

struct packet_header
{
    u_int32_t unix_epoch;
    u_int32_t micro_seconds_epoch;
    u_int32_t length_of_data_captured;
    u_int32_t untrucated_packet_length;
};

struct ethernet_frame
{
    u_int16_t  dest_mac[3];
    u_int16_t  source_mac[3];
    u_int16_t ethernet_type;
};

struct ip_header
{
    u_int8_t  version : 4;
    u_int8_t  ihl : 4;
    u_int8_t  dscp : 7;
    u_int8_t  ecn : 1;
    u_int16_t total_length;
    u_int16_t identification;
    u_int8_t  flags : 3;
    u_int16_t fragment_offset : 13;
    u_int8_t  time_to_live;
    u_int8_t  protocol;
    u_int16_t header_checksum;
    u_int32_t source_ip_address;
    u_int32_t destination_ip_address;
};

struct tcp_header
{
    u_int16_t source_port;
    u_int16_t destination_port;
    u_int32_t sequence_number;
    u_int32_t acknowledment_number;
    u_int8_t  data_offset : 4;
    u_int16_t reserved_plus_flags : 12;
    u_int16_t window_size;
    u_int16_t checksum;
    u_int16_t urgent_pointer;
};

struct tls_header
{
    u_int16_t content_type : 8;
    u_int16_t version;
    u_int16_t length;
};

struct alien_packet_header
{
    u_int8_t version;
    u_int8_t type;
    u_int32_t total_length : 24;
    u_int16_t source_id;
    u_int16_t destination;
    u_int32_t sequence_id;
};

struct alien_movement
{
    double galactic_azimuth;
    double galactic_inclination;
    float distance;
    float speed;
};

/* structure declarations */
typedef struct file_header     file_header_t;
typedef struct packet_header   packet_header_t;
typedef struct ethernet_frame  ethernet_frame_t;
typedef struct ip_header       ip_header_t;
typedef struct tcp_header      tcp_header_t;
typedef struct tls_header      tls_header_t;
typedef struct alien_packet_header alien_pkt_hdr_t;
typedef struct alien_movement alien_mvmt_t;

/*** function declarations (prototypes) ***/

/* displays program usage */
void display_usage(void);

/* verify pcap magic number */
bool verify_magic_number(file_header_t * file_hdr);

/* validates proper number of arguments */
void verify_arg_count(int argc);

/* get file length */
int get_file_length(FILE * p_file);

/* convert key string to 16 byte array */
u_int8_t * convert_key_to_array(char * key);

/* checks if file was not opened */
void did_file_open(FILE * p_file);

/* determines the size of each message */
int packet_size(FILE * p_file);

/* checks the type of packet ( message or movement ) */
int decrypt_payload_type(int payload_type);

/* converts argv[1] string to hex_key */
void convert_string_to_hex_key(char * key, u_int8_t *);

/* accepts azimuth or inclination and add/subtracts 180 */
void adjust_azimuth_and_inclination(double * az_or_inclination);

/* reverses the byte order of argument passed */
void swap_endianess_back(void * alien_movement);

#endif /* REVERSE_H */

/*** end of file ***/ 
