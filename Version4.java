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
                    //matrix[i][j] = 5;
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

    static int opMenu(Scanner scanner){
        
        int choice = 0;

        System.out.println("Menu: ");
        System.out.println("[1] Add");
        System.out.println("[2] Subtract");
        System.out.println("[3] Multiply");
        System.out.print("Please enter a choice: ");
        choice = scanner.nextInt();

        return choice;
        

    }

    public static void inMenu(int dim[], int choice, Scanner scanner){
        
        boolean isCorrect = true;
        while(isCorrect){
            System.out.print("\nEnter number of rows for First Matrix: ");
            dim[0] = scanner.nextInt();
            System.out.print("\nEnter number of columns for First Matrix: ");
            dim[1] = scanner.nextInt();
            System.out.print("\nEnter number of rows for Second Matrix: ");
            dim[2] = scanner.nextInt();
            System.out.print("\nEnter number of columns for Second Matrix: ");
            dim[3] = scanner.nextInt();

            if (choice == 1 || choice == 2) {
                if(dim[0] == dim[2] && dim[1] == dim[3]){
                    isCorrect = false;
                } else{
                    System.out.println("Error: Matrix Dimension not Equal");
                    continue;
                }
            } else{
                if(dim[1] == dim[2]){
                    isCorrect = false;
                } else {
                    System.out.println("Error: Column of Matrix 1 not equal with Row of Matrix 2");
                    continue;
                }
            }
        }
    
    }

    public static void main(String[] args) {
        
        int choice = 0, contMenu = 0;
        Scanner scanner = new Scanner(System.in);
        int[] dim = new int[4];
        
        choice = opMenu(scanner);
        inMenu(dim, choice, scanner);
        System.out.println("Enter First Matrix: ");
        Matrix mat1 = new Matrix(dim[0], dim[1]);
        System.out.println("Enter First Matrix: ");
        Matrix mat2 = new Matrix(dim[2], dim[3]);
        
        while(true){
            switch (choice)
            {
            case 1:
            {
                mat1.add(mat2);
                break;
            }
            case 2:
            {    
                mat1.sub(mat2);
                break;
            }
            case 3:
            {    
                //long start = System.currentTimeMillis();
                mat1.mul(mat2);
                //long end =System.currentTimeMillis();
                //System.out.println("Elapse Time " + (end - start) + " milliseconds");
                break;
            }
            default:
                break;
            }
            System.out.print("[1] change operation [2] change matrix [3] quit: ");
            contMenu = scanner.nextInt();

            if(contMenu == 1){
                if(dim[0] != dim[2] && dim[1] != dim[3]){
                    System.out.println("Dimensions not equal for Add or Subtract! Change Dimensions");
                    inMenu(dim, choice, scanner);
                    System.out.println("Enter First Matrix: ");
                    mat1.setMatrix(dim[0], dim[1]);
                    System.out.println("Enter Second Matrix: ");
                    mat2.setMatrix(dim[2], dim[3]);
                }
                choice = opMenu(scanner);
            }else if(contMenu == 2) {
                inMenu(dim, choice, scanner);
                System.out.println("Enter First Matrix: ");
                mat1.setMatrix(dim[0], dim[1]);
                System.out.println("Enter Second Matrix: ");
                mat2.setMatrix(dim[2], dim[3]);
            }else{
                System.exit(1);
                scanner.close();
            }
        }
    }
}