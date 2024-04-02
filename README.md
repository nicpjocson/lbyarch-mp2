# Kernel to perform 1-D stencil of vector X place the result in vector Y
1.) Add NASM to PATH environment variable  
2.) Set 'Solution Platforms' to 'x64'  
  
The program was run 30 times to get the average execution time for vector size n = 2<sup>20</sup>, 2<sup>24</sup>, and 2<sup>30</sup> of each kernel version. The average execution times are truncated to 4 decimal places.

## Performance of the Kernels in Debug Mode
1.) Set 'Solution Configurations' to 'Debug'

### Comparative execution time
C kernel  
| Vector size (n) | Average execution time (s) |
| --------------- | -------------------------- |
| 2<sup>20</sup>  | 0.0155                     |
| 2<sup>24</sup>  | 0.2459                     |
| 2<sup>30</sup>  | 15.8285                    |

x86-64 kernel  
| Vector size (n) | Average execution time (s) |
| --------------- | -------------------------- |
| 2<sup>20</sup>  | 0.0014                     |
| 2<sup>24</sup>  | 0.0201                     |
| 2<sup>30</sup>  | 1.9187                     | 

### Short analysis
The x86-64 kernel observed an execution time approximately 10x lesser than the C kernel, suggesting a faster execution time.

## Performance of the Kernels in Release Mode
1.) Set 'Solution Configurations' to 'Release'

### Comparative execution time
C kernel  
| Vector size (n) | Average execution time (s) |
| --------------- | -------------------------- |
| 2<sup>20</sup>  | 0.0155                     |
| 2<sup>24</sup>  | 0.2459                     |
| 2<sup>30</sup>  | 15.8285                    |

x86-64 kernel  
| Vector size (n) | Average execution time (s) |
| --------------- | -------------------------- |
| 2<sup>20</sup>  | 0.0014                     |
| 2<sup>24</sup>  | 0.0201                     |
| 2<sup>30</sup>  | 1.9187                     | 

### Short analysis
The x86-64 kernel observed an execution time approximately 10x lesser than the C kernel, suggesting a faster execution time.  

## Screenshots of the program output with correctness check
Process: Y[i] = X[i-3] + X[i-2] + X[i-1] + X[i] + X[i+1] + X[i+2] + X[i+3] <br>
Y[0] = 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28 <br>
Y[1] = 2 + 3 + 4 + 5 + 6 + 7 + 8 = 35 <br> 
Y[2] = 3 + 4 + 5 + 6 + 7 + 8 + 9 = 42 <br>
Y[3] = 4 + 5 + 6 + 7 + 8 + 9 + 10 = 49 <br>
Output: 28, 35, 42, 49

### C kernel
Vector size n = 10  
![Alt text](https://imgur.com/i8Bc54y)

### x86-64 kernel
Vector size n = 10  
![Alt text](https://imgur.com/5lYwzsR)
