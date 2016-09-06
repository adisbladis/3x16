#include "x16.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "sha3/sph_blake.h"
#include "sha3/sph_bmw.h"
#include "sha3/sph_groestl.h"
#include "sha3/sph_jh.h"
#include "sha3/sph_keccak.h"
#include "sha3/sph_skein.h"
#include "sha3/sph_luffa.h"
#include "sha3/sph_cubehash.h"
#include "sha3/sph_shavite.h"
#include "sha3/sph_simd.h"
#include "sha3/sph_echo.h"
#include "sha3/sph_hamsi.h"
#include "sha3/sph_fugue.h"
#include "sha3/sph_shabal.h"
#include "sha3/sph_whirlpool.h"
#include "sha3/sph_sha2.h"

void x16_hash(const char* input, char* output)
{
    sph_blake512_context     ctx_blake;
    sph_bmw512_context       ctx_bmw;
    sph_groestl512_context   ctx_groestl;
    sph_skein512_context     ctx_skein;
    sph_jh512_context        ctx_jh;
    sph_keccak512_context    ctx_keccak;
    sph_luffa512_context	ctx_luffa1;
    sph_cubehash512_context	ctx_cubehash1;
    sph_shavite512_context	ctx_shavite1;
    sph_simd512_context		ctx_simd1;
    sph_echo512_context		ctx_echo1;
    sph_hamsi512_context	ctx_hamsi1;
    sph_fugue512_context	ctx_fugue1;
	sph_shabal512_context   ctx_shabal1;
    sph_whirlpool_context   ctx_whirlpool1;
    sph_sha512_context      ctx_sha2;

    //these uint512 in the c++ source of the client are backed by an array of uint32
    uint32_t hash0[16], hash1[16], hash2[16], hash3[16],
    hash4[16], hash5[16], hash6[16], hash7[16],
    hash8[16], hash9[16], hashA[16], hashB[16],
    hashC[16], hashD[16], hashE[16], hashF[16];
    uint32_t hash[256];

    sph_blake512_init(&ctx_blake);
    sph_blake512 (&ctx_blake, input, 1024);
    sph_blake512_close (&ctx_blake, hash0);

    sph_bmw512_init(&ctx_bmw);
    sph_bmw512 (&ctx_bmw, input, 1024);
    sph_bmw512_close(&ctx_bmw, hash1);

    sph_groestl512_init(&ctx_groestl);
    sph_groestl512 (&ctx_groestl, input, 1024);
    sph_groestl512_close(&ctx_groestl, hash2);

    sph_skein512_init(&ctx_skein);
    sph_skein512 (&ctx_skein, input, 1024);
    sph_skein512_close (&ctx_skein, hash3);

    sph_jh512_init(&ctx_jh);
    sph_jh512 (&ctx_jh, input, 1024);
    sph_jh512_close(&ctx_jh, hash4);

    sph_keccak512_init(&ctx_keccak);
    sph_keccak512 (&ctx_keccak, input, 1024);
    sph_keccak512_close(&ctx_keccak, hash5);
	
    sph_luffa512_init (&ctx_luffa1);
    sph_luffa512 (&ctx_luffa1, input, 1024);
    sph_luffa512_close (&ctx_luffa1, hash6);	
	
    sph_cubehash512_init (&ctx_cubehash1); 
    sph_cubehash512 (&ctx_cubehash1, input, 1024);   
    sph_cubehash512_close(&ctx_cubehash1, hash7);  
	
    sph_shavite512_init (&ctx_shavite1);
    sph_shavite512 (&ctx_shavite1, input, 1024);   
    sph_shavite512_close(&ctx_shavite1, hash8);  
	
    sph_simd512_init (&ctx_simd1); 
    sph_simd512 (&ctx_simd1, input, 1024);   
    sph_simd512_close(&ctx_simd1, hash9); 
	
    sph_echo512_init (&ctx_echo1); 
    sph_echo512 (&ctx_echo1, input, 1024);   
    sph_echo512_close(&ctx_echo1, hashA); 

    sph_hamsi512_init (&ctx_hamsi1);
    sph_hamsi512 (&ctx_hamsi1, input, 1024);
    sph_hamsi512_close(&ctx_hamsi1, hashB);

    sph_fugue512_init (&ctx_fugue1);
    sph_fugue512 (&ctx_fugue1, input, 1024);
    sph_fugue512_close(&ctx_fugue1, hashC);

    sph_shabal512_init (&ctx_shabal1);
    sph_shabal512 (&ctx_shabal1, input, 1024);
    sph_shabal512_close(&ctx_shabal1, hashD);

    sph_whirlpool_init (&ctx_whirlpool1);
    sph_whirlpool (&ctx_whirlpool1, input, 1024);
    sph_whirlpool_close(&ctx_whirlpool1, hashE);

    sph_sha512_init (&ctx_shabal1);
    sph_sha512 (&ctx_shabal1, input, 1024);
    sph_sha512_close(&ctx_shabal1, hashF);

    for (int i = 0; i < 16; i += 1){
    	hash[16*i+0] = hash0[i]; hash[16*i+1] = hash1[i]; hash[16*i+2] = hash2[i]; hash[16*i+3] = hash3[i];
    	hash[16*i+4] = hash4[i]; hash[16*i+5] = hash5[i]; hash[16*i+6] = hash6[i]; hash[16*i+7] = hash7[i];
    	hash[16*i+8] = hash8[i]; hash[16*i+9] = hash9[i]; hash[16*i+10] = hashA[i]; hash[16*i+11] = hashB[i];
    	hash[16*i+12] = hashC[i]; hash[16*i+13] = hashD[i]; hash[16*i+14] = hashE[i]; hash[16*i+15] = hashF[i];
    }

    memcpy(output, hash, 1024);
	
}