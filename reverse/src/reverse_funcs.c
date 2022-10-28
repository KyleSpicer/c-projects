/** @file reverse_funcs.c
 * 
 * @brief reverse_funcs.c houses the function definitions used within the
 * reverse program.
 * 
 * @par #include "reverse.h"
 * 
 */

#include "reverse.h"

/* displays program usage */
void display_usage(void)
{
    printf("Usage: reverse <128-bit key> <input file>\n");
}

/* ensures .pcap magic number is present before continuing program# */
bool verify_magic_number(file_header_t * file_hdr)
{
    long pcap_magic_number = {0xd4c3b2a1};

    if(!(htonl(file_hdr->file_type_id) == pcap_magic_number))
    {
        return false;
    }

    else
    {
        return true;
    }
}

/* validates proper number of arguments */
void verify_arg_count(int argc)
{
    if (argc != 3)
    {
        display_usage();
        exit(1);
    } 
}

/* get file length */
int get_file_length(FILE * p_file)
{
    fseek(p_file, 0, SEEK_END);
    int file_length = ftell(p_file);
    fseek(p_file, 0, SEEK_SET);

    return file_length;
}

/* checks if file was not opened */
void did_file_open(FILE * p_file)
{
    if (!p_file)
    {
        perror("Unable to open file ");
        display_usage();
        exit(1);
    }
}

/* finds message size of entire packet */
int packet_size(FILE * p_file)
{   
    fseek(p_file, 0, SEEK_END);
    int file_length = ftell(p_file);
    fseek(p_file, 0, SEEK_SET);

    int packet_start = 99;
    int packet_size = file_length - packet_start;

    return packet_size;
}

/* checks the type of packet ( message or movement ) */
int decrypt_payload_type(int payload_type)
{
    if (payload_type == 16 || payload_type == 0)
    {
        return 0;
    }

    else if (payload_type == 17)
    {
        return 1;
    }

    else
    {
        return -1;
    }
}

/* converts argv[1] string to hex_key */
void convert_string_to_hex_key(char * key, u_int8_t * hex_arr)
{
    int key_len = strlen(key);
    char buff[3] = {0};
    buff[2] = '\0';
    char * ptr = {0};

    for(int idx = 0, j = 0; idx < key_len; idx += 2)
    {
        buff[0] = key[idx];
        buff[1] = key[idx + 1];
        hex_arr[j] = strtol(buff, &ptr, 16);
        j++;
    }
}

/* adjusts azimuth or inclination by 180 degrees */
void adjust_azimuth_and_inclination(double * az_or_inclination)
{
    if (*az_or_inclination <= 180)
    {
        *az_or_inclination += 180;
    }
    else
    {
        *az_or_inclination -= 180;
    }
}

/* converts endianess from big to little or little to big endian */
void swap_endianess_back(void * alien_movement)
{
    char old_move[8];
    char new_move[8];
    memcpy(old_move, alien_movement, 8);

    new_move[0] = old_move[7];
    new_move[1] = old_move[6];
    new_move[2] = old_move[5];
    new_move[3] = old_move[4];
    new_move[4] = old_move[3];
    new_move[5] = old_move[2];
    new_move[6] = old_move[1];
    new_move[7] = old_move[0];
    
    memcpy(alien_movement, new_move, 8);

}

/*** end of file ***/ 
