import java.util.ArrayList;
import java.util.Scanner;
import java.util.Random;
import java.util.Collections;
public class test{
    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        Random random = new Random();

        ArrayList<Integer> list = new ArrayList<Integer>();
        System.out.println("how many numbers do you want?");
        int size = scan.nextInt();

        for(int i = 0; i < size;i++){
            list.add(random.nextInt(10));
        }
        
        Collections.sort(list);
        
        
        System.out.println(list);

        //int size = list.size();

        for(int i = 0; i < size/2;i++){
            int temp = list.get(i);
            list.set(i,list.get(size-i-1));
            list.set(size-i-1, temp);
         }

        System.out.println(list);

        //Do you really want this life?
        //First try to tell me what the hell you mean by this "life"

    }

}

 
