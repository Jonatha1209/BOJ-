using System;

class MainClass {
    public static void Main (string[] args) {
        int N;
        bool isValidInput = false;

        do {
            string input = Console.ReadLine();

            isValidInput = int.TryParse(input, out N);

            if (!isValidInput) {
               
            }
        } while (!isValidInput);

        int originalN = N;
        int count = 0;

        do {
            int sum = (N / 10 + N % 10) % 10; 
            N = (N % 10) * 10 + sum; 
            count++;
        } while (N != originalN); 

        Console.WriteLine(count);
    }
}
