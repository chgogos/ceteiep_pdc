# SIMD

## Παραδείγματα

* [simd4.cpp](./simd4.cpp)

```
$ g++ -mavx -o simd4 simd4.cpp
```

```
$ g++ -mavx2 -o simd4 simd4.cpp
```

```
$ objdump -d simd4 > simd4.asm
```