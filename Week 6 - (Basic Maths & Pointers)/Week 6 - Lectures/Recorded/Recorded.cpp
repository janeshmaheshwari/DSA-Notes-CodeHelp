#include <iostream>
#include<vector>
#include<math.h>
using namespace std;

bool isPrime(int x)
{
    if (x <= 1)
    {
        return false;
    }

    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x%i == 0)
        {
            return false;
        }
    }
    return true;
}

int CountPrimes(int n) //TO = O(n^2)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (isPrime(i))
        {
            count++ ;
        }
    }
    return count;
}

int CountPrimesArray(int n) //TO = O(n * log(log n))
{
    if (n <= 2)
    {
        return 0;
    }

    vector<bool> prime(n, true); // 0 to n-1 -> Total: n
    prime[0] = prime[1] = false;
    
    int count = 0;

    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            cout << "=> " << i << endl; //Showing Prime Numbers
            count++ ;

            int j = 2*i;
            while (j < n)
            {
                prime[j] = false;
                j+=i;
            }
        }
    }
    cout << "Total : ";
    return count;
}

int gcd(int A, int B)
{
    if (A == 0) return B;
    if (B == 0) return A;
    
    while (A > 0 && B > 0)
    {
        if (A > B)
        {
            A = A - B;
        }
        else
        {
            B = B - A;
        }
    }
    return A == 0 ? B : A;
}

int lcm(int A, int B)
{
    return (A * B) / gcd(A, B);
}

int slowExponential(int a, int b) //TO = O(b)
{
    int ans = 1;
    while (b)
    {
        ans *= a;
        b-- ;
    }
    return ans;
}

int fastExponential(int a, int b) //TO = O(log(b))
{
    int ans = 1;
    while (b)
    {
        if (b & 1) //Odd
        {
            ans = ans * a;
        }
        a = a*a;
        b = b>>1;
    }
    return ans;
}

long long int PowMod(long long int x, long long int n, long long int M)
{
    long long int ans = 1;
    while (n)
    {
        if (n&1)
        {
            ans = (ans * x) % M;
        }
        x = (x * x) % M;
        n = n >> 1;
    }
    return ans % M;
}

vector<bool> Sieve(int n)
{
    vector<bool>sieve(n + 1, true);
    sieve[0] = sieve[1] = false;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (sieve[i])
        {
            int j = i*i;

            while (j <= n)
            {
                sieve[j] = false;
                j += i;     
            }
        }
    }
    return sieve;
}

//int, double, char Array Max Size = 10^6
//bool Array size = 10^7
//Global -> int, double, char Array Max Size = 10^7
//Global -> bool Array Max Size = 10^8

vector<bool> segSieve(int L, int R)
{
    vector<bool> sieve = Sieve(sqrt(R));
    vector<int> basePrimes;

    for (int i = 0; i < sieve.size(); i++)
    {
        if (sieve[i])
        {
            basePrimes.push_back(i);
        }
    }
    
    vector<bool> segsieve(R - L + 1, true);
    
    if (L == 0)
    {
        segsieve[0] = false;
    }
    if (L <= 1 && R >= 1)
    {
        segsieve[1 - L] = false;
    }
    
    for (auto prime : basePrimes)
    {
        int first_multiple = (L / prime) * prime;
        if (first_multiple < L)
        {
            first_multiple += prime;
        }
        int j = max(first_multiple, prime*prime);
        while (j <= R)
        {
            segsieve[j - L] = false;
            j += prime;
        }
    }
    return segsieve;
}

int main()
{
    // cout << CountPrimes(12) << endl;
    // cout << CountPrimesArray(12) << endl;

    // cout << gcd(10, 15) << endl;
    // cout << lcm(10, 15) << endl;

    // cout << slowExponential(5, 3) << endl;
    // cout << fastExponential(5, 3) << endl;

    // cout << PowMod(10, 5, 7) << endl;

    // vector<bool> ans = Sieve(11);
    // for (int i = 0; i <= 11; i++)
    // {
    //     if (ans[i])
    //     {
    //         cout << "=> " << i << endl;
    //     }
    // }

    // vector<bool> ans = segSieve(110, 130);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     if (ans[i])
    //     {
    //         cout << "=> " << i + 110 << endl;
    //     }
    // }

    float arr[5] = {12.5, 10.0, 13.5, 90.5, 0.5};
    float *ptr1 = &arr[0];
    float *ptr2 = ptr1 + 3;
    cout << *ptr2 << " ";
    cout << ptr2 - ptr1;

    return 0;
}