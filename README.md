# LBYARCH x86-to-C interface programming project

1.) Add NASM to PATH environment variable
2.) Set 'Solution Platforms' to 'x64'

## Debug Mode
1.) Set 'Solution Configurations' to 'Debug'

## Release Mode
1.) Set 'Solution Configurations' to 'Release'

## Requirements
### Comparative execution time and short analysis of the performance of the kernels
#### Vector size n = 2<sup>20</sup>
C Average Execution Time: 0.0155 seconds  
x86-64 Average Execution Time: 0.0014 seconds

#### Vector size n = 2<sup>24</sup>
C Average Execution Time: 0.2459 seconds  
x86-64 Average Execution Time: 0.0201 seconds

#### Vector size n = 2<sup>30</sup>
C Average Execution Time: 15.8285 seconds  
x86-64 Average Execution Time: 1.9187 seconds  
  
* Note: average execution times are truncated to 4 decimal places

### Screenshot of the program output with the correctness check (C)
![Alt text](https://i.imgur.com/oMdVph0.jpeg)

### Screenshot of the program output, including the correctness check (x86-64)
![Alt text](https://i.imgur.com/oMdVph0.jpeg)