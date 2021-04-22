# Δεύτερη εργασία (OpenMP)

[Εκφώνηση εργασίας](./heat_equation.pdf) - παράδοση στο eclass μέχρι τις 16/5/2021

## Κώδικας

* [heat_serial.c](./heat_serial.c)
* [lodepng.h](./lodepng.h)
* [lodepng.c](./lodepng.c)
* [data_to_png.h](./data_to_png.h)
* [data_to_png.c](./data_to_png.c)
* [data_to_png_main.c](./data_to_png_main.c)

## Μεταγλώττιση και εκτέλεση του σειριακού κώδικα

```
$  gcc "‐Wl,‐‐stack,16777216" heat_serial.c -O3 ‐o heat_serial
$ ./heat_serial 0.0001 results.out
20 April 2021 02:24:02 PM

HEATED_PLATE
  C version
  A program to solve for the steady state temperature distribution
  over a rectangular plate.

  Spatial grid of 500 by 500 points.

  The iteration will be repeated until the change is <= 0.000010

  The steady state solution will be written to 'results.out'.

 Iteration  Change

         1  18.737475
         2  9.368737
         4  4.098823
         8  2.289577
        16  1.136604
        32  0.568201
        64  0.282805
       128  0.141777
       256  0.070808
       512  0.035427
      1024  0.017707
      2048  0.008856
      4096  0.004428
      8192  0.002210
     16384  0.001043
     32768  0.000371
     65536  0.000064

    102697  0.000010

  Error tolerance achieved.
  CPU time = 35.244000

  Solution written to the output file 'results.out'

HEATED_PLATE:
  Normal end of execution.

20 April 2021 02:24:37 PM
```

## Μετατροπή αποτελεσμάτων σε εικόνα

```
$  gcc data_to_png.c lodepng.c data_to_png_main.c -O3 -o data_to_png_main
$ ./data_to_png_main
```

![](./result.png)
