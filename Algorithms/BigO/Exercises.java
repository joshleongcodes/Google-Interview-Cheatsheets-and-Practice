class Exercises {
    public static void main(String[] args) {
       
    }

    /* 
     * What is the runtime of the below code?
     * Example 1
     */
    public static void foo(int[] array) {
        int sum = 0;
        int product = 1;
        for(int i = 0; i < array.length; i++) {
            sum += array[i];
        }
        for(int i = 0; i < array.length; i++) {
            product *= array[i];
        }
        System.out.println(sum + ", " + product);
    }  

    /*
     * What is the runtime of the below code?
     * Example 2
     */
    public static void printPairs(int[] array) {
        for(int i = 0; i<array.length; i++) {
            for(int j = 0; j<array.length; j++) {
                System.out.println(array[i] + "," + array[j]);
            }
        }
    }

     /*
     * What is the runtime of the below code?
     * Example 3
     */
    public static void printUnorderedPairs(int[] array) {
        for(int i = 0; i < array.length; i++) {
            for(int j = i + 1; j < array.length; j++) {
                System.out.println(array[i] + "," + array[j]);
            }
        }
    }

    /*
     * What is the runtime of the below code?
     * Example 4
     */
    public static void printUnorderedPairs_2(int[] arrayA, int[] arrayB) {
        for(int i = 0; i < arrayA.length; i++) {
            for(int j = 0; j < arrayB.length; j++) {
                System.out.println(arrayA[i] + "," + arrayB[j]);
            }
        }
    }

    /*
     * What is the runtime of the below code?
     * Example 5
     */
    public static void printUnorderedPairs_3(int[] arrayA, int[] arrayB) {
        for(int i = 0; i < arrayA.length; i++) {
            for(int j = 0; j < arrayB.length; j++) {
                for(int k = 0; k<100000; k++) {
                    System.out.println(arrayA[i] + "," + arrayB[j]);
                }
            }
        }
    }
    /*
     * What is the runtime of the below code?
     * Example 6
     */
    public static void reverse(int[] array) {
        for(int i = 0; i<array.length; i++) {
            int other = array.length - i - 1;
            int temp = array[i];
            array[i] = array[other];
            array[other] = temp;
        }
    }

    /*
     * Which of the following are equivilent to O(n)?
     * Example 7
     * 
     * O(N + P), where P < N/2
     * O(2N)
     * O(N + log(N))
     * O(N + M)
     */

    /*
     * What is the runtime fo the below code?
     * Example 9
     */

    // int sum(Node node){
    //     if (!node){
    //         return 0;
    //     }
    //     return sum(node.left) + node.value + sum(node.right);
    // }

    /*
     * What is the runtime of the below code?
     * Example 10
     */
    public static boolean isPrime(int n){
        for(int x = 2; x * x <= n; x++){
            if(n % x == 0){
                return false;
            }
        }
        return true;
    }

    /*
     * What is the runtime of the below code?
     * Example 11
     */

    public static int factorial(int n){
        if(n < 0){
            return -1;
        } else if(n == 0) {
            return 1;
        } else {
            return n * factorial(n - 1);
        }
    }

    /*
     * What is the runtime of the below code?
     * Example 12
     */
    
    public static void permutation(String str) {
        permutation(str, "");
    }
    public static void permutation(String str, String prefix) {
        if(str.length() == 0){
            System.out.println(prefix);
        } else {
            for(int i = 0; i < str.length(); i++){
                String rem = str.substring(0, i) + str.substring(i+1);
                permutation(rem, prefix + str.charAt(i));
            }
        }
    }

     /*
     * What is the runtime of the below code?
     * Example 13
     */
    int fib(int n) {
        if(n <= 0) return 0;
        else if(n == 1) return 1;
        return fib(n - 1) + fib(n - 2);
    }

}