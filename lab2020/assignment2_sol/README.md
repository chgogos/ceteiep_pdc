# OpenMP

* [Google advanced image search](https://www.google.com/advanced_image_search)
  * tiger.bmp  3200X2400

* [tiger.bmp (3200x2400 ~20MB)](./tiger.bmp)

    ```
    ##############################################
    CPU: Intel Core i7-7700K @ 4.2GHz  (4C/8T)
    RAM: 32GB DDR4
    ----------------------------------------------
    Windows 10
    ##############################################
    ```

## Εκτέλεση σειριακού κώδικα

    ```
    $ cd C1-imflip
    $ gcc imflip.c ImageStuff.c -o imflip
    $ imflip.exe tiger.bmp tigerH.bmp H  
    Input BMP File name:            tiger.bmp  (3200 x 2400)
    Output BMP File name:           tigerH.bmp  (3200 x 2400)
    Total execution time: 5566.0000 ms (724.740 ns per pixel)
    $ imflip.exe tiger.bmp tigerV.bmp V
    Input BMP File name:            tiger.bmp  (3200 x 2400)
    Output BMP File name:           tigerV.bmp  (3200 x 2400)
    Total execution time: 11823.0000 ms (1539.453 ns per pixel)
    ```

## Εκτέλεση παράλληλου κώδικα με pthreads 

    ```
    $ cd C2-imflipP
    $ gcc imflipP.c ImageStuff.c -o imflipP
    $ imflipP.exe tiger.bmp tigerH.bmp H 8
    Executing the multi-threaded version with 8 threads ...
    Input BMP File name:            tiger.bmp  (3200 x 2400)
    Output BMP File name:           tigerH.bmp  (3200 x 2400)
    Total execution time: 1638.9710 ms (Horizontal flip) (213.408 ns/pixel)
    $ imflipP.exe tiger.bmp tigerV.bmp V 8
    Executing the multi-threaded version with 8 threads ...
    Input BMP File name:            tiger.bmp  (3200 x 2400)
    Output BMP File name:           tigerV.bmp  (3200 x 2400)
    Total execution time: 3023.0000 ms (Vertical flip) (393.620 ns/pixel)
    ```

## Εκτέλεση κώδικα με OpenMP

    ```
    $ cd C2-imflipOMP
    $ gcc imflipOMP.c ImageStuff.c -o imflipOMP -fopenmp
    $ imflipOMP.exe tiger.bmp tigerH.bmp H 8
    Input BMP File name:            tiger.bmp  (3200 x 2400)
    Output BMP File name:           tigerH.bmp  (3200 x 2400)
    Total execution time: 1518.9998 ms (197.786 ns per pixel)
    $ imflipOMP.exe tiger.bmp tigerV.bmp V 8
    Input BMP File name:            tiger.bmp  (3200 x 2400)
    Output BMP File name:           tigerV.bmp  (3200 x 2400)
    Total execution time: 2809.0000 ms (365.755 ns per pixel)    
    ```

## Horizontal (χρόνος εκτέλεσης σε ms)

| Threads | Pthreads |  OpenMP  |
|:-------:|---------:|---------:|
|    1    |    5621.0|    5596.9|
|    2    |    3093.5|    2888.0|
|    3    |    2280.0|    2053.9|
|    4    |    2202.9|    1885.9|
|    5    |    2168.9|    2056.9|
|    6    |    1888.9|    1775.9|
|    7    |    1692.9|    1583.9|
|    8    |    1616.0|    1480.0|


## Vertical (χρόνος εκτέλεσης σε ms)

| Threads | Pthreads |  OpenMP  |
|:-------:|---------:|---------:|
|    1    |   11804.9|   11832.0|
|    2    |    6712.0|    6279.0|
|    3    |    4966.0|    4529.0|
|    4    |    4264.9|    4010.9|
|    5    |    3919.9|    3673.0|
|    6    |    3423.0|    3204.9|
|    7    |    3124.0|    3076.0|
|    8    |    3188.0|    3155.0|
