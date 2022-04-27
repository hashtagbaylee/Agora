#!/bin/bash
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1
#SBATCH --time=60
#SBATCH -J Matrix
#SBATCH -o info_cpu.txt
#SBATCH -e error_cpu.txt

./matrix_cpu 5000 >./output_cpu.txt

exit 0