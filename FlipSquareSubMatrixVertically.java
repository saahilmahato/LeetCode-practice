class FlipSquareSubMatrixVertically {
    public int[][] reverseSubmatrix(int[][] grid, int x, int y, int k) {
        for (int i = 0; i < k/2; i++) {
            int topRowIndex = x + i;
            int bottomRowIndex = x + k - 1 - i;

            for (int j = 0; j < k; j++) {
                int currentCol = y + j;

                int temp = grid[topRowIndex][currentCol];
                grid[topRowIndex][currentCol] = grid[bottomRowIndex][currentCol];
                grid[bottomRowIndex][currentCol] = temp;
            }
        }

        return grid;
    }
}