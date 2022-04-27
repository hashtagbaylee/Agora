// Compile: g++ -o matrix_cpu matrix_cpu.cpp
// Run: ./matrix_cpu 5000


#include <iostream>
#include <cstdlib>
#include <chrono>
#include <ctime>

using namespace std;


void cpu_matrix_mult(int *a, int *b, int *c, int m, int n, int k) 
{
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < k; j++) 
        {
            int sum = 0;
            for (int h = 0; h < n; h++) 
            {
                sum += a[i * n + h] * b[h * k + j];
            }
            c[i * k + j] = sum;
        }
    }
}


int main(int argc, char *argv[])
{
    int m, n, k;
	
	m = atoi(argv[1]);
	n = k = m;
	
    srand(0);

    int *h_a, *h_b, *h_c;
	h_a = new int[m*n];
	h_b = new int[n*k];
	h_c = new int[m*k];

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            h_a[i * n + j] = rand() % 2;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            h_b[i * k + j] = rand() % 2;
        }
    }

	double cpu_time;
    std::chrono::time_point<std::chrono::system_clock> start, end;

    start = std::chrono::system_clock::now();
	
    cpu_matrix_mult(h_a, h_b, h_c, m, n, k);
	
    end = std::chrono::system_clock::now();
	
    std::chrono::duration<double> elapsed_seconds = end - start;
	cpu_time = elapsed_seconds.count();
    cout << "CPU Time: " << cpu_time << " seconds"<< endl;

    delete[] h_a;
    delete[] h_b;
    delete[] h_c;
    return 0;
}