#include <iostream>
#include <fstream>

using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int a, b, t = 0;
    fstream in ("U1.txt");
    in >> a;
    int varztai[a];
    for(int i = 0; i < a; i++)
    {
        in >> varztai[i];
    }
    in >> b;
    int verzles[b];
    for(int i = 0; i < b; i++)
    {
        in >> verzles[i];
    }
    in.close();
    bubbleSort(varztai, a);
    bubbleSort(verzles, b);
    for(int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (varztai[i] == verzles[j])
            {
                varztai[i] = 0;
                verzles[j] = 0;
            }
        }
    }
    ofstream out ("U1rez.txt");
    out << "Reikalingi varztai: " << endl;
    for (int i = 1; i <= 20; i++)
    {
        int c = 0;
        for (int j = 0; j < b; j++)
        {
            if (i == verzles[j])
            {
                c++;
                t++;
            }
        }
        if (c !=0)
        {
            out << c << " " << i << endl;
        }
        else
        {
            continue;
        }
    }
    if (t == 0)
    {
        out << "Varztu nereikia" << endl;
    }
    t = 0;
    out << "Reikalingos verzles: " << endl;
    for (int i = 1; i <= 20; i++)
    {
        int c = 0;
        for (int j = 0; j < a; j++)
        {
            if (i == varztai[j])
            {
                c++;
                t++;
            }
        }
        if (c !=0)
        {
            out << c << " " << i << endl;
        }
        else
        {
            continue;
        }

    }
    if (t == 0)
    {
        out << "Verzliu nereikia";
    }
    return 0;
}
