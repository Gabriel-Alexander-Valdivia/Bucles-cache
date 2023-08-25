#include <iostream>
#include <chrono>
#include <vector>
#include <unistd.h>
#define MAX 1000


using namespace std;

int main() {
    //double A[MAX][MAX], x[MAX], y[MAX];
    vector<vector<double>> A(MAX,vector<double>(MAX));
    vector<double>x(MAX);
    vector<double>y(MAX);

    /*Initialize values*/
    for(int i = 0; i < MAX; i++)
    {
        x[i]=1.0;
        y[i]=1.0;
        for(int j = 0; j < MAX; j++)
            A[i][j]=1.0;
    }

    /*First loop*/
    auto start = chrono::steady_clock::now();
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            y[i] += A[i][j]*x[j];
        }
    }
    auto end = chrono::steady_clock::now();

    cout << " (first loop): "<<chrono::duration_cast
            <chrono::nanoseconds>(end - start).count()
         << " ns" << endl;

    /*Re - Initialize values*/
    for(int i = 0; i < MAX; i++)
    {
        x[i]=1.0;
        y[i]=1.0;
        for(int j = 0; j < MAX; j++)
            A[i][j]=1.0;
    }

    /*Second loop*/
    start = chrono::steady_clock::now();

    for(int j = 0; j < MAX; j++)
    {
        for(int i = 0; i < MAX; i++)
        {
            y[i] += A[i][j]*x[j];
        }
    }

    end = chrono::steady_clock::now();
    cout << "(second loop): "<< chrono::duration_cast
            <chrono::nanoseconds>(end - start).count()
         << " ns" << endl;
}