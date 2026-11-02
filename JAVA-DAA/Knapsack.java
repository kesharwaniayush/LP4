import java.util.*;

class Knapsack {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of items: ");
        int n = sc.nextInt();

        double[][] items = new double[n][3];

        for (int i = 0; i < n; i++) {
            System.out.print("Enter weight and profit: ");
            double weight = sc.nextDouble();
            double profit = sc.nextDouble();

            items[i][0] = weight;
            items[i][1] = profit;
            items[i][2] = profit / weight;
        }

        System.out.print("Enter knapsack capacity: ");
        double capacity = sc.nextDouble();

        // Sort items by profit-to-weight ratio in descending order
        Arrays.sort(items, (a, b) -> Double.compare(b[2], a[2]));

        double totalProfit = 0;

        for (int i = 0; i < n && capacity > 0; i++) {
            double weight = items[i][0];
            double profit = items[i][1];
            double ratio = items[i][2];

            if (weight <= capacity) {
                capacity -= weight;
                totalProfit += profit;
            } else {
                totalProfit += ratio * capacity;
                capacity = 0;
            }
        }

        System.out.printf("Maximum Profit: %.2f%n", totalProfit);

        sc.close();
    }
}

//10 60,20 100,30 120