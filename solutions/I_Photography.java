package org.example;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
    public static int submatrixSum(int[][] matrix, int target) {
        int m = matrix.length;
        int n = matrix[0].length;

        int[] temp = new int[m];
        int ans = 0;
        for (int left = 0; left < n; left++) {
            Arrays.fill(temp, 0);
            for (int right = left; right < n; right++) {
                for (int i = 0; i < m; i++) {
                    temp[i] += matrix[i][right];
                }
                ans += subCount(temp, target);
            }
        }
        return ans;
    }

    private static int subCount(int[] temp, int target) {
        HashMap<Integer, Integer> prevSum = new HashMap<>();

        int res = 0;
        int currentSum = 0;

        for (int t : temp) {

            currentSum += t;
            if (currentSum == target) {
                res++;
            }
            if (prevSum.containsKey(currentSum - target)) {
                res += prevSum.get(currentSum - target);
            }
            prevSum.merge(currentSum, 1, Integer::sum);
        }

        return res;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        int[][] matrix = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int val = sc.nextInt();
                if (val == 0) {
                    matrix[i][j] = -1;
                } else {
                    matrix[i][j] = 1;
                }
            }
        }
        System.out.println(submatrixSum(matrix, 0));
    }
}
