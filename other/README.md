# Atomic-operations-for-C
Common Atomic operations for the C programming language

The modern C11 programming language has already supported atomic operations. However, the back-end or runtime of some compilers does not support C11 atomics yet. 

This project intends to introduce common atomic operations for the C Programming language. For instance, it can be used in **MSVC** which does not support C11 standard yet, **Clang with MS CodeGen** which does not support C11 atomics back-end and **Objective-C for Linux** which does not support the syntax of C11 atomics.

You may build the source code as a static library or dynamic shared library and import it into your project.
