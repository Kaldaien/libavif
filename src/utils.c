// Copyright 2019 Joe Drago. All rights reserved.
// SPDX-License-Identifier: BSD-2-Clause

#include "avif/internal.h"

#include <math.h>
#include <string.h>

float avifRoundf(float v)
{
    return floorf(v + 0.5f);
}

// Thanks, Rob Pike! https://commandcenter.blogspot.nl/2012/04/byte-order-fallacy.html

uint16_t avifHTONS(uint16_t s)
{
    uint8_t data[2];
    data[0] = (s >> 8) & 0xff;
    data[1] = (s >> 0) & 0xff;
    uint16_t result;
    memcpy(&result, data, sizeof(uint16_t));
    return result;
}

uint16_t avifNTOHS(uint16_t s)
{
    uint8_t data[2];
    memcpy(&data, &s, sizeof(data));

    return (uint16_t)((data[1] << 0)
                      | (data[0] << 8));
}

uint32_t avifHTONL(uint32_t l)
{
    uint8_t data[4];
    data[0] = (l >> 24) & 0xff;
    data[1] = (l >> 16) & 0xff;
    data[2] = (l >> 8) & 0xff;
    data[3] = (l >> 0) & 0xff;
    uint32_t result;
    memcpy(&result, data, sizeof(uint32_t));
    return result;
}

uint32_t avifNTOHL(uint32_t l)
{
    uint8_t data[4];
    memcpy(&data, &l, sizeof(data));

    return ((uint32_t)data[3] << 0)
           | ((uint32_t)data[2] << 8)
           | ((uint32_t)data[1] << 16)
           | ((uint32_t)data[0] << 24);
}

uint64_t avifHTON64(uint64_t l)
{
    uint8_t data[8];
    data[0] = (l >> 56) & 0xff;
    data[1] = (l >> 48) & 0xff;
    data[2] = (l >> 40) & 0xff;
    data[3] = (l >> 32) & 0xff;
    data[4] = (l >> 24) & 0xff;
    data[5] = (l >> 16) & 0xff;
    data[6] = (l >> 8) & 0xff;
    data[7] = (l >> 0) & 0xff;
    uint64_t result;
    memcpy(&result, data, sizeof(uint64_t));
    return result;
}

uint64_t avifNTOH64(uint64_t l)
{
    uint8_t data[8];
    memcpy(&data, &l, sizeof(data));

    return ((uint64_t)data[7] << 0)
           | ((uint64_t)data[6] << 8)
           | ((uint64_t)data[5] << 16)
           | ((uint64_t)data[4] << 24)
           | ((uint64_t)data[3] << 32)
           | ((uint64_t)data[2] << 40)
           | ((uint64_t)data[1] << 48)
           | ((uint64_t)data[0] << 56);
}
