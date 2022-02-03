#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  string tabel[7][4] = {
      {"person", "present", "past", "future"},
      {"1st", "o", "ei", "ai"},
      {"2nd", "os", "es", "ais"},
      {"3rd", "a", "e", "i"},
      {"4th", "om", "em", "aem"},
      {"5th", "ons", "est", "aist"},
      {"6th", "am", "im", "aim"}};

  string verb;
  string tense;
  string person;
  string word, suffix, prefix;
  bool wasFound;

  // input file
  fstream fin;
  fin.open("verb.in", ios::in);

  // output file
  fstream fout;
  fout.open("verb.out", ios::out);

  while (!fin.eof())
  {
    fin >> word;
    fout << word << " - ";

    suffix = word.substr(word.length() - 4, 4); // stores the last 3 letters
    prefix = word.substr(0, word.length() - 4); // stores the remaining letters
    wasFound = false;

    for (int i = 0; i < 7; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        if (suffix == tabel[i][j])
        {
          verb = "verb " + prefix + "en, ";
          tense = tabel[0][j] + " tense, ";
          person = tabel[i][0] + " person";
          wasFound = true;
          break;
        }
      }
    }
    for (int i = 0; i < 7; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        if (!wasFound)
        {
          prefix = word.substr(0, word.length() - 3);
          suffix = word.substr(word.length() - 3, 3);
          if (suffix == tabel[i][j] && !wasFound)
          {
            verb = "verb " + prefix + "en, ";
            tense = tabel[0][j] + " tense, ";
            person = tabel[i][0] + " person";
            wasFound = true;
            break;
          }
        }
      }
    }
    for (int i = 0; i < 7; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        if (!wasFound)
        {
          prefix = word.substr(0, word.length() - 2);
          suffix = word.substr(word.length() - 2, 2);
          if (suffix == tabel[i][j] && !wasFound)
          {
            verb = "verb " + prefix + "en, ";
            tense = tabel[0][j] + " tense, ";
            person = tabel[i][0] + " person";
            wasFound = true;
            break;
          }
        }
      }
    }
    for (int i = 0; i < 7; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        if (!wasFound)
        {
          prefix = word.substr(0, word.length() - 1);
          suffix = word.substr(word.length() - 1, 1);
          if (suffix == tabel[i][j] && !wasFound)
          {
            verb = "verb " + prefix + "en, ";
            tense = tabel[0][j] + " tense, ";
            person = tabel[i][0] + " person";
            wasFound = true;
            break;
          }
        }
      }
    }

    if (!wasFound)
    {
      verb = "not a verb case";
      tense = "";
      person = "";
    }
    fout << verb << tense << person << "\n";
  }

  fin.close();
  fout.close();
  return 0;
}
