#ifndef TLS_CRYPTO_H
#define TLS_CRYPTO_H

#include <stdint.h>
#include <stddef.h>

/**
 * @brief Number of bytes/octets in an AES block.
 *
 * This reflects the 128bit block size definition.
 */
#define AES_BLOCKLEN 16

/**
 * @brief Decrypts a TLS AES encrypted message with a 16 byte key.
 *
 * The "message" is expected to be everything after the TLS header including
 * the opaque IV and opaque HMAC. Meaning the message will not be decrypted
 * unless the length is at least 48 bytes. (len(IV) + len(MAC) -> 16 + 32 -> 48)
 * The first 16 bytes of the message are assumed to be an opaque IV. The opaque IV,
 * the decrypted data, and the MAC are copied into the dest array. The "dest" needs
 * to be at least "length" bytes long.
 *
 * @param dest Pointer to the destination array where the decrypted message is to be copied.
 * @param message Pointer to the array to decrypt.
 * @param length Size in bytes of the message.
 * @param key Pointer to a 16 byte array containing the decryption key.
 *
 * @return NULL on fail, dest on success.
 */
uint8_t *decrypt_message(uint8_t *dest, const uint8_t *message, size_t length, const uint8_t *key);

/**
 * @brief Encrypts a message with an AES CBC cipher using a 16 byte key.
 *
 * The "message" is expected to be everything after the TLS header including
 * the opaque IV and opaque HMAC. Meaning the message will not be encrypted
 * unless the length is at least 48 bytes. (len(IV) + len(MAC) -> 16 + 32 -> 48)
 * The first 16 bytes of the message are assumed to be an opaque IV. The opaque IV,
 * the encrypted data, and the MAC are copied into the dest array. The "dest" needs
 * to be at least "length" bytes long.
 *
 * @param dest Pointer to the destination array where the encrypted message is to be copied.
 * @param message Pointer to the array to encrypt.
 * @param length Size in bytes of the message.
 * @param key Pointer to a 16 byte array containing the encryption key.
 *
 * @return NULL on fail, dest on success.
 */
uint8_t *encrypt_message(uint8_t *dest, const uint8_t *message, size_t length, const uint8_t *key);

/**
 * @brief Writes a SHA256 HMAC into the last 32 bytes of a message, using a 16 byte key.
 *
 * The "message" is expected to be everything after the TLS header including
 * the opaque IV and opaque HMAC. Meaning the message will not be encrypted
 * unless the length is at least 48 bytes. (len(IV) + len(MAC) -> 16 + 32 -> 48)
 * The first 16 bytes of the message are assumed to be an opaque IV. The opaque IV,
 * the encrypted data, and the MAC are copied into the dest array. The "dest" needs
 * to be at least "length" bytes long.
 *
 * @param dest Pointer to the destination array where the encrypted message is to be copied.
 * @param message Pointer to the array to encrypt.
 * @param length Size in bytes of the message.
 * @param key Pointer to a 16 byte array containing the encryption key.
 * @param seq_num The TLS sequence number as per RFC5246.
 * @param tls_type The type of the TLS packet, likely 17.
 * @param tls_version The TLS version, for TLS 1.2 it's 0x0303.
 *
 * @note The 16 byte key is automatically expanded to 32 bytes needed for the SHA256 HMAC.
 * @note The last 3 paramaters are needed as per RFC7366.
 *
 * @return NULL on fail, dest on success.
 */
uint8_t *hmac_message(uint8_t *dest, const uint8_t *message, size_t length, const uint8_t *key,
                uint64_t seq_num, uint8_t tls_type, uint16_t tls_version);

#endif
