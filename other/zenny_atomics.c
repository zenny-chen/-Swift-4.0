//
//  zenny_atomics.c
//  ZennyAtomics
//
//  Created by Zenny Chen on 2019/2/4.
//  Copyright © 2019 Zenny Chen. All rights reserved.
//

#include "zenny_atomics.h"

#ifdef _MSC_VER

#include <intrin.h>

// MARK: Initialization

void ZennyAtomicInitByte(volatile struct ZennyAtomicType *atomic, int8_t value)
{
    *(int8_t*)atomic = value;
}

void ZennyAtomicInitInt(volatile struct ZennyAtomicType *atomic, int value)
{
    *(int*)atomic = value;
}

void ZennyAtomicInitLong(volatile struct ZennyAtomicType *atomic, int64_t value)
{
    *(int64_t*)atomic = value;
}

void ZennyAtomicInitPtr(volatile struct ZennyAtomicType *atomic, intptr_t value)
{
    *(intptr_t*)atomic = value;
}

void ZennyAtomicInitFlag(volatile struct ZennyAtomicType *atomic)
{
    *(bool*)atomic = false;
}

// MARK: Load

int8_t ZennyAtomicLoadByte(volatile struct ZennyAtomicType *atomic)
{
    return *(int8_t*)atomic;
}

int ZennyAtomicLoadInt(volatile struct ZennyAtomicType *atomic)
{
    return *(int*)atomic;
}

int64_t ZennyAtomicLoadLong(volatile struct ZennyAtomicType* atomic)
{
    return *(int64_t*)atomic;
}

intptr_t ZennyAtomicLoadPtr(volatile struct ZennyAtomicType* atomic)
{
    return *(intptr_t*)atomic;
}

// MARK: Flag atomic operations

bool ZennyAtomicLoadFlag(volatile struct ZennyAtomicType *atomic)
{
    return *(bool*)atomic;
}

bool ZennyAtomicTestAndSetFlag(volatile struct ZennyAtomicType *atomic)
{
    return _interlockedbittestandset((long*)atomic, 1);
}

void ZennyAtomicClearFlag(volatile struct ZennyAtomicType *atomic)
{
    _InterlockedExchange8((char*)atomic, 0);
}

// MARK: Store

void ZennyAtomicStoreByte(volatile struct ZennyAtomicType *atomic, int8_t value)
{
    *(int8_t*)atomic = value;
}

void ZennyAtomicStoreInt(volatile struct ZennyAtomicType *atomic, int value)
{
    *(int*)atomic = value;
}

void ZennyAtomicStoreLong(volatile struct ZennyAtomicType *atomic, int64_t value)
{
    *(int64_t*)atomic = value;
}

void ZennyAtomicStorePtr(volatile struct ZennyAtomicType *atomic, intptr_t value)
{
    *(intptr_t*)atomic = value;
}

// MARK: Add

int8_t ZennyAtomicAddByte(volatile struct ZennyAtomicType *atomic, int8_t value)
{
    int8_t comparand;
    int8_t desired;
    bool successful;

    do
    {
        comparand = *(int8_t*)atomic;
        desired = comparand + value;
        const int8_t dstValue = _InterlockedCompareExchange8((volatile char*)atomic, desired, comparand);
        successful = dstValue == comparand;
        if (!successful)
            _mm_pause();
    } while (!successful);

    return comparand;
}

int ZennyAtomicAddInt(volatile struct ZennyAtomicType *atomic, int value)
{
    long comparand;
    long desired;
    bool successful;

    do
    {
        comparand = *(long*)atomic;
        desired = comparand + value;
        const long dstValue = _InterlockedCompareExchange((volatile long*)atomic, desired, comparand);
        successful = dstValue == comparand;
        if (!successful)
            _mm_pause();
    } while (!successful);

    return comparand;
}

int64_t ZennyAtomicAddLong(volatile struct ZennyAtomicType *atomic, int64_t value)
{
    int64_t comparand;
    int64_t desired;
    bool successful;

    do
    {
        comparand = *(int64_t*)atomic;
        desired = comparand + value;
        const int64_t dstValue = _InterlockedCompareExchange64((volatile int64_t*)atomic, desired, comparand);
        successful = dstValue == comparand;
        if (!successful)
            _mm_pause();
    } while (!successful);

    return comparand;
}

intptr_t ZennyAtomicAddPtr(volatile struct ZennyAtomicType *atomic, intptr_t value)
{
    intptr_t comparand;
    intptr_t desired;
    bool successful;

    do
    {
        comparand = *(intptr_t*)atomic;
        desired = comparand + value;
        const intptr_t dstValue = (intptr_t)_InterlockedCompareExchangePointer((void* volatile *)atomic, (void*)desired, (void*)comparand);
        successful = dstValue == comparand;
        if (!successful)
            _mm_pause();
    } while (!successful);

    return comparand;
}

// MARK: Subtract

int8_t ZennyAtomicSubByte(volatile struct ZennyAtomicType *atomic, int8_t value)
{
    int8_t comparand;
    int8_t desired;
    bool successful;

    do
    {
        comparand = *(int8_t*)atomic;
        desired = comparand - value;
        const int8_t dstValue = _InterlockedCompareExchange8((volatile char*)atomic, desired, comparand);
        successful = dstValue == comparand;
        if (!successful)
            _mm_pause();
    } while (!successful);

    return comparand;
}

int ZennyAtomicSubInt(volatile struct ZennyAtomicType *atomic, int value)
{
    long comparand;
    long desired;
    bool successful;

    do
    {
        comparand = *(long*)atomic;
        desired = comparand - value;
        const long dstValue = _InterlockedCompareExchange((volatile long*)atomic, desired, comparand);
        successful = dstValue == comparand;
        if (!successful)
            _mm_pause();
    } while (!successful);

    return comparand;
}

int64_t ZennyAtomicSubLong(volatile struct ZennyAtomicType *atomic, int64_t value)
{
    int64_t comparand;
    int64_t desired;
    bool successful;

    do
    {
        comparand = *(int64_t*)atomic;
        desired = comparand - value;
        const int64_t dstValue = _InterlockedCompareExchange64((volatile int64_t*)atomic, desired, comparand);
        successful = dstValue == comparand;
        if (!successful)
            _mm_pause();
    } while (!successful);

    return comparand;
}

intptr_t ZennyAtomicSubPtr(volatile struct ZennyAtomicType *atomic, intptr_t value)
{
    intptr_t comparand;
    intptr_t desired;
    bool successful;

    do
    {
        comparand = *(intptr_t*)atomic;
        desired = comparand - value;
        const intptr_t dstValue = (intptr_t)_InterlockedCompareExchangePointer((void* volatile *)atomic, (void*)desired, (void*)comparand);
        successful = dstValue == comparand;
        if (!successful)
            _mm_pause();
    } while (!successful);

    return comparand;
}

// MARK: Bitwise OR

int8_t ZennyAtomicOrByte(volatile struct ZennyAtomicType *atomic, int8_t value)
{
    return _InterlockedOr8((volatile char*)atomic, value);
}

int ZennyAtomicOrInt(volatile struct ZennyAtomicType *atomic, int value)
{
    return _InterlockedOr((volatile long*)atomic, value);
}

int64_t ZennyAtomicOrLong(volatile struct ZennyAtomicType *atomic, int64_t value)
{
    return _InterlockedOr64((volatile int64_t*)atomic, value);
}

intptr_t ZennyAtomicOrPtr(volatile struct ZennyAtomicType *atomic, intptr_t value)
{
    return sizeof(intptr_t) == 8 ? _InterlockedOr64((volatile int64_t*)atomic, value) : _InterlockedOr((volatile long*)atomic, value);
}

// MARK: Bitwise XOR

int8_t ZennyAtomicXorByte(volatile struct ZennyAtomicType *atomic, int8_t value)
{
    return _InterlockedXor8((volatile char*)atomic, value);
}

int ZennyAtomicXorInt(volatile struct ZennyAtomicType *atomic, int value)
{
    return _InterlockedXor((volatile long*)atomic, value);
}

int64_t ZennyAtomicXorLong(volatile struct ZennyAtomicType *atomic, int64_t value)
{
    return _InterlockedXor64((volatile int64_t*)atomic, value);
}

intptr_t ZennyAtomicXorPtr(volatile struct ZennyAtomicType *atomic, intptr_t value)
{
    return sizeof(intptr_t) == 8 ? _InterlockedXor64((volatile int64_t*)atomic, value) : _InterlockedXor((volatile long*)atomic, value);
}

// MARK: Bitwise And

int8_t ZennyAtomicAndByte(volatile struct ZennyAtomicType *atomic, int8_t value)
{
    return _InterlockedAnd8((volatile char*)atomic, value);
}

int ZennyAtomicAndInt(volatile struct ZennyAtomicType *atomic, int value)
{
    return _InterlockedAnd((volatile long*)atomic, value);
}

int64_t ZennyAtomicAndLong(volatile struct ZennyAtomicType *atomic, int64_t value)
{
    return _InterlockedAnd64((volatile int64_t*)atomic, value);
}

intptr_t ZennyAtomicAndPtr(volatile struct ZennyAtomicType *atomic, intptr_t value)
{
    return sizeof(intptr_t) == 8 ? _InterlockedAnd64((volatile int64_t*)atomic, value) : _InterlockedAnd((volatile long*)atomic, value);
}

// MARK: Exchange

int8_t ZennyAtomicExchangeByte(volatile struct ZennyAtomicType *atomic, int8_t value)
{
    return _InterlockedExchange8((volatile char*)atomic, value);
}

int ZennyAtomicExchangeInt(volatile struct ZennyAtomicType *atomic, int value)
{
    return _InterlockedExchange((volatile long*)atomic, value);
}

int64_t ZennyAtomicExchangeLong(volatile struct ZennyAtomicType *atomic, int64_t value)
{
    return _InterlockedExchange64((volatile int64_t*)atomic, value);
}

intptr_t ZennyAtomicExchangePtr(volatile struct ZennyAtomicType *atomic, intptr_t value)
{
    return (intptr_t)_InterlockedExchangePointer((void* volatile *)atomic, (void*)value);
}

// MARK: Compare and Exchange

bool ZennyAtomicCompareExchangeByte(volatile struct ZennyAtomicType *atomic, int8_t *expected, int8_t desired)
{
    const int8_t dstValue = _InterlockedCompareExchange8((volatile char*)atomic, desired, *expected);
    const bool successful = dstValue == *expected;
    if (!successful)
        *expected = dstValue;

    return successful;
}

bool ZennyAtomicCompareExchangeInt(volatile struct ZennyAtomicType *atomic, int *expected, int desired)
{
    const long dstValue = _InterlockedCompareExchange((volatile long*)atomic, desired, *expected);
    const bool successful = dstValue == *expected;
    if (!successful)
        *expected = dstValue;

    return successful;
}

bool ZennyAtomicCompareExchangeLong(volatile struct ZennyAtomicType *atomic, int64_t *expected, int64_t desired)
{
    const int64_t dstValue = _InterlockedCompareExchange64((volatile int64_t*)atomic, desired, *expected);
    const bool successful = dstValue == *expected;
    if (!successful)
        *expected = dstValue;

    return successful;
}

bool ZennyAtomicCompareExchangePtr(volatile struct ZennyAtomicType *atomic, intptr_t *expected, intptr_t desired)
{
    const intptr_t dstValue = (intptr_t)_InterlockedCompareExchangePointer((void* volatile *)atomic, (void*)desired, (void*)*expected);
    const bool successful = dstValue == *expected;
    if (!successful)
        *expected = dstValue;

    return successful;
}

#else

#include <stdatomic.h>

// MARK: Initialization

void ZennyAtomicInitByte(volatile struct ZennyAtomicType *atomic, int8_t value)
{
    atomic_init((atomic_schar*)atomic, value);
}

void ZennyAtomicInitInt(volatile struct ZennyAtomicType *atomic, int value)
{
    atomic_init((atomic_int*)atomic, value);
}

void ZennyAtomicInitLong(volatile struct ZennyAtomicType *atomic, int64_t value)
{
    atomic_init((atomic_llong*)atomic, value);
}

void ZennyAtomicInitPtr(volatile struct ZennyAtomicType *atomic, intptr_t value)
{
    atomic_init((atomic_intptr_t*)atomic, value);
}

void ZennyAtomicInitFlag(volatile struct ZennyAtomicType *atomic)
{
    *(atomic_flag*)atomic = (atomic_flag)ATOMIC_FLAG_INIT;
}

// MARK: Load

int8_t ZennyAtomicLoadByte(volatile struct ZennyAtomicType *atomic)
{
    return atomic_load((atomic_schar*)atomic);
}

int ZennyAtomicLoadInt(volatile struct ZennyAtomicType *atomic)
{
    return atomic_load((atomic_int*)atomic);
}

int64_t ZennyAtomicLoadLong(volatile struct ZennyAtomicType* atomic)
{
    return atomic_load((atomic_llong*)atomic);
}

intptr_t ZennyAtomicLoadPtr(volatile struct ZennyAtomicType* atomic)
{
    return atomic_load((atomic_intptr_t*)atomic);
}

// MARK: Flag atomic operations

bool ZennyAtomicLoadFlag(volatile struct ZennyAtomicType *atomic)
{
    return atomic_load(&((atomic_flag*)atomic)->_Value);
}

bool ZennyAtomicTestAndSetFlag(volatile struct ZennyAtomicType *atomic)
{
    return atomic_flag_test_and_set((atomic_flag*)atomic);
}

void ZennyAtomicClearFlag(volatile struct ZennyAtomicType *atomic)
{
    atomic_flag_clear((atomic_flag*)atomic);
}

// MARK: Store

void ZennyAtomicStoreByte(volatile struct ZennyAtomicType *atomic, int8_t value)
{
    atomic_store((atomic_schar*)atomic, value);
}

void ZennyAtomicStoreInt(volatile struct ZennyAtomicType *atomic, int value)
{
    atomic_store((atomic_int*)atomic, value);
}

void ZennyAtomicStoreLong(volatile struct ZennyAtomicType *atomic, int64_t value)
{
    atomic_store((atomic_llong*)atomic, value);
}

void ZennyAtomicStorePtr(volatile struct ZennyAtomicType *atomic, intptr_t value)
{
    atomic_store((atomic_intptr_t*)atomic, value);
}

// MARK: Add

int8_t ZennyAtomicAddByte(volatile struct ZennyAtomicType *atomic, int8_t value)
{
    return atomic_fetch_add((atomic_schar*)atomic, value);
}

int ZennyAtomicAddInt(volatile struct ZennyAtomicType *atomic, int value)
{
    return atomic_fetch_add((atomic_int*)atomic, value);
}

int64_t ZennyAtomicAddLong(volatile struct ZennyAtomicType *atomic, int64_t value)
{
    return atomic_fetch_add((atomic_llong*)atomic, value);
}

intptr_t ZennyAtomicAddPtr(volatile struct ZennyAtomicType *atomic, intptr_t value)
{
    return atomic_fetch_add((atomic_intptr_t*)atomic, value);
}

// MARK: Subtract

int8_t ZennyAtomicSubByte(volatile struct ZennyAtomicType *atomic, int8_t value)
{
    return atomic_fetch_sub((atomic_schar*)atomic, value);
}

int ZennyAtomicSubInt(volatile struct ZennyAtomicType *atomic, int value)
{
    return atomic_fetch_sub((atomic_int*)atomic, value);
}

int64_t ZennyAtomicSubLong(volatile struct ZennyAtomicType *atomic, int64_t value)
{
    return atomic_fetch_sub((atomic_llong*)atomic, value);
}

intptr_t ZennyAtomicSubPtr(volatile struct ZennyAtomicType *atomic, intptr_t value)
{
    return atomic_fetch_sub((atomic_intptr_t*)atomic, value);
}

// MARK: Bitwise OR

int8_t ZennyAtomicOrByte(volatile struct ZennyAtomicType *atomic, int8_t value)
{
    return atomic_fetch_or((atomic_schar*)atomic, value);
}

int ZennyAtomicOrInt(volatile struct ZennyAtomicType *atomic, int value)
{
    return atomic_fetch_or((atomic_int*)atomic, value);
}

int64_t ZennyAtomicOrLong(volatile struct ZennyAtomicType *atomic, int64_t value)
{
    return atomic_fetch_or((atomic_llong*)atomic, value);
}

intptr_t ZennyAtomicOrPtr(volatile struct ZennyAtomicType *atomic, intptr_t value)
{
    return atomic_fetch_or((atomic_intptr_t*)atomic, value);
}

// MARK: Bitwise XOR

int8_t ZennyAtomicXorByte(volatile struct ZennyAtomicType *atomic, int8_t value)
{
    return atomic_fetch_xor((atomic_schar*)atomic, value);
}

int ZennyAtomicXorInt(volatile struct ZennyAtomicType *atomic, int value)
{
    return atomic_fetch_xor((atomic_int*)atomic, value);
}

int64_t ZennyAtomicXorLong(volatile struct ZennyAtomicType *atomic, int64_t value)
{
    return atomic_fetch_xor((atomic_llong*)atomic, value);
}

intptr_t ZennyAtomicXorPtr(volatile struct ZennyAtomicType *atomic, intptr_t value)
{
    return atomic_fetch_xor((atomic_intptr_t*)atomic, value);
}

// MARK: Bitwise And

int8_t ZennyAtomicAndByte(volatile struct ZennyAtomicType *atomic, int8_t value)
{
    return atomic_fetch_and((atomic_schar*)atomic, value);
}

int ZennyAtomicAndInt(volatile struct ZennyAtomicType *atomic, int value)
{
    return atomic_fetch_and((atomic_int*)atomic, value);
}

int64_t ZennyAtomicAndLong(volatile struct ZennyAtomicType *atomic, int64_t value)
{
    return atomic_fetch_and((atomic_llong*)atomic, value);
}

intptr_t ZennyAtomicAndPtr(volatile struct ZennyAtomicType *atomic, intptr_t value)
{
    return atomic_fetch_and((atomic_intptr_t*)atomic, value);
}

// MARK: Exchange

int8_t ZennyAtomicExchangeByte(volatile struct ZennyAtomicType *atomic, int8_t value)
{
    return atomic_exchange((atomic_schar*)atomic, value);
}

int ZennyAtomicExchangeInt(volatile struct ZennyAtomicType *atomic, int value)
{
    return atomic_exchange((atomic_int*)atomic, value);
}

int64_t ZennyAtomicExchangeLong(volatile struct ZennyAtomicType *atomic, int64_t value)
{
    return atomic_exchange((atomic_llong*)atomic, value);
}

intptr_t ZennyAtomicExchangePtr(volatile struct ZennyAtomicType *atomic, intptr_t value)
{
    return atomic_exchange((atomic_intptr_t*)atomic, value);
}

// MARK: Compare and Exchange

bool ZennyAtomicCompareExchangeByte(volatile struct ZennyAtomicType *atomic, int8_t *expected, int8_t desired)
{
    return atomic_compare_exchange_strong((atomic_schar*)atomic, expected, desired);
}

bool ZennyAtomicCompareExchangeInt(volatile struct ZennyAtomicType *atomic, int *expected, int desired)
{
    return atomic_compare_exchange_strong((atomic_int*)atomic, expected, desired);
}

bool ZennyAtomicCompareExchangeLong(volatile struct ZennyAtomicType *atomic, int64_t *expected, int64_t desired)
{
    return atomic_compare_exchange_strong((atomic_llong*)atomic, expected, desired);
}

bool ZennyAtomicCompareExchangePtr(volatile struct ZennyAtomicType *atomic, intptr_t *expected, intptr_t desired)
{
    return atomic_compare_exchange_strong((atomic_intptr_t*)atomic, expected, desired);
}

#endif // _MSC_VER

