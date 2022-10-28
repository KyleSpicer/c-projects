#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

uint8_t * convert_string_to_hex_key(char * key)
{
    uint8_t buff[16];
    uint8_t hex_key[16];

    for(int idx = 0; idx < (strlen(key)); idx += 2)
    {
        hex_key[0] = *(key + idx);
        hex_key[1] = *(key + idx + 1);
        *(buff + (idx >> 1)) = strtol(hex_key, NULL, 16);
        printf("%x\n", *(buff + (idx >> 1)));
    }

    return * hex_key;
}


int
main()
{
    char * key = "df290c80bb7f9ecb08d4a6b3030951aa";

    uint8_t * hex_key = convert_string_to_hex_key(key);

    printf("%x\n", hex_key[0]);
  
}