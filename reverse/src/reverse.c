/** @file reverse.c
 * 
 * @brief reverse.c is a program that accepts command line arguments to open
 * encrypted .pcap files, decypt and manipulate the data, reencrypt and write
 * to a new out.pcap file.
 * 
 * @par Usage: ./reverse <128-bit key> <input-file>
 * 
 */

#include "reverse.h"

int
main(int argc, char *argv[])
{
    char * key       = argv[1];
    char * file_name = argv[2];

    verify_arg_count(argc);

    /* open file */
    FILE * p_file;
    p_file = fopen(file_name, "rb");

    did_file_open(p_file); // verify file opened

    /* file length for packet */
    int  file_length   = get_file_length(p_file);
    bool file_complete = false;
    
    // /* open and write to pcap.out */
    FILE * p_out_file;
    p_out_file = fopen("out.pcap", "wb");

    /* go through packet and pack structs */
    file_header_t file_hdr;
    fread(&file_hdr, sizeof(file_hdr), 1, p_file);
    fwrite(&file_hdr, 1, sizeof(file_header_t), p_out_file);
    
    bool is_magic_number = verify_magic_number(&file_hdr);
    if(!is_magic_number)
    {
        goto FINISH_PROGRAM;
    }

    while (!file_complete)
    {
        packet_header_t pkt_hdr;
        fread(&pkt_hdr, sizeof(pkt_hdr), 1, p_file);
        ethernet_frame_t eth_frm;
        fread(&eth_frm, sizeof(eth_frm), 1, p_file);
        ip_header_t ip_hdr;
        fread(&ip_hdr, sizeof(ip_hdr), 1, p_file);
        tcp_header_t tcp_hdr;
        fread(&tcp_hdr, sizeof(tcp_hdr), 1, p_file);
        tls_header_t tls_hdr;
        fread(&tls_hdr, sizeof(tls_hdr), 1, p_file);

        /* find size of packet */
        u_int16_t packet_length = ntohs(tls_hdr.length);

        /* allocate memory for encrypted data ( everything after tls hdr ) */
        u_int8_t * packet = calloc(packet_length, 1);

        /* grab encrypted packet content ( everything after tls_hdr ) */
        fread(packet, packet_length, 1, p_file);

        /* convert command line string to hex_key */
        u_int8_t hex_key[16] = { 0 };
        convert_string_to_hex_key(key, hex_key);

        /* allocate storage for decrypted alien packet information */
        u_int8_t * destination_for_decrypted_data = calloc(packet_length, 1);

        decrypt_message(
            destination_for_decrypted_data, packet, packet_length, hex_key);

        /* pack alien packet header with information */
        alien_pkt_hdr_t alien_pkt_hdr;
        alien_pkt_hdr.version = destination_for_decrypted_data[16];
        alien_pkt_hdr.type    = destination_for_decrypted_data[16];
        alien_pkt_hdr.total_length
            = destination_for_decrypted_data[19] - FIXED_HEADER_SIZE;
        alien_pkt_hdr.source_id   = destination_for_decrypted_data[21];
        alien_pkt_hdr.destination = destination_for_decrypted_data[23];
        alien_pkt_hdr.sequence_id = destination_for_decrypted_data[27];

        /* determine if payload is a message or movement */
        int payload_type = decrypt_payload_type(alien_pkt_hdr.type);

        /* display decrypted message */
        if (0 == payload_type)
        {
            /* adding end of line to message */
            printf("%d : \"", alien_pkt_hdr.destination);
            for (int i = 0; i < alien_pkt_hdr.total_length; i++)
            {
                printf("%c", destination_for_decrypted_data[28 + i]);
            }
            printf("\"");
            printf("\n");

            /* convert first letter to lowercase */
            destination_for_decrypted_data[28] += 32;

            u_int8_t array[6]   = { 68, 111, 110, 39, 116, 32 }; // "Don't "
            int      array_size = sizeof(array);
 
            /* allocate memory, create updated message */
            u_int8_t * new_message = calloc((packet_length + array_size), 1);

            /* concatenate new string */
            strncat((char *)new_message, (char *)array, array_size);
            strncat((char *)new_message,
                    (char *)&destination_for_decrypted_data[28],
                    alien_pkt_hdr.total_length);

            /* adjust position for new string */
            destination_for_decrypted_data[19] += array_size;

            /* pointer to destination for new message */
            u_int8_t * p_new_dest = &destination_for_decrypted_data[28];
            
            /* copy new message to byte stream */
            strncpy((char *)p_new_dest,
                    (char *)new_message,
                    strlen((char *)new_message));

            /* display newly constructed message */
            printf("%d : \"%s.\"\n", alien_pkt_hdr.destination, new_message);

            /* memory allocation for new encrypt message */
            u_int8_t * encrypt_destination = calloc(packet_length, 1);

            encrypt_message(encrypt_destination,
                            destination_for_decrypted_data,
                            packet_length,
                            hex_key);

            /* write updated structs to out.pcap */
            fwrite(&pkt_hdr, 1, sizeof(packet_header_t), p_out_file);
            fwrite(&eth_frm, 1, sizeof(ethernet_frame_t), p_out_file);
            fwrite(&ip_hdr, 1, sizeof(ip_header_t), p_out_file);
            fwrite(&tcp_hdr, 1, sizeof(tcp_header_t), p_out_file);
            fwrite(&tls_hdr, 1, sizeof(tls_header_t), p_out_file);
            fwrite(encrypt_destination, 1, packet_length, p_out_file);

            /* free allocated memory for new message */
            free(new_message);
            free(encrypt_destination);
        }

        else if (1 == payload_type)
        {
            /* movement */
            /* pointer to destination for byte stream */
            u_int8_t * p_new_dest = &destination_for_decrypted_data[28];

            /* decalre alien_mvmt struct */
            alien_mvmt_t alien_mvmt;

            /* convert and adjust azimuth */
            alien_mvmt.galactic_azimuth = *(double *)p_new_dest;

            /* swap endianess, adjust azimuth, swap endianess, copy to dest */
            swap_endianess_back(&alien_mvmt.galactic_azimuth);
            adjust_azimuth_and_inclination(&alien_mvmt.galactic_azimuth);
            swap_endianess_back(&alien_mvmt.galactic_azimuth);
            memcpy(p_new_dest, &alien_mvmt.galactic_azimuth, sizeof(double));

            /* inclination */
            /* move dest pointer to capture incliniation data */
            p_new_dest += sizeof(alien_mvmt.galactic_azimuth);

            /* swap endianess, adjust azimuth, swap endianess, copy to dest */
            alien_mvmt.galactic_inclination = *(double *)p_new_dest;
            swap_endianess_back(&alien_mvmt.galactic_inclination);
            adjust_azimuth_and_inclination(&alien_mvmt.galactic_inclination);
            swap_endianess_back(&alien_mvmt.galactic_inclination);
            memcpy(p_new_dest, &alien_mvmt.galactic_inclination, sizeof(double));
            p_new_dest =  (u_int8_t *)&alien_mvmt.galactic_inclination;

            /* reencrypt message */
            u_int8_t * encrypt_destination = calloc(packet_length, 1);

            encrypt_message(encrypt_destination,
                            destination_for_decrypted_data,
                            packet_length,
                            hex_key);

            /* write updated structs and new message to out.pcap */
            fwrite(&pkt_hdr, 1, sizeof(packet_header_t), p_out_file);
            fwrite(&eth_frm, 1, sizeof(ethernet_frame_t), p_out_file);
            fwrite(&ip_hdr, 1, sizeof(ip_header_t), p_out_file);
            fwrite(&tcp_hdr, 1, sizeof(tcp_header_t), p_out_file);
            fwrite(&tls_hdr, 1, sizeof(tls_header_t), p_out_file);
            fwrite(encrypt_destination, 1, packet_length, p_out_file);

            free(encrypt_destination);
        }

        else
        {
            printf("Error reading payload type from \"%s\".\n", file_name);
            goto FINISH_PROGRAM;
        }

        /* free allocated memory */
        free(packet);
        free(destination_for_decrypted_data);

        /* verify if the end of file has been reached */
        int packet_end = ftell(p_file);
        if (file_length != packet_end)
        {
            file_complete = false;
        }
        else
        {
            /* if end of file, break loop and complete program */
            file_complete = true;
        }
    }
    
FINISH_PROGRAM:
    /* close files */
    fclose(p_file);
    fclose(p_out_file);
}

/*** end of file ***/ 