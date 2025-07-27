#include <bits/stdc++.h>

using namespace std;

struct Activity
{
  int id;
  int startTime;
  int endTime;
};

int maxActivitiesCount(Activity *A, int n);

bool compare(const Activity &x, const Activity &y)
{
  return x.endTime < y.endTime;
}

int main()
{
  int ST[] = {0, 1, 2, 3, 3, 5, 5, 6, 8, 8, 12},
      ET[] = {6, 4, 13, 5, 8, 7, 9, 10, 11, 12, 14};

  int n = sizeof(ST) / sizeof(int);

  Activity A[n];

  for (int i = 0; i < n; i++)
  {
    A[i].id = i + 1;
    A[i].startTime = ST[i];
    A[i].endTime = ET[i];
  }

  printf("Maior quantidade de atividades: %d\n", maxActivitiesCount(A, n));

  return 0;
}

int maxActivitiesCount(Activity *A, int n)
{

  int i = 0, qtt = 1, maxStart = 0, maxEnd = 0;

  sort(A, A + n, compare);

  maxEnd = A[0].endTime;

  printf("ID->%d|S->%d|F->%d\n", A[0].id, A[0].startTime, A[0].endTime);
  for (i = 1; i < n; i++)
  {
    if (A[i].startTime >= maxEnd)
    {
      maxEnd = A[i].endTime;

      qtt++;
    }

    // if (A[i].startTime >= maxEnd || maxStart >= A[i].endTime)
    // {
    //   if (A[i].startTime < maxStart)
    //   {
    //     maxStart = A[i].startTime;
    //   }
    //   if (A[i].endTime > maxEnd)
    //   {
    //     maxEnd = A[i].endTime;
    //   }

    //   qtt++;
    // }

    printf("ID->%d|S->%d|F->%d\n", A[i].id, A[i].startTime, A[i].endTime);
  }

  return qtt;
}
