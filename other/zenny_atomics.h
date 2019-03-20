//
//  zenny_atomics.h
//  ZennyAtomics
//
//  Created by Zenny Chen on 2019/2/4.
//  Copyright © 2019 Zenny Chen. All rights reserved.
//

#ifndef zenny_atomics_h
#define zenny_atomics_h

#include <stdint.h>
#include <stdbool.h>
#include <stdalign.h>

/** Common Atomic Type */
struct ZennyAtomicType
{
    intmax_t alignas(sizeof(intmax_t[2])) values[2];
};

// MARK: Initialization

/**
 * Initialize an atomic int8_t object
 * @param atomic pointer to an atomic int8_t object
 * @param value the initial value assigned to `atomic`
 */
extern void ZennyAtomicInitByte(volatile struct ZennyAtomicType *atomic, int8_t value);

/**
 * Initialize an atomic int object
 * @param atomic pointer to an atomic int object
 * @param value the initial value assigned to `atomic`
 */
extern void ZennyAtomicInitInt(volatile struct ZennyAtomicType *atomic, int value);

/**
 * Initialize atomic long object
 * @param atomic pointer to an atomic int64_t object
 * @param value the initial value assigned to `atomic`
 */
extern void ZennyAtomicInitLong(volatile struct ZennyAtomicType *atomic, int64_t value);

/**
* Initialize atomic pointer object
* @param atomic pointer to an atomic intptr_t object
* @param value the initial value assigned to `atomic`
*/
extern void ZennyAtomicInitPtr(volatile struct ZennyAtomicType *atomic, intptr_t value);

/**
 * Initialize an atomic flag object
 * @param atomic pointer to an atomic flag object
 */
extern void ZennyAtomicInitFlag(volatile struct ZennyAtomicType *atomic);

// MARK: Load

/**
 * Load an atomic int8_t object
 * @param atomic pointer to an atomic int8_t object
 * @return the value of the atomic object
 */
extern int8_t ZennyAtomicLoadByte(volatile struct ZennyAtomicType *atomic);

/**
 * Load an atomic int object
 * @param atomic pointer to an atomic int object
 * @return the value of the atomic object
 */
extern int ZennyAtomicLoadInt(volatile struct ZennyAtomicType *atomic);

/**
 * Load an atomic long object
 * @param atomic pointer to an atomic long object
 * @return the value of the atomic object
 */
extern int64_t ZennyAtomicLoadLong(volatile struct ZennyAtomicType* atomic);

/**
* Load an atomic pointer object
* @param atomic pointer to an atomic intptr_t object
* @return the value of the atomic object
*/
extern intptr_t ZennyAtomicLoadPtr(volatile struct ZennyAtomicType* atomic);

// MARK: Flag atomic operations

/**
 * Load an atomic flag object
 * @param atomic pointer to an atomic flag object
 * @return the value of the atomic object
 */
extern bool ZennyAtomicLoadFlag(volatile struct ZennyAtomicType *atomic);

/**
 * Perform test and set atomic operation.
 * @param atomic pointer to an atomic flag object
 * @return If the flag was set before the call, return true; Otherwise return false.
 */
extern bool ZennyAtomicTestAndSetFlag(volatile struct ZennyAtomicType *atomic);

/**
 * Clear the atomic flag
 * @param atomic pointer to an atomic flag object
 */
extern void ZennyAtomicClearFlag(volatile struct ZennyAtomicType *atomic);

// MARK: Store

/**
 * Store a value to an atomic int8_t object
 * @param atomic pointer to an atomic int8_t object
 * @param value the value to be stored
 */
extern void ZennyAtomicStoreByte(volatile struct ZennyAtomicType *atomic, int8_t value);

/**
 * Store a value to an atomic int object
 * @param atomic pointer to an atomic int object
 * @param value the value to be stored
 */
extern void ZennyAtomicStoreInt(volatile struct ZennyAtomicType *atomic, int value);

/**
 * Store a value to an atomic int64_t object
 * @param atomic pointer to an atomic int64_t object
 * @param value the value to be stored
 */
extern void ZennyAtomicStoreLong(volatile struct ZennyAtomicType *atomic, int64_t value);

/**
* Store a value to an atomic pointer object
* @param atomic pointer to an atomic intptr_t object
* @param value the value to be stored
*/
extern void ZennyAtomicStorePtr(volatile struct ZennyAtomicType *atomic, intptr_t value);

// MARK: Add

/**
 * Add a value to an atomic int8_t object
 * @param atomic pointer to an atomic int8_t object
 * @param value the value to be added
 * @return the value of the atomic object just before the addition
 */
extern int8_t ZennyAtomicAddByte(volatile struct ZennyAtomicType *atomic, int8_t value);

/**
 * Add a value to an atomic int object
 * @param atomic pointer to an atomic int object
 * @param value the value to be added
 * @return the value of the atomic object just before the addition
 */
extern int ZennyAtomicAddInt(volatile struct ZennyAtomicType *atomic, int value);

/**
 * Add a value to an atomic int64_t object
 * @param atomic pointer to an atomic int64_t object
 * @param value the value to be added
 * @return the value of the atomic object just before the addition
 */
extern int64_t ZennyAtomicAddLong(volatile struct ZennyAtomicType *atomic, int64_t value);

/**
* Add a value to an atomic pointer object
* @param atomic pointer to an atomic intptr_t object
* @param value the value to be added
* @return the value of the atomic object just before the addition
*/
extern intptr_t ZennyAtomicAddPtr(volatile struct ZennyAtomicType *atomic, intptr_t value);

// MARK: Subtract

/**
 * Subtract a value from an atomic int8_t object
 * @param atomic pointer to an atomic int8_t object
 * @param value the value to be subtracted
 * @return the value of the atomic object just before the subtraction
 */
extern int8_t ZennyAtomicSubByte(volatile struct ZennyAtomicType *atomic, int8_t value);

/**
 * Subtract a value to an atomic int object
 * @param atomic pointer to an atomic int object
 * @param value the value to be subtracted
 * @return the value of the atomic object just before the subtraction
 */
extern int ZennyAtomicSubInt(volatile struct ZennyAtomicType *atomic, int value);

/**
 * Subtract a value to an atomic int64_t object
 * @param atomic pointer to an atomic int64_t object
 * @param value the value to be subtracted
 * @return the value of the atomic object just before the subtraction
 */
extern int64_t ZennyAtomicSubLong(volatile struct ZennyAtomicType *atomic, int64_t value);

/**
* Subtract a value to an atomic pointer object
* @param atomic pointer to an atomic intptr_t object
* @param value the value to be subtracted
* @return the value of the atomic object just before the subtraction
*/
extern intptr_t ZennyAtomicSubPtr(volatile struct ZennyAtomicType *atomic, intptr_t value);

// MARK: bitwise OR

/**
 * Perform bitwise OR to an atomic int8_t object with a value
 * @param atomic pointer to an atomic int8_t object
 * @param value the value as a bitwise OR operand
 * @return the value of the atomic object just before the bitwise OR
 */
extern int8_t ZennyAtomicOrByte(volatile struct ZennyAtomicType *atomic, int8_t value);

/**
 * Perform bitwise OR to an atomic int object with a value
 * @param atomic pointer to an atomic int object
 * @param value the value as a bitwise OR operand
 * @return the value of the atomic object just before the bitwise OR
 */
extern int ZennyAtomicOrInt(volatile struct ZennyAtomicType *atomic, int value);

/**
 * Perform bitwise OR to an atomic int64_t object with a value
 * @param atomic pointer to an atomic int64_t object
 * @param value the value as a bitwise OR operand
 * @return the value of the atomic object just before the bitwise OR
 */
extern int64_t ZennyAtomicOrLong(volatile struct ZennyAtomicType *atomic, int64_t value);

/**
* Perform bitwise OR to an atomic pointer object with a value
* @param atomic pointer to an atomic intptr_t object
* @param value the value as a bitwise OR operand
* @return the value of the atomic object just before the bitwise OR
*/
extern intptr_t ZennyAtomicOrPtr(volatile struct ZennyAtomicType *atomic, intptr_t value);

// MARK: bitwise XOR

/**
 * Perform bitwise XOR to an atomic int8_t object with a value
 * @param atomic pointer to an atomic int8_t object
 * @param value the value as a bitwise XOR operand
 * @return the value of the atomic object just before the bitwise XOR
 */
extern int8_t ZennyAtomicXorByte(volatile struct ZennyAtomicType *atomic, int8_t value);

/**
 * Perform bitwise XOR to an atomic int object with a value
 * @param atomic pointer to an atomic int object
 * @param value the value as a bitwise XOR operand
 * @return the value of the atomic object just before the bitwise XOR
 */
extern int ZennyAtomicXorInt(volatile struct ZennyAtomicType *atomic, int value);

/**
 * Perform bitwise XOR to an atomic int64_t object with a value
 * @param atomic pointer to an atomic int64_t object
 * @param value the value as a bitwise XOR operand
 * @return the value of the atomic object just before the bitwise XOR
 */
extern int64_t ZennyAtomicXorLong(volatile struct ZennyAtomicType *atomic, int64_t value);

/**
* Perform bitwise XOR to an atomic pointer object with a value
* @param atomic pointer to an atomic intptr_t object
* @param value the value as a bitwise XOR operand
* @return the value of the atomic object just before the bitwise XOR
*/
extern intptr_t ZennyAtomicXorPtr(volatile struct ZennyAtomicType *atomic, intptr_t value);

// MARK: bitwise AND

/**
 * Perform bitwise AND to an atomic int8_t object with a value
 * @param atomic pointer to an atomic int8_t object
 * @param value the value as a bitwise AND operand
 * @return the value of the atomic object just before the bitwise AND
 */
extern int8_t ZennyAtomicAndByte(volatile struct ZennyAtomicType *atomic, int8_t value);

/**
 * Perform bitwise AND to an atomic int object with a value
 * @param atomic pointer to an atomic int object
 * @param value the value as a bitwise AND operand
 * @return the value of the atomic object just before the bitwise AND
 */
extern int ZennyAtomicAndInt(volatile struct ZennyAtomicType *atomic, int value);

/**
 * Perform bitwise AND to an atomic int64_t object with a value
 * @param atomic pointer to an atomic int64_t object
 * @param value the value as a bitwise AND operand
 * @return the value of the atomic object just before the bitwise AND
 */
extern int64_t ZennyAtomicAndLong(volatile struct ZennyAtomicType *atomic, int64_t value);

/**
* Perform bitwise AND to an atomic pointer object with a value
* @param atomic pointer to an atomic intptr_t object
* @param value the value as a bitwise AND operand
* @return the value of the atomic object just before the bitwise AND
*/
extern intptr_t ZennyAtomicAndPtr(volatile struct ZennyAtomicType *atomic, intptr_t value);

// MARK: Exchange

/**
 * Atomically store the specified value to the atomic object
 * and return the value of the atomic object just before the exchange operation.
 * @param atomic pointer to an atomic int8_t object
 * @param value the value used to exchange
 * @return the value of the atomic object just before the exchange operation
 */
extern int8_t ZennyAtomicExchangeByte(volatile struct ZennyAtomicType *atomic, int8_t value);

/**
 * Atomically store the specified value to the atomic object
 * and return the value of the atomic object just before the exchange operation.
 * @param atomic pointer to an atomic int object
 * @param value the value used to exchange
 * @return the value of the atomic object just before the exchange operation
 */
extern int ZennyAtomicExchangeInt(volatile struct ZennyAtomicType *atomic, int value);

/**
 * Atomically store the specified value to the atomic object
 * and return the value of the atomic object just before the exchange operation.
 * @param atomic pointer to an atomic int64_t object
 * @param value the value used to exchange
 * @return the value of the atomic object just before the exchange operation
 */
extern int64_t ZennyAtomicExchangeLong(volatile struct ZennyAtomicType *atomic, int64_t value);

/**
* Atomically store the specified value to the atomic object
* and return the value of the atomic object just before the exchange operation.
* @param atomic pointer to an atomic intptr_t object
* @param value the value used to exchange
* @return the value of the atomic object just before the exchange operation
*/
extern intptr_t ZennyAtomicExchangePtr(volatile struct ZennyAtomicType *atomic, intptr_t value);

// MARK: Compare and Exchange

/**
 * Compare the atomic object and the expected object.
 * If they are equal, store the desired value to the atomic object and return true;
 * Otherwise store the atomic object value to the expected object and return false.
 * @param atomic pointer to an atomic int8_t object
 * @param expected pointer to the expected object. It is commonly loaded from the atomic object.
 * @param desired the value to be stored to the atomic object
 * @return true, if the exchange happens; false otherwise.
 */
extern bool ZennyAtomicCompareExchangeByte(volatile struct ZennyAtomicType *atomic, int8_t *expected, int8_t desired);

/**
 * Compare the atomic object and the expected object.
 * If they are equal, store the desired value to the atomic object and return true;
 * Otherwise store the atomic object value to the expected object and return false.
 * @param atomic pointer to an atomic int object
 * @param expected pointer to the expected object. It is commonly loaded from the atomic object.
 * @param desired the value to be stored to the atomic object
 * @return true, if the exchange happens; false otherwise.
 */
extern bool ZennyAtomicCompareExchangeInt(volatile struct ZennyAtomicType *atomic, int *expected, int desired);

/**
 * Compare the atomic object and the expected object.
 * If they are equal, store the desired value to the atomic object and return true;
 * Otherwise store the atomic object value to the expected object and return false.
 * @param atomic pointer to an atomic int64_t object
 * @param expected pointer to the expected object. It is commonly loaded from the atomic object.
 * @param desired the value to be stored to the atomic object
 * @return true, if the exchange happens; false otherwise.
 */
extern bool ZennyAtomicCompareExchangeLong(volatile struct ZennyAtomicType *atomic, int64_t *expected, int64_t desired);

/**
* Compare the atomic object and the expected object.
* If they are equal, store the desired value to the atomic object and return true;
* Otherwise store the atomic object value to the expected object and return false.
* @param atomic pointer to an atomic intptr_t object
* @param expected pointer to the expected object. It is commonly loaded from the atomic object.
* @param desired the value to be stored to the atomic object
* @return true, if the exchange happens; false otherwise.
*/
extern bool ZennyAtomicCompareExchangePtr(volatile struct ZennyAtomicType *atomic, intptr_t *expected, intptr_t desired);

#endif /* zenny_atomics_h */

