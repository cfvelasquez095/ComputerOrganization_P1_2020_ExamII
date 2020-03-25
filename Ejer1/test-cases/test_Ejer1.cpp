#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "VEjer1_AsyncROM.h"
#include "VEjer1_Ejer1.h"
#include "VEjer1.h"
#include  "signals.h"

static inline uint64_t join(uint8_t vb, uint32_t tag, uint32_t word)
{
    return ((static_cast<uint64_t>(vb) << 52)
            | (static_cast<uint64_t>(tag) << 32)
            | (static_cast<uint64_t>(word)));
}

static inline uint32_t makeAddress(uint32_t tag, uint32_t index)
{
    return ((tag << 12) | (index << 2));
}

struct Data {
    uint32_t tag;
    uint32_t index;
    uint32_t word_data;
};

static Data cache_data[] = {
    { 0xaa, 8, 0xdeadbeef },
    { 0xbb, 32, 0x11223344 },
    { 0xcc, 257, 0xaabbccdd },
};
int cache_data_size = sizeof(cache_data)/sizeof(cache_data[0]);

void initCacheMem(VEjer1& m, int size) 
{
    for (int i = 0; i < size; i++) {
        m.Ejer1->cache_mem->memory[i] = 0;
    }
    for (int i = 0; i < cache_data_size; i++) {
        m.Ejer1->cache_mem->memory[cache_data[i].index] = join(1, cache_data[i].tag, cache_data[i].word_data);
    }
}

TEST_CASE("Cache controller test") {
    VEjer1 m;
    
    initCacheMem(m, 1024);
    m.eval();

    for (int i = 0; i < cache_data_size; i++) {
        m.ADDR_PORT = makeAddress(cache_data[i].tag, cache_data[i].index);
        m.eval();
        REQUIRE(m.HIT_PORT == true);
        REQUIRE(m.DATA_PORT == cache_data[i].word_data);
    }
    m.ADDR_PORT = makeAddress(0xfcad, 513);
    m.eval();
    REQUIRE(m.HIT_PORT == false);
}
