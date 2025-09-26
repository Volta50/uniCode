import java.util.*;

public class MergeSort{
    public static void main(String[] args){
        ArrayList<Integer> list = new ArrayList<>();

    }


    public static void mergeSort(int start, int end){
        mid = (start+end)/2;
        
        if(start == end){
            return void;
        }

        //FirstArray
        mergeSort(start,mid);
        
        //SecondArray
        mergeSort(mid+1,end);

        //Sort
        int i = start;
        int j = mid+1;
        

        while(i < mid || j < end){
            if()
        }


    }
}