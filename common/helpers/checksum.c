#include "common/helpers/checksum.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common/kerl/hash.h"
#include "common/sign/v1/iss_kerl.h"
#include "common/trinary/trit_tryte.h"
#include "utils/export.h"

IOTA_EXPORT char* iota_checksum(const char* input, const size_t input_length,
                                const size_t checksum_length) {
  Kerl kerl;
  init_kerl(&kerl);

  if (checksum_length == 0) {
    return NULL;
  }

  trit_t trits_hash[HASH_LENGTH];
  trit_t* trits = calloc(sizeof(trit_t) * input_length * RADIX, sizeof(trit_t));
  if (!trits) {
    return NULL;
  }
  trytes_to_trits((tryte_t*)input, trits, input_length);
  kerl_hash(trits, input_length * RADIX, trits_hash, &kerl);
  free(trits);

  char* checksum_trytes =
      calloc(sizeof(tryte_t) * checksum_length, sizeof(tryte_t));
  if (!checksum_trytes) {
    return NULL;
  }
  trits_to_trytes((trit_t*)(&trits_hash[HASH_LENGTH - checksum_length * RADIX]),
                  (tryte_t*)checksum_trytes, checksum_length * RADIX);

  return checksum_trytes;
}

IOTA_EXPORT flex_trit_t* iota_flex_checksum(const flex_trit_t* flex_trits,
                                            const size_t num_trits,
                                            const size_t checksum_length) {
  Kerl kerl;
  init_kerl(&kerl);

  if (checksum_length == 0) {
    return NULL;
  }

  trit_t trits_hash[HASH_LENGTH];
  trit_t* trits = (trit_t*)calloc(sizeof(trit_t) * num_trits, sizeof(trit_t));
  if (!trits) {
    return NULL;
  }
  flex_trits_to_trits(trits, num_trits, flex_trits, num_trits, num_trits);
  kerl_hash(trits, num_trits, trits_hash, &kerl);
  free(trits);

  size_t flex_len = num_flex_trits_for_trits(num_trits);
  flex_trit_t* checksum_flex_trits =
      (flex_trit_t*)calloc(sizeof(flex_trit_t) * flex_len, sizeof(flex_trit_t));
  if (!checksum_flex_trits) {
    return NULL;
  }
  flex_trits_from_trits(checksum_flex_trits, HASH_LENGTH,
                        &trits_hash[HASH_LENGTH - checksum_length], HASH_LENGTH,
                        checksum_length);

  return checksum_flex_trits;
}
