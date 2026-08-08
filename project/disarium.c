#include <math.h>
#include <stdbool.h>
#include <stdio.h>

// Function to calculate the total number of digits
int countDigits(int num)
{
    int count = 0;
    while (num > 0)
    {
        count++;
        num /= 10; // Remove the last digit
    }
    return count;
}

// Function to check if a number is a Disarium number
bool isDisarium(int num)
{
    int totalDigits = countDigits(num);
    int temp = num;
    int sum = 0;

    // Process digits from right to left
    while (temp > 0)
    {
        int remainder = temp % 10; // Extract the rightmost digit

        // Add the digit raised to its position exponent to our running sum
        sum += round(pow(remainder, totalDigits));

        totalDigits--; // Move to the previous position exponent
        temp /= 10;    // Drop the processed digit
    }

    // Return true if the calculated sum matches the original number
    return (sum == num);
}

int main()
{
    int inputNumber;

    printf("Enter a number to check: ");
    if (scanf("%d", &inputNumber) != 1)
    {
        printf("Invalid input.\n");
        return 1;
    }

    if (isDisarium(inputNumber))
    {
        printf("%d is a Disarium Number.\n", inputNumber);
    }
    else
    {
        printf("%d is NOT a Disarium Number.\n", inputNumber);
    }

    return 0;
}
