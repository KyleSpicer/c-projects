/** @file check_reverse.c
 * 
 * @brief check_reverse.c is a unit testing program to test all functions that return something other than void.
 * 
 * @par COPYRIGHT NOTICE (c) 2022 Kyle Spicer.
 * 
 */

#include "../src/reverse.h"
#include <check.h>

/* verifies .pcap magic number is present */
START_TEST(test_invalid_file_type)
{
    file_header_t mock_file_header;
    mock_file_header.file_type_id = 0xd4c3b2a2;
    ck_assert(!verify_magic_number(&mock_file_header));

} END_TEST

/* verifies if .pcap magic number is not present, exits program properly */
START_TEST(test_valid_file_type)
{
    file_header_t mock_file_header;
    mock_file_header.file_type_id = 0xd4c3b2a1;
    ck_assert(verify_magic_number(&mock_file_header) == 0);

} END_TEST

START_TEST(test_invalid_payload_type)
{
    alien_pkt_hdr_t mock_alien_pkt_hdr;
    mock_alien_pkt_hdr.type = 5;
    ck_assert(decrypt_payload_type(mock_alien_pkt_hdr.type) == -1);
} END_TEST

START_TEST(test_valid_payload_type)
{
    alien_pkt_hdr_t mock_alien_pkt_hdr;
    mock_alien_pkt_hdr.type = 16;
    ck_assert(decrypt_payload_type(mock_alien_pkt_hdr.type) == 0);
} END_TEST

Suite * check_reverse(void)
{
    Suite * suite;
    TCase * tc_core;

    /* creates intitial suite */
    suite = suite_create("reverse_test");

    /* confirms successful creation/deletion of structures */
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_invalid_file_type);
    tcase_add_test(tc_core, test_valid_file_type);
    tcase_add_test(tc_core, test_invalid_payload_type);
    tcase_add_test(tc_core, test_valid_payload_type);

    suite_add_tcase(suite, tc_core);
    return suite;
}

int main()
{
    /* creating Suite*/
    Suite * suite = check_reverse();
    SRunner * runner = srunner_create(suite);

    /* prevents confusing valgrind errors from displaying */
    srunner_set_fork_status(runner, CK_NOFORK);
    
    /* actual Suite Runner execution with desired verbosity level */
    srunner_run_all(runner, CK_VERBOSE);
    
    /* extracts results for exit code handling */
    int no_failed = srunner_ntests_failed(runner);
    
    /* free memory */
    srunner_free(runner);
    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;

}

/*** end of file ***/