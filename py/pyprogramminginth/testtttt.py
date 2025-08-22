#!/usr/bin/env python3

import sys
import time

def write_prime_to_file():
    """
    Calculates the largest known prime number and writes it to a file.
    Note: This calculation is computationally intensive and will take a significant amount of time.
    The resulting file will be very large (over 41 million characters).
    """

    # The exponent for the largest known Mersenne prime.
    # The prime number itself is 2^136279841 - 1.
    exponent = int(input("Enter exponential number here: "))

    print(f"Starting calculation for 2^{exponent} - 1...")
    start_time = time.time()

    # Python's built-in integers handle numbers of arbitrary size.
    try:
        prime_number = pow(2, exponent) - 1
        
        # Define the output file path.
        file_path = "prime_number.txt"

        print("Calculation complete. Starting file write...")

        # Open the file in write mode ('w') with UTF-8 encoding.
        # The 'with' statement ensures the file is properly closed even if errors occur.
        with open(file_path, 'w', encoding='utf-8') as f:
            # Convert the large integer to a string and write it to the file.
            f.write(str(prime_number))

        end_time = time.time()
        duration = end_time - start_time

        print(f"Successfully wrote the prime number to '{file_path}'")
        print(f"The process took approximately {duration:.2f} seconds.")

    except MemoryError:
        print("Error: Not enough memory to complete the calculation.")
        sys.exit(1)
    except Exception as e:
        print(f"An unexpected error occurred: {e}")
        sys.exit(1)


# Run the function when the script is executed.
if __name__ == "__main__":
    write_prime_to_file()