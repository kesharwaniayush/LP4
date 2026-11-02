import java.util.*;

class Huffman {
    static class Node {
        char ch;
        int freq;
        Node left, right;

        Node(char ch, int freq) {
            this.ch = ch;
            this.freq = freq;
        }
    }

    static int totalBits = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of characters: ");
        int n = sc.nextInt();

        char[] ch = new char[n];
        int[] freq = new int[n];

        for (int i = 0; i < n; i++) {
            System.out.print("Enter character and frequency: ");
            ch[i] = sc.next().charAt(0);
            freq[i] = sc.nextInt();
        }

        PriorityQueue<Node> pq = new PriorityQueue<>(
            (a, b) -> a.freq - b.freq
        );

        //Add to the priority queue
        for (int i = 0; i < n; i++) {
            pq.add(new Node(ch[i], freq[i]));
        }

        while (pq.size() > 1) {
            Node left = pq.poll();
            Node right = pq.poll();

            Node parent = new Node('-', left.freq + right.freq);
            parent.left = left;
            parent.right = right;

            pq.add(parent);
        }

        System.out.println("Huffman Codes:");
        printCodes(pq.poll(), "");

        System.out.println("Total Bits Required: " + totalBits);

        sc.close();
    }

    static void printCodes(Node root, String code) {
        if (root == null)
            return;

        if (root.left == null && root.right == null) {
            if (code.isEmpty())
                code = "0";

            System.out.println(root.ch + " : " + code);

            totalBits += root.freq * code.length();

            return;
        }

        printCodes(root.left, code + "0");
        printCodes(root.right, code + "1");
    }
}