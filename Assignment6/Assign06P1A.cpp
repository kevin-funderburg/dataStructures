// A practice program for recursion: CS3358(Fall 2018) Assignment 6 Part 1A
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// prototype for LowIndexMinNeg (to be filled in - part of exercise)
int LowIndexMinNeg(const int arr[], int n);


void SeedRand();
int BoundedRandomInt(int lowerBound, int upperBound);
void ShowArray(const int a[], int size);
void DebugShowCase(int whichCase, int totalCasesToDo,
                   const int caseValues[], int caseSize);

int main()
{
   int testCasesToDo = 900000,
       testCasesDone = 0,
       loSize = 0,
       hiSize = 20,
       loValue = -9,
       hiValue = 9;
   int numInts,
       used,
       intCount,
       limnO2B,
       limn,
       newInt;
   int *intArr = 0;

   // SeedRand(); // disabled for reproducible result

   do
   {
      ++testCasesDone;
      limnO2B = -999;
      numInts = BoundedRandomInt(loSize, hiSize);
      if (numInts > 0) intArr = new int [numInts];
      used = 0;
      for (intCount = 0; intCount < numInts; ++intCount)
      {
         newInt = BoundedRandomInt(loValue, hiValue);
         if (newInt < 0)
            if (limnO2B == -999 || newInt < intArr[limnO2B])
               limnO2B = used;
         intArr[used++] = newInt;
      }

      limn = LowIndexMinNeg(intArr, used);

      if (limn != limnO2B)
      {
         cout << "Incorrect limn ..." << endl;
         cout << "test_case: " << testCasesDone << endl;
         cout << "array: ";
         ShowArray(intArr, used);
         cout << "limn expected: " << limnO2B << endl;
         cout << "limn returned: " << limn << endl;
         exit(EXIT_FAILURE);
      }

      if (testCasesDone < 10)
      {
         DebugShowCase(testCasesDone, testCasesToDo, intArr, used);
         cout << "limn_returned--> " << limn
              << " == " << limnO2B << " <--limn_ought2b" << endl;
      }
      else // uncomment next line to show array involved in every case
          DebugShowCase(testCasesDone, testCasesToDo, intArr, used);
      if (testCasesDone % 30000 == 0)
      {
         cout << "================================" << endl;
         clog << "testing case " << testCasesDone
              << " of " << testCasesToDo << endl;
         clog << "================================" << endl;
         cout << "array: ";
         ShowArray(intArr, used);
         cout << "limn returned: " << limn << "\tlimn ought2b: " << limnO2B << endl;
      }
      delete [] intArr;
      intArr = 0;
   }
   while (testCasesDone < testCasesToDo);
   cout << "================================" << endl;
   cout << "test program terminated normally" << endl;
   cout << "================================" << endl;

   return EXIT_SUCCESS;
}

/////////////////////////////////////////////////////////////////////
// Function to seed the random number generator
// PRE:  none
// POST: The random number generator has been seeded.
/////////////////////////////////////////////////////////////////////
void SeedRand()
{
   srand( (unsigned) time(NULL) );
}

/////////////////////////////////////////////////////////////////////
// Function to generate a random integer between
// lowerBound and upperBound (inclusive)
// PRE:  lowerBound is a positive integer.
//       upperBound is a positive integer.
//       upperBound is larger than lowerBound
//       The random number generator has been seeded.
// POST: A random integer between lowerBound and upperBound
//       has been returned.
/////////////////////////////////////////////////////////////////////
int BoundedRandomInt(int lowerBound, int upperBound)
{
   return ( rand() % (upperBound - lowerBound + 1) ) + lowerBound;
}

void ShowArray(const int a[], int size)
{
   for (int i = 0; i < size; ++i)
      cout << a[i] << "  ";
   cout << endl;
}

void DebugShowCase(int whichCase, int totalCasesToDo,
                   const int caseValues[], int caseSize)
{
   cout << "test case " << whichCase
        << " of " << totalCasesToDo << endl;
   cout << "array: ";
   ShowArray(caseValues, caseSize);
}
//  -2  -1  8  0  4  -6  2
// definition for LowIndexMinNeg (to be filled in - part of exercise)
int LowIndexMinNeg(const int arr[], int n) {

//    if (n == 1) {
//        if (arr[0] >= 0) {
//            return -999;
//        } else {
//            return 0;
//        }
//    }

    if (n < 1) return -999;

    if (n == 1)
    {
        cout << "n == 1\tarr[0]: "  << arr[0] << "\n";

        if (arr[0] < 0)
            return -999;
        else
            return -999 - (n + 1);
    }



    int min1 = LowIndexMinNeg(arr + 1, n - 1) + 1;
    int min2 = LowIndexMinNeg(arr - 1, n - 1);

    if (arr[0] < 0 && arr[0] <= arr[min1])
    {
        return 0;
    }
    else if (arr[0] < 0 && arr[0] < arr[min2])
    {
        return 0;
    }


//    cout << "arr[0]:\t" << arr[0] << "\t<=?\t\tarr[minIndexTheRest + 1]:\t" << arr[minIndexTheRest + 1]
//         << "\t\tminIndexTheRest: " << minIndexTheRest << "\tn: " << n << endl;
//
//
//    if (arr[0] < 0 && arr[0] <= arr[minIndexTheRest + 1]) {
//        return 0;
//    } else {
//        return 1 + minIndexTheRest;
//    }

}

//int LowIndexMinNeg(const int arr[], int n)
//{
////    for (int i = 0; i < n; ++i) {
////        cout << arr[i] << " ";
////    }
//    if (n == 0)
//        return -999;
//
//    if (n == 1) {
//        if(arr[0] >= 0)
//            return -999;
//        else
//            return 0;
//    }
//
////    if (n == 1)
////        return 0;
//
////    if (arr[n] >= 0)
////        int minIndexTheRest = LowIndexMinNeg(arr + 1, n - 1);
//
//    int minIndexTheRest = LowIndexMinNeg(arr + 1, n - 1);
//
////    if (arr[0] <= arr[minIndexTheRest + 1])
////        return 0;
////    else
////        return 1 + minIndexTheRest;
//
////    cout << "arr[0]: " << arr[0] << " : arr[minIndexTheRest + 1]: " << arr[minIndexTheRest + 1] << endl;
//
//    if (arr[0] <= arr[minIndexTheRest + 1])
//        return 0;
//    else
//        return 1 + minIndexTheRest;
//
//}