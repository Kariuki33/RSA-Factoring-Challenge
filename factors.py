import sys

def factors(n):

    """
    Returns a list of the factors of n.
    """
    result = []
    for i in range(2, n // 2 + 1):

        if n % i == 0:
            result.append(i)
    return result

def main():

    # Read the numbers from the file
    with open(sys.argv[1], 'r') as f:
        numbers = [int(line.strip()) for line in f]

    # Factorize each number and print the result
    for n in numbers:

        for p in factors(n):
            q = n // p
            print(f"{n}={p}*{q}")

if __name__ == '__main__':
    main()
