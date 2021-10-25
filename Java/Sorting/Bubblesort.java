public class Bubblesort {
    public static void main(String[] args) {
        Bubblesort ob=new Bubblesort();
        int ar[]={1,9,3,2,5};
        ob.bubbleSort(ar);
        System.out.println("sorted array");
        int n=ar.length;
        for(int i=0;i<n;i++)
        {
            System.out.print(ar[i]+" ");
        }
        
    }
    void bubbleSort(int arr[])
    {
        int n = arr.length;
        for (int i = 0; i < n-1; i++)
            for (int j = 0; j < n-i-1; j++)
                if (arr[j] > arr[j+1])
                {
                    // swap arr[j+1] and arr[j]
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
    }
}
