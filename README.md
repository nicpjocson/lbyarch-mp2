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
### C kernel vs. x86-64 kernel
![Alt text](https://i.imgur.com/tW9s40V.png)
![Alt text](https://i.imgur.com/LsgvgpH.png)
![Alt text](https://i.imgur.com/6sLHPXN.png)