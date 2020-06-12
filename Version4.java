import java.util.Scanner;

class Version4 {
    
    public static class Matrix{
        
        private int row;
        private int col;
        private float[][] matrix;

        Scanner scanner = new Scanner(System.in);

        public Matrix(int row, int col){
            
            this.row = row;
            this.col = col;
            matrix = new float[row][col];
            
            for(int i=0; i<row; i++){
                for(int j=0; j<col; j++){
                    System.out.print("Input value for ["+i+"]["+j+"]: ");
                    this.matrix[i][j] = scanner.nextFloat();
                    System.out.println();
                }
            }
        }

        public int getRow(){
            return row;
        }

        public int getSet(){
            return col;
        }

        public float getValue(int row, int col){
            return matrix[row][col];
        }

        void setMatrix(int row, int col){
            
            this.row = row;
            this.col = col;
            matrix = new float[row][col];
            
            for(int i=0; i<this.row; i++){
                for(int j=0; j<this.col; j++){
                    System.out.print("Input value for ["+i+"]["+j+"]: ");
                    matrix[i][j] = scanner.nextFloat();
                }
            }
        }

        void add(Matrix other){
            
            for(int i=0; i<row; i++){
                for(int j=0; j<col; j++){
                    System.out.print(matrix[i][j] + other.getValue(i, j) + "  ");
                }
                System.out.println();
            }
        }

        void sub(Matrix other){
            
            for(int i=0; i<row; i++){
                for(int j=0; j<col; j++){
                    System.out.print(matrix[i][j] - other.getValue(i, j) + "  ");
                }
                System.out.println();
            }
        }

        void mul(Matrix other){
            float ans = 0;
            for(int i=0; i<row; i++){
                for(int j=0; j<other.getRow(); j++){
                    for(int k=0; k<col;k++){
                        ans += matrix[i][k] * other.getValue(k, j); 
                    }
                    System.out.print(ans + "  ");
                    ans = 0;
                }
                System.out.println();
            }
        }

    }

    static int opMenu(){
        
        int choice;
        Scanner scanner = new Scanner(System.in);

        System.out.println("Menu: ");
        System.out.println("[1] Add");
        System.out.println("[2] Subtract");
        System.out.println("[3] Multiply");
        System.out.print("Please enter a choice: ");
        choice = scanner.nextInt();
        scanner.close();

        return choice;

    }

    static void inMenu(int row, int col, int row2, int col2, int choice){
        
        Scanner scanner = new Scanner(System.in);
        boolean isCorrect = true;
        
        while(isCorrect){
            System.out.print("\nEnter number of rows for First Matrix: ");
            row = scanner.nextInt();
            System.out.print("\nEnter number of columns for First Matrix: ");
            col = scanner.nextInt();
            System.out.print("\nEnter number of rows for Second Matrix: ");
            row2 = scanner.nextInt();
            System.out.print("\nEnter number of columns for Second Matrix: ");
            col2 = scanner.nextInt();

            if (choice == 1 || choice == 2) {
                if(row == row2 && col == col2){
                    isCorrect = false;
                } else{
                    System.out.println("Error: Matrix Dimension not Equal");
                    continue;
                }
            } else{
                if(col == row2){
                    isCorrect = false;
                } else {
                    System.out.println("Error: Column of Matrix 1 not equal with Row of Matrix 2");
                    continue;
                }
            }
        }
        scanner.close();
    }

    public static void main(String[] args) {
        
        int choice = 0, contMenu = 0;
        int row = 0, col = 0, row2 = 0, col2 = 0; 
        Scanner scanner = new Scanner(System.in);

        choice = opMenu();
        inMenu(row, col, row2, col2, choice);
        Matrix mat1 = new Matrix(row,col);
        Matrix mat2 = new Matrix(row2,col2);
        
        while(true){
            switch (choice)
            {
            case 1:
                mat1.add(mat2);
                break;
            case 2:
                mat1.sub(mat2);
                break;
            case 3:
                mat1.mul(mat2);
                break;
            default:
                break;
            }
            System.out.print("[1] change operation [2] change matrix [3] quit: ");
            contMenu = scanner.nextInt();

            if(contMenu == 1){
                if(row != row2 && col != col2){
                    System.out.println("Dimensions not equal for Add or Subtract! Change Dimensions");
                    inMenu(row, col, row2, col2, choice);
                    mat1.setMatrix(row, col);
                    mat2.setMatrix(row2, col2);
                }
                choice = opMenu();
            }else if(contMenu == 2) {
                inMenu(row, col, row2, col2, choice);
                mat1.setMatrix(row, col);
                mat2.setMatrix(row2, col2);
            }else{
                System.exit(1);
                scanner.close();
            }
        }
    }
}