#!/bin/bash
#SBATCH --nodes=1
#SBATCH --gres=gpu:1
#SBATCH --ntasks-per-node=1
#SBATCH --time=10
#SBATCH -J Matrix
#SBATCH -o info_gpu.txt
#SBATCH -e error_gpu.txt

module load cuda10.1/toolkit/10.1.243 

./matrix_gpu 5000 >./output_gpu.txt

exit 0