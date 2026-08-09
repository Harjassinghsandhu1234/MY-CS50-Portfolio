from cs50 import get_float

def main():
    # Prompt the user for change owed, ensuring it is greater than 0
    while True:
        dollars = get_float("Change owed: ")
        if dollars > 0:
            break

    # Convert dollars to cents and round to avoid float precision issues
    cents = round(dollars * 100)

    # Initialize coin counts
    coins = 0
    coin_values = [25, 10, 5, 1]

    # Calculate the number of coins
    for value in coin_values:
        coins += cents // value  # Integer division to get coin count
        cents %= value           # Remainder becomes the new cents to evaluate

    print(coins)

if __name__ == "__main__":
    main()
