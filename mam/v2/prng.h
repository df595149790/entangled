/*
 * Copyright (c) 2018 IOTA Stiftung
 * https://github.com/iotaledger/entangled
 *
 * MAM is based on an original implementation & specification by apmi.bsu.by
 * [ITSec Lab]
 *
 * Refer to the LICENSE file for licensing information
 */

#ifndef __MAM_V2_PRNG_H__
#define __MAM_V2_PRNG_H__

#include "mam/v2/sponge.h"

// PRNG key size
#define MAM2_PRNG_KEY_SIZE 243
// PRNG key flex size
#define MAM2_PRNG_KEY_FLEX_SIZE FLEX_TRIT_SIZE_243

// PRNG AE destination tryte
#define MAM2_PRNG_DST_SEC_KEY 0
// PRNG WOTS destination tryte
#define MAM2_PRNG_DST_WOTS_KEY 1
// PRNG NTRU destination tryte
#define MAM2_PRNG_DST_NTRU_KEY 2

// PRNG interface
typedef struct prng_s {
  sponge_t *sponge;
  flex_trit_t key[MAM2_PRNG_KEY_FLEX_SIZE];
} prng_t;

/**
 * Initializes PRNG
 *
 * @param prng PRNG interface
 * @param sponge Sponge interface
 * @param key Key of size MAM2_PRNG_KEY_SIZE
 */
void prng_init(prng_t *const prng, sponge_t *const sponge,
               flex_trit_t const *const key);

/**
 * Resets PRNG
 *
 * @param prng PRNG interface
 */
void prng_reset(prng_t *const prng);

/**
 * Outputs pseudorandom trits with one input nonce
 *
 * @param prng PRNG interface
 * @param dest Destination tryte
 * @param nonce Nonce
 * @param output Pseudorandom trits
 */
void prng_gen(prng_t *const prng, uint8_t const dest,
              trit_array_t const *const nonce, trit_array_t *const output);

/**
 * Outputs pseudorandom trits with two input nonces
 *
 * @param prng PRNG interface
 * @param dest Destination tryte
 * @param nonce1 First nonce
 * @param nonce2 Second nonce
 * @param output Pseudorandom trits
 */
void prng_gen2(prng_t *const prng, uint8_t const dest,
               trit_array_t const *const nonce1,
               trit_array_t const *const nonce2, trit_array_t *const output);

/**
 * Outputs pseudorandom trits with three input nonces
 *
 * @param prng PRNG interface
 * @param dest Destination tryte
 * @param nonce1 First nonce
 * @param nonce2 Second nonce
 * @param nonce3 Third nonce
 * @param output Pseudorandom trits
 */
void prng_gen3(prng_t *const prng, uint8_t const dest,
               trit_array_t const *const nonce1,
               trit_array_t const *const nonce2,
               trit_array_t const *const nonce3, trit_array_t *const output);

#endif  // __MAM_V2_PRNG_H__
