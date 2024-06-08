#include <stdio.h>
#include <string.h>
#define N 100

void threeSumClosest(int arr[], int target) {
  int i = 0;
  int sum = 0;
  int size = 0;

  if (arr == NULL) {
    printf("Invalid Input!\n");
  }

  while (arr[size]) {
    size++;
  }

  sum = arr[0] + arr[1] + arr[2];
  if (sum == target) {
    printf("the sum closest to the target %d is %d\n", target, sum);
    return;
  }
  return threeSumClosest(arr + 1, target);
  return threeSumClosest(arr, target + 1);
  return threeSumClosest(arr, target - 1);
}

int collatz_max(int n) {
  int max = n;

  if (n <= 0) {
    return 0;
  }

  if (n == 1) {
    return n;
  }

  if (n > max) {
    max = n;
  }

  if (n % 2 == 0) {
    return collatz_max(n / 2);
  }

  if (n % 2 == 1) {
    return collatz_max((n * 3) + 1);
  }
  return max;
  printf("%d", max);
}

void reversed_Vowels(char *str) {

  if (*str == '\0') {
    return;
  }

  reversed_Vowels(str + 1);

  char vowels[] = "aeiouAEIOU";
  int i = 0;
  while (vowels[i] != '\0') {
    if (*str == vowels[i]) {
      printf("%c", *str);
    }
    i++;
  }
}

int main(void) {

  int pressedkey = 0;
  int arr[N];
  int target;
  int CollatzNum;
  char Don[N];

  printf("Please Press a function number: 1- 3SumClosest 2- Collatz Max 3- "
         "reversed Vowels 4- EXIT\n");
  while (scanf("%d", &pressedkey) != 0) {
    if (pressedkey <= 0) {
      printf("Input Error!\n");
    }
    if (pressedkey == 1) {
      int arrsize1;
      printf("Enter the number of elements in the array:\n");
      while (scanf("%d", &arrsize1) != 1 || arrsize1 > 100 || arrsize1 < 3) {
        printf("Invalid Input!\n");
      }
      printf("Enter the elements in the array:\n");
      for (int i = 0; i < arrsize1; i++) {
        while (scanf("%d", &arr[i]) != 1) {
          printf("Invalid Input!");
          while (getchar() != '\n')
            ;
        }
      }
      printf("Enter target value:\n");
      while (scanf("%d", &target) != 1) {
        printf("Invalid Input!\n");
        while (getchar() != '\n')
          ;
      }
      threeSumClosest(arr, target);
      printf("\n");
    }

    else if (pressedkey == 2) {
      printf("Enter a positive integer:\n");
      while (scanf("%d", &CollatzNum) != 1 || CollatzNum > 100) {
        printf("Invalid Input!\n");
      }
      printf("Tha max is %d\n", collatz_max(CollatzNum));
    }

    else if (pressedkey == 3) {
      printf("Enter a string\n");
      while (scanf("%s", Don) != 1 || strlen(Don) > 101) {
        printf("Invalid Input!\n");
      }
      printf("RECURSIVE METHOD - Reversed vowels are: ");
      reversed_Vowels(Don);
    }
  }
  return 0;
}
