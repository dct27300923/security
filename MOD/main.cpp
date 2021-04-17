#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>
#include <chrono>
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int randPrime(int n)
{

	int a = rand();
	while (gcd(a, n) != 1)
	{
		a = rand();
	}
	return a;
}
long long pow(long long k, int x, int N) {
	if (x == 0) return 1;
	if (x == 1) return k;
	if (x % 2 == 1) return (k * pow(k*k % N, x / 2, N)) % N;
	if (x % 2 == 0) return pow(k*k %N, x / 2, N) % N;
}
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	srand(time(NULL));
	int N;
	int rangeMax = 99999;
	int rangeMin = 10000;
	std::ofstream output("./test_6.txt");
	clock_t start, end;
	for (int i = 0; i < 100; i++)
	{
		N = (int)(((double)((rand() << 15) | rand())) / (((RAND_MAX << 15) | RAND_MAX) + 1) * (rangeMax - rangeMin) + rangeMin);

		int k = randPrime(N);

		int x = 1;
		std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
		for (long long result = k % N; result != 1; ++x)
		{
			result = pow(result, x, N);
		}
		std::chrono::duration<double> sec = std::chrono::system_clock::now() - start;
		std::cout << "<" << i << ">" << k << "^" << x << " mod " << N << " = 1 | time : " << sec.count() << "��\n";
		output << "<" << i << ">" << k << "^" << x << " mod " << N << " = 1 | time : " << sec.count() << "��\n";
	}

	return 0;
}
