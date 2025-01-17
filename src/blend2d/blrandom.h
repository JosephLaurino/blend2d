// [Blend2D]
// 2D Vector Graphics Powered by a JIT Compiler.
//
// [License]
// Zlib - See LICENSE.md file in the package.

#ifndef BLEND2D_BLRANDOM_H
#define BLEND2D_BLRANDOM_H

#include "./blapi.h"

//! \addtogroup blend2d_api_globals
//! \{

// ============================================================================
// [BLRandom]
// ============================================================================

//! Simple pseudo random number generator.
//!
//! The current implementation uses a PRNG called `XORSHIFT+`, which has 64-bit
//! seed, 128 bits of state, and full period `2^128 - 1`.
//!
//! Based on a paper by Sebastiano Vigna:
//!   http://vigna.di.unimi.it/ftp/papers/xorshiftplus.pdf
struct BLRandom {
  uint64_t data[2];

  // --------------------------------------------------------------------------
  #ifdef __cplusplus
  //! \name Construction & Destruction
  //! \{

  BL_INLINE BLRandom() noexcept = default;
  BL_INLINE BLRandom(const BLRandom&) noexcept = default;

  BL_INLINE explicit BLRandom(uint64_t seed) noexcept { reset(seed); }

  //! \}

  //! \name Overloaded Operators
  //! \{

  BL_INLINE bool operator==(const BLRandom& other) const noexcept { return  equals(other); }
  BL_INLINE bool operator!=(const BLRandom& other) const noexcept { return !equals(other); }

  //! \}

  //! \name Common Functionality
  //! \{

  //! Resets the random number generator to the given `seed`.
  BL_INLINE void reset(uint64_t seed = 0) noexcept { blRandomReset(this, seed); }

  //! Gets whether the random number generator is equivalent to `other`.
  BL_INLINE bool equals(const BLRandom& other) const noexcept {
    return blEquals(this->data[0], other.data[0]) &
           blEquals(this->data[1], other.data[1]);
  }

  //! \}

  //! \name Random Numbers
  //! \{

  //! Returns the next `uint64_t` value.
  BL_INLINE uint64_t nextUInt64() noexcept { return blRandomNextUInt64(this); }
  //! Returns the next `uint32_t` value.
  BL_INLINE uint32_t nextUInt32() noexcept { return blRandomNextUInt32(this); }
  //! Returns the next `double` precision floating point in [0..1) range.
  BL_INLINE double nextDouble() noexcept { return blRandomNextDouble(this); }

  //! \}
  #endif
  // --------------------------------------------------------------------------
};

//! \}

#endif // BLEND2D_BLRANDOM_H
