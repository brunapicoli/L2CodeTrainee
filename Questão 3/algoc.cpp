#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
  int constant;
  int count;
  int aux;
  bool isEven;

  // input file
  fstream fin;
  fin.open("algoc.in", ios::in);

  // output file
  fstream fout;
  fout.open("algoc.out", ios::out);

  while (!fin.eof())
  {
    fin >> constant;

    if (constant == 0)
    {
      break;
    }

    fout << "Constant " << constant << "\n";

    count = 0;
    if (constant > 0)
    {
      fout << "PLUSONE\n";
      count++;

      if (constant % 2 == 0)
      {
        while ((count * 2) < constant)
        {
          fout << "DUP\n";
          count = count * 2;
        }
        while (count < constant)
        {
          fout << "INC\n";
          count++;
        }
      }
      else
      {
        // checks if constant-1 is a power of 2
        if (((constant - 1) & (constant - 2)) == 0)
        {
          while ((count * 2) < constant)
          {
            fout << "DUP\n";
            count = count * 2;
          }
          fout << "INC\n";
          count++;
        }
        else
        {
          aux = (constant - 1) / 2;
          while ((count * 2) < aux)
          {
            fout << "DUP\n";
            count = count * 2;
          }
          while ((count + 1) <= aux)
          {
            fout << "INC\n";
            count++;
          }
          // when the counter reaches (constant-1)/2, just double and increment
          if (count == aux)
          {
            fout << "DUP\n";
            count = count * 2;
            fout << "INC\n";
            count++;
          }
        }
      }
    }

    else
    {
      fout << "MINUSONE\n";
      count--;

      if (constant % 2 == 0)
      {
        aux = (constant / 2) - 1;
        isEven = true;
      }
      else
      {
        aux = (constant - 1) / 2;
        isEven = false;
      }
      while ((count * 2) > constant)
      {
        fout << "DUP\n";
        count = count * 2;
      }
      while (count != constant)
      {
        if (count == aux)
        {
          if (isEven)
          {
            fout << "INC\n";
            count++;
            fout << "DUP\n";
            count = count * 2;
          }
          else
          {
            fout << "DUP\n";
            count = count * 2;
            fout << "INC\n";
            count++;
          }
        }
        else
        {
          fout << "INC\n";
          count++;
        }
      }
    }

    fout << "\n";
  }

  fin.close();
  fout.close();
  return 0;
}
