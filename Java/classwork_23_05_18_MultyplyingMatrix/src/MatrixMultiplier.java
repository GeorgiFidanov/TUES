import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class MatrixMultiplier {
    public static int[][] multiplyMatricesParallel(int[][] matrix1, int[][] matrix2) {
        int numRows1 = matrix1.length;
        int numCols1 = matrix1[0].length;
        int numRows2 = matrix2.length;
        int numCols2 = matrix2[0].length;

        if (numCols1 != numRows2) {
            throw new IllegalArgumentException("Cannot multiply matrices. Invalid dimensions.");
        }

        int[][] result = new int[numRows1][numCols2];

        try (ExecutorService executor = Executors.newFixedThreadPool(Runtime.getRuntime().availableProcessors())) {

            for (int i = 0; i < numRows1; i++) {
                for (int j = 0; j < numCols2; j++) {
                    final int row = i;
                    final int col = j;

                    executor.submit(() -> {
                        int sum = 0;
                        for (int k = 0; k < numCols1; k++) {
                            sum += matrix1[row][k] * matrix2[k][col];
                        }
                        result[row][col] = sum;
                    });
                }
            }

            executor.shutdown();
            try {
                executor.awaitTermination(Long.MAX_VALUE, TimeUnit.NANOSECONDS);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        return result;
    }
}
