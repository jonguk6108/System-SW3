//addr_decoder.h

#include <cstdint>

#define PAGE_SIZE 4096
#define ADDR_BITS 64
#define BYTE 8

typedef uint64_t ADDR;
typedef uint32_t OFFSET;

typedef struct addr_info {

    ADDR virtual_page_number;
    OFFSET offset;

}ADDR_INFO;

ADDR_INFO get_addr_info (ADDR input_addr);
ADDR get_addr (ADDR_INFO info);
void print_addr_info (ADDR_INFO info);
void print_addr_info (ADDR addr);
