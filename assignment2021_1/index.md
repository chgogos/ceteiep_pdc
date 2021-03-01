# Πρώτη εργασία (pThreads)

[Εκφώνηση εργασίας](./mandelbrot.pdf)

## Κώδικας

* [lodepng.h](./lodepng.h)
* [lodepng.c](./lodepng.c)
* [timer.h](./timer.h)
* [mandelbrot_serial.c](./mandelbrot_serial.c)

## Μεταγλώττιση και εκτέλεση του σειριακού κώδικα

```
$  gcc mandelbrot_serial.c lodepng.c -O3 -std=gnu99 -lm -o mandelbrot_serial
$ ./mandelbrot_serial
```