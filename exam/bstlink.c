import java.io.*;
import java.io.DataOutputStream;
import java.io.FileOutputStream;
import java.util.*;
public class employee{
    public static void main(String []args){
        Scanner sc = new Scanner(System.in);
        int ci1,ci2,ci3,uc1,uc2,uc3;
        int tc1,tc2,tc3,avg=0;
        int[] a = new int[10];
         
        System.out.println("----------Enter details we have---------");
        
            System.out.println("Enter the consumer id:");
             ci1=sc.nextInt();
            System.out.println("Enter the unit consumed :");
             uc1=sc.nextInt();
            
             tc1=uc1*100;
            System.out.println("Total amount per month:"+tc1);
            sc.nextLine();
            System.out.println("----------Enter details we have---------");
        
            System.out.println("Enter the consumer id:");
             ci2=sc.nextInt();
            System.out.println("Enter the unit consumed :");
            uc2=sc.nextInt();
            
             tc2=uc2*100;
            System.out.println("Total amount per month:"+tc2);
            sc.nextLine();
            System.out.println("----------Enter details we have---------");
        
            System.out.println("Enter the consumer id:");
             ci3=sc.nextInt();
            System.out.println("Enter the unit consumed :");
             uc3=sc.nextInt();
            
             tc3=uc3*100;
            System.out.println("Total amount per month:"+tc3);
    
            int max;
            if((tc1>tc2)&&(tc1>tc3)){
                 max = tc1;
            }
            else if((tc2>tc3)&&(tc2>tc1)){
                 max=tc2;
            }
            else{
                max=tc3;
            }
    for(int  i=0;i<3;i++){
        try{
FileOutputStream fo = new FileOutputStream("/home/mec/text.txt");
String w1="Total amount:"+tc1;    
byte b1[]=w1.getBytes();
fo.write(b1);
String w2="Total amount:"+tc2;    
byte b2[]=w2.getBytes();
fo.write(b2);
String w3="Total amount:"+tc3;    
byte b3[]=w3.getBytes();
fo.write(b3);
fo.close();
        }
        catch(Exception e){
            System.out.println(e.getMessage());
        }
        finally{
            System.out.println("written sucesfull");
        }
    }

        if(max==tc1){
            
            System.out.println("----employee with high consumption----");
            System.out.println("cosumer id "+ci1);
            System.out.println("unit cosumed:"+uc1);
            System.out.println("Enter the 5 previous reading");
            for(int i=1;i<=5;i++){
                a[i]=sc.nextInt();
                avg=avg+a[i]/5;
            }
            System.out.println("Average of the given employee"+avg);
            if(avg>500){
                System.out.println("Alert :You are on above limit");
            }
            else{
                System.out.println("Alert :Under limit");
            }

        }
        else if(max==tc2){
            
            System.out.println("----employee with high consumption----");
            System.out.println("cosumer id "+ci2);
            System.out.println("unit cosumed:"+uc2);
            System.out.println("Enter the 5 previous reading");
            for(int i=1;i<=5;i++){
                a[i]=sc.nextInt();
                avg=avg+a[i]/5;
            }
            System.out.println("Average of the given employee"+avg);
            if(avg>500){
                System.out.println("Alert :Your are on above limit");
            }
            else{
                System.out.println("Alert :under limit");
            }

        }
        else{
            
                System.out.println("----employee with high consumption----");
                System.out.println("cosumer id "+ci3);
                System.out.println("unit cosumed:"+uc3);
                System.out.println("Enter the 5 previous reading");
                for(int i=1;i<=5;i++){
                    a[i]=sc.nextInt();
                    avg=avg+a[i]/5;
                }
                System.out.println("Average of the given employee"+avg);
                if(avg>500){
                    System.out.println("Alert :Your are on above limit");
                }
                else{
                    System.out.println("Alert :under limit");
                }
    
            
        }
       
    }
}

