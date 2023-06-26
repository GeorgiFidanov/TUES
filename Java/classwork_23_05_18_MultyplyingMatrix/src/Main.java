public class Main {
    public static void main(String[] args) {
        int[][] matrix1 = {{1, 2, 3}, {4, 5, 6}};
        int[][] matrix2 = {{10, 11}, {20, 21}, {30, 31}};

        int[][] result = MatrixMultiplier.multiplyMatricesParallel(matrix1, matrix2);

        PrintMatrix printMatrix = new PrintMatrix();
        // Print the input
        System.out.print("matrix1:\n");
        printMatrix.printer(matrix1);
        System.out.print("matrix2:\n");
        printMatrix.printer(matrix2);
        // Print the result
        System.out.print("result:\n");
        printMatrix.printer(result);
    }
}
