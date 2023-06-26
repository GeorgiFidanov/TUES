public class PrintMatrix {
    public void printer(int [][] result) {
        for (int[] row : result) {
            for (int element : row) {
                if (element == row[0]) {
                    System.out.print("| ");
                }
                System.out.print(element + " ");
            }
            System.out.print("|");
            System.out.println();
        }
        System.out.print("\n");
    }
}
