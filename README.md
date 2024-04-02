# Kernel to perform 1-D stencil of vector X place the result in vector Y

The program was run 30 times to get the average execution time for vector size n = 2<sup>20</sup>, 2<sup>24</sup>, and 2<sup>30</sup> of each kernel version. The average execution times are truncated to 4 decimal places.

## Performance of the Kernels in Debug Mode
1.) Set 'Solution Configurations' to 'Debug'

### Comparative execution time
C kernel  
| Vector size (n) | Average execution time (s) |
| --------------- | -------------------------- |
| 2<sup>20</sup>  | 0.0155                     |
| 2<sup>24</sup>  | 0.1004					   |
| 2<sup>30</sup>  | 6.7896                     |

x86-64 kernel  
| Vector size (n) | Average execution time (s) |
| --------------- | -------------------------- |
| 2<sup>20</sup>  | 0.0014                     |
| 2<sup>24</sup>  | 0.0147                  |
| 2<sup>30</sup>  | 1.0488                     |

## Performance of the Kernels in Release Mode
1.) Set 'Solution Configurations' to 'Release'

### Comparative execution time
C kernel
| Vector size (n) | Average execution time (s) |
| --------------- | -------------------------- |
| 2<sup>20</sup>  | 0.0030                     |
| 2<sup>24</sup>  | 0.0381                     |
| 2<sup>30</sup>  | 2.9050                     |

x86-64 kernel  
| Vector size (n) | Average execution time (s) |
| --------------- | -------------------------- |
| 2<sup>20</sup>  | 0.0016                     |
| 2<sup>24</sup>  | 0.0205                     |
| 2<sup>30</sup>  | 1.5228                     |

## Short analysis
The two tables outline the comparative performance between the two kernels, one implemented in C and the other in x86-64 assembly, across vector n = 2<sup>20</sup>, 2<sup>24</sup>, and 2<sup>30</sup>. In both kernels, as the vector size increases, the average execution time also increases. This is expected due to the larger amount of data being processed. The notable differences between the two kernels is how the C kernel exhibits higher execution times across all vector sizes, with a significant spike in execution time observed for vector size 2<sup>30</sup>. On the other hand, the x86-64 kernel demonstrates consistently lower execution times across all vector sizes, suggesting a better performance compared to the C kernel. Overall, the data highlights the superior performance of the x86-64 kernel in terms of average execution time, indicating its efficiency in processing larger datasets compared to the C implementation.  

## Screenshots of the program output with correctness check
Process: Y[i] = X[i-3] + X[i-2] + X[i-1] + X[i] + X[i+1] + X[i+2] + X[i+3] <br>
Y[0] = 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28 <br>
Y[1] = 2 + 3 + 4 + 5 + 6 + 7 + 8 = 35 <br> 
Y[2] = 3 + 4 + 5 + 6 + 7 + 8 + 9 = 42 <br>
Y[3] = 4 + 5 + 6 + 7 + 8 + 9 + 10 = 49 <br>
Output: 28, 35, 42, 49

### C kernel
Vector size n = 10  
![Alt text](https://i.imgur.com/lFBHSvN.png)

### x86-64 kernel
Vector size n = 10  
![Alt text](https://i.imgur.com/5lYwzsR.png)
