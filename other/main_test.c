//
//  main.c
//  ZennyAtomics
//
//  Created by Zenny Chen on 2019/2/4.
//  Copyright © 2019 Zenny Chen. All rights reserved.
//

#include <stdio.h>
#include "zenny_atomics.h"

void main_test(void)
{
    // insert code here...
    
    printf("The size is: %zu\n", sizeof(struct ZennyAtomicType));
    
    struct ZennyAtomicType flag;
    ZennyAtomicInitFlag(&flag);
    printf("The init value is: %d\n", ZennyAtomicLoadFlag(&flag));
    printf("flag alignment is: %zu\n", alignof(flag));

    printf("flag value is: %d\n", ZennyAtomicTestAndSetFlag(&flag));
    printf("flag value is: %d\n", ZennyAtomicTestAndSetFlag(&flag));

    ZennyAtomicClearFlag(&flag);
    printf("flag value is: %d\n", ZennyAtomicTestAndSetFlag(&flag));
    
    puts("----------------");
    
    struct ZennyAtomicType atomicPtr;
    
    ZennyAtomicInitPtr(&atomicPtr, 100LL);
    printf("The init value is: %td\n", ZennyAtomicLoadPtr(&atomicPtr));
    ZennyAtomicStorePtr(&atomicPtr, 10000LL);
    printf("The stored value is: %td\n", ZennyAtomicLoadPtr(&atomicPtr));
    
    intptr_t oldValue = ZennyAtomicAddPtr(&atomicPtr, 5000LL);
    printf("The old value is: %td, the new value is: %td\n", oldValue, ZennyAtomicLoadPtr(&atomicPtr));
    
    puts("----------------");
    
    ZennyAtomicStorePtr(&atomicPtr, 0x0055);
    oldValue = ZennyAtomicXorPtr(&atomicPtr, 0x00aa);
    printf("The old value is: 0x%.4tX, the new value is: 0x%.4tX\n", oldValue, ZennyAtomicLoadPtr(&atomicPtr));

    puts("----------------");

    intptr_t value = ZennyAtomicExchangePtr(&atomicPtr, 1000);
    printf("old value is: %td, stored value is: %td\n", value, ZennyAtomicLoadPtr(&atomicPtr));

    puts("----------------");
    
    value = ZennyAtomicLoadPtr(&atomicPtr);
    if(ZennyAtomicCompareExchangePtr(&atomicPtr, &value, 50))
        puts("CAS succeeded!");
    
    value = 0;
    if(!ZennyAtomicCompareExchangePtr(&atomicPtr, &value, 10))
        printf("CAS failed! expected value is: %td\n", value);
    
    if(ZennyAtomicCompareExchangePtr(&atomicPtr, &value, 10))
        printf("CAS succeeded! value = %td, new value = %td\n", value, ZennyAtomicLoadPtr(&atomicPtr));
}

