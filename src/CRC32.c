/**
 * @copyright manoel-serafim
 */

#include "types.h"


static const uint32_t POLY_CASTAGNOLI = 0xedb88320;

void CRC_32C(
    uint32_t* const crc,
    const uint8_t *message_p,
    const uint32_t message_lenght) //byte-lenght
{
    uint32_t itterator = message_lenght;
    //*crc = ~(*crc);

    //compute as much 32-bit words as possible
    uint8_t rest = (uint8_t)( message_lenght & (uint32_t)0xF );

    while(rest)
    {

        *crc ^= *message_p;

        crc = crc & 0x1 ? (crc >> 1) ^ POLY_CASTAGNOLI : crc >> 1;
        crc = crc & 1 ? (crc >> 1) ^ POLY_CASTAGNOLI : crc >> 1;
        crc = crc & 1 ? (crc >> 1) ^ POLY_CASTAGNOLI : crc >> 1;
        crc = crc & 1 ? (crc >> 1) ^ POLY_CASTAGNOLI : crc >> 1;
        crc = crc & 1 ? (crc >> 1) ^ POLY_CASTAGNOLI : crc >> 1;
        crc = crc & 1 ? (crc >> 1) ^ POLY_CASTAGNOLI : crc >> 1;
        crc = crc & 1 ? (crc >> 1) ^ POLY_CASTAGNOLI : crc >> 1;
        crc = crc & 1 ? (crc >> 1) ^ POLY_CASTAGNOLI : crc >> 1;
            
        ++message_p;
        --rest;
        --itterator;
    }
        
    itterator = itterator>>4;
    while (itterator) {
        *crc ^= *((uint32_t*)message_p);
        

        crc = crc & 1 ? (crc >> 1) ^ POLY_CASTAGNOLI : crc >> 1;
        crc = crc & 1 ? (crc >> 1) ^ POLY_CASTAGNOLI : crc >> 1;
        crc = crc & 1 ? (crc >> 1) ^ POLY_CASTAGNOLI : crc >> 1;
        crc = crc & 1 ? (crc >> 1) ^ POLY_CASTAGNOLI : crc >> 1;
        crc = crc & 1 ? (crc >> 1) ^ POLY_CASTAGNOLI : crc >> 1;
        crc = crc & 1 ? (crc >> 1) ^ POLY_CASTAGNOLI : crc >> 1;
        crc = crc & 1 ? (crc >> 1) ^ POLY_CASTAGNOLI : crc >> 1;
        crc = crc & 1 ? (crc >> 1) ^ POLY_CASTAGNOLI : crc >> 1;
        
        --itterator;
        ++message_p;
    }
    
    *crc = ~(*crc);
}